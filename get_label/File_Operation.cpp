#include "StdAfx.h"
#include "File_Operation.h"
#include "imgInfo.h"

//struct imginfo{
//string name;
//string angle;
//};

imgInfo ii;

vector<string> filenames;

File_Operation::File_Operation(void)
{
}

File_Operation::~File_Operation(void)
{
}

void File_Operation::getFilesName(string path){

	//文件句柄  
	long   hFile = 0;
	//文件信息  
	struct _finddata_t fileinfo;
	string p;

	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之  
			//如果不是,加入列表  
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFilesName(p.assign(path).append("\\").append(fileinfo.name));

			}
			else
			{
				filenames.push_back(fileinfo.name);  // 直接获取名字即可
				//files.push_back(p.assign(path).append("\\").append(fileinfo.name));  
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
	//ofstream fout("out.txt",ios::out);
	ofstream fout("train.txt", ios::out);
	ofstream fout2("val.txt", ios::out);
	//ofstream fout3("test.txt",ios::out);

	int size = filenames.size();
	int label = 0;
	fout2 << filenames[0] <<" "<<label << endl;
	//494414张图片
	for (int i = 1; i < size; i++)
	{
		//struct imginfo ii 获取 name;
		//ii.name = filenames[i];
		ii.name = filenames[i];
		//printf("load");
		//if (filenames[i].substr(0, 7) != filenames[i - 1].substr(0, 7))
		if (filenames[i].substr(3, 6) != filenames[i - 1].substr(3, 6))
		{
			label = label + 1;
		}
		fout2 <<ii.name << " " << label << endl;

		//////if (strcmp(ii.name.substr(7, 3).c_str(), "060") < 0){
		//	if (!strcmp(ii.name.substr(7, 3).c_str(), "001") || !strcmp(ii.name.substr(7, 3).c_str(), "002"))
		//	{
		//		fout2 << ii.name << " " << label << endl;
		//	}
		//	else
		//	{
		//		fout << ii.name << " " << label << endl;
		//	}
		//////}
		
		

		//char c = filenames[i][30];
		//if(c - '0'==1){
		//	//fout<<"Accessory\\"<<ii.name<<' '<<filenames[i].substr(5,4)<<endl;
		//	fout2<<ii.name<<endl;
		//}else{
		//	fout<<ii.name<<endl;
		//}

	}
}






