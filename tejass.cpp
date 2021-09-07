/*
author:Karan
created:23.08.2021 17:29:06
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
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    set<int,greater<int>> s;
    for(int i=0;i<n;i++) {
        s.insert(arr[i]);
    }
    s.erase(*s.begin());
    if(s.size()) {
        cout<<*s.begin()<<endl;
    }
    else {
        cout<<INT_MIN<<endl;
    }
}