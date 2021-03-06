#include <fstream>
#include <iostream>
#include <string>
#include "../header/FileIO.hpp"

using namespace std;

//declare static var
vector<DATATYPE> FileIO::allData;
FileIO* FileIO::FileIOInstance = nullptr;
FileIO::FileIO()
{
}
FileIO* FileIO::GetInstance()
{
    if (FileIOInstance == nullptr)
        FileIOInstance = new FileIO();
    return FileIOInstance;
}

void FileIO::writeToFile(std::string writeFileName)
{
    ofstream  out;
    out.open(writeFileName.c_str(), ios::out); 
    if (out.is_open())
    {
        for (int i = 0;i< allData.size(); i++)
        {
            out << allData[i] << endl;   
        }
    }
    out.close();
}

DATATYPE FileIO::showAllData()
{
    string output = "";

    for (int i = 0; i < allData.size(); i++)
    {
        output+= allData[i] + "\n";   
    }
    return output;
}

void FileIO::addData(DATATYPE data)
{
    allData.push_back(data);
}

DATATYPE FileIO::getData(int size)
{
    return allData[size];
}

void FileIO::readFromFile(std::string readFileName)
{
    allData.clear();
    ifstream in;
    in.open(readFileName.c_str(), ios::in);
    if (in.is_open())
    {
        while(!in.eof())
        {
            DATATYPE midata;
            in >> midata;      
            if (in.eof())
            {
                break;
            }
            allData.push_back(midata);
        }
    }
    in.close();
}

FileIO::unloader::~unloader()
{
    if (FileIOInstance != nullptr)
    {
        delete FileIO::FileIOInstance;
    }
}
