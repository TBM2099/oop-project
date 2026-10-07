#include "Image_Class.h"
#include "Filters.h"
#include <algorithm>

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


void applyCrop_11 (Image& image, int x, int y, int width, int height){
    
    if ((x < 0)  || (x+width >= image.width) || (y < 0) || (y + height >= image.height)) 
        return ;

    Image croppedPart(width, height);

    for (int newX = 0; newX < width; newX++) {
        for (int newY = 0; newY < height; newY++) {
            for (int c = 0 ; c < 3 ; c++) {
                croppedPart(newX, newY,c) = image(x+newX, y+newY, c) ;
            }
        }
    }
    
    image = croppedPart;
}

void applyPurple_15(Image& image) {
    
    for (int x = 0; x < image.width; x++){
        for (int y = 0; y < image.height; y++) {
            int newG = static_cast <unsigned char>(image.getPixel(x,y,1)*0.73) ;  
            
            image.setPixel(x,y,0,image.getPixel(x,y,0));
            image.setPixel(x,y,1,newG);
            image.setPixel(x,y,2,image.getPixel(x,y,2));
        }
    }
}
 

