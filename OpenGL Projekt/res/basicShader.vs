#version 330
  
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 3) in vec2 uvs;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 Normal;
out vec3 FragPos;
out vec2 uv;

void main()
{
	uv = uvs;
    gl_Position = projection * view * model * vec4(position.x, position.y, position.z, 1.0f);	
	FragPos = vec3(model * vec4(position, 1.0f));
	Normal = mat3(transpose(inverse(model))) * normal;
}