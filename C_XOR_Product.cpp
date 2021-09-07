#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll mod=(ll)1e9+7;
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int q;
    cin>>q;
    while(q--) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        if(b-a+1 > 200) {
            cout << 0 << '\n' ; 
        }
        else {
            int ans = 1 ; 
            for(int i= a ; i <= b ; ++i) {
                for(int j = i+1 ; j <= b ; ++j) {
                    ans = (ans * (arr[i] ^ arr[j])) % mod ; 
                }
            }
            cout << ans << endl;
        }
    }
}