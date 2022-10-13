#include<iostream>
using namespace std;
int main() {
    string str;
    cin>>str;
    int x1=0, x2=0;
    for(int i=0;i<str.size();i++) {
        if(str[i] == 'N') {
            x1++;
        } else if(str[i] == 'S') {
            x1--;
        } else if(str[i] == 'E') {
            x2++;
        } else {
            x2--;
        }
    }
    cout<<x1<<","<<x2;
}