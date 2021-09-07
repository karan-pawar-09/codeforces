#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        bool answer=true;
        if(n>62) {
            answer=false;
        }
        else {
            for(ll i=0;i<n;i++) {
                for(ll j=i+1;j<n;j++) {
                    if(i!=j) {
                        if(((arr[i]|arr[j])==arr[i])||((arr[i]|arr[j])==arr[j])) {
                            answer=false;
                            break;
                        }
                    }
                }
            }
        }
        if(answer) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}