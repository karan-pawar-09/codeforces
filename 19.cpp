#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>> t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int i=0;
        while(a%b!=0){
            a++;
            i++;
        }
        cout<<i<<endl;
    }
}
