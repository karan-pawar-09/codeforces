/*
author:Karan
created:29.08.2021 16:22:46
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> a(n),b(n);
        for(ll i=0;i<n;i++) {
            cin>>a[i];
        }
        for(ll i=0;i<n;i++) {
            cin>>b[i];
        }
        int cnt=0;
        int ans=0;
        vector<int> ar(n, -1);
        for(int i = 30; i >= 0; i--) {
            int isGood = 1;
            for(int j = 0; j < n; j++) {
                if(ar[j] != -1) {
                    if(ar[j] == 1) isGood = ((isGood&(b[j]>>i)&1));
                    else isGood = ((isGood&(a[j]>>i)&1));
                    continue;
                }
                if(((a[j]>>i)&1) || ((b[j]>>i)&1)) {
                    
                }
                else {
                    isGood = 0;
                    break;
                }
            }
            if(!isGood)
                continue;
            int price = 1;
            for(int j = 0; j < n; j++) {
            if(ar[j] != -1) {
                if(ar[j] == 1) price = ((price&(b[j]>>i)&1));
                else price = ((price&(a[j]>>i)&1));
                continue;
            }
            if(((a[j]>>i)&1) && ((b[j]>>i)&1)) {}
            else if(((a[j]>>i)&1)) ar[j] = 0;
            else if(((b[j]>>i)&1)) ar[j] = 1, cnt++;
            else {
                price = 0;
                break;
            }
            }
            ans += (price * (1ll<<i));
        }
        cout << ans << " " << cnt << '\n';

    }
}