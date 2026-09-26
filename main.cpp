#include "Image_Class.h"
#include "Filters.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

void showAppName () {
    std::cout << "\n ================================" << '\n';
    std::cout << "           Baby Photoshop        " << '\n';
    std::cout << " ================================" << '\n'<<'\n';
}

void showMenu () {
    std::cout << "1.Grayscale Conversion \n" ;
    std::cout << "2.Black and White \n" ;
    std::cout << "3.Invert Image \n" ;
    std::cout << "4.Adding a Frame \n" ;
    std::cout << "5.Flip Image \n" ;
    std::cout << "6.Rotate Image \n" ;
    std::cout << "7.Darken or Lighten Image (Brightness) \n" ;
    std::cout << "8.Resizing Image \n" ;
    std::cout << "S.Save Current Image \n" ;
    std::cout << "L.Load New Image \n" ;
    std::cout << "E.Exit \n" ;
    std::cout <<"\n" <<"--> choose an option: ";
} 

bool loadNewImage(Image& image) {
    std::string file_name ; 
    std::cout <<"Enter image filename/path: ";
    std::cin >> file_name;
    try {
        image.loadNewImage(file_name) ;
        std::cout << "Image loaded successfully! \n";
        return true ;
    } catch (...) {
        std::cout <<"Failed to load image!. please check the file path.\n";
        return false;
    }
}

void saveImage (Image& image) {
    std::cout << " Enter the target path/filename (e.g., output.png, result.jpg, myImage.bmp)\n";
    std::string filename ;
    std::cin >> filename;

    try {
        image.saveImage(filename);
        std::cout << "Image saved successfully as "<< filename <<"!\n" ;
    } catch(...) {
        std::cout << "Error: could not save the image!" << '\n';
    }

}

void getRGBFromUser(unsigned char& r, unsigned char& g, unsigned char& b) {
    int choice = 0;
    std::cout << "\nSelect Color:\n1. Red\n2. Blue\n3. Green\n4. Custom RGB\nChoice: ";
    std::cin >> choice;

    if (choice == 1)      { r = 255; g = 0;   b = 0;   }
    else if (choice == 2) { r = 0;   g = 0;   b = 255; }
    else if (choice == 3) { r = 0;   g = 255; b = 0;   }
    else {
        int tempR, tempG, tempB;
        std::cout << "Enter Red (0-255): ";   std::cin >> tempR;
        std::cout << "Enter Green (0-255): "; std::cin >> tempG;
        std::cout << "Enter Blue (0-255): ";  std::cin >> tempB;

        r = (tempR > 255) ? 255 : (tempR < 0 ? 0 : tempR);
        g = (tempG > 255) ? 255 : (tempG < 0 ? 0 : tempG);
        b = (tempB > 255) ? 255 : (tempB < 0 ? 0 : tempB);
    }
}

int main() {
    
    Image currentImage ;

    bool running = true;

    showAppName();
    
    // load the image before starting the main loop
    while (!loadNewImage(currentImage)){
        std::cout << "try again.\n";
    }

    // main loop 
    while (running) {
        
        showMenu();

        // get user choice 
        char  choice ; 
        std::cin >> choice;
        choice = tolower(choice); 

        switch (choice)
        {
        
            case '1':
            applyGrayscale_1(currentImage);
            std::cout << "Filter applyed successfully!\n" ;
            
            break;
        
            case '2':
            applyBlackAndWhite_2(currentImage);
            std::cout << "Filter applyed  successfully!\n";
            break;
        
            case '3':
            applyInvert_3(currentImage);
            std::cout << "Filter applyed  successfully!\n";
            break;
        
            case '4':
            {
                std::cout << "Choose frame style :\n1.simple\n2.fancy\n";
                int frameStyle ; 
                std::cin >> frameStyle;

                unsigned char r,g,b; 
                getRGBFromUser(r,g,b);

                applyFrame_4(currentImage, frameStyle, r, g, b);
                std::cout << "Frame added successfully!\n";
            }
            
            break;
        
            case '5':
            {
                std::cout << "Choose an option:1.horizontal\n2.vertical\n";
                int choice;
                std::cin >> choice ; 
                if (choice == 2 ){
                    applyFlip_5(currentImage,false);
                }
                else {
                    applyFlip_5(currentImage);
                }
            }
            break;
        
            case '6':
            {
                std::cout << "Enter a degree of rotation (e.g, 180, 90):\n";
                int degree;
                std::cin >> degree;

                applyRotate_6(currentImage, degree%360);
                
                std::cout << "Filter applied successfully!\n";
            }
            break;
        
            case '7':{
            
            int mode;
            double factor;

            std::cout << "Select Lightness Mode:\n1. Lighten Image\n2. Darken Image\n";
            std::cin >> mode;

            std::cout << "Enter percentage (1 - 100%):\n";
            std::cin >> factor;
            
            applyBrightness_7 (currentImage, (mode == 1)? factor: -factor);

            std::cout << "Filter added successfully!\n";

        }
            break;
        
            case '8':
            {
                int newWidth , newHeight;
                std::cout << "Enter new width:\n";
                std::cin >> newWidth;

                std::cout << "Enter new height:\n";
                std::cin >> newHeight;

                applyResize_8(currentImage,newWidth,newHeight);

                std::cout << "Resizing applied successfully!\n";
            }
            break;
        
            case 's':
            saveImage(currentImage);
            break;
        
            case 'l':{
            char confirm;
            std::cout << "Do you want to save before loading a new image ?(Y/N)\n" ;
            std::cin >> confirm ;
            if (tolower(confirm) == 'y') {
                saveImage(currentImage);
            }           
            loadNewImage(currentImage);
           
            break; 
            }
        
            case 'e':
            {
                char confirm ; 
                std::cout<< "Do you want to save before exiting?(Y/N)\n";
                std::cin >> confirm;

                if (tolower(confirm) == 'y') {
                    saveImage(currentImage) ;
                }
                running = false;
            }
            break;
        
        default:
        std::cout << "Invalid choice. try again!"<< '\n';
            break;
        }

        


    }

    }
    
   


