/*
 * Course: CS213 - Object-Oriented Programming
 * Project: Baby Photoshop - Phase 1
 * File: main.cpp
 * 
 * Team Members & Filter Assignments:
 * 1. Hatem Abdullah Al-Yafai       - ID: 20253050 - Filters: 1, 5
 * 2. Alaa Al-Deen Nabil Al-Maliki  - ID: 20253072 - Filters: 2, 6
 * 3. Mohammed Mazen Al-Sofi        - ID: 20253073 - Filters: 3, 7
 * 4. Mohammed Abdulmalik Albawah   - ID: 20253081 - Filters: 4, 8
 *
 * Project Structure & Integration Notes:
 * - System Architecture & Main Menu Logic: Planned and designed collaboratively by all team members.
 * - Main Program Implementation & Integration: Implemented, finalized, and uploaded by Mohammed Mazen Al-Sofi.
 *
 * Repository & Diagram Links:
 * - GitHub Repository: https://github.com/TBM2099/oop-project
 * - System Architecture Diagram: https://github.com/TBM2099/oop-project/blob/origin/System%20Architecture%20Diagram.png
 */

#include "Image_Class.h"
#include "Filters.h"
#include <iostream>
#include <string>
#include <algorithm>


// Filter 1: Grayscale Conversion
void applyGrayscale_1(Image& imagez)
{

    for (int x = 0; x < imagez.width; x++ )//To scroll through pixels horizontally
    {
        for (int y = 0; y < imagez.height; y++)//To scroll through pixels vertically
        {
            //I used "unigned char" because its range is 0-255, and because it also only reserves 1 byte.
            
            unsigned char red = imagez(x, y, 0);
            unsigned char green = imagez(x, y, 1);//Here I wanted to assign the color channel values ​​to variables so that I could take their average.
            unsigned char blue = imagez(x, y, 2);

            unsigned char avg = (int(red) + green + blue) / 3 ;//this "int(red)" To avoid overflow

            imagez(x, y, 0) = avg;
            imagez(x, y, 1) = avg;//Here, I applied the same ratio to all channels.
            imagez(x, y, 2) = avg;

        }
    }

}

// Filter 2: Black and White
void applyBlackAndWhite_2(Image& image){
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int avr=0;
            for (int k = 0; k < 3; ++k) {
                 avr+=image(i, j, k);
            }
            if(avr/3 >=128){
              for (int k = 0; k < 3; ++k) {  
                image(i, j, k) =255;
                }
            }
            else {
                for (int k = 0; k < 3; ++k) {  
                    image(i, j, k) =0;
                }
            }
        }   
    }

}

// Filter 3: Invert Image
void applyInvert_3(Image& image){
   

    for (int x = 0; x < image.width; x++){
        for (int y = 0; y < image.height; y++) {
            image.setPixel(x,y,0,255-image.getPixel(x,y,0));
            image.setPixel(x,y,1,255-image.getPixel(x,y,1));
            image.setPixel(x,y,2,255-image.getPixel(x,y,2));
        }
    }
}

