#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        if(n==1) {
            cout<<"0"<<endl;
        }
        else if(n==2) {
            cout<<"1"<<endl;
        }
        else if(n==3) {
            cout<<"2"<<endl;
        }
        else {
            if(n%2) {
                cout<<"3"<<endl;
            }
            else{
                cout<<"2"<<endl;
            }
        }
    }
}