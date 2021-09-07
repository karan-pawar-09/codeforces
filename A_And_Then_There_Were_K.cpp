/*
authot:Karan
created:20.05.2021 20:06:46
*/
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
        ll n;
        cin>>n;
        ll p=1;
        while(p<=n) {
            p*=2;
        }
        p/=2;
        cout<<p-1<<endl;
    }
        
}