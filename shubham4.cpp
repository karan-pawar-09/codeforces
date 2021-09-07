/*
author:Karan
created:13.06.2021 18:19:16
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n;
        vector<string> arr;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            set<char> s;
            for(int j=0;j<arr[i].size();j++) {
                s.insert(arr[i][j]);
            }
            arr[i].clear();
            for(auto x:s) {
                arr[i].push_back(x);
            }
            sort(all(arr[i]));
        }
        map<string,
    }
}