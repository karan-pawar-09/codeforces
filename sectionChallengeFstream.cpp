#include<bits/stdc++.h>
#include<fstream>
#include<iomanip>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fstream input;
    string correct;
    string name;
    string response;
    input.open("C:\\Users\\karan\\OneDrive\\Documents\\karan.txt");
    input>>correct;
    int total=0;
    int loop=0;
    cout<<setw(20)<<left<<"Name"<<setw(10)<<right<<"Score"<<endl;
    cout<<setw(30)<<setfill('-')<<""<<endl;
    cout<<setfill(' ');
    while(!input.eof()) {
        input>>name>>response;
        int score=0;
        for(int i=0;i<5;i++) {
            if(correct[i]==response[i]) {
                score++;
            }
        }
        total+=score;
        loop++;
        cout<<setw(20)<<left<<name<<setw(10)<<right<<score<<endl;
    }
    cout<<setw(30)<<setfill('-')<<""<<endl;
    cout<<setfill(' ');
    cout<<setw(20)<<left<<"Average Score"<<setw(10)<<right<<(double)total/loop<<endl;
    input.close();
    return 0;
}