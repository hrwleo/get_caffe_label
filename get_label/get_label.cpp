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
	//��ȡ��·���µ������ļ����������ļ���Ϣд��txt�ļ���
	fo.getFilesName(filePath);
	//system("pause");

	return 0;
}
