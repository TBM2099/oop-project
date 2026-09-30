#include <iostream>
#include "Filters.h"
#include "Image_Class.h"
#include <string>

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

void applyFlip_5(Image& image, bool horizontal = true)
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


