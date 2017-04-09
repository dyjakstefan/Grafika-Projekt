#version 330
  
layout (location = 0) in vec3 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
out vec3 pos;

void main()
{
    gl_Position = projection * view * model * vec4(position.x, position.y, position.z, 1.0f);	
    pos = position;
}