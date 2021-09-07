/*
author:Karan
created:19.06.2021 16:56:53
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mx=(ll)2e5+7;
vector<ll> grid[mx];
bool visited[mx];
ll value[mx];
ll required[mx];
bool arr[mx];

bool dfs(ll i,bool a) {
    visited[i]=true;
    arr[i]=a;
    for(ll p:grid[i]) {
        if(!visited[p]) {
            if(dfs(p,!a)==false) {
                return false;
            }
        }
        else {
            if(arr[i]==arr[p]) {
                return false;
            }
        }        
    }
    return true;
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        bool ans=true;
        ll n,m;
        cin>>n>>m;
        ll a,b;
        ll sum1=0;
        ll sum2=0;
        for(ll i=1;i<=n;i++) {
            grid[i].clear();
            visited[i]=false;
            cin>>value[i];
            sum1+=(ll)1e12;
            sum1=(sum1+value[i])%2;
        }
        for(ll i=1;i<=n;i++) {
            cin>>required[i];
            sum2+=(ll)1e12;
            sum2=(sum2+required[i])%2;
            value[i]-=required[i];
        }
        while(m--) {
            cin>>a>>b;
            grid[a].push_back(b);
            grid[b].push_back(a);
        }
        if(sum1 != sum2){
		   cout<<"NO"<<endl;
		   continue;
		 }
        bool isBipartite=dfs(1,true); 
        if(isBipartite) {
            ll s1=0;
            ll s2=0;
            for(ll i=1;i<=n;i++) {
                if(arr[i]) s1+=value[i];
                else s2+=value[i];
            }       
            if(s1==s2) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }
    }   
}