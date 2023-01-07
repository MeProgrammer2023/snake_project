#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <windows.h>
#include <fstream>
using namespace std;


class Savefile{

    private:

    public:
        void write_to_file(string name,int bestscore);

    
};



void Savefile::write_to_file(string name,int bestscore){

ofstream myfile;

myfile.open ("scoreboard.txt", ios_base::app | ios_base::out);
myfile <<name<<" - "<<bestscore<<endl;
myfile.close();    


}










#endif 