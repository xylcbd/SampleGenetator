#ifndef __SAMPLE_GENETATOR_H__
#define __SAMPLE_GENETATOR_H__

#include <opencv2/opencv.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H

class SampleGenetator 
{
public:
	SampleGenetator(const char* fontPath,const int textHeight);
    ~SampleGenetator();
	cv::Mat SampleGenetator::genSample(const wchar_t wc);
private:
    FT_Library library;
    FT_Face face;
};

#endif //__SAMPLE_GENETATOR_H__

