#include "Filters.h"
#include "Image_class.h"

using namespace std;

void applyBlackAndWhite_2(Image& image){
    // I`ll do it latter
};


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
     image.saveImage("rotatedImage.jpg");   

};
