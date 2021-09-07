/*
author:Karan
created:24.08.2021 20:06:22
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool sorted(vector<int> &arr) {
    bool ans=true;
    for(int i=1;i<arr.size();i++) {
        if(arr[i]<arr[i-1]) {
            ans=false;
            break;
        }
    }
    return ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int k=0;
        int ans=0;
        bool tr=true;
        if(sorted(arr)) {
            tr=false;
        }
        while(tr) {
            if(k%2==0) {
                for(int i=0;i<n-1;i+=2) {
                    if(arr[i]>arr[i+1]) {
                        swap(arr[i],arr[i+1]);
                    }
                }
            }
            else {
                for(int i=1;i<n-1;i+=2) {
                    if(arr[i]>arr[i+1]) {
                        swap(arr[i],arr[i+1]);
                    }
                }
            }
            k++;
            if(sorted(arr)) {
                break;
            }
            
        }
        cout<<k<<endl;
    }
}