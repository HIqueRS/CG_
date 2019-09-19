#include "Mesh.h"



Mesh::Mesh()
{
	BoxEx();
	NGps = 0;

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

	CreateGroup("xis");
	CreateFaceinGroup("xis", 0, 1, 2);
	CreateFaceinGroup("xis", 2, 3, 0);
	CreateFaceinGroup("xis", 4, 5, 6);
	CreateFaceinGroup("xis", 6, 7, 4);
	CreateFaceinGroup("xis", 0, 4, 5);
	CreateFaceinGroup("xis", 5, 1, 0);
	CreateFaceinGroup("xis", 2, 3, 6);
	CreateFaceinGroup("xis", 3, 6, 7);
	CreateFaceinGroup("xis", 0, 3, 7);
	CreateFaceinGroup("xis", 0, 4, 7);
	CreateFaceinGroup("xis", 1, 2, 6);
	CreateFaceinGroup("xis", 1, 5, 6);
}

std::vector<glm::vec3*> Mesh::GetVerts()
{
	return Verts;
}

void Mesh::CreateGroup(std::string name)
{
	auxG = new Group;
	auxG->SetName(name);
	Gps.push_back(auxG);

	Nomes[name] = NGps;
	NGps++;


}

void Mesh::CreateFaceinGroup(std::string name, int ID1, int ID2, int ID3)
{
	//Gps[];
	Gps[Nomes.find(name)->second]->CreateFace(ID1, ID2, ID3);
}

Group* Mesh::GetGroup(std::string name)
{
	
	return Gps[Nomes.find(name)->second];
}
