#include "Filters.h"
#include "Image_class.h"

using namespace std;

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
       

};
void applyDetectImageEdges_10(Image& image){
    
    for(int i = 0;i <image.width - 1;++i){

        for(int j = 0; j<image.height;++j){

            int avr1 = 0;
            int avr2 = 0;

            for (int k = 0; k < 3;++k){
                avr1 +=image(i,j,k);
            }

            for (int k = 0; k < 3;++k){
                avr2 +=image(i + 1, j,k);

            }

            avr1 /= 3;
            avr2 /=3;

            if(avr1 > avr2+7 || avr1 < avr2-7){

                for(int k = 0; k < 3;++k){
                 image(i,j,k) = 0;
                }

            }else{

                for(int k =0; k <3; ++k){
                 image(i,j,k)= 255;

                 }
            }
        }
    }

       
}
