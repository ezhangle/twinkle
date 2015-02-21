
#include "Surface.h"
#include <assert.h>

bgfx::VertexDecl PosVertex::ms_decl;

static css_node_t* GetLayoutChild(void *context, int i)
{
	Surface* s = static_cast<Surface*>(context);
	return s->GetChild(i)->GetCss();
}

static bool _IsLayoutDirty(void *context)
{
	Surface* s = static_cast<Surface*>(context);
	return s->IsLayoutDirty();
}

Surface::Surface(float width, float height, float color[4])
{
	m_isLayoutDirty = true;
	
	m_cssNode = new_css_node();
	init_css_node(m_cssNode);
	m_cssNode->context = this;
	m_cssNode->get_child = GetLayoutChild;
	m_cssNode->is_dirty = _IsLayoutDirty;

	m_textBufferHandle = { bgfx::invalidHandle };
	m_texture = { bgfx::invalidHandle };
	m_u_tex = bgfx::createUniform("u_texColor", bgfx::UniformType::Uniform1iv);
	m_isLayoutDirty = true;
	
	PosVertex::init();

	m_color[0] = color[0];
	m_color[1] = color[1];
	m_color[2] = color[2];
	m_color[3] = color[3];

	// Create static vertex and index buffer.
	// Static data can be passed with bgfx::makeRef
	m_vbh = bgfx::createVertexBuffer(bgfx::makeRef(s_rectVertices, sizeof(s_rectVertices)), PosVertex::ms_decl);
	m_ibh = bgfx::createIndexBuffer(bgfx::makeRef(s_rectIndices, sizeof(s_rectIndices)));
	m_u_color = bgfx::createUniform("u_color", bgfx::UniformType::Uniform4fv);
	
	// Create program from shaders.
	m_program = loadProgram("vs_surface_default", "fs_surface_default");

	m_showDebug = true;
}

void Surface::Render(bool showDebug)
{
	float mtx[16];
	bx::mtxIdentity(mtx);

	float x = m_cssNode->layout.position[CSS_LEFT];
	float y = m_cssNode->layout.position[CSS_TOP];
	float width = m_cssNode->layout.dimensions[CSS_WIDTH];
	float height = m_cssNode->layout.dimensions[CSS_HEIGHT];

	if (isValid(m_textBufferHandle))
	{
		TextBufferManager* tbm = TwinkleFontManager::GetInstance().GetTextBufferManager();
		tbm->clearTextBuffer(m_textBufferHandle);
		tbm->setPenPosition(m_textBufferHandle, x, y);
		tbm->appendText(m_textBufferHandle, m_fontHandle, m_text.c_str());
		tbm->submitTextBuffer(m_textBufferHandle, 0);
	}
	else
	{
		bx::mtxSRT(mtx, width, height, 1.0f, 0.0f, 0.0f, 0.0f, float(x), float(y), 0.0f);

		if (showDebug)
		{
			bgfx::dbgTextPrintf(0, 3, 0x0f, "X: %.2f Y: %.2f", x, y);
			bgfx::dbgTextPrintf(0, 4, 0x0f, "W: %.2f H: %.2f", width, height);
		}

		bgfx::setTransform(mtx); // Set model matrix for rendering.
		bgfx::setProgram(m_program); // Set vertex and fragment shaders.

		// Set vertex and index buffer.
		bgfx::setVertexBuffer(m_vbh);
		bgfx::setIndexBuffer(m_ibh);

		if (isValid(m_texture))
		{
			bgfx::setTexture(0, m_u_tex, m_texture);
		}

		bgfx::setUniform(m_u_color, m_color);

		bgfx::setState(BGFX_STATE_RGB_WRITE | BGFX_STATE_ALPHA_WRITE); // Set render states.
		bgfx::submit(0); // Submit primitive for rendering to view 0.
	}


	for (stl::vector<Surface*>::iterator it = m_children.begin(); it != m_children.end(); ++it)
	{
		(*it)->Render(false);
	}
}

void Surface::CalculateLayout()
{
	layoutNode(m_cssNode, CSS_UNDEFINED);
	m_isLayoutDirty = false;
}

bool Surface::IsLayoutDirty()
{
	return m_isLayoutDirty;
}

void Surface::PrintLayout()
{
	print_css_node(m_cssNode, CSS_PRINT_LAYOUT);
	for (stl::vector<Surface*>::iterator it = m_children.begin(); it != m_children.end(); ++it) {
		(*it)->PrintLayout();
	}
}

void Surface::SetColor(float* color)
{
	m_color[0] = color[0];
	m_color[1] = color[1];
	m_color[2] = color[2];
	m_color[3] = color[3];
}

void Surface::SetText(stl::string text, int fontSize)
{
	TextBufferManager* tbm = TwinkleFontManager::GetInstance().GetTextBufferManager();
	m_textBufferHandle = tbm->createTextBuffer(FONT_TYPE_DISTANCE_SUBPIXEL, BufferType::Transient);
	tbm->setTextColor(m_textBufferHandle, 0xFFFFFFFF);
	m_text = text;
	m_fontHandle = TwinkleFontManager::GetInstance().GetFont("../example/fonts/droidsans.ttf", fontSize);
}

void Surface::SetTexture(const char* filename)
{
	m_texture = loadTexture(filename);
}

void Surface::AddChild(Surface* child)
{
	m_cssNode->context = this;
	m_children.push_back(child);
	m_cssNode->children_count = m_children.size();
}

Surface* Surface::GetChild(int i)
{
	assert(i < (int)m_children.size());
	return m_children[i];
}

css_node_t* Surface::GetCss()
{
	return m_cssNode;
}
