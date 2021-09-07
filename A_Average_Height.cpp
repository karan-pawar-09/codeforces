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
        vector<ll> arr(n);
        vector<ll> odd;
        vector<ll> even;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i]%2) {
                odd.push_back(arr[i]);
            }
            else {
                even.push_back(arr[i]);
            }
        }
        for(int i=0;i<odd.size();i++) {
            cout<<odd[i]<<" ";
        }
        for(int i=0;i<even.size();i++) {
            cout<<even[i]<<" ";
        }
        cout<<endl;
    }
}