// Filter 4: Adding a Frame to the Picture
void applyFrame_4(Image& image, int frameType,
     unsigned char r, unsigned char g, unsigned char b) {

        int Width_Of_Image = image.width; 
        int Height_Of_Image = image.height;
        
        //simple frame 

        if(frameType == 1 )
        {
            short TheThickness_Of_simple =10; 

            for(int x = 0; x < Width_Of_Image; x++)
            {
               for (int y = 0 ;y < Height_Of_Image ; y++ ) 
               {
                if (x < TheThickness_Of_simple || x >= Width_Of_Image - TheThickness_Of_simple || y < TheThickness_Of_simple || y >= Height_Of_Image - TheThickness_Of_simple)
                {
                    image.setPixel(x , y ,0 ,r);
                    image.setPixel(x , y ,1 ,g);
                    image.setPixel(x , y ,2 ,b);
                }
                
               }
            }
        
        }

        //fans frame
        else if (frameType == 2 )
        {
            int OuterThick = 15 ; 
            int StripeThick = 5 ;
            int InnerThick = 5 ;

            int TotalFrame = OuterThick + StripeThick + InnerThick ; //24 all 

            for(int x = 0; x < Width_Of_Image; x++)
            {
               for (int y = 0 ;y < Height_Of_Image ; y++ )
               {
                bool isFrameArea = (x < TotalFrame || x >= Width_Of_Image - TotalFrame || 
                    y < TotalFrame || y >= Height_Of_Image - TotalFrame);

                if(isFrameArea) 
                {
                    

                    if (x < OuterThick || x >= Width_Of_Image - OuterThick || y < OuterThick || y >= Height_Of_Image - OuterThick)
                    {
                        if ((x + y) % 8 < 2 || (x - y) % 8 == 0)
                        {
                            image.setPixel(x, y, 0, 255); // لون أبيض للنجوم
                            image.setPixel(x, y, 1, 255);
                            image.setPixel(x, y, 2, 255);
                        }
                        else
                        {
                            image.setPixel(x, y, 0, r); 
                            image.setPixel(x, y, 1, g);
                            image.setPixel(x, y, 2, b);
                        }

                        
                    }
                   
                    else if (x > OuterThick + StripeThick || x >= Width_Of_Image -(OuterThick + StripeThick)|| y < OuterThick + StripeThick || y >= Height_Of_Image - (OuterThick + StripeThick) )    
                    {
                        image.setPixel(x, y, 0, 255); // Red 
                        image.setPixel(x, y, 1, 255); // Green
                        image.setPixel(x, y, 2, 255); // Bule 

                    }


                    else 
                    {
                        image.setPixel(x, y, 0, r);
                        image.setPixel(x, y, 1, g);
                        image.setPixel(x, y, 2, b);

                    }

                }

                int cornerSize = TotalFrame; 
                bool isTopLeft     = (x < cornerSize && y < cornerSize);
                bool isTopRight    = (x >= Width_Of_Image - cornerSize && y < cornerSize);
                bool isBottomLeft  = (x < cornerSize && y >= Height_Of_Image - cornerSize);
                bool isBottomRight = (x >= Width_Of_Image - cornerSize && y >= Height_Of_Image - cornerSize);

                if (isTopLeft || isTopRight || isBottomLeft || isBottomRight)
                {
                    if ((x + y) % 6 < 3)
                    { 
                        image.setPixel(x, y, 0, 240);
                        image.setPixel(x, y, 1, 240);
                        image.setPixel(x, y, 2, 240);

                    }
                }

               }
            
            }


        }

     }

// Filter 5: Flip Image
void applyFlip_5(Image& image, bool horizontal )
{
    Image temp = image;//Original backup image for copying

    for (int x = 0; x < image.width; x++)//To go through all pixels
    {
        for (int y = 0; y < image.height; y++)
        {
            if (horizontal)//To perform horizontal inversion
            {
                //This is the variable in which we will store the new coordinate.
                int newX = image.width - 1 - x;//The equation that makes each pixel match its counterpart on the opposite side

                //Here we began copying from the original version we created above to the mirrored version.
                image(x, y, 0) = temp(newX, y, 0);
                image(x, y, 1) = temp(newX, y, 1);
                image(x, y, 2) = temp(newX, y, 2);
                            
            }

            else
            {
                int newY = image.height -1 - y;

                image(x, y, 0) = temp(x, newY, 0);
                image(x, y, 1) = temp(x, newY, 1);
                image(x, y, 2) = temp(x, newY, 2);

            }
        }
    }
}

