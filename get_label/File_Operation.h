#pragma once
#include <iostream>
#include "cstringt.h"
#include "io.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class File_Operation
{
public:
	File_Operation(void);
	~File_Operation(void);
	void getFilesName(string path);
};

