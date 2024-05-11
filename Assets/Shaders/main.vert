#version 330 core

layout(location = 0) in vec3 vertexPos;
layout(location = 1) in vec2 texturePos;

out vec2 textureCoords;

uniform mat4 uView;

void main()
{
    textureCoords = texturePos;
    gl_Position = uView * vec4(vertexPos, 1.0);
}
