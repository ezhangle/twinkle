#ifndef TWINKLE_FONT_MANAGER_H_HEADER_GUARD
#define TWINKLE_FONT_MANAGER_H_HEADER_GUARD

#include <tinystl/allocator.h>
#include <tinystl/vector.h>
#include <tinystl/string.h>
#include <tinystl/unordered_map.h>
#include <bgfx-common/font/text_buffer_manager.h>

namespace stl = tinystl;
typedef stl::unordered_map<stl::string, FontHandle> FontHashMap;

class TwinkleFontManager
{
public:
	static TwinkleFontManager& GetInstance();

	TwinkleFontManager();

	FontHandle GetFont(const char* filename, int size);
	TextBufferManager* GetTextBufferManager();

private:
	FontHandle LoadSdfFont(stl::string key, stl::string filename);
	FontHandle LoadScaledFont(FontHandle fontSdf, stl::string filenameSdfKey, int size);
	TrueTypeHandle LoadTtf(stl::string filename);

	FontHashMap m_fontHandles;
	FontManager* m_bgfxFontManager;
	TextBufferManager* m_textBufferManager;
};

#endif // TWINKLE_FONT_MANAGER_H_HEADER_GUARD