#ifndef FILTERS_H
#define FILTERS_H

#include "Image_Class.h"

// =================================================================
// Prototypes for Filters  
// ==================================================================

// Filter 1: Grayscale Conversion
void applyGrayscale_1(Image& image);

// Filter 2: Black and White
void applyBlackAndWhite_2(Image& image);//

// Filter 3: Invert Image
void applyInvert_3(Image& image);

// Filter 4: Adding a Frame to the Picture
void applyFrame_4(Image& image, int frameType,
     unsigned char r, unsigned char g, unsigned char b) ; // frame style : 1. simple , 2.fancy

// Filter 5: Flip Image
void applyFlip_5(Image& image, bool horizontal = true);

// Filter 6: Rotate Image
void applyRotate_6(Image& image, int degree);

// Filter 7: Darken and Lighten Image
void applyBrightness_7(Image& image, double factor);

// Filter 8: Resizing Images
void applyResize_8(Image& image, int newWidth , int newHeight);

// Filter 9: Merging two images
/*
Merge Type: 
1.resize the smaller image or both images to the biggest height and the biggest width 
2.merge the common area of the smaller width and the smaller height
*/
void applyMerge_9 (Image& image_1,Image& image_2, bool resize);

// Filter 10: Detecting Edges 

void applyDetectImageEdges_10 (Image& image);

//Filter 11: cropping Images
//(x,y) is the up left corner 
void applyCrop_11 (Image& image, int x, int y, int width, int height); 

// Filter 12: blurring Image 
void applyBlur_12 (Image& image, float factor); // "factor" allows different levels of blurring

// Filter 13: Wano Sunlight 

void applySunlight_13 (Image& image) ;

// Filter 14: TV effect
void applyOldTvscreen_14 (Image& image);

// Filter 15: Purple look 
void applyPurple_15(Image& image) ;

// Filter 16: Infrared Photography 
void applyInfrared_16(Image& image);

// Filter 17: Skewing image
void applySkewing_17 (Image& image, int degree );

// Filter 18: Oil Painting 
void applyOilPainting (Image& image) ;
#endif // FILTERS_H