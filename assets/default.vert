#version 430

// Input Attributes
// Note: location must be EXACTLY THE SAME as in the VAO
layout( location = 0 ) in vec3 iPosition;
layout( location = 1 ) in vec2 iTexCoord;

// Uniform data
layout( location = 0 ) uniform mat4 uProjCameraWorld;

// Output attributes 
// (outputs FROM vertex shader TO fragement shader)
out vec2 v2fTexCoord;

// In main, copy inputs into outputs
void main()
{
	// Copy position into inbuilt gl_Position
	gl_Position = uProjCameraWorld * vec4( iPosition, 1.0 );

	v2fTexCoord = iTexCoord;
}
