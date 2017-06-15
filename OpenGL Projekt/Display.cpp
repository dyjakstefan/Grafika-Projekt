#include "Display.h"
#include <iostream>



Display::Display(int width, int height, const std::string& title)
{
	oldWitdth = width;
	oldHeight = height;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	m_glContext = SDL_GL_CreateContext(m_window);
	
	GLenum status = glewInit();

	if (status != GLEW_OK)
	{
		std::cout << "Glew failed to initialize!" << std::endl;
	}

	m_isClosed = false;

	glViewport(0, 0, width, height);

	glewExperimental = GL_TRUE;
	glewInit();
	glEnable(GL_FRAMEBUFFER_SRGB);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glDisable(GL_SCISSOR_TEST);
	glCullFace(GL_BACK);
}

Display::~Display()
{
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::Update()
{
	SDL_GL_SwapWindow(m_window);
}

bool Display::IsClosed()
{
	return m_isClosed;
}

void Display::Close()
{
	m_isClosed = true;
}

void Display::UpdateSize()
{
	SDL_GetWindowSize(m_window, &newWidth, &newHeight);

	if (oldWitdth != newWidth || oldHeight != newHeight)
	{
		oldWitdth = newWidth;
		oldHeight = newHeight;
		Options::GetInstance().SetScreenWidth(oldWitdth);
		Options::GetInstance().SetScreenHeight(oldHeight);
		glViewport(0, 0, oldWitdth, oldHeight);
	}
}

SDL_Window * Display::Window()
{
	return m_window;
}
