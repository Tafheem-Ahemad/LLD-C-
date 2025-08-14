#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "File.hpp"
#include "User.hpp"


class TextFile : : public File{
private:
	
public:
	TextFile(const string &name,const User* creator,const FileServiceNode* parent = nullptr);
	~TextFile();

	void readFile() override;
	void WriteFile() override;
};
