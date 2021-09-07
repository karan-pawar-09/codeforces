/*
author:Karan
created:21.06.2021 15:31:57
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
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second;
    } 
    sort(all(arr));
    int current_date=0;
    for(int i=0;i<n;i++) {
        if(arr[i].second>=current_date) {
            current_date=arr[i].second;
        }
        else {
            current_date=arr[i].first;
        }
    }
    cout<<current_date<<endl;
}