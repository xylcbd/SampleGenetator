#include "SampleGenetator.h"

SampleGenetator::SampleGenetator(const char* fontPath, const int textHeight)
{
	if (FT_Init_FreeType(&library)) 
	{
		assert(false);
		exit(-1);
	}
	if (FT_New_Face(library, fontPath, 0, &face))
	{
		assert(false);
		exit(-1);
	}
	FT_Set_Pixel_Sizes(face, textHeight, 0);
}

SampleGenetator::~SampleGenetator() 
{
    FT_Done_Face(face);
    FT_Done_FreeType(library);
}
cv::Mat SampleGenetator::genSample(const wchar_t wc) 
{
	cv::Mat result;

    FT_UInt glyph_index = FT_Get_Char_Index(face, wc);
    FT_Load_Glyph(face, glyph_index, FT_LOAD_DEFAULT);
	FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);
    FT_GlyphSlot slot = face->glyph;

    int rows = slot->bitmap.rows;
    int cols = slot->bitmap.width;

	result = cv::Mat(rows, cols, CV_8UC1);
	const uchar foreColor = 0;
	const uchar bgColor = 255;
	result.setTo(bgColor);

    for (int row = 0; row < rows; ++row) 
	{
        for (int col = 0; col < cols; ++col) 
		{
            const int offset = row  * slot->bitmap.pitch + col;
            if (slot->bitmap.buffer[offset]) 
			{
				result.at<uchar>(row, col) = foreColor;
            }
        }
    }
	return result;
}