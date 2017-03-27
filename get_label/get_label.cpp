// File.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "cstringt.h"
#include "afx.h"
#include "stdafx.h"
#include "File_Operation.h"
#include "imgInfo.h"

using namespace std;

char *filePath = "E:\\CAS-PEAL\\train_original";

int main(){

	File_Operation fo;
	imgInfo ii;
	//获取该路径下的所有文件名，并将文件信息写入txt文件中
	fo.getFilesName(filePath);
	//system("pause");

	return 0;
}
