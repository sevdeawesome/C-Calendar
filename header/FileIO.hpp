#pragma once
#include <string>
#include <vector>

#define DATATYPE int   //any datatype

class FileIO {
private:
	static FileIO* FileIOInstance;   //instance pointer
	static std::vector<DATATYPE> allData;   //var for saving data
	FileIO(); //cons
	
private:
	class unloader {
	public:
		~unloader();
	};
	static unloader aUnloader;
public:
	static FileIO* GetInstance();  //gets instance
	void writeToFile(std::string writeFileName);  //save data to file
	string showAllData(); //show
	void addData(DATATYPE data); //adding entry
	DATATYPE getData(int size);  //get specific data from arr
	void readFromFile(std::string readFileName);  //read data from file
};