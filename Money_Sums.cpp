/*
author:Karan
created:30.05.2021 13:16:08
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
    vector<int> arr(n);
    int sum=0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        sum+=arr[i];
    }
    vector<bool> isPossible(sum+1,false);
    isPossible[0]=true;
    for(int i=0;i<n;i++) {
        for(int j=sum;j>=0;j--) {
            if(j>=arr[i]) {
                isPossible[j]=isPossible[j]|isPossible[j-arr[i]];
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=sum;i++) {
        if(isPossible[i]) cnt++;
    }
    cout<<cnt<<endl;
    for(int i=1;i<=sum;i++) {
        if(isPossible[i]) cout<<i<<" ";
    }
    cout<<endl;
}