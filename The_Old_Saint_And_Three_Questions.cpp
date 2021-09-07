/*
author:Karan
created:02.09.2021 20:00:34
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    vector<int> ar(3),arr(3);
    int first=0;
    int second=0;
    for(int i=0;i<3;i++) {
        cin>>ar[i];
        if(ar[i]==1) {
            first++;
        }
    }
    for(int i=0;i<3;i++) {
        cin>>arr[i];
        if(arr[i]==1) {
            second++;
        }
    }
    if(first==second) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail"<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}