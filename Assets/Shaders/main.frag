#version 330 core

in vec2 textureCoords;

out vec4 FragColor;

uniform sampler2D tex;

void main()
{
    FragColor = texture(tex, textureCoords);
}