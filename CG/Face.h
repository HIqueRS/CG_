#pragma once
class Face
{
public:
	Face();
	~Face();
	
	void Add_Vert(int id);

//protected:
	int Actual_Vert;
	int Id_Vert[3];
	int Max_Vert;
	int N_Vert;
};

