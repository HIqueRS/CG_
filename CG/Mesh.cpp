#include "Mesh.h"



Mesh::Mesh()
{
	//BoxEx();


}


Mesh::~Mesh()
{
}

void Mesh::SetVertices(GLfloat x, GLfloat y, GLfloat z)
{
	aux = new glm::vec3;
	aux->x = x;
	aux->y = y;
	aux->z = z;
	Verts.push_back(aux);
	
}

void Mesh::BoxEx()
{
	SetVertices( 0.5f, 0.5f, 0.5f);
	SetVertices( -0.5f, 0.5f, 0.5f);
	SetVertices( -0.5f, 0.5f, -0.5f);
	SetVertices( 0.5f, 0.5f, -0.5f);
	
	SetVertices( 0.5f, -0.5f, 0.5f);
	SetVertices( -0.5f, -0.5f, 0.5f);
	SetVertices( -0.5f, -0.5f, -0.5f);
	SetVertices( 0.5f, -0.5f, -0.5f);
}

std::vector<glm::vec3*> Mesh::GetVerts()
{
	return Verts;
}

void Mesh::CreateGroup(std::string name)
{
	auxG = new Group;

}
