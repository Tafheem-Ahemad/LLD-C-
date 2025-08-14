#include "CSVFile.hpp"


CSVFile(const string &name,const User* creator,const FileServiceNode* parent = nullptr):
	File(name, creator, parent), type("csv") {
	// Additional initialization if needed
}
~CSVFile();


void readFile(){
	// Implementation for reading CSV file
	cout << "Reading CSV file: " << getName() << endl;
}
void WriteFile(){
	// Implementation for writing to CSV file
	cout << "Writing to CSV file: " << getName() << endl;
}