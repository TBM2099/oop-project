#include "Image_Class.h"
#include "Filters.h"

void applyInvert_3(Image& image){
   

    for (int x = 0; x < image.width; x++){
        for (int y = 0; y < image.height; y++) {
            image.setPixel(x,y,0,255-image.getPixel(x,y,0));
            image.setPixel(x,y,1,255-image.getPixel(x,y,1));
            image.setPixel(x,y,2,255-image.getPixel(x,y,2));
        }
    }
}

void applyBrightness_7(Image& image, double factor) {
    // write your code here
}
