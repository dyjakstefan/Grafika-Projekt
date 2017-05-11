#include "ObjectManager.h"



ObjectManager::ObjectManager()
{
	movementSpeed = 1.0f;

	ziemia.SetScale(glm::vec3(30.0f, 1.0f, 30.0f));
	ziemia.Model().GetPos().y = -1.5f;
	ziemia.SetMaterial(Material(glm::vec3(0.2, 0.3, 0.3), glm::vec3(0.35, 0.45, 0.45), glm::vec3(0.5, 0.5, 0.5), 25));

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

	objectsToDraw.push_back(&ziemia);
	objectsToDraw.push_back(&podloga);
	objectsToDraw.push_back(&stol);
	objectsToDraw.push_back(&bottom1);
	objectsToDraw.push_back(&bottom2);
	objectsToDraw.push_back(&bottom3);
	objectsToDraw.push_back(&bottom4);
	objectsToDraw.push_back(&middle1);
	objectsToDraw.push_back(&middle2);
	objectsToDraw.push_back(&middle3);
	objectsToDraw.push_back(&middle4);
	objectsToDraw.push_back(&middle5);
	objectsToDraw.push_back(&middle6);
	objectsToDraw.push_back(&middle7);
	objectsToDraw.push_back(&middle8);
	objectsToDraw.push_back(&lozysko_poziome_lewe);
	objectsToDraw.push_back(&lozysko_poziome_prawe);
	objectsToDraw.push_back(&glowica);

	objectsToDraw.push_back(&prowadnica_pionowa_lewa);
	objectsToDraw.push_back(&prowadnica_pionowa_prawa);
	objectsToDraw.push_back(&prowadnica_pozioma_lewa);
	objectsToDraw.push_back(&prowadnica_pozioma_prawa);
	objectsToDraw.push_back(&mala_prowadnica_pozioma1);
	objectsToDraw.push_back(&mala_prowadnica_pozioma2);

	objectsY.push_back(&stol);
	objectsX.push_back(&glowica);
	objectsZ.push_back(&glowica);
	objectsZ.push_back(&mala_prowadnica_pozioma1);
	objectsZ.push_back(&mala_prowadnica_pozioma2);
	objectsZ.push_back(&lozysko_poziome_lewe);
	objectsZ.push_back(&lozysko_poziome_prawe);
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::Draw(Camera view, Projection projection)
{
	for (int i = 0; i < objectsToDraw.size(); i++)
	{
		objectsToDraw[i]->Draw(view, projection);
	}
}

void ObjectManager::Events(const Uint8 * currentKeyStates, GLfloat deltaTime)
{
	GLfloat velocity = movementSpeed * deltaTime;
	if (currentKeyStates[SDL_SCANCODE_D])
	{
		if (glowica.Model().GetPos().x < 0.8)
		{
			for(int i = 0; i < objectsX.size(); i++)
				objectsX[i]->Model().GetPos().x += velocity;
		}
	}
	if (currentKeyStates[SDL_SCANCODE_A])
	{
		if (glowica.Model().GetPos().x > -0.8)
		{
			for (int i = 0; i < objectsX.size(); i++)
				objectsX[i]->Model().GetPos().x -= velocity;
		}
	}
	if (currentKeyStates[SDL_SCANCODE_W])
	{
		if (glowica.Model().GetPos().z > -1.31)
		{
			for (int i = 0; i < objectsZ.size(); i++)
				objectsZ[i]->Model().GetPos().z -= velocity;
		}
	}
	if (currentKeyStates[SDL_SCANCODE_S])
	{
		if (glowica.Model().GetPos().z < 1.31)
		{
			for (int i = 0; i < objectsZ.size(); i++)
				objectsZ[i]->Model().GetPos().z += velocity;
		}
	}
	if (currentKeyStates[SDL_SCANCODE_Q])
	{
		if (stol.Model().GetPos().y < 1.89)
		{
			for (int i = 0; i < objectsX.size(); i++)
				objectsY[i]->Model().GetPos().y += velocity;
		}
	}
	if (currentKeyStates[SDL_SCANCODE_E])
	{
		if (stol.Model().GetPos().y > -0.45)
		{
			for (int i = 0; i < objectsX.size(); i++)
				objectsY[i]->Model().GetPos().y -= velocity;
		}
	}
}
