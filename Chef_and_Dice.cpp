#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        ll length=n/4;
        ll remainder=n%4;

        if(length==0) {
            if(remainder==0) {
                cout<<0<<endl;
            }
            else if(remainder==1) {
                cout<<20<<endl;
            }
            else if(remainder==2) {
                cout<<36<<endl;
            }
            else {
                cout<<36+15<<endl;
            }
        }
        else {
            if(remainder==0) {
                cout<<44*length+4*4<<endl;
            }
            else if(remainder==1) {
                ll a=44*length;
                cout<<a+20+12<<endl;
            }
            else if(remainder==2) {
                ll a=44*length;
                cout<<a+36+8<<endl;
            }
            else {
                ll a=44*length;
                cout<<a+36+15+4<<endl;
            }
        }
    }
}