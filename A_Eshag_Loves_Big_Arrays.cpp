/*
author:Karan
created:24.05.2021 20:06:20
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        vector<int> freq(101,0);
        for(int i=0;i<n;i++) {
            freq[arr[i]]++;
        }
        int k=*min_element(all(arr));
        cout<<n-freq[k]<<endl;
    }
}