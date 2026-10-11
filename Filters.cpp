#include "Filters.h"
#include <algorithm>

// Filter 1: Grayscale Conversion
void applyGrayscale_1(Image& imagez)
{
    for (int x = 0; x < imagez.width; x++ )
    {
        for (int y = 0; y < imagez.height; y++)
        {
            unsigned char red = imagez(x, y, 0);
            unsigned char green = imagez(x, y, 1);
            unsigned char blue = imagez(x, y, 2);

            unsigned char avg = (int(red) + green + blue) / 3;

            imagez(x, y, 0) = avg;
            imagez(x, y, 1) = avg;
            imagez(x, y, 2) = avg;
        }
    }
}


// Filter 2: Black and White
void applyBlackAndWhite_2(Image& image)
{
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
void applyInvert_3(Image& image)
{
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

            int TotalFrame = OuterThick + StripeThick + InnerThick ;

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
                            image.setPixel(x, y, 0, 255);
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
                        image.setPixel(x, y, 0, 255);
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
    Image temp = image;

    for (int x = 0; x < image.width; x++)
    {
        for (int y = 0; y < image.height; y++)
        {
            if (horizontal)
            {
                int newX = image.width - 1 - x;

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


// Filter 9: Merging two images
/*
Merge Type: 
1.resize the smaller image or both images to the biggest height and the biggest width 
2.merge the common area of the smaller width and the smaller height
*/
 void applyMerge_9(Image& image1, Image& image2, bool resize){

     

    if (image1.width != image2.width || image1.height != image2.height)
    {
        
        

        if (resize)
        {
             applyResize_8(image2, image1.width, image1.height);

        }
               
    }
    // take commom area 
    int targetWidth = (resize) ? image1.width : std::min(image1.width ,image2.width);
    int targeHeight = (resize) ? image1.height : std::min(image1.height ,image2.height);

        
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
    if ( !resize ) {
    applyCrop_11(image1 , 0,0,targetWidth,targeHeight);
    };
};


// Filter 10: Detecting Edges 
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


//Filter 11: cropping Images
//(x,y) is the up left corner 
void applyCrop_11 (Image& image, int x, int y, int width, int height){
    // all inputs should be positive
    if (x < 0 || y < 0 || width <= 0 || height <= 0) return ;
    if (width > image.width - x || height > image.height - y) return;
 
    // Image object that will hold the cropped part
    Image cropped_Image (width, height ); 

    for (int newX = 0 ; newX < width; newX++) {
        for (int newY = 0; newY < height; newY++) {
            for (int c = 0; c < 3; c++) {
                cropped_Image(newX, newY , c) = image( x + newX, y + newY, c);
            }
        } 
    }
    image = cropped_Image;

}; 


// Filter 12: blurring Image 
void applyBlur_12(Image& image, float factor) {

    Image TheOriginal_image  = image;

    int TheRadius = factor / 5 ; 
    if(TheRadius  < 1 ){
        TheRadius = 1 ;
    }

    for(int Y_Height12 =0 ; Y_Height12 <image.height ; ++Y_Height12){
        for(int X_Width12=0 ; X_Width12  < image.width ; ++X_Width12 ){ 
            for (int channal =0 ; channal < 3 ; ++channal){

                int Total_NreabyPixels = 0 , How_ManyPixelsWe_H = 0  ;


                for(int Delta_Y = -TheRadius ; Delta_Y <= TheRadius ; ++Delta_Y){
                    for(int Delta_X =-  TheRadius ; Delta_X <= TheRadius ; ++Delta_X ){

                        int neighbours_Y = Y_Height12 + Delta_Y ; 
                        int neighbours_X = X_Width12 + Delta_X ; 

                        if (neighbours_Y >= 0 && neighbours_Y < image.height && neighbours_X >= 0 && neighbours_X < image.width ){

                            Total_NreabyPixels += TheOriginal_image.getPixel(neighbours_X, neighbours_Y , channal );

                            How_ManyPixelsWe_H = How_ManyPixelsWe_H + 1 ; 
                        }
                    }
                }




                int ave = Total_NreabyPixels / How_ManyPixelsWe_H;

                image.setPixel(X_Width12 , Y_Height12 , channal  , ave);

            }

        }
    }
}


// Filter 13: Wano Sunlight 
void applySunlight_13(Image& wano)
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


// Filter 14: TV effect
void applyOldTvscreen_14 (Image& image){
    
    for(int i = 0; i < image.width ;++i){
        for(int j = 0; j < image.height ;++j){
            if(j %2 == 0){
                for(int k = 0; k < 3; ++k){
                    if(image(i,j,k) >= 40)
                        image(i,j,k) -= 40;
                    else
                        image(i,j,k) = 0;
                
                    
                }
                
            }   
            
        }
    }

}


// Filter 15: Purple look 
void applyPurple_15(Image& image) {
  
    for (int x = 0; x < image.width; x++){
        for (int y = 0; y < image.height; y++) {
            int newR = image.getPixel(x,y,0)   ;
            int newG = static_cast <unsigned char>(image.getPixel(x,y,1)*0.74) ;  
            int newB = image.getPixel(x,y,2) ;
            image.setPixel(x,y,0,newR);
            image.setPixel(x,y,1,newG);
            image.setPixel(x,y,2,newB);
        }
    }
}


// Filter 16: Infrared Photography 
void applyInfrared_16(Image& Image){
    for (int Y_Height16 =0 ; Y_Height16< Image.height ; ++Y_Height16 ){ 
        for(int X_Windth16  =0 ; X_Windth16 < Image.width ; ++ X_Windth16){

            unsigned char RedColor = Image.getPixel(X_Windth16 , Y_Height16 , 0);
            unsigned char GreenColor = Image.getPixel(X_Windth16 , Y_Height16 , 1);          
            unsigned char BuleColor = Image.getPixel(X_Windth16 , Y_Height16 , 2);

            unsigned char NewColor_ofRed =255; 
            unsigned char ReverseGreen  = 255 - GreenColor ; 
            unsigned char ReverseBlue = 255 - BuleColor ; 

            Image.setPixel(X_Windth16 , Y_Height16 , 0 , NewColor_ofRed );
            Image.setPixel(X_Windth16 , Y_Height16 , 1 , ReverseGreen ); 
            Image.setPixel(X_Windth16 , Y_Height16 , 2 , ReverseBlue );
        }
    }
}


// Filter 17: Skewing Image
void applySkewing_17(Image& image, int angle) {
    int w = image.width;
    int h = image.height;

    const double PI = 3.14159265358979;
    double t = std::tan(angle * PI / 180.0);

    int totalShift = (int)std::round(std::fabs(w * t));
    int newH = h + totalShift;

    Image result(w, newH);
    for (int x = 0; x < w; x++)
        for (int y = 0; y < newH; y++)
            for (int c = 0; c < 3; c++)
                result.setPixel(x, y, c, 255);

    for (int x = 0; x < w; x++) {
        int shift = (int)std::round(x * t);
        if (t < 0)
            shift += totalShift;

        for (int y = 0; y < newH; y++) {
            int srcY = y - shift;
            if (srcY >= 0 && srcY < h) {
                for (int c = 0; c < 3; c++)
                    result.setPixel(x, y, c, image.getPixel(x, srcY, c));
            }
        }
    }

    image = result;
}


// Filter 18: Oil Painting
void applyOilPainting_18(Image& image){

    Image therealpict = image ;
    int TheRadius_18 = 4 ;
    int Lightinglevels = 10 ;  

    for (int Y_Height_18 =0 ; Y_Height_18 < image.height ; ++Y_Height_18){
        for(int X_Width_18 = 0 ; X_Width_18 < image.width ; ++X_Width_18 ){

           int  num_pixsl[10] = {0} ; 
           int sumRedColor [10] = {0} , sumGreenColor[10] = {0} , sumBlueColor[10] = {0};

           for (int Neighbour_Y_18 = - TheRadius_18 ; Neighbour_Y_18 <= TheRadius_18 ; ++Neighbour_Y_18 ){
            for (int Neighbour_X_18 = - TheRadius_18 ; Neighbour_X_18 <= TheRadius_18 ; ++Neighbour_X_18){


                int clamp_Of_X = std::clamp(X_Width_18 + Neighbour_X_18, 0, image.width - 1);
                int clamp_Of_Y = std::clamp(Y_Height_18 + Neighbour_Y_18, 0 , image.height -1);

                int RedColor_18 = therealpict.getPixel(clamp_Of_X , clamp_Of_Y , 0 ); 
                int GreenColor_18 = therealpict.getPixel(clamp_Of_X , clamp_Of_Y , 1);
                int BlueColor_18 = therealpict.getPixel(clamp_Of_X , clamp_Of_Y , 2);

                int Total_18 =( ((RedColor_18 + GreenColor_18 + BlueColor_18 )/3) * Lightinglevels / 256);
                
                num_pixsl    [Total_18]++;
                sumRedColor  [Total_18] += RedColor_18 ; 
                sumGreenColor[Total_18]  += GreenColor_18;
                sumBlueColor [Total_18 ]+= BlueColor_18; 
                


            }
            
           }


           int max_18 = 0 ;
           for (int i =1 ; i < Lightinglevels ; ++i){
            if(num_pixsl[i]>num_pixsl[max_18 ]){
                max_18 = i;
            }
           }


           image.setPixel(X_Width_18 , Y_Height_18 , 0 , sumRedColor[max_18]    / num_pixsl[max_18]);
           image.setPixel(X_Width_18 , Y_Height_18 , 1 , sumGreenColor[max_18] / num_pixsl[max_18]);
           image.setPixel(X_Width_18 , Y_Height_18 , 2 , sumBlueColor[max_18] / num_pixsl[max_18]);





        }
    }

}

