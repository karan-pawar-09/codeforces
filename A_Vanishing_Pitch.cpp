#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v,t,s,d;
    cin>>v>>t>>s>>d;
    if(d>=v*t&&d<=v*s) {
        cout<<"No"<<endl;
    }
    else {
        cout<<"Yes"<<endl;
    }
}