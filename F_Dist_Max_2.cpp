/*
author:Karan
created:21.08.2021 18:55:37
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool comparator(pair<int,int> &a, pair<int,int> &b) {
    int first=min(1e9-a.first,1e9-a.second);
    return min(a.first-b.first,a.second-b.second);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
}