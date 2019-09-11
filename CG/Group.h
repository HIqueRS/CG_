#pragma once
#include "Face.h"
#include <string>
class Group
{
public:
	Group();
	~Group();
	void CreateFace(int n,int V1, int V2, int V3);
	void BoxEx();
	void SetName(std::string N);

//protected:
	Face faces[12];
	std::string Name;
};

