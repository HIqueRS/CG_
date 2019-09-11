#include "Group.h"



Group::Group()
{
	BoxEx();
}


Group::~Group()
{
}

void Group::CreateFace(int n, int V1, int V2, int V3)
{
	//faces[n].Add_Vert[V1];
	//faces[n].Add_Vert[V2];
	//faces[n].Add_Vert[V3];
}

void Group::BoxEx()
{
	//CreateFace(0, 0, 1, 2);
	faces[0].Id_Vert[0] = 0;
	faces[0].Id_Vert[1] = 1;
	faces[0].Id_Vert[2] = 2;
	//CreateFace(1, 2, 3, 0);
	faces[1].Id_Vert[0] = 2;
	faces[1].Id_Vert[1] = 3;
	faces[1].Id_Vert[2] = 0;
	//CreateFace(2, 4, 5, 6);
	faces[2].Id_Vert[0] = 4;
	faces[2].Id_Vert[1] = 5;
	faces[2].Id_Vert[2] = 6;
	//CreateFace(3, 6, 7, 4);
	faces[3].Id_Vert[0] = 6;
	faces[3].Id_Vert[1] = 7;
	faces[3].Id_Vert[2] = 4;
	//CreateFace(4, 0, 4, 5);
	faces[4].Id_Vert[0] = 0;
	faces[4].Id_Vert[1] = 4;
	faces[4].Id_Vert[2] = 5;
	//CreateFace(5, 5, 1, 0);
	faces[5].Id_Vert[0] = 5;
	faces[5].Id_Vert[1] = 1;
	faces[5].Id_Vert[2] = 0;
	
	//CreateFace(6, 2, 3, 6);
	faces[6].Id_Vert[0] = 2;
	faces[6].Id_Vert[1] = 3;
	faces[6].Id_Vert[2] = 6;
	//CreateFace(7, 3, 6, 7);
	faces[7].Id_Vert[0] = 3;
	faces[7].Id_Vert[1] = 6;
	faces[7].Id_Vert[2] = 7;
	//CreateFace(8, 0, 3, 7);
	faces[8].Id_Vert[0] = 0;
	faces[8].Id_Vert[1] = 3;
	faces[8].Id_Vert[2] = 7;
	//CreateFace(9, 0, 4, 7);
	faces[9].Id_Vert[0] = 0;
	faces[9].Id_Vert[1] = 4;
	faces[9].Id_Vert[2] = 7;
	//CreateFace(10, 1, 2, 6);
	faces[10].Id_Vert[0] = 1;
	faces[10].Id_Vert[1] = 2;
	faces[10].Id_Vert[2] = 6;
	//CreateFace(11, 1, 5, 6);
	faces[11].Id_Vert[0] = 1;
	faces[11].Id_Vert[1] = 5;
	faces[11].Id_Vert[2] = 6;

	
}

void Group::SetName(std::string N)
{
	Name = N;
}
