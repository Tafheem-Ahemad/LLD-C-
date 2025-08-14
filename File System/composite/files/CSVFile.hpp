#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "File.hpp"
#include "User.hpp"
#include "FileServiceNode.hpp"

class CSVFile:public File{
private:
	/* data */
	const string type;
public:
	CSVFile(const string &name,const User* creator,const FileServiceNode* parent = nullptr);
	~CSVFile();

	void readFile() override;
	void WriteFile() override;
};