// Filter 6: Rotate Image
void applyRotate_6(Image& image, int degree){

    if (degree ==90){
       Image anotherImageWithReversedSize(image.height, image.width);

        for (int i = 0; i <anotherImageWithReversedSize.width; ++i) {
            for (int j =0; j < anotherImageWithReversedSize.height; ++j) {

                for (int k = 0; k < 3; ++k) {

                anotherImageWithReversedSize(i, j, k)
                    = image(j, anotherImageWithReversedSize.width- 1 - i, k);
                 }
             }
         } 
         image=anotherImageWithReversedSize;
    }
    else if(degree==180){
        Image originalImage =image;
        for (int i = 0; i < image.width; ++i) {
             for (int j = 0; j < image.height; ++j) {
                 int newi=image.width-1-i;
                 int newj=image.height-1-j;
                    for (int k = 0; k < 3; ++k) {
            
                
                        image(i, j, k) = originalImage(newi, newj, k);
                    }
                }
        }

    
    }

    else if(degree==270){
        Image anotherImageWithReversedSize2(image.height, image.width);

        for (int i = 0; i < anotherImageWithReversedSize2.width; ++i) {
            for (int j = 0; j < anotherImageWithReversedSize2.height; ++j) {

                for (int k = 0; k < 3; ++k) {

                anotherImageWithReversedSize2(i, j, k)
                    = image(image.width - 1 - j, i, k);
                }
            }
        }
        image=anotherImageWithReversedSize2;
        }
       

}

// Filter 7: Darken and Lighten Image
void applyBrightness_7(Image& image, double factor) {
    factor/= 100.0;
    for (int x = 0; x < image.width; x++){
        for (int y = 0; y < image.height; y++) {

            int  r,g,b;
            r = image.getPixel(x,y,0)*(1+factor);
            g = image.getPixel(x,y,1)*(1+factor);
            b = image.getPixel(x,y,2)*(1+factor);
            
            image.setPixel(x,y,0, (r >= 0) ? ((r <= 255) ? r: 255): 0);
            image.setPixel(x,y,1, (g >= 0) ? ((g <= 255) ? g: 255): 0);
            image.setPixel(x,y,2, (b >= 0) ? ((b <= 255) ? b: 255): 0);
        }
    }
}

// Filter 8: Resizing Images
void applyResize_8(Image& image, int newWidth, int newHeight) 
{
    int TheOriginal_PIC_heihgt = image.height;
    int TheOriginal_PIC_width =image.width;

    Image The_newIMAGE_for_Wth_Hit(newWidth , newHeight);

    double Axis_X , Axis_Y;
     Axis_X = (double)TheOriginal_PIC_width /  newWidth;
     Axis_Y = (double)TheOriginal_PIC_heihgt / newHeight; 

    
    for(int y = 0; y < newHeight ; ++y)
    {
        for(int x =0 ; x< newWidth ; ++ x)
        {
            int Area_X , Area_Y ;

            Area_Y = y * Axis_Y ; 
            Area_X = x * Axis_X;

            int The_channel; 
            for(The_channel = 0 ; The_channel < 3; ++The_channel)
            {
                The_newIMAGE_for_Wth_Hit.setPixel(x , y , The_channel , image.getPixel(Area_X , Area_Y , The_channel));
            }
        }
    }
            image = The_newIMAGE_for_Wth_Hit;





}



void showAppName () {
    std::cout << "\n ***===================================***" << '\n';
    std::cout << "             Baby Photoshop        " << '\n';
    std::cout << " ***===================================***" << '\n'<<'\n';
}

void showMenu () {
    std::cout << "\n1.Grayscale Conversion \n" ;
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
        std::cout << "\nImage loaded successfully! \n";
        return true ;
    } catch (...) {
        std::cout <<"\nERROR! please check the file path.\n";
        return false;
    }
}

