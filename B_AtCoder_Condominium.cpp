/*
author:Karan
created:30.05.2021 20:18:21
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=k;j++) {
            ans+=i*100+j;
        }
    }
    cout<<ans<<endl;
}