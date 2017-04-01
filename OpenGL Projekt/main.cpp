#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include <vector>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

int main(int argc, char** argv)
{
	Display display(800, 600, "OpenGL Projekt");
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
	Transform transform;

	float counter = 0.0f;

	while (!display.IsClosed())
	{
		display.Clear(0.2f, 0.3f, 0.3f, 1.0f);
		
		//transform.GetPos().x = sinf(counter);
		transform.GetRot().y = counter;
		transform.GetRot().x = counter;
		transform.GetRot().z = counter;
		//transform.SetScale(glm::vec3(cosf(counter), cosf(counter), cosf(counter)));
		shader.Bind();
		shader.Update(transform);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		mesh.Draw();
		display.Update();
		counter += 0.01f;
	}
	return 0;
}