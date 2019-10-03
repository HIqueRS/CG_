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
	/*SetVertices( 0.5f, 0.5f, 0.5f);
	SetVertices( -0.5f, 0.5f, 0.5f);
	SetVertices( -0.5f, 0.5f, -0.5f);
	SetVertices( 0.5f, 0.5f, -0.5f);
	
	SetVertices( 0.5f, -0.5f, 0.5f);
	SetVertices( -0.5f, -0.5f, 0.5f);
	SetVertices( -0.5f, -0.5f, -0.5f);
	SetVertices( 0.5f, -0.5f, -0.5f);*/

	/*CreateGroup("xis");
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
	CreateFaceinGroup("xis", 1, 5, 6);*/
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

void Mesh::CreateFaceinGroup(std::string name, int v1, int t1, int n1, int v2, int t2, int n2, int v3, int t3, int n3)
{
	//Gps[];
	Gps[Nomes.find(name)->second]->CreateFace(v1, v2, v3);
}

void Mesh::SetMtlinGroup(std::string name, std::string Mtl)
{
	Gps[Nomes.find(name)->second]->SetMtl(Mtl);
}

Group* Mesh::GetGroup(std::string name)
{
	return Gps[Nomes.find(name)->second];
}
