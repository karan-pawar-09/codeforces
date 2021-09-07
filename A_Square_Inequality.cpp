#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c;
    cin>>a>>b>>c;
    if((a*a+b*b)<c*c) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}