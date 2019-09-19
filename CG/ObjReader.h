#pragma once
#include "Mesh.h"
class ObjReader
{
public:
	ObjReader();
	~ObjReader();
	void Read(Mesh* m);
};

