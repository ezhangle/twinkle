#ifndef TWINKLE_SURFACE_H_HEADER_GUARD
#define TWINKLE_SURFACE_H_HEADER_GUARD
#include <bgfx-common/common.h>
#include <bgfx-common/bgfx_utils.h>
#include "FontManager.h"

extern "C" {
	#include <css-layout/Layout.h>
}

#include <tinystl/allocator.h>
#include <tinystl/vector.h>
#include <tinystl/string.h>

namespace stl = tinystl;

struct PosVertex
{
	float m_x;
	float m_y;
	float m_z;
	int16_t m_u;
	int16_t m_v;

	static void init()
	{
		ms_decl
			.begin()
			.add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
			.add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Int16, true, true)
			.end();
	};

	static bgfx::VertexDecl ms_decl;
};

static PosVertex s_rectVertices[4] =
{
	{ 0.0f, 1.0f, 1.0f, 0, 0x7fff },
	{ 1.0f, 1.0f, 1.0f, 0x7fff, 0x7fff },
	{ 0.0f, 0.0f, 1.0f, 0, 0 },
	{ 1.0f, 0.0f, 1.0f, 0x7fff, 0 },
};

static const uint16_t s_rectIndices[6] =
{
	0, 1, 2,
	1, 3, 2,
};

class Surface
{
public:
	Surface(float width, float height, float color[4]);

	void Render(bool showDebug);
	void CalculateLayout();
	void AddChild(Surface* child);
	Surface* GetChild(int i);
	css_node_t* GetCss();
	bool IsLayoutDirty();
	void PrintLayout();
	void SetColor(float* color);
	void SetText(stl::string text, int fontSize);
	void Surface::SetTexture(const char* filename);

private:
	bool m_showDebug;
	bool m_isLayoutDirty;
	bgfx::VertexBufferHandle m_vbh;
	bgfx::IndexBufferHandle m_ibh;
	bgfx::UniformHandle m_u_color;
	bgfx::UniformHandle m_u_tex;
	bgfx::ProgramHandle m_program;
	stl::vector<Surface*> m_children;
	bgfx::TextureHandle m_texture;
	stl::string m_text;
	int m_fontSize;
	TextBufferHandle m_textBufferHandle;
	FontHandle m_fontHandle;
	float m_color[4];
	css_node_t* m_cssNode;
};

#endif // TWINKLE_SURFACE_H_HEADER_GUARD