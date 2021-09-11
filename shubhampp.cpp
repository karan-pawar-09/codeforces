/*
    author:Karan
    created:11.09.2021 10:40:57
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool comp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b) {
    return((a.second.first*b.second.second)>(b.second.first*a.second.second));
}
void solve() {
    int n;
    cin>>n;
    vector<int> cost(n),nutrients(n),min_quantity(n),max_quantity(n);
    int m;
    for(int i=0;i<n;i++) cin>>cost[i];
    cin>>n;
    for(int i=0;i<n;i++) cin>>nutrients[i];
    cin>>n;
    for(int i=0;i<n;i++) cin>>min_quantity[i];
    cin>>n;
    for(int i=0;i<n;i++) cin>>max_quantity[i];
    cin>>m;
    int money=0;
    int ans=0;
    for(int i=0;i<n;i++) {
        money+=min_quantity[i]*cost[i];
        ans+=nutrients[i]*min_quantity[i];
        max_quantity[i]-=min_quantity[i];
    }
    vector<pair<int,pair<int,int>>> arr(n);
    for(int i=0;i<n;i++) {
        arr[i].first=max_quantity[i];
        arr[i].second.first=nutrients[i];
        arr[i].second.second=cost[i];
    }
    sort(all(arr),comp);
    int mon=m-money;
    for(int i=0;i<n && mon>0;i++) {
        int temp=mon/arr[i].second.second;
        temp=min(temp,arr[i].first);
        mon-=temp*arr[i].second.second;
        ans+=temp*arr[i].second.first;
    }
    if(mon<0) {
        cout<<0<<endl;
    }
    else
        cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);    
    solve();    
}