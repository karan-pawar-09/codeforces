/*
author:Karan
created:27.08.2021 12:00:24
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int ceil(int a,int b) {
    return (a+b-1)/b;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int l,r;
        cin>>l>>r;
        int b=max(ceil(r,2),l);
        int a;
        a=min(2*b-1,r);
        cout<<a%b<<endl;
    }
}