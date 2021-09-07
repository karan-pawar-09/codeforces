/*
author:Karan
created:27.08.2021 18:11:57
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int ceil(int a,int b) {
    return (a+b-1)/b;
}

int minTime(vector<int> &batchSize,vector<int> &processingTime,vector<int> &numTasks) {
    long ans=0;
    int n=batchSize.size();
    for(int i=0;i<n;i++) {
        ans=max(ans,(long)(ceil(numTasks[i],batchSize[i])*processingTime[i]));
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> a(n),b(n),c(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    for(int i=0;i<n;i++) {
        cin>>c[i];
    }
    cout<<minTime(a,b,c)<<endl;
}