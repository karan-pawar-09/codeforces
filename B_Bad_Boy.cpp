/*
author:Karan
created:18.06.2021 20:21:30
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll n,m,i,j;
        cin>>n>>m>>i>>j;
        if(i==1&&j==1) {
            cout<<1<<" "<<m<<" "<<n<<" "<<1<<endl;
        }
        else {
            cout<<1<<" "<<1<<" "<<n<<" "<<m<<endl;
        }
    }  
}