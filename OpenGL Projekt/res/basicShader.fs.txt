#version 330

out vec4 color;
in vec3 pos;

void main()
{
    color = vec4((pos/2) + 0.5, 1.0f);
} 