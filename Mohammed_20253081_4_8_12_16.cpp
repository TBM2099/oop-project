#include "Filter.h"
#include "Image_class.h"

     // Filter 4: Adding a Frame to the Picture
void applyFrame_4(Image& image, int frameType,
     unsigned char r, unsigned char g, unsigned char b) {

    int imgWidth  = image.width;
    int imgHeight = image.height;

    // We determine the frame thickness based on the type chosen by the user
    double percentage;
    switch (frameType) {
        case 1:
            percentage = 0.02; // 2% From the smallest dimension, in picture
            break;
        case 2:
            percentage = 0.05; // 5%
            break;
        case 3:
            percentage = 0.10; // 10%
            break;
        default:
            percentage = 0.03; 
            break;
    }

    int minDimension = (imgWidth < imgHeight) ? imgWidth : imgHeight;
    int thickness = (int)(minDimension * percentage);

    if (thickness < 1) {
        thickness = 1; // The thinnest possible 
    }

    // It goes through every pixel in the image 
    for (int y = 0; y < imgHeight; y++) {
        for (int x = 0; x < imgWidth; x++) {

            // If the pixel is within the frame area (above / below / to the right / to the left)
            bool isInFrame = (x < thickness) || (x >= imgWidth - thickness) ||
                             (y < thickness) || (y >= imgHeight - thickness);

            if (isInFrame) {
                image.setPixel(x, y, 0, r); // Red
                image.setPixel(x, y, 1, g); // Green
                image.setPixel(x, y, 2, b); // Blue
            }
        }
    }
}


int main() {
    Image myImage("");
    applyFrame_4(myImage, 1, 100, 100, 100);
    myImage.saveImage("");
    return 0;
}