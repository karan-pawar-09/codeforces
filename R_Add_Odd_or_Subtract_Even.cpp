#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll a,b;
        cin>>a>>b;
        if(a==b) {
            cout<<"0"<<endl;
        }
        else if(b>a) {
            if((b-a)%2) {
                cout<<"1"<<endl;
            }
            else{
                cout<<"2"<<endl;
            }
        }
        else{
            if((a-b)%2) {
                cout<<"2"<<endl;
            }
            else {
                cout<<"1"<<endl;
            }
        }
    }
}