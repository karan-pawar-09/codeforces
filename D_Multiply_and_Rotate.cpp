/*
    author:Karan
    created:15.01.2022 17:49:19
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

const ll mx=1e6+7;
const ll inf=1e18+7;
ll dp[mx];
ll ans,n,a;
bool visited[mx];
void leftrotate(string &s, ll d)
{
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
}
void rightrotate(string &s, ll d)
{
   leftrotate(s, s.length()-d);
}
void fun(ll k,ll val) {
    visited[k]=true;
    if(k<1) return;
    if(k==1) {
        ans=min(ans,val);
        return;
    }
    if(k%a==0) {
        fun(k/a,val+1);
    }
    string kk=to_string(k);
    
    if(kk[kk.size()-1]!='0') {
        string p=kk;
        ll vl=1;
        leftrotate(p,1);
        while(p!=kk and p[0]!='0') {
            if(!visited[stoll(p)]) {
                fun(stoll(p),val+vl);
            }
            if(p[p.size()-1]!='0') {
                leftrotate(p,1);
                vl++;
            }
        }
    }
}
void solve() {
    cin>>a>>n;
    for(ll i=0;i<mx;i++) {
        visited[i]=false;
    }
    ans=inf;
    fun(n,0);
    if(ans==inf) cout<<-1<<endl;
    else cout<<ans<<endl;
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