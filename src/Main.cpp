#include <stdio.h>
#include <wchar.h>
#include <stdexcept>
#include <bgfx/bgfx.h>
#include <bx/timer.h>
#include <bx/string.h>
#include <bx/fpumath.h>
#include <bgfx-common/font/text_buffer_manager.h>
#include <bgfx-common/entry/input.h>
#include <duktape/duktape.h>

#include "App.h"
#include "Surface.h"
#include "FontManager.h"

float RED[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
float GREEN[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
float BLUE[4] = { 0.0f, 0.0f, 1.0f, .2f };
float CYAN[4] = { 0.0f, 1.0f, 1.0f, 1.0f };
float YELLOW[4] = { 1.0f, 1.0f, 0.0f, 1.0f };
float WHITE[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
float MAGENTA[4] = { 1.0f, 0.0f, 1.0f, .2f };
float TEAL[4] = { 0.0f, 0.6f, 0.6f, 1.0f };

Surface* ParseSurfaceTree(duk_context *ctx, Surface* parent) {
	Surface* s = new Surface(50, 50, BLUE);
	css_style_t* style = &s->GetCss()->style;

	if (parent != NULL) {
		parent->AddChild(s);
	}

	if (duk_get_prop_string(ctx, -1, "backgroundColor")) {
		int len = (unsigned long)duk_get_length(ctx, -1);
		if (len != 4) {
			throw std::runtime_error("backgroundColor must contain exactly 4 elements (red/green/blue/alpha)");
		}
		
		float rgba[4];
		duk_get_prop_index(ctx, -1, 0); rgba[0] = (float)duk_get_number(ctx, -1); duk_pop(ctx);
		duk_get_prop_index(ctx, -1, 1); rgba[1] = (float)duk_get_number(ctx, -1); duk_pop(ctx);
		duk_get_prop_index(ctx, -1, 2); rgba[2] = (float)duk_get_number(ctx, -1); duk_pop(ctx);
		duk_get_prop_index(ctx, -1, 3); rgba[3] = (float)duk_get_number(ctx, -1); duk_pop(ctx);
		//printf("RGBA: %.02f %.02f %.02f %.02f\n", rgba[0], rgba[1], rgba[2], rgba[3]);

		s->SetColor(rgba);
	}
	duk_pop(ctx);

	if (duk_get_prop_string(ctx, -1, "width")) {
		float width = (float)duk_get_number(ctx, -1);
		style->dimensions[CSS_WIDTH] = width;
		//printf("width: %.02f\n", width);
	}
	duk_pop(ctx);

	if (duk_get_prop_string(ctx, -1, "height")) {
		float height = (float)duk_get_number(ctx, -1);
		style->dimensions[CSS_HEIGHT] = height;
		//printf("height: %.02f\n", height);
	}
	duk_pop(ctx);

	if (duk_get_prop_string(ctx, -1, "padding")) {
		int len = (unsigned long)duk_get_length(ctx, -1);
		if (len != 4) {
			throw std::runtime_error("padding must contain exactly 4 elements (top/right/bottom/left)");
		}

		float padding[4];
		duk_get_prop_index(ctx, -1, 0); padding[0] = (float)duk_get_number(ctx, -1); duk_pop(ctx);
		duk_get_prop_index(ctx, -1, 1); padding[1] = (float)duk_get_number(ctx, -1); duk_pop(ctx);
		duk_get_prop_index(ctx, -1, 2); padding[2] = (float)duk_get_number(ctx, -1); duk_pop(ctx);
		duk_get_prop_index(ctx, -1, 3); padding[3] = (float)duk_get_number(ctx, -1); duk_pop(ctx);

		style->padding[CSS_TOP] = padding[0];
		style->padding[CSS_RIGHT] = padding[1];
		style->padding[CSS_BOTTOM] = padding[2];
		style->padding[CSS_LEFT] = padding[3];

		//printf("padding: %.02f %.02f %.02f %.02f\n", padding[0], padding[1], padding[2], padding[3]);
	}
	duk_pop(ctx);

	if (duk_get_prop_string(ctx, -1, "margin")) {
		int len = (unsigned long)duk_get_length(ctx, -1);
		if (len != 4) {
			throw std::runtime_error("margin must contain exactly 4 elements (top/right/bottom/left)");
		}

		float margin[4];
		duk_get_prop_index(ctx, -1, 0); margin[0] = (float)duk_get_number(ctx, -1); duk_pop(ctx);
		duk_get_prop_index(ctx, -1, 1); margin[1] = (float)duk_get_number(ctx, -1); duk_pop(ctx);
		duk_get_prop_index(ctx, -1, 2); margin[2] = (float)duk_get_number(ctx, -1); duk_pop(ctx);
		duk_get_prop_index(ctx, -1, 3); margin[3] = (float)duk_get_number(ctx, -1); duk_pop(ctx);

		style->margin[CSS_TOP] = margin[0];
		style->margin[CSS_RIGHT] = margin[1];
		style->margin[CSS_BOTTOM] = margin[2];
		style->margin[CSS_LEFT] = margin[3];

		//printf("margin: %.02f %.02f %.02f %.02f\n", margin[0], margin[1], margin[2], margin[3]);
	}
	duk_pop(ctx);

	if (duk_get_prop_string(ctx, -1, "flexWrap")) {
		const char *str = duk_get_string(ctx, -1);
		if (str && strcmp("wrap", str) == 0) {
			style->flex_wrap = CSS_WRAP;
			//printf("flexWrap: CSS_WRAP");
		} else if (str && strcmp("nowrap", str) == 0)	{
			style->flex_wrap = CSS_NOWRAP;
			//printf("flexWrap: CSS_NOWRAP\n");
		} else {
			throw std::runtime_error("Invalid flexWrap");
		}
	}
	duk_pop(ctx);

	if (duk_get_prop_string(ctx, -1, "flexDirection")) {
		const char *str = duk_get_string(ctx, -1);
		if (str && strcmp("row", str) == 0) {
			style->flex_direction = CSS_FLEX_DIRECTION_ROW;
			//printf("flexDirection: CSS_FLEX_DIRECTION_ROW\n");
		}
		else if (str && strcmp("col", str) == 0)	{
			style->flex_direction = CSS_FLEX_DIRECTION_COLUMN;
			//printf("flexDirection: CSS_FLEX_DIRECTION_COL\n");
		}
		else {
			throw std::runtime_error("Invalid flexDirection");
		}
	}
	duk_pop(ctx);

	if (duk_get_prop_string(ctx, -1, "background")) {
		const char *filename = duk_get_string(ctx, -1);
		s->SetTexture(filename);
	}
	duk_pop(ctx);

	if (duk_get_prop_string(ctx, -1, "text")) {
		int len = (unsigned long)duk_get_length(ctx, -1);
		if (len != 2) {
			throw std::runtime_error("text must contain exactly 2 elements (text/fontSize)");
		}

		duk_get_prop_index(ctx, -1, 0); const char *text = duk_get_string(ctx, -1); duk_pop(ctx);
		duk_get_prop_index(ctx, -1, 1); int fontSize = (int)duk_get_number(ctx, -1); duk_pop(ctx);
		s->SetText(stl::string(text), fontSize);
	}
	duk_pop(ctx);


	if (duk_get_prop_string(ctx, -1, "children")) {
		int len = (unsigned long)duk_get_length(ctx, -1);
		
		for (int i = 0; i < len; i++) {
			duk_get_prop_index(ctx, -1, i);
			ParseSurfaceTree(ctx, s);
			duk_pop(ctx);
		}
	}
	duk_pop(ctx);
	
	return s;
}

Surface* mainRootSurface = NULL;

static duk_ret_t CreateSurface(duk_context *ctx) {
	duk_pop(ctx);
	//duk_dump_context_stdout(ctx);
	
	mainRootSurface = ParseSurfaceTree(ctx, NULL);
	duk_push_true(ctx);
	return 1;
}

void InitDuktape()
{
	duk_context *ctx = NULL;

	ctx = duk_create_heap_default();
	if (!ctx) {
		printf("Failed to create a Duktape heap.\n");
		exit(1);
	}

	duk_push_global_object(ctx);
	duk_push_c_function(ctx, CreateSurface, 2);
	duk_put_prop_string(ctx, -2, "createSurface");


	if (duk_peval_file(ctx, "../example/basic.js") != 0) {
		printf("Error: %s\n", duk_safe_to_string(ctx, -1));
		duk_destroy_heap(ctx);
		exit(1);
		return;
	}
	duk_pop(ctx);
}

int _main_(int, char**)
{
	uint32_t width = 1280;
	uint32_t height = 720;
	uint32_t debug = BGFX_DEBUG_TEXT;
	uint32_t reset = BGFX_RESET_VSYNC;

	bgfx::init();
	bgfx::reset(width, height, reset);
	bgfx::setDebug(debug); // Enable debug text.

	App* app = new App();
	TwinkleFontManager* fm = new TwinkleFontManager();
	
	try {
		InitDuktape();
	}
	catch (const std::exception& ex) {
		printf("Error initializing JS app: %s", ex.what());
	}

	// Set view 0 clear state.
	bgfx::setViewClear(0
		, BGFX_CLEAR_COLOR_BIT | BGFX_CLEAR_DEPTH_BIT
		, 0x303030ff
		, 1.0f
		, 0
		);

	mainRootSurface->CalculateLayout();

	while (!entry::processEvents(width, height, debug, reset))
	{
		bgfx::dbgTextClear();
		//bgfx::dbgTextPrintf(0, 1, 0x4f, "Simple debug text");
		
		app->Render();
	
		float at[3] = { 0, 0, 0.0f };
		float eye[3] = { 0, 0, -1.0f };
		float view[16];
		float ortho[16];

		bx::mtxLookAt(view, eye, at);
		bx::mtxOrtho(ortho, 0.0f, (float)width, (float)height, 0.0f, -10.0f, 10.0f);
		bgfx::setViewTransform(0, view, ortho);
		bgfx::setViewRect(0, 0, 0, width, height);

		bgfx::submit(0);

		mainRootSurface->Render(false);

		// Advance to next frame. Rendering thread will be kicked to
		// process submitted rendering primitives.
		bgfx::frame();
	}

	bgfx::shutdown();

	return 0;
}