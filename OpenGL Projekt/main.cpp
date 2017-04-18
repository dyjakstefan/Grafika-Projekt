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
	Camera camera(glm::vec3(0.0f, 2.0f, 10.0f));
	Mouse mouse(WIDTH / 2, HEIGHT / 2);

	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

	Cylinder cylinder(100);
	Cylinder prowadnica_pionowa_lewa(100), prowadnica_pionowa_prawa(100);
	Cylinder prowadnica_pozioma_lewa(100), prowadnica_pozioma_prawa(100);
	Cylinder mala_prowadnica_pozioma1(100), mala_prowadnica_pozioma2(100);


	Cube stol, podloga, lozysko_poziome_lewe, lozysko_poziome_prawe, glowica;
	Cube bottom1, bottom2, bottom3, bottom4;
	Cube middle1, middle2, middle3, middle4, middle5, middle6, middle7, middle8;
	Cube ziemia;
	
	// LIGHTING
	
	Cube lamp("lampShader");
	lamp.Model().GetPos().x = 10.0f;
	lamp.Model().GetPos().y = 3.0f;
	lamp.SetScale(glm::vec3(0.5f));
	//////////////////////////////////////////
	ziemia.SetScale(glm::vec3(30.0f, 1.0f, 30.0f));
	ziemia.Model().GetPos().y = -1.5f;

	stol.SetScale(glm::vec3(3.0f, 0.1f, 3.0f));

	podloga.SetScale(glm::vec3(3.18f, 0.5f, 3.25f));
	podloga.Model().GetPos().y = -0.75f;
	 
	prowadnica_pionowa_lewa.Model().GetPos().x = -1.4f;
	prowadnica_pionowa_lewa.SetScale(glm::vec3(0.1f, 4.0f, 0.1f));
	prowadnica_pionowa_lewa.Model().GetPos().y = 1.5f;

	prowadnica_pionowa_prawa.Model().GetPos().x = 1.4f;
	prowadnica_pionowa_prawa.SetScale(glm::vec3(0.1f, 4.0f, 0.1f));
	prowadnica_pionowa_prawa.Model().GetPos().y = 1.5f;

	prowadnica_pozioma_lewa.Model().GetPos().x = -1.2f;
	prowadnica_pozioma_lewa.SetScale(glm::vec3(0.1f, 3.2f, 0.1f));
	prowadnica_pozioma_lewa.Model().GetPos().y = 2.5f;
	prowadnica_pozioma_lewa.Model().GetRot().x = 1.57f;

	prowadnica_pozioma_prawa.Model().GetPos().x = 1.2f;
	prowadnica_pozioma_prawa.SetScale(glm::vec3(0.1f, 3.2f, 0.1f));
	prowadnica_pozioma_prawa.Model().GetPos().y = 2.5f;
	prowadnica_pozioma_prawa.Model().GetRot().x = 1.57f;

	mala_prowadnica_pozioma1.SetScale(glm::vec3(0.05f, 2.5f, 0.05f));
	mala_prowadnica_pozioma1.Model().GetRot().z = 1.57f;
	mala_prowadnica_pozioma1.Model().GetPos().y = 2.5f;
	mala_prowadnica_pozioma1.Model().GetPos().z = 0.1f;

	mala_prowadnica_pozioma2.SetScale(glm::vec3(0.05f, 2.5f, 0.05f));
	mala_prowadnica_pozioma2.Model().GetRot().z = 1.57f;
	mala_prowadnica_pozioma2.Model().GetPos().y = 2.5f;
	mala_prowadnica_pozioma2.Model().GetPos().z = -0.1f;

	lozysko_poziome_lewe.SetScale(glm::vec3(0.2f, 0.2f, 0.4f));
	lozysko_poziome_lewe.Model().GetPos().x = -1.2f;
	lozysko_poziome_lewe.Model().GetPos().y = 2.5f;

	lozysko_poziome_prawe.SetScale(glm::vec3(0.2f, 0.2f, 0.4f));
	lozysko_poziome_prawe.Model().GetPos().x = 1.2f;
	lozysko_poziome_prawe.Model().GetPos().y = 2.5f;

	glowica.SetScale(glm::vec3(0.6f, 0.7f, 0.6f));
	glowica.Model().GetPos().y = 2.5f;

	bottom1.Model().GetPos().z = 1.6f;
	bottom1.Model().GetPos().y = 3.3f;
	bottom1.SetScale(glm::vec3(3.25f, 0.5f, 0.1f));

	bottom2.Model().GetRot().y = 1.57f;
	bottom2.Model().GetPos().x = 1.57f;
	bottom2.Model().GetPos().y = 3.3f;
	bottom2.SetScale(glm::vec3(3.12f, 0.5f, 0.1f));

	bottom3.Model().GetRot().y = 1.57f;
	bottom3.Model().GetPos().x = -1.57f;
	bottom3.Model().GetPos().y = 3.3f;
	bottom3.SetScale(glm::vec3(3.12f, 0.5f, 0.1f));

	bottom4.Model().GetPos().z = -1.6f;
	bottom4.Model().GetPos().y = 3.3f;
	bottom4.SetScale(glm::vec3(3.25f, 0.5f, 0.1f));

	middle1.Model().GetPos().z = 1.6f;
	middle1.Model().GetPos().x = -1.34f;
	middle1.Model().GetPos().y = 1.32f;
	middle1.Model().GetRot().z = 1.57f;
	middle1.SetScale(glm::vec3(3.65f, 0.5f, 0.05f));

	middle2.Model().GetPos().z = 1.6f;
	middle2.Model().GetPos().x = 1.34f;
	middle2.Model().GetPos().y = 1.32f;
	middle2.Model().GetRot().z = 1.57f;
	middle2.SetScale(glm::vec3(3.65f, 0.5f, 0.05f));

	middle3.Model().GetPos().z = -1.6f;
	middle3.Model().GetPos().x = -1.34f;
	middle3.Model().GetPos().y = 1.32f;
	middle3.Model().GetRot().z = 1.57f;
	middle3.SetScale(glm::vec3(3.65f, 0.5f, 0.05f));

	middle4.Model().GetPos().z = -1.6f;
	middle4.Model().GetPos().x = 1.34f;
	middle4.Model().GetPos().y = 1.32f;
	middle4.Model().GetRot().z = 1.57f;
	middle4.SetScale(glm::vec3(3.65f, 0.5f, 0.05f));

	middle5.Model().GetPos().z = 1.32f;
	middle5.Model().GetPos().x = -1.57f;
	middle5.Model().GetPos().y = 1.32f;
	middle5.Model().GetRot().z = 1.57f;
	middle5.Model().GetRot().x = 1.57f;
	middle5.SetScale(glm::vec3(3.65f, 0.5f, 0.05f));

	middle6.Model().GetPos().z = -1.32f;
	middle6.Model().GetPos().x = -1.57f;
	middle6.Model().GetPos().y = 1.32f;
	middle6.Model().GetRot().z = 1.57f;
	middle6.Model().GetRot().x = 1.57f;
	middle6.SetScale(glm::vec3(3.65f, 0.5f, 0.05f));

	middle7.Model().GetPos().z = 1.32f;
	middle7.Model().GetPos().x = 1.57f;
	middle7.Model().GetPos().y = 1.32f;
	middle7.Model().GetRot().z = 1.57f;
	middle7.Model().GetRot().x = 1.57f;
	middle7.SetScale(glm::vec3(3.65f, 0.5f, 0.05f));

	middle8.Model().GetPos().z = -1.32f;
	middle8.Model().GetPos().x = 1.57f;
	middle8.Model().GetPos().y = 1.32f;
	middle8.Model().GetRot().z = 1.57f;
	middle8.Model().GetRot().x = 1.57f;
	middle8.SetScale(glm::vec3(3.65f, 0.5f, 0.05f));

	Projection projection(camera.m_zoom, 0.1f, 1000.0f);

	float counter = 0.0f;

	while (!display.IsClosed())
	{
		GLfloat currentFrame = SDL_GetTicks();
		deltaTime = (currentFrame - lastFrame) * 0.000001f;
		lastFrame = currentFrame * 0, 001;
		//std::cout << deltaTime << std::endl;

		SDL_PumpEvents();
		
		while (SDL_PollEvent(&e))
		{
			int x, y;
			SDL_GetMouseState(&x, &y);

			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
			
			if (e.type == SDL_QUIT)
				display.Close();
			
			//Poruszanie g³owic¹
			if (currentKeyStates[SDL_SCANCODE_D])
			{
				if(glowica.Model().GetPos().x < 0.8)
					glowica.Model().GetPos().x += 0.01f;
			}
			if (currentKeyStates[SDL_SCANCODE_A])
			{
				if (glowica.Model().GetPos().x > -0.8)
					glowica.Model().GetPos().x -= 0.01f;
			}
			if (currentKeyStates[SDL_SCANCODE_W])
			{
				if (glowica.Model().GetPos().z > -1.31)
				{
					glowica.Model().GetPos().z -= 0.01f;
					mala_prowadnica_pozioma1.Model().GetPos().z -= 0.01f;
					mala_prowadnica_pozioma2.Model().GetPos().z -= 0.01f;
					lozysko_poziome_lewe.Model().GetPos().z -= 0.01f;
					lozysko_poziome_prawe.Model().GetPos().z -= 0.01f;
				}
			}
			if (currentKeyStates[SDL_SCANCODE_S])
			{
				if (glowica.Model().GetPos().z < 1.31)
				{
					glowica.Model().GetPos().z += 0.01f;
					mala_prowadnica_pozioma1.Model().GetPos().z += 0.01f;
					mala_prowadnica_pozioma2.Model().GetPos().z += 0.01f;
					lozysko_poziome_lewe.Model().GetPos().z += 0.01f;
					lozysko_poziome_prawe.Model().GetPos().z += 0.01f;
				}
			}
			if (currentKeyStates[SDL_SCANCODE_Q])
			{
				if (stol.Model().GetPos().y < 1.89)
					stol.Model().GetPos().y += 0.01f;
			}
			if (currentKeyStates[SDL_SCANCODE_E])
			{
				if (stol.Model().GetPos().y > -0.45)
					stol.Model().GetPos().y -= 0.01f;
			}
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

		display.Clear(0.2f, 0.3f, 0.3f, 1.0f);

		projection.SetFov(camera.m_zoom);

		//DRUKARKA
		
		ziemia.Draw(camera, projection);
		podloga.Draw(camera, projection);
		stol.Draw(camera, projection);
		prowadnica_pionowa_lewa.Draw(camera, projection);
		prowadnica_pionowa_prawa.Draw(camera, projection);
		prowadnica_pozioma_lewa.Draw(camera, projection);
		prowadnica_pozioma_prawa.Draw(camera, projection);
		mala_prowadnica_pozioma1.Draw(camera, projection);
		mala_prowadnica_pozioma2.Draw(camera, projection);
		lozysko_poziome_lewe.Draw(camera, projection);
		lozysko_poziome_prawe.Draw(camera, projection);
		glowica.Draw(camera, projection);
		bottom1.Draw(camera, projection);
		bottom2.Draw(camera, projection);
		bottom3.Draw(camera, projection);
		bottom4.Draw(camera, projection);
		middle1.Draw(camera, projection);
		middle2.Draw(camera, projection);
		middle3.Draw(camera, projection);
		middle4.Draw(camera, projection);
		middle5.Draw(camera, projection);
		middle6.Draw(camera, projection);
		middle7.Draw(camera, projection);
		middle8.Draw(camera, projection);

		//OBUDOWA

		lamp.Draw(camera, projection);

		display.Update();
		//counter += 0.001f;
	}
	return 0;
}