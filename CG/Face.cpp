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
	

	Id_Vert[Actual_Vert] = id;
	Actual_Vert++;
	

	
}
