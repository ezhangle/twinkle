#ifndef TWINKLE_APP_H_HEADER_GUARD
#define TWINKLE_APP_H_HEADER_GUARD

class App
{
public:
	App();
	~App();

	void Render();

private:
	void CalculateFrameTime();
};

#endif // TWINKLE_APP_H_HEADER_GUARD