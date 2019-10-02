#include "ObjReader.h"



ObjReader::ObjReader()
{
}


ObjReader::~ObjReader()
{
}

Mesh ObjReader::Read(std::string name)
{
	
	Mesh New_mesh;

	ifstream myfile(name); // ifstream = padrão ios:in


	while (!myfile.eof())
	{
		getline(myfile, line);



		stringstream sline;
		sline << line;
		string temp;

		sline >> temp;

		if (temp == "v")
		{
			float x1, y1, z1;
			sline >> x1 >> y1 >> z1;
			cout << x1 << y1 << z1;

			New_mesh.SetVertices(x1, y1, z1);
		}
		else if (temp == "g")
		{
			sline >> nameg; //nome grupo

			New_mesh.CreateGroup(nameg);
		}
		else if (temp == "usemtl")
		{

			string TempMtl;
			sline >> TempMtl;

			New_mesh.SetMtlinGroup(nameg, TempMtl); //é aqui que eu quero usar o nome do grupo dnv
		}
		else if (temp == "f")
		{
			int id1, id2, id3;
			//string bla1, bla2, bla3;

			sline >> id1 >> id2 >> id3;
			//sline >> bla1 >> bla2 >> bla3;
			
			New_mesh.CreateFaceinGroup(nameg, id1, id2, id3);
		}
	}


	return New_mesh;
}

