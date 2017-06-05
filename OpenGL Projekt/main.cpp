#include <iostream>
#include "SDL_events.h"
#include "Display.h"
#include "Projection.h"
#include "Camera.h"
#include "Mouse.h"
#include "ObjectManager.h"
#include "Line.h"
#include <AntTweakBar.h>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

int main(int argc, char** argv)
{
	Line k;
	std::string kolor, kolory[6] = {
		"Czerwony",
		"Czarny" ,
		"Zielony" ,
		"Bialy" ,
		"Zolty" ,
		"Cyjan"
	};
	Display display(WIDTH, HEIGHT, "OpenGL Projekt");
	SDL_WarpMouseInWindow(display.Window(), WIDTH / 2, HEIGHT / 2);
	SDL_Event e;
	int handled;
	Camera camera(glm::vec3(0.0f, 2.0f, 10.0f));
	Mouse mouse(WIDTH / 2, HEIGHT / 2);
	ObjectManager objManager;
	int i = 0, j = 0;
	TwBar *myBar;
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;
	float counter = 0.0f;
	Projection projection(camera.m_zoom, 0.1f, 1000.0f);
	//Line line;
	/*line.AddVertex(glm::vec3(1.0f, 1.0f, 1.0f));
	line.AddVertex(glm::vec3(2.0f, 2.0f, 2.0f));
	line.AddVertex(glm::vec3(-2.0f, 3.0f, -2.0f));

	line.SetPos(glm::vec3(3.0f, 3.0f, 3.0f));*/
	TwInit(TW_OPENGL, NULL);
	TwWindowSize(WIDTH, HEIGHT);
	myBar = TwNewBar("Menu drukarki");
	TwAddVarRW(myBar, "kol1", TW_TYPE_INT8, &i, "label='Kolor filamentu' ");
	TwAddVarRW(myBar, "kol2", TW_TYPE_INT8, &j, "label='Kolor oswietlenia' ");

	//TwAddButton(myBar, "comment1", NULL, NULL, " label='Life is like a box a chocolates' ");

	while (!display.IsClosed())
	{
		GLfloat currentFrame = SDL_GetTicks();
		deltaTime = (currentFrame - lastFrame) * 0.001;
		lastFrame = currentFrame;
		SDL_PumpEvents();

		while (SDL_PollEvent(&e))
		{
			int x, y;
			SDL_GetMouseState(&x, &y);
			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

			if (e.type == SDL_QUIT)
				display.Close();

			handled = TwEventSDL(&e, SDL_MAJOR_VERSION, SDL_MINOR_VERSION);

			//Menu
			if (!handled)
			{
				switch (e.type)
				{
				case SDL_KEYDOWN:
					if (e.key.keysym.sym == 'p')
					{
						if (i < 7)
							i++;
						else
							i = 0;
					}
					if (e.key.keysym.sym == 'o')
					{
						if (j < 7)
							j++;
						else
							j = 0;
					}
					k.ZmianaKoloru(i);
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



		/*if (counter < 2)
		{
		GLfloat angle = 2 * glm::pi<float>() * counter*100 / 100;
		line.AddVertex(glm::vec3(glm::cos(angle) * 0.5, counter, glm::sin(angle) * 0.5));
		}*/

		if (currentFrame > 2000 && currentFrame < 5000)
		{
			objManager.MoveByRoute(deltaTime);
		}

		//display.Clear(0.2f, 0.3f, 0.3f, 1.0f);
		display.Clear(0.85f, 0.98f, 0.98f, 1.0f);

		projection.SetFov(camera.m_zoom);

		//line.Draw(camera, projection);
		objManager.Draw(camera, projection); TwDraw();
		display.Update();

		counter += 0.01;
	}
	TwTerminate();
	return 0;
}