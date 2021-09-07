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
        long double k1,k2,k3,v;
        cin>>k1>>k2>>k3>>v;
        long double velocity=k1*k2*k3*v;
        long double dist= 100;
        long double time = dist/velocity;
        time = round( time * 100.0 ) / 100.0;
        long double record=9.58;
        record = round(record * 100.0 ) / 100.0;
        if(time<record) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }    
}