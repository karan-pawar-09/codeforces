#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b||b==c||a==c) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}