#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main() {
    ifstream infile;
    string line;
    int rnum;
    double cpi;
    infile.open("C:\\Users\\karan\\OneDrive\\Documents\\karan.txt");
    if(!infile) {
        cerr<<"Problem Openeng File"<<endl;
        return 1;
    }
    //cout<<"File is good to go"<<endl;
    while(!infile.eof()) {
        infile>>line>>rnum>>cpi;
        cout<<setw(10)<<left<<line<<setw(10)<<rnum<<setw(10)<<cpi<<endl;
    }    
    infile.close();
    return 0;
}