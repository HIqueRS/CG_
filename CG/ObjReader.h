#pragma once
#include "Mesh.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class ObjReader
{
public:
	ObjReader();
	~ObjReader();
	Mesh Read(std::string name);

	string line;
	string nameg;
};

