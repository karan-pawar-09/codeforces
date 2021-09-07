/*
author:Karan
created:30.06.2021 18:14:46
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define init_zero(arr) for(int i=0;i<mx;i++) {for(int j=0;j<mx;j++) arr[i][j]=0}

const int mx= 137;
int arr[mx][mx];
int dist[mx];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    init_zero(arr);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        dist[i]=(ll)1e18+7;
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    
}