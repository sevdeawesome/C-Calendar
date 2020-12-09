#include <iostream>
#include <string>
#include "FileIO.h"

using namespace std;

int main()
{
	FileIO::GetInstance()->readFromFile("readFile.txt");
	cout << FileIO::GetInstance()->showAllData() << endl;
	FileIO::GetInstance()->addData(6);
	FileIO::GetInstance()->addData(7);
	cout << FileIO::GetInstance()->getData(2) << endl;
	FileIO::GetInstance()->writeToFile("writeFile.txt");
	return 0;
}