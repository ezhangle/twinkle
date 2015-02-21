#include "FontManager.h"
#include <assert.h>
#include <stdio.h>

long int fsize(FILE* _file)
{
	long int pos = ftell(_file);
	fseek(_file, 0L, SEEK_END);
	long int size = ftell(_file);
	fseek(_file, pos, SEEK_SET);
	return size;
}

TwinkleFontManager& TwinkleFontManager::GetInstance()
{
	static TwinkleFontManager instance; // Guaranteed to be destroyed.
	return instance;
};

TwinkleFontManager::TwinkleFontManager()
{
	m_bgfxFontManager = new FontManager(512);
	m_textBufferManager = new TextBufferManager(m_bgfxFontManager);
}

FontHandle TwinkleFontManager::GetFont(const char* filename, int size)
{
	stl::string filenameSdf(filename);
	filenameSdf.append("_sdf");

	FontHashMap::iterator iter = m_fontHandles.find(filenameSdf);
	FontHandle fontSdf;
	if (iter == m_fontHandles.end())
	{
		fontSdf = LoadSdfFont(filenameSdf, stl::string(filename));
	}
	else
	{
		fontSdf = iter->second;
	}

	return m_bgfxFontManager->createScaledFontToPixelSize(fontSdf, size);
}

TextBufferManager* TwinkleFontManager::GetTextBufferManager()
{
	return m_textBufferManager;
}

FontHandle TwinkleFontManager::LoadSdfFont(stl::string key, stl::string filename)
{
	TrueTypeHandle fontFile = this->LoadTtf(filename);
	FontHandle fontSdf = m_bgfxFontManager->createFontByPixelSize(fontFile, 0, 64, FONT_TYPE_DISTANCE_SUBPIXEL);
	m_bgfxFontManager->preloadGlyph(fontSdf, L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ. \n");
	m_fontHandles[key] = fontSdf;

	return fontSdf;
}

FontHandle TwinkleFontManager::LoadScaledFont(FontHandle fontSdf, stl::string filenameSdfKey, int size)
{
	FontHandle fontScaled = m_bgfxFontManager->createScaledFontToPixelSize(fontSdf, size);
	m_fontHandles[filenameSdfKey] = fontScaled;

	return fontScaled;
}

TrueTypeHandle TwinkleFontManager::LoadTtf(stl::string filename)
{
	FILE* file = fopen(filename.c_str(), "rb");
	if (NULL != file)
	{
		uint32_t size = (uint32_t)fsize(file);
		uint8_t* mem = (uint8_t*)malloc(size + 1);
		size_t ignore = fread(mem, 1, size, file);
		BX_UNUSED(ignore);
		fclose(file);
		mem[size - 1] = '\0';
		TrueTypeHandle handle = m_bgfxFontManager->createTtf(mem, size);
		free(mem);
		return handle;
	}

	TrueTypeHandle invalid = BGFX_INVALID_HANDLE;
	return invalid;
}