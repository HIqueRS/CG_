#pragma once
#include "Face.h"
#include <vector>
#include <string>
#include <GL/glew.h> /* include GLEW and new version of GL on Windows */
#include <GLFW/glfw3.h> /* GLFW helper library */
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/common.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <fstream>
#include <sstream>

class Group
{
public:
	Group();
	~Group();
	void CreateFace(int V1, int V2, int V3);
	void BoxEx();
	void SetName(std::string N);
	void SetMtl(std::string M);

//protected:
	Face faces[12];
	std::vector<Face> Vec_Faces;
	std::string Name;
	int NFace;
	std::string Mtl;

	GLuint vao;
	GLuint vboV;
	GLuint vboT;
	GLuint vboN;
};

