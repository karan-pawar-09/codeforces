/*
    author:Karan
    created:26.02.2022 17:38:41
*/
#if true
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

ll counti(ll i,ll j,ll n,vector<string>&arr) {
    ll res=0;
    for(ll k=0;k<6;k++) {
        if(arr[i+k][j]=='#') {
            res++;
        }
    }
    return res;
}
ll countj(ll i,ll j,ll n,vector<string>&arr) {
    ll res=0;
    for(ll k=0;k<6;k++) {
        if(arr[i][j+k]=='#') {
            res++;
        }
    }
    return res;
}
ll countij(ll i,ll j,ll n,vector<string> &arr) {
    ll res=0;
    for(ll k=0;k<6;k++) {
        if(arr[i+k][j+k]=='#') {
            res++;
        }
    }
    return res;
}
ll countji(ll i,ll j, ll n, vector<string> &arr) {
    ll res=0;
    for(ll k=0;k<6;k++) {
        if(arr[i+k][j-k]=='#') {
            res++;
        }
    }
    return res;
}
void solve() {
    ll n;
    cin>>n;
    vector<string> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    if(n<6) {
        cout<<"No"<<endl;
        return;
    }
    bool ans=false;
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            ll cnt=0;


            if(((j+6)<=n)) {
                ll res=countj(i,j,n,arr);
                if(res>=4) {
                    ans=true;
                }
            }


            if(((i+6)<=n)) {
                ll res=counti(i,j,n,arr);
                if(res>=4) {
                    ans=true;
                }
            }


            if(((i+6)<=n) and ((j+6)<=n)) {
                ll res=countij(i,j,n,arr);
                cnt=max(res,cnt);
                if(res>=4) {
                    ans=true;
                }
            }

            if((i+6)<=n and (j)>=5) {
                ll res=countji(i,j,n,arr);
                if(res>=4) {
                    ans=true;
                }
            }


        }
    }
    ans?cout<<"Yes"<<endl:cout<<"No"<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}