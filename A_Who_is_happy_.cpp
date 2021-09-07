//1912134 Karan
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        string s;
        int a=0;
        int b=0;
        cin>>n>>s;
        for(int i=0;i<n;i++) {
            if(s[i]=='A') {
                a++;
            }
            if(s[i]=='B') {
                b++;
            }
        }
        if(a>b) {
            cout<<"Anirban"<<endl;
        }
        else if(b>a) {
            cout<<"Biswa"<<endl;
        }
        else {
            cout<<"Samay"<<endl;
        }
    }
}