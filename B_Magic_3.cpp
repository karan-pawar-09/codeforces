#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,s,d;
    cin>>n>>s>>d;
    bool ans=false;
    for(int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        if(a<s&&b>d) {
            ans=true;
        }
    } 
    if(ans) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}