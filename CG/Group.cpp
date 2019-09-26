#include "Group.h"



Group::Group()
{
	//BoxEx();
	NFace = 0;
}


Group::~Group()
{
}

void Group::CreateFace(int V1, int V2, int V3)
{
	/*faces[n].Id_Vert[0] = V1;
	faces[n].Id_Vert[1] = V2;
	faces[n].Id_Vert[2] = V3;*/

	faces[NFace].Add_Vert(V1);
	faces[NFace].Add_Vert(V2);
	faces[NFace].Add_Vert(V3);
	NFace++;
}

void Group::BoxEx()
{
	/*CreateFace(0, 0, 1, 2);
	
	CreateFace(1, 2, 3, 0);
	
	CreateFace(2, 4, 5, 6);
	
	CreateFace(3, 6, 7, 4);
	
	CreateFace(4, 0, 4, 5);
	
	CreateFace(5, 5, 1, 0);
	
	
	CreateFace(6, 2, 3, 6);
	
	CreateFace(7, 3, 6, 7);
	
	CreateFace(8, 0, 3, 7);
	
	CreateFace(9, 0, 4, 7);
	
	CreateFace(10, 1, 2, 6);
	
	CreateFace(11, 1, 5, 6);
	*/

	
}

void Group::SetName(std::string N)
{
	Name = N;
}

void Group::SetMtl(std::string M)
{
	Mtl = M;
}
