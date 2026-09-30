#ifndef FILTERS_H
#define FILTERS_H

#include "Image_Class.h"

// =================================================================
// Prototypes for Filters 
// =================================================================

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

#endif // FILTERS_H