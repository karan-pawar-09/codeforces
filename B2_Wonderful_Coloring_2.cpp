/*
author:Karan
created:23.07.2021 20:19:46
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        vector<int> count(n+1,0);
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            count[arr[i]]++;
            if(count[arr[i]]<=k) {
                v.push_back({arr[i],i});
            }
        }
        sort(all(v));
        v.resize(v.size()-(v.size()%k));
        for(int i=0;i<n;i++) {
            arr[i]=0;
        }
        for(int i=0;i<v.size();i++) {
            arr[v[i].second]=((i)%(k))+1;
        }
        for(int i=0;i<n;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
 }