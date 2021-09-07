#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll> a(51,-1);
    for(int i=0;i<n;i++) {
        if(a[arr[i]]==-1) {
            a[arr[i]]=i+1;
        }
    }
    for(int i=0;i<q;i++) {
        int t;
        cin>>t;
        cout<<a[t]<<" ";
        for(int i=0;i<51;i++) {
            if(a[i]!=-1) {
                if(a[i]<a[t]) {
                    a[i]++;
                }
                else {
                    
                }
            }
        }
        a[t]=1;
    }
    cout<<endl;
}