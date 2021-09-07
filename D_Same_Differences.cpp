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
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            arr[i]-=i;
        }
        arr.push_back(-1*(ll)1e6);
        arr.push_back((ll)1e6);
        sort(all(arr));
        n+=2;
        ll ans=0;
        ll k=0;
        for(int i=1;i<n;i++) {
            if(arr[i]==arr[i-1]) {
                ans++;
            }
            else{
                if(ans>0) {
                    ans++;
                    k+=(ans*(ans-1))/2;
                } 
                ans=0;
            }
        }
            
        cout<<k<<endl;
    }
}