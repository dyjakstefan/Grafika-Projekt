#include <iostream>
#include "SDL_events.h"
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Projection.h"
#include "Camera.h"
#include "Mouse.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

int main(int argc, char** argv)
{
	Display display(WIDTH, HEIGHT, "OpenGL Projekt");
	SDL_WarpMouseInWindow(display.Window(), WIDTH / 2, HEIGHT / 2);
	SDL_Event e;
	Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
	Mouse mouse(WIDTH / 2, HEIGHT / 2);

	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

	Vertex vertices[] = { Vertex(glm::vec3(0.5, 0.5, 0.5)),
						Vertex(glm::vec3(0.5, -0.5, 0.5)),
						Vertex(glm::vec3(-0.5, -0.5, 0.5)),
		Vertex(glm::vec3(-0.5, 0.5, 0.5)),
		Vertex(glm::vec3(0.5, 0.5, -0.5)),
		Vertex(glm::vec3(0.5, -0.5, -0.5)),
		Vertex(glm::vec3(-0.5, -0.5, -0.5)),
		Vertex(glm::vec3(-0.5, 0.5, -0.5)) };

	std::vector<GLuint> indices = {
		0, 3, 2,
		0, 2, 1,
		4, 7, 3,
		4, 3, 0,
		5, 6, 7,
		5, 7, 4,
		1, 2, 6,
		1, 6, 5,
		3, 7, 6,
		3, 6, 2,
		4, 0, 1,
		4, 1, 5,	
	};

	Shader shader("./res/basicShader");
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices);
	Transform model;
	/*Transform view;
	view.SetPos(glm::vec3(0.0f, 0.0f, -3.0f));*/
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
				std::cout << "UP" <<std::endl;
			}
			if (currentKeyStates[SDL_SCANCODE_DOWN])
			{
				camera.ProcessKeyboard(BACKWARD, deltaTime);
				std::cout << "DOWN" << std::endl;
			}
			if (currentKeyStates[SDL_SCANCODE_LEFT])
			{
				camera.ProcessKeyboard(LEFT, deltaTime);
				std::cout << "LEFT" << std::endl;
			}
			if (currentKeyStates[SDL_SCANCODE_RIGHT])
			{
				camera.ProcessKeyboard(RIGHT, deltaTime);
				std::cout << "RIGHT" << std::endl;
			}

			if (e.type == SDL_MOUSEWHEEL)
			{
				std::cout << e.wheel.y <<std::endl;
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

		//model.GetPos().x = sinf(counter);
		model.GetRot().y = counter;
		model.GetRot().x = counter;
		model.GetRot().z = counter;
		//model.SetScale(glm::vec3(cosf(counter) + 1.1, cosf(counter) + 1.1, cosf(counter) + 1.1));
		std::cout << camera.m_zoom<<std::endl;
		projection.SetFov(camera.m_zoom);
		shader.Bind();
		shader.Update(model, camera, projection);
		mesh.Draw();
		display.Update();
		counter += 0.01f;
	}
	return 0;
}