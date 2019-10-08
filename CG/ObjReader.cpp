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
		cout << temp;

		if (temp == "v")
		{
			float x1, y1, z1;
			sline >> x1 >> y1 >> z1;
			//cout << " " <<x1  <<" "<< y1 <<" "<< z1 ;

			if (x1 > maiorx)
			{
				maiorx = x1;
			}
			else if (x1 < menorx)
			{
				menorx = x1;
			}

			if (y1 > maiory)
			{
				maiory = y1;
			}
			else if (y1 < menory)
			{
				menory = y1;
			}

			if (z1 > maiorz)
			{
				maiorz = z1;
			}
			else if (z1 < menorz)
			{
				menorz = z1;
			}

			New_mesh.SetVertices(x1, y1, z1);
		}
		else if (temp == "g")
		{
			sline >> nameg; //nome grupo
			//cout << " " << nameg ;
			New_mesh.CreateGroup(nameg);
		}
		else if (temp == "usemtl")
		{

			string TempMtl;
			sline >> TempMtl;

			//cout << TempMtl;

			New_mesh.SetMtlinGroup(nameg, TempMtl); //é aqui que eu quero usar o nome do grupo dnv
		}
		else if (temp == "f")
		{
			string aux, aux1, aux2,token;
			stringstream stoken;

			

			sline >> token;
			

			int auxBar = 0;
			bool Tb = false;

			

			

			for (int i = 0; i < token.length(); i++)
			{
				
				if (token[i] == '/')
				{
					auxBar++;
				}
				if (token[i] == '/' && token[i + 1] == '/')
				{
					Tb = true;
				}
			}
			
			

			if (auxBar == 0)
			{
				//caso só vertice
				cout << "Só vertice";

				stoken << token;
				getline(stoken, aux, ' ');
				v1 = stoi(aux);				

				stoken.clear();

				sline >> token;
				stoken << token;
				getline(stoken, aux, ' ');
				v2 = stoi(aux);				

				stoken.clear();

				sline >> token;
				stoken << token;
				getline(stoken, aux, ' ');
				v3 = stoi(aux);
				
			}
			else if (Tb)
			{
				//vertice e normal
				cout << "Vertice e normal";

				stoken << token;
				getline(stoken, aux, '/');
				v1 = stoi(aux);				
				getline(stoken, aux, '/');							
				getline(stoken, aux, ' ');				
				n1 = stoi(aux);

				stoken.clear();

				sline >> token;
				stoken << token;
				getline(stoken, aux, '/');
				v2 = stoi(aux);				
				getline(stoken, aux, '/');							
				getline(stoken, aux, ' ');
				n2 = stoi(aux);				

				stoken.clear();

				sline >> token;
				stoken << token;
				getline(stoken, aux, '/');
				v3 = stoi(aux);
				getline(stoken, aux, '/');				
				getline(stoken, aux, ' ');
				n3 = stoi(aux);
			}
			else if (auxBar == 1)
			{
				//vertice e textura
				cout << "Vertice e textura";
				stoken << token;
				getline(stoken, aux, '/');
				v1 = stoi(aux);				
				getline(stoken, aux, ' ');
				t1 = stoi(aux);							

				stoken.clear();

				sline >> token;
				stoken << token;
				getline(stoken, aux, '/');
				v2 = stoi(aux);				
				getline(stoken, aux, ' ');
				t2 = stoi(aux);				

				stoken.clear();

				sline >> token;
				stoken << token;
				getline(stoken, aux, '/');
				v3 = stoi(aux);
				getline(stoken, aux, ' ');
				t3 = stoi(aux);
				
			}
			else if (auxBar == 2)
			{
				//tudo

				stoken << token;
				getline(stoken, aux, '/');
				v1 = stoi(aux); 
				cout << v1 << "/";
				getline(stoken, aux, '/');
				t1 = stoi(aux);
				cout << t1 << "/";
				getline(stoken, aux, ' ');
				n1 = stoi(aux);
				cout << n1 << " ";

				stoken.clear();

				sline >> token;
				stoken << token;
				getline(stoken, aux, '/');
				v2 = stoi(aux);
				cout << v2 << "/";
				getline(stoken, aux, '/');
				t2 = stoi(aux);
				cout << t2 << "/";
				getline(stoken, aux, ' ');
				n2 = stoi(aux);
				cout << n2 << "\n";

				stoken.clear();

				sline >> token;
				stoken << token;
				getline(stoken, aux, '/');
				v3 = stoi(aux);
				getline(stoken, aux, '/');
				t3 = stoi(aux);
				getline(stoken, aux, ' ');
				n3 = stoi(aux);

			}
			
			New_mesh.CreateFaceinGroup(nameg, v1, 1, 1, v2, 1, 1, v3, 1, 1);
		}

		//cout << endl;
	}

	//scale = sqrt(pow(maiorx - menorx, 2) + pow(maiory - menory, 2) + pow(maiorz - menorz, 2));
	
	New_mesh.scale = scale;

	return New_mesh;
}

