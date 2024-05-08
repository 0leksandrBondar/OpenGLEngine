#version 330 core

layout(location = 0) in vec3 vertexPos;
uniform mat4 uView;

void main()
{
    gl_Position = uView * vec4(vertexPos, 1.0);
}
