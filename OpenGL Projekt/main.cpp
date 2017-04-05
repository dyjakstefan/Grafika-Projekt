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

	Cube cube;
	Cube cube2;
	cube.Model().GetPos().y = -2.0f;
	cube2.Model().GetPos().y = 2.0f;

	Cylinder cylinder(100);
	
	Projection projection(camera.m_zoom, 0.1f, 1000.0f);

	float counter = 0.0f;

	while (!display.IsClosed())
	{
		GLfloat currentFrame = SDL_GetTicks();
		deltaTime = (currentFrame - lastFrame) * 0.000001;
		lastFrame = currentFrame * 0, 001;
		//std::cout << deltaTime << std::endl;

		SDL_PumpEvents();
		
		while (SDL_PollEvent(&e))
		{
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

			int x, y;
			SDL_GetMouseState(&x, &y);
			if (mouse.IsPositionChanged(x, y))
			{
				glm::vec2 offset = mouse.UpdatePosition(x, y);
				camera.ProcessMouseMovement(offset.x, offset.y);
			}
		}

		display.Clear(0.2f, 0.3f, 0.3f, 1.0f);

		cube.SetRot(glm::vec3(counter, counter, counter));
		cube2.SetPos(glm::vec3(sinf(counter), cube2.GetPos().y, cube2.GetPos().z));
		cube2.SetScale(glm::vec3(5 * (sinf(counter) + 1), 1, 1));
		cylinder.SetRot(glm::vec3(counter, counter, counter));

		projection.SetFov(camera.m_zoom);

		cube.Draw(camera, projection);
		cube2.Draw(camera, projection);
		cylinder.Draw(camera, projection);

		display.Update();
		counter += 0.01f;
	}
	return 0;
}