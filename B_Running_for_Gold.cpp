/*
author:Karan
created:27.07.2021 21:20:17
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool comperator(vector<pair<int,int>> arr,vector<pair<int,int>> ar) {
    int no=0;
    int nn=0;
    for(int i=0;i<5;i++) {
        if(arr[i].first>ar[i].first) {
            no++;
        }
        else {
            nn++;
        }
    }
    return no>nn;
}
bool isGood(vector<pair<int,int>> arr,vector<pair<int,int>> ar) {
    int no=0;
    for(int i=0;i<5;i++) {
        if(arr[i].first>ar[i].first) {
            no++;
        }
    }
    return no>=3;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<pair<int,int>>> arr(n,vector<pair<int,int>> (5));
        for(int i=0;i<n;i++) {
            for(int j=0;j<5;j++) {
                cin>>arr[i][j].first;
                arr[i][j].first*=-1;
                arr[i][j].second=i;
            }
        }
        sort(all(arr),comperator);
        bool ans=true;
        for(int i=1;i<n;i++) {
            if(!isGood(arr[0],arr[i])) {
                ans=false;
                break;
            }
        }
        if(ans)
            cout<<arr[0][0].second+1<<endl;
        else cout<<-1<<endl;
    }
}