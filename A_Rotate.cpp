#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    ll sum=0;
    for(ll i=0;i<s.size();i++) {
        ll p=s[i]-'0';
        sum+=p*100+p*10+p;
    }  
    cout<<sum<<endl;
}