#include "App.h"
#include <assert.h>
#include <bgfx/bgfx.h>
#include <bx/timer.h>
#include <bx/string.h>
#include <bx/fpumath.h>

App::App()
{
}

void App::Render()
{
	this->CalculateFrameTime();
}

void App::CalculateFrameTime()
{
	int64_t now = bx::getHPCounter();
	static int64_t last = now;
	const int64_t frameTime = now - last;
	last = now;
	const double freq = double(bx::getHPFrequency());
	const double toMs = 1000.0 / freq;
}