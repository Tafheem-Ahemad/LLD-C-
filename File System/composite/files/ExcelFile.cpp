#include "ExcelFile.hpp"

ExcelFile::ExcelFile(const string &name,const User* creator,const FileServiceNode* parent = nullptr):
File(name, creator, parent) , type("excel") {
	// Additional initialization if needed
}
ExcelFile::~ExcelFile();

void ExcelFile::readFile(){
	// Implementation for reading Excel file
	cout << "Reading Excel file: " << getName() << endl;
}
void ExcelFile::WriteFile(){
	// Implementation for writing to Excel file
	cout << "Writing to Excel file: " << getName() << endl;
}