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

void TW_CALL Run(void *)
{
	Options::GetInstance().Print(true);
	std::cout << "1";
}
void TW_CALL Zapisz(void *)
{
	Options::GetInstance().Save();
}
void TW_CALL Anuluj(void *)
{
	Options::GetInstance().Cancel();
}

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

	Material filamentColor = Options::GetInstance().GetLineColor();
	Material lightColor = Options::GetInstance().GetLightColor();
	Shape currShape = Options::GetInstance().GetCurrentShape();
	
	TwInit(TW_OPENGL, NULL);
	TwWindowSize(Options::GetInstance().GetScreenWidth(), Options::GetInstance().GetScreenHeight());

	myBar = TwNewBar("Menu_drukarki");
	TwDefine(" Menu_drukarki label='Menu drukarki' color='0 0 0' text=light alpha=200");

	TwEnumVal shapeEV[NUM_SHAPES] = { {KOMIN, "Komin"}, {PIRAMIDA, "Piramida"} };
	TwType shapeType = TwDefineEnum("ShapeType", shapeEV, NUM_SHAPES);
	TwAddVarRW(myBar, "Shape", shapeType, &currShape, " keyIncr='<' keyDecr='>' ");
	//TwAddVarRW(myBar, "Wireframe", TW_TYPE_BOOLCPP, &s," key=z ");
	TwAddVarRW(myBar, "Ambient", TW_TYPE_COLOR3F, &filamentColor.ambient, " group='Kolor filamentu' ");
	TwAddVarRW(myBar, "Diffuse", TW_TYPE_COLOR3F, &filamentColor.diffuse, " group='Kolor filamentu' ");
	TwAddVarRW(myBar, "Specular", TW_TYPE_COLOR3F, &filamentColor.specular, " group='Kolor filamentu' ");
	TwAddVarRW(myBar, "Shininess", TW_TYPE_INT32, &filamentColor.shininess, " label='Shininess' min=1 max=100  group='Kolor filamentu' ");
	
	TwAddVarRW(myBar, "Ambient 2", TW_TYPE_COLOR3F, &lightColor.ambient, " group='Kolor oświetlenia' ");
	TwAddVarRW(myBar, "Diffuse 2", TW_TYPE_COLOR3F, &lightColor.diffuse, " group='Kolor oświetlenia' ");
	TwAddVarRW(myBar, "Specular 2", TW_TYPE_COLOR3F, &lightColor.specular, " group='Kolor oświetlenia' ");

	TwAddButton(myBar, "Start", Run, NULL, "label='Drukuj'");
	TwAddButton(myBar, "Zapisz", Zapisz, NULL, "label='Zapisz zmiany'");
	TwAddButton(myBar, "Anuluj", Anuluj, NULL, "label='Anuluj zmiany'");
	
	std::queue<glm::vec3> route;
	route.push(glm::vec3(5, 0, 0));
	route.push(glm::vec3(0, 5, 0));
	//route.push(glm::vec3(1, 1, 0));
	route.push(glm::vec3(0, 0, 5));


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
					TwKeyPressed(e.key.keysym.sym, TW_KMOD_NONE);
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