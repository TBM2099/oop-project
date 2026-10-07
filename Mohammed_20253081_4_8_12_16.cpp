#include "Filter.h"
#include "Image_class.h"


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

        //fancy frame
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
                            image.setPixel(x, y, 0, 255); // white color for stars
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
