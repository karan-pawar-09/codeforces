/*
author:Karan
created:14.06.2021 13:38:30
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
    int h,w,n;
    cin>>h>>w>>n;
    vector<vector<int>> arr(h,vector<int> (w));
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            cin>>arr[i][j];
        }
    }   
    
}