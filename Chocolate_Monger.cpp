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
        int x,n;
        cin>>n>>x;
        vector<ll> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        set<ll> s;
        for(int i=0;i<n;i++) {
            s.insert(arr[i]);
        }
        ll diff=(ll)s.size();
        if((n-diff)>=x) {
            cout<<diff<<endl;
        }
        else {
            cout<<n-x<<endl;
        }
    }
}