#include "simple_mesh.hpp"

SimpleMeshData concatenate( SimpleMeshData aM, SimpleMeshData const& aN )
{
	aM.positions.insert( aM.positions.end(), aN.positions.begin(), aN.positions.end() );
	aM.texcoords.insert( aM.texcoords.end(), aN.texcoords.begin(), aN.texcoords.end() );
	return aM;
}


GLuint create_vao( SimpleMeshData const& aMeshData )
{
	// Set up VBO
	// 1. Naming
	GLuint positionVBO= 0;
	glGenBuffers( 1, &positionVBO );

	GLuint texCoordVBO = 0;
	glGenBuffers( 1, &texCoordVBO );

	// 2. Recourse alloc
	glBindBuffer( GL_ARRAY_BUFFER, positionVBO );
	glBufferData( GL_ARRAY_BUFFER, aMeshData.positions.size() * sizeof(Vec3f), aMeshData.positions.data(), GL_STATIC_DRAW );

	glBindBuffer( GL_ARRAY_BUFFER, texCoordVBO );
	glBufferData( GL_ARRAY_BUFFER, aMeshData.texcoords.size() * sizeof(Vec3f), aMeshData.texcoords.data(), GL_STATIC_DRAW );


	// Set up VAO
	// 1. Naming
	GLuint vao = 0;
	glGenVertexArrays( 1, &vao );
	glBindVertexArray( vao );

	// 2. Bind raw data into shape
	glBindBuffer( GL_ARRAY_BUFFER, positionVBO );
	glVertexAttribPointer(
		0, // index in shader
		3, GL_FLOAT, GL_FALSE, // 3 floats (non-normalized) PER VERTEX
		0,
		0
	);
	glEnableVertexAttribArray( 0 );

	glBindBuffer( GL_ARRAY_BUFFER, texCoordVBO );
	glVertexAttribPointer(
		1, // location = 1 in vertex shader
		2, GL_FLOAT, GL_FALSE, // 2 floats, not normalized to 0..1 (GL FALSE)
		0, // see above
		nullptr // see above
	);
	glEnableVertexAttribArray( 1 );

	// 3. Reset VAO
	glBindVertexArray( 0 );
	glBindBuffer( GL_ARRAY_BUFFER, 0 );

	// 4. Clean up VBO recourse
	glDeleteBuffers( 1, &positionVBO );
	glDeleteBuffers( 1, &texCoordVBO );

	//TODO: implement me
	return 0;
}

