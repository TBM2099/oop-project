#include <iostream>
#include "Filters.h"
#include "Image_Class.h"
#include <string>
#include <algorithm>


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
                
                for (int c = 0; c < image.channels; c++)
                    {
                        image(x, y, c) = temp(newX, y, c);
                    }


                            
            }

            else
            {
                int newY = image.height -1 - y;

                for (int c = 0; c < image.channels; c++)
                    {
                        image(x, y, c) = temp(x, newY, c);
                    }
            }
        }
    }
}

void applyMerge_9(Image& image1, Image& image2)
{
    
    int choice = 1;

    if (image1.width != image2.width || image1.height != image2.height)
    {
        
        std::cout <<"\nThe imgages have different dimensions.\n";
        std::cout <<"1. Resixe the second image to match the first.\n";
        std::cout <<"2.Merge olnly the common (intersecting) area.\n";
        std::cout <<"Enter your choice (1 or 2): ";
        
        std::cin >> choice;

        if (choice == 1)
        {
             applyResize_8(image2, image1.width, image1.height);

        }
               
    }

    int targetWidth = (choice == 1) ? image1.width : std::min(image1.width ,image2.width);
    int targeHeight = (choice == 1) ? image1.height : std::min(image1.height ,image2.height);

        
    for (int x = 0; x < targetWidth; x++)
    {
        for (int y = 0; y < targeHeight; y++)
        {
            for (int c = 0; c < 3; c++)
            {

                int pixel1 = image1(x, y, c);
                int pixel2 = image2(x, y, c);

                image1(x, y, c) = (pixel1 + pixel2) / 2;



            }
        }
        
    }
}
 
void Wano_13(Image& wano)
{
    for (int x = 0; x < wano.width; x++)
    {
        for (int y = 0; y < wano.height; y++)
        {
            int red = wano(x, y, 0) * 1.15;
            int green = wano(x, y, 1) * 1.15;
            int blue = wano(x, y, 2) * 0.7;

            wano(x, y, 0) = std::min(red, 255);
            wano(x, y, 1) = std::min(green, 255);
            wano(x, y, 2) = blue;
        }
    }
}
























int main()
{
    Image coco, dodo;

    std::cout << "enter ur file name or path: ";
    std::string file_name;
    std::getline(std::cin, file_name);

    coco.loadNewImage(file_name);
    system(("start " + file_name).c_str());

    applyGrayscale_1( coco);

    std::cout << "\ngray filter applied is done.";
    std::cout << "\ntarger file name to save the imgae: ";

    std::string NewFileName;
    std::getline(std::cin, NewFileName);

    coco.saveImage(NewFileName);

    system(("start " + NewFileName).c_str());

    std::cout << "\n\nImage save successfuly";

    
}