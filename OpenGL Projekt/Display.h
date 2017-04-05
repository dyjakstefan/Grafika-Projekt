#pragma once
#include <GL/glew.h>
#include <string>
#include <SDL.h>

class Display
{
public:
	Display(int width, int height, const std::string& title);
	~Display();
	
	void Clear(float r, float g, float b, float a);
	void Update();
	bool IsClosed();
	void Close();
	SDL_Window* Window();
private:
	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;
};

