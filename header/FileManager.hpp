#include <iostream>
#include <fstream>

using namespace std;


struct WriteInterface {
    virtual void writeToFile(ofstream& output) const = 0;
};


struct ReadInterface {
    virtual void readToFile(ifstream& input) = 0;
};
 
class FileManager
{
public:
    //singleton
    static FileManager& Instance() {
        static FileManager manager;
        return manager;
    }


    void writeToFile(WriteInterface& data) {
        ofstream output("data.txt");
        if (output) {
            data.writeToFile(output);
        }
    }

    void readFromFile(ReadInterface& data) {
        ifstream input("data.txt");
        if (input) {
            data.readToFile(input);
        }
    }

private:
    //contruct functions to make sure it is singleton.
    FileManager() {

    }
    ~FileManager() {

    }
};
