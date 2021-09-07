#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n,x;
        cin>>n>>x;
        vector<ll> arr(n);
        int negative=0;
        for(int i=0;i<n;i++) { 
            cin>>arr[i];
            if(arr[i]<0) negative++;
        }
        sort(arr.begin(),arr.end());
        if(negative<x) {
            for(int i=0;i<negative;i++) {
                arr[i]=-arr[i];
            }
            sort(arr.begin(),arr.end());
            for(int i=0;i<x-negative;i++) {
                arr[0]=-arr[0];
            }
        }
        else {
            for(int i=0;i<x;i++) {
                arr[i]=-arr[i];
            } 
        }
        ll sum=0;
        for(int i=0;i<n;i++) {
            sum+=arr[i];
        }
        cout<<sum<<endl;
    }
}