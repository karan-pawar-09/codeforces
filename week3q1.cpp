/*
authot:Karan
created:21.05.2021 14:57:44
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin>>m;
    int ans=0;   
    ans+=m/10;
    m%=10;
    ans+=m/5;
    m%=5;    
    ans+=m;
    cout<<ans<<endl;
}