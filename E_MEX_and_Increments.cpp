/*
    author:Karan
    created:20.12.2021 21:56:33
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

const ll inf=1e18+7;

void solve() {
    ll n;
    cin>>n;
    vector<ll> arr(n);
    vector<ll> freq(n+1,0);
    multiset<ll> s;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        freq[arr[i]]++;
    }
    ll res=0;
    ll i=0;
    ll p=0;
    bool first=true;
    bool conti=true;
    s.insert(inf);
    for(i;i<=n and conti;i++) {
        if(res<i) {
            cout<<-1<<" ";
            conti=false;
            break;
        }
        if(freq[i]==0) {
            if(first) {
                first=false;
                cout<<p+freq[i]<<" ";
                ll no=*s.lower_bound(-(i));
                no=-no;
                {
                    p+=(i-no);
                    if(no==-inf) {
                        conti=false;
                        break;
                    }
                    s.erase(s.find(-no));
                }
            } else {
                if(s.size()<1) {
                    conti=false;
                    // cout<<-1<<" ";
                    break;
                } else {
                    ll no=*s.lower_bound(-(i));
                    no=-no;
                    {
                        cout<<p+freq[i]<<" ";
                        if(no==-inf) {
                            conti=false;
                            break;
                        }
                        s.erase(s.find(-no));                        
                        p+=(i-no);
                    }
                }
                
            }
        } else {
            cout<<p+freq[i]<<" ";
            for(int k=0;k<freq[i]-1;k++) {
                s.insert(-i);
            }
            res+=freq[i];
        }
    }
    for(i;i<n;i++) {
        cout<<-1<<" ";
    }
    cout<<endl;
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