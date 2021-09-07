/*
author:Karan
created:02.06.2021 17:48:08
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    string dynasty;
    string prev=arr[0];
    int ans=0;
    vector<vector<int>> dp(26,vector<int> (26,0));
    
}