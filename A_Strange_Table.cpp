#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll n,m,x;
        cin>>n>>m>>x;
        
        ll j=ceil((double)x/n);
        ll i=x-((j-1)*n);
        cout<<(((i-1)*m)+j)<<endl;
    }
}