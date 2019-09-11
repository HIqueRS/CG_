#include "Face.h"



Face::Face()
{
	Actual_Vert = 0;
	N_Vert = 0;
	Max_Vert = 3;
}


Face::~Face()
{
}

void Face::Add_Vert(int id)
{
	if (Actual_Vert >= Max_Vert)
	{
		Actual_Vert = 0;
	}

	Id_Vert[Actual_Vert] = id;
	Actual_Vert++;
	

	N_Vert++;
	if (N_Vert >= Max_Vert)
	{
		N_Vert = 3;
	}
}