void saveImage (Image& image) {
    std::cout << " Enter the target path/filename (e.g., output.png, result.jpg, myImage.bmp)\n";
    std::string filename ;
    std::cin >> filename;
    // try to save ; if it failed will appear an error massage for the
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
    Image currentImage;
    bool running = true;

    showAppName();
    
    // load the image before starting the main loop
    while (!loadNewImage(currentImage)){
        std::cout << "try again.\n";
    }

    // main loop 
    while (running) {
        // Clear screen at the beginning of each loop iteration
        system("cls");
        showAppName();
        showMenu();

        // get user choice 
        char choice; 
        std::cin >> choice;
        choice = tolower(choice); 

        switch (choice) {
            case '1':
                applyGrayscale_1(currentImage);
                std::cout << "\nFilter applied successfully!\n";
                break;
            
            case '2':
                applyBlackAndWhite_2(currentImage);
                std::cout << "\nFilter applied successfully!\n";
                break;
            
            case '3':
                applyInvert_3(currentImage);
                std::cout << "\nFilter applied successfully!\n";
                break;
            
            case '4': {
                std::cout << "\nChoose frame style :\n1.simple\n2.fancy\n";
                int frameStyle; 
                // Validation: ensure input is a valid number and strictly 1 or 2
                while (!(std::cin >> frameStyle) || (frameStyle != 1 && frameStyle != 2)) {
                    std::cout << "Invalid input. Enter 1 or 2: ";
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }

                unsigned char r, g, b; 
                getRGBFromUser(r, g, b);

                applyFrame_4(currentImage, frameStyle, r, g, b);
                std::cout << "\nFrame added successfully!\n";
                break;
            }
            
            case '5': {
                std::cout << "\nChoose an option:\n1.horizontal\n2.vertical\n";
                int subChoice;
                // Validation: ensure input is a valid number and strictly 1 or 2
                while (!(std::cin >> subChoice) || (subChoice != 1 && subChoice != 2)) {
                    std::cout << "Invalid input. Enter 1 or 2: ";
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                
                if (subChoice == 2) {
                    applyFlip_5(currentImage, false);
                } else {
                    applyFlip_5(currentImage);
                }
                std::cout << "\nFlip applied successfully!\n";
                break;
            }
            
            case '6': {
                std::cout << "Enter a degree of rotation (e.g. 180, 90):\n";
                int degree;
                // Validation: ensure input is a valid integer
                while (!(std::cin >> degree)) {
                    std::cout << "Invalid input. Enter a valid number for degree: ";
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }

                applyRotate_6(currentImage, degree % 360);
                std::cout << "\nFilter applied successfully!\n";
                break;
            }
            
            case '7': {
                int mode;
                double factor;

                std::cout << "Select Lightness Mode:\n1. Lighten Image\n2. Darken Image\n";
                // Validation: ensure mode is 1 or 2
                while (!(std::cin >> mode) || (mode != 1 && mode != 2)) {
                    std::cout << "Invalid input. Enter 1 or 2: ";
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }

                std::cout << "Enter percentage (1 - 100%):\n";
                // Validation: ensure factor is a valid positive number
                while (!(std::cin >> factor) || factor <= 0) {
                    std::cout << "Invalid input. Enter a valid positive percentage: ";
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                
                applyBrightness_7(currentImage, (mode == 1) ? factor : -factor);
                std::cout << "\nFilter added successfully!\n";
                break;
            }
            
            case '8': {
                int newWidth, newHeight;
                
                std::cout << "Enter new width:\n";
                // Validation: ensure width is a positive integer
                while (!(std::cin >> newWidth) || newWidth <= 0) {
                    std::cout << "Invalid input. Enter a valid positive width: ";
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }

                std::cout << "Enter new height:\n";
                // Validation: ensure height is a positive integer
                while (!(std::cin >> newHeight) || newHeight <= 0) {
                    std::cout << "Invalid input. Enter a valid positive height: ";
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }

                applyResize_8(currentImage, newWidth, newHeight);
                std::cout << "\nResizing applied successfully!\n";
                break;
            }
            
            case 's':
                saveImage(currentImage);
                std::cout << "\nImage saved successfully!\n";
                break;
            
            case 'l': {
                char confirm;
                std::cout << "Do you want to save before loading a new image? (Y/N)\n";
                std::cin >> confirm;
                if (tolower(confirm) == 'y') {
                    saveImage(currentImage);
                }         
                while (!loadNewImage(currentImage)) {
                    std::cout << "try again.\n";
                }
                break; 
            }
            
            case 'e': {
                char confirm; 
                std::cout << "Do you want to save before exiting? (Y/N)\n";
                std::cin >> confirm;

                if (tolower(confirm) == 'y') {
                    saveImage(currentImage);
                }
                running = false;
                break;
            }
            
            default:
                std::cout << "\nInvalid choice. Try again!\n";
                break;
        }

        // Pause to let the user read the success message before clearing the screen for the next loop
        if (running) {
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore();
            std::cin.get();
        }
    }

    return 0;
}


