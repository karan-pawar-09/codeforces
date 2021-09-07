/*
author:Karan
created:30.06.2021 18:21:31
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll n,m;
const ll mx=507;
const ll inf=(ll)1e17+7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout)
    ll n,m,q;
    cin>>n>>m>>q;
    ll arr[mx][mx];
    for(ll i=0;i<mx;i++) {
        for(ll j=0;j<mx;j++) {
            arr[i][j]=inf;
        }
    }
    for(int i=0;i<mx;i++) {
        arr[i][i]=0;
    }
    for(ll i=0;i<m;i++) {
        ll a,b,c;
        cin>>a>>b>>c;
        arr[a][b]=min(arr[a][b],c);
        arr[b][a]=min(arr[b][a],c);
    }
    for(ll i=0;i<=n;i++) {
        for(ll j=0;j<=n;j++) {
            for(ll k=0;k<=n;k++) {
                arr[j][k]=min(arr[j][k],arr[j][i]+arr[i][k]);
            }
        }
    } 
    while(q--) {
        ll a,b;
        cin>>a>>b;
        if(arr[a][b]==inf) cout<<-1<<endl;
        else cout<<arr[a][b]<<endl;
    }
}