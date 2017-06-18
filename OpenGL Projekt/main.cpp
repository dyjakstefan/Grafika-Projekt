#include <iostream>
#include "SDL_events.h"
#include "Display.h"
#include "Projection.h"
#include "Camera.h"
#include "Mouse.h"
#include "ObjectManager.h"
#include "Line.h"
#include "Options.h"
#include <AntTweakBar.h>
#include "TextureManager.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

int main(int argc, char** argv)
{
		
	std::string kolor, kolory[6] = {
		"Czerwony",
		"Czarny" ,
		"Zielony" ,
		"Bialy" ,
		"Zolty" ,
		"Cyjan"
	};
	Display display(Options::GetInstance().GetScreenWidth(), Options::GetInstance().GetScreenHeight(), "OpenGL Projekt");
	SDL_WarpMouseInWindow(display.Window(), WIDTH / 2, HEIGHT / 2);
	SDL_Event e;
	int handled = 0;
	Camera camera(glm::vec3(3.0f, 5.0f, 10.0f));
	Mouse mouse(Options::GetInstance().GetScreenWidth() / 2, Options::GetInstance().GetScreenHeight() / 2);
	ObjectManager objManager;
	int i = 0, j = 0, numCubes = 1;
	TwBar *myBar;
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;
	float counter = 0.0f;
	Projection projection(camera.m_zoom, 0.1f, 1000.0f);

	TwInit(TW_OPENGL, NULL);
	TwWindowSize(Options::GetInstance().GetScreenWidth(), Options::GetInstance().GetScreenHeight());
	
	myBar = TwNewBar("Menu drukarki");

	TwAddVarRW(myBar, "NumCubes", TW_TYPE_INT32, &numCubes,
		" label='Number of cubes' min=1 max=100 keyIncr=c keyDecr=v help='Defines the number of cubes in the scene.' ");
	TwAddVarRW(myBar, "kol1", TW_TYPE_INT8, &i, "label='Kolor filamentu' keyIncr=z");
	TwAddVarRW(myBar, "kol2", TW_TYPE_INT8, &j, "label='Kolor oswietlenia' keyIncr=x");

	//TwAddButton(myBar, "comment1", NULL, NULL, " label='Life is like a box a chocolates' ");
	std::queue<glm::vec3> route;
	route.push(glm::vec3(5, 0, 0));
	route.push(glm::vec3(0, 5, 0));
	//route.push(glm::vec3(1, 1, 0));
	route.push(glm::vec3(0, 0, 5));

	std::queue<glm::vec3> route2;
	int x = -1;
	route2.push(glm::vec3(0, 0, 5));

	for (int i = 0; i < 4; i++)
	{
		route2.push(glm::vec3(1, 0, 0));
		route2.push(glm::vec3(0, 0, x * 4));
		x *= -1;
	}
	for (int j = 0; j < 5; j++)
	{
		route2.push(glm::vec3(0, 3, 0));
		route2.push(glm::vec3(0, 0, -4));
		route2.push(glm::vec3(-4, 0, 0));
		route2.push(glm::vec3(0, 0, 4));
		route2.push(glm::vec3(4, 0, 0));
	}
	

	objManager.SetRoute(route2);

	while (!display.IsClosed())
	{
		GLfloat currentFrame = SDL_GetTicks();
		deltaTime = (currentFrame - lastFrame) * 0.001f;
		lastFrame = currentFrame;
		SDL_PumpEvents();

		if (SDL_PollEvent(&e))
		{
			int x, y;
			SDL_GetMouseState(&x, &y);
			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

			if (e.type == SDL_QUIT)
				display.Close();
			if(e.key.keysym.sym == 'c')
				TwKeyPressed('c', TW_KMOD_NONE);

			handled = TwEventSDL(&e, SDL_MAJOR_VERSION, SDL_MINOR_VERSION);

			//Menu
			if (!handled)
			{
				TwMouseMotion(x, y);
				switch (e.type)
				{
				case SDL_KEYDOWN:
					if (e.key.keysym.sym == 'z')
					{
						TwKeyPressed('z', TW_KMOD_NONE);
					}
					if (e.key.keysym.sym == 'x')
					{
						TwKeyPressed('x', TW_KMOD_NONE);
					}
					if (e.key.keysym.sym == 'c')
						TwKeyPressed('c', TW_KMOD_NONE);
					if (e.key.keysym.sym == 'v')
						TwKeyPressed('v', TW_KMOD_NONE);
					break;
				case SDL_MOUSEBUTTONDOWN:
					if(e.button.button == SDL_BUTTON_LEFT)
						TwMouseButton(TW_MOUSE_PRESSED, TW_MOUSE_LEFT);
					break;
				case SDL_MOUSEBUTTONUP:
					if(e.button.button == SDL_BUTTON_LEFT)
						TwMouseButton(TW_MOUSE_RELEASED, TW_MOUSE_LEFT);
					break;
				}
				
				
			}
			//Poruszanie g³owic¹ i sto³em

			objManager.Events(currentKeyStates, deltaTime);

			//Poruszanie kamer¹
			

			if (currentKeyStates[SDL_SCANCODE_UP])
			{
				camera.ProcessKeyboard(FORWARD, deltaTime);
			}
			if (currentKeyStates[SDL_SCANCODE_DOWN])
			{
				camera.ProcessKeyboard(BACKWARD, deltaTime);
			}
			if (currentKeyStates[SDL_SCANCODE_LEFT])
			{
				camera.ProcessKeyboard(LEFT, deltaTime);
			}
			if (currentKeyStates[SDL_SCANCODE_RIGHT])
			{
				camera.ProcessKeyboard(RIGHT, deltaTime);
			}

			if (e.type == SDL_MOUSEWHEEL)
			{
				camera.ProcessMouseScroll(e.wheel.y);
			}

			
			if (e.button.button == SDL_BUTTON_LEFT)
			{
				if (mouse.IsPositionChanged(x, y))
				{
					glm::vec2 offset = mouse.UpdatePosition(x, y);
					camera.ProcessMouseMovement(offset.x, offset.y);
				}
			}
			else
			{
				mouse.SetPosX(x);
				mouse.SetPosY(y);
			}

		}



		if (currentFrame > 2000)
		{
			//objManager.MoveByRoute(deltaTime);
			objManager.PrintCubes();
		}

		display.UpdateSize();
		display.Clear(0.85f, 0.98f, 0.98f, 1.0f);

		projection.SetFov(camera.m_zoom);

		objManager.Draw(camera, projection);
		TwRefreshBar(myBar);
		TwDraw();
		display.Update();
		counter += 0.01f;
	}
	TwTerminate();
	return 0;
}