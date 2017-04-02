#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Projection.h"
#include <vector>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")



int main(int argc, char** argv)
{
	Display display(WIDTH, HEIGHT, "OpenGL Projekt");
	
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
	Transform view;
	view.SetPos(glm::vec3(0.0f, 0.0f, -3.0f));
	Projection projection;

	float counter = 0.0f;

	while (!display.IsClosed())
	{
		display.Clear(0.2f, 0.3f, 0.3f, 1.0f);
		
		//model.GetPos().x = sinf(counter);
		model.GetRot().y = counter;
		model.GetRot().x = counter;
		model.GetRot().z = counter;
		//model.SetScale(glm::vec3(cosf(counter) + 1.1, cosf(counter) + 1.1, cosf(counter) + 1.1));
		shader.Bind();
		shader.Update(model, view, projection);
		mesh.Draw();
		display.Update();
		counter += 0.01f;
	}
	return 0;
}