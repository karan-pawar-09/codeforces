#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(v) v.begin(),v.end()
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        vector<ll> arr(n);
        vector<ll> pprice(m);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        for(int i=0;i<m;i++) {
            cin>>pprice[i];
        }
        sort(all(arr));
        int k=m;
        ll ans=0;
        int j=0;
        for(int i=n-1;i>=0;i--) {
            if(k) {
                if(j<arr[i]-1) { 
                    ans+=pprice[j];
                }
                else {
                    ans+=pprice[arr[i]-1];
                }
                k--;
                j++;
            }
            else {
                ans+=pprice[arr[i]-1];
            }
        }
        cout<<ans<<endl;
    }
}