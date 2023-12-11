#version 430

// Input Attributes
// must MATCH the .vert attributes
in vec2 v2fTexCoord;

// Uniform data
layout( location = 0 ) uniform mat4 uProjCameraWorld;
uniform sampler2D uTexture;

// Output Attributes
layout( location = 0 ) out vec3 oColor;

void main()
{
        oColor = texture( uTexture, v2fTexCoord ).rgb;
}
