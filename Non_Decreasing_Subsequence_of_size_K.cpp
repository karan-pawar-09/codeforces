/*
    author:Karan
    created:21.11.2021 22:00:46
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(all(arr));
    ll res=1;
    ll len=1;
    for(ll i=1;i<n;i++) {
        if(arr[i]==arr[i-1]) {
            res++;
        } else {
            res=1;
        }
        len=max(len,res);
    }
  {
        if(k==1) {
            if(len==1) {
                for(ll i=n-1;i>=0;i--) {
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            } else  {
                cout<<-1<<endl;
            }
        }
        else {
            bool can=true;
            for(ll i=1;i<=n;i++) {
                if(i%k==0) {
                    ll j=i+1;
                    while(j<=n) {
                        if(arr[j-1]>arr[i-1]) {
                            break;
                        }
                        j++;
                    }
                    if(j<=n) {
                        swap(arr[i-1],arr[j-1]);
                    } else {
                        if(i!=(n)) {
                            can=false;
                            break;
                        }
                    }
                }
            }
            if(can) {
                for(ll i=0;i<n;i++) {
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            } else {
                cout<<-1<<endl;
            }
        }

    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}