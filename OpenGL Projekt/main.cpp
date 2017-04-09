#include <iostream>
#include "SDL_events.h"
#include "Display.h"
#include "Projection.h"
#include "Camera.h"
#include "Mouse.h"
#include "Cube.h"
#include "Cylinder.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

int main(int argc, char** argv)
{
	Display display(WIDTH, HEIGHT, "OpenGL Projekt");
	SDL_WarpMouseInWindow(display.Window(), WIDTH / 2, HEIGHT / 2);
	SDL_Event e;
	Camera camera(glm::vec3(0.0f, 0.0f, 10.0f));
	Mouse mouse(WIDTH / 2, HEIGHT / 2);

	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

	Cube stol, lozysko_poziome_lewe;
	Cylinder prowadnica_pionowa_lewa(100), prowadnica_pionowa_prawa(100);
	Cylinder prowadnica_pozioma_lewa(100), prowadnica_pozioma_prawa(100);
	Cylinder mala_prowadnica_pozioma1(100), mala_prowadnica_pozioma2(100);

	stol.SetScale(glm::vec3(3.0f, 0.1f, 3.0f));

	prowadnica_pionowa_lewa.Model().GetPos().x = -1.4f;
	prowadnica_pionowa_lewa.SetScale(glm::vec3(0.1f, 4.0f, 0.1f));
	prowadnica_pionowa_lewa.Model().GetPos().y = 1.0f;

	prowadnica_pionowa_prawa.Model().GetPos().x = 1.4f;
	prowadnica_pionowa_prawa.SetScale(glm::vec3(0.1f, 4.0f, 0.1f));
	prowadnica_pionowa_prawa.Model().GetPos().y = 1.0f;

	prowadnica_pozioma_lewa.Model().GetPos().x = -1.2f;
	prowadnica_pozioma_lewa.SetScale(glm::vec3(0.1f, 3.0f, 0.1f));
	prowadnica_pozioma_lewa.Model().GetPos().y = 2.5f;
	prowadnica_pozioma_lewa.Model().GetRot().x = 1.57f;

	prowadnica_pozioma_prawa.Model().GetPos().x = 1.2f;
	prowadnica_pozioma_prawa.SetScale(glm::vec3(0.1f, 3.0f, 0.1f));
	prowadnica_pozioma_prawa.Model().GetPos().y = 2.5f;
	prowadnica_pozioma_prawa.Model().GetRot().x = 1.57f;

	mala_prowadnica_pozioma1.SetScale(glm::vec3(0.05f, 2.9f, 0.05f));
	mala_prowadnica_pozioma1.Model().GetRot().z = 1.57f;
	mala_prowadnica_pozioma1.Model().GetPos().y = 2.5f;
	mala_prowadnica_pozioma1.Model().GetPos().z = 0.3f;

	lozysko_poziome_lewe.SetScale(glm::vec3(0.2f, 0.2f, 0.4f));
	lozysko_poziome_lewe.Model().GetPos().x = -1.2f;
	lozysko_poziome_lewe.Model().GetPos().y = 2.5f;
	Projection projection(camera.m_zoom, 0.1f, 1000.0f);

	float counter = 0.0f;

	while (!display.IsClosed())
	{
		GLfloat currentFrame = SDL_GetTicks();
		deltaTime = (currentFrame - lastFrame) * 0.000001;
		lastFrame = currentFrame * 0, 001;
		//std::cout << deltaTime << std::endl;

		//SDL_PumpEvents();
		
		while (SDL_PollEvent(&e))
		{
			int x, y;
			SDL_GetMouseState(&x, &y);

			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
			
			if (e.type == SDL_QUIT)
				display.Close();

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

		display.Clear(0.2f, 0.3f, 0.3f, 1.0f);

		projection.SetFov(camera.m_zoom);


		stol.Draw(camera, projection);
		prowadnica_pionowa_lewa.Draw(camera, projection);
		prowadnica_pionowa_prawa.Draw(camera, projection);
		prowadnica_pozioma_lewa.Draw(camera, projection);
		prowadnica_pozioma_prawa.Draw(camera, projection);
		mala_prowadnica_pozioma1.Draw(camera, projection);
		lozysko_poziome_lewe.Draw(camera, projection);

		display.Update();
		counter += 0.01f;
	}
	return 0;
}