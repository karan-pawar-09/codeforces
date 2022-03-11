/*
    author:Karan
    created:08.03.2022 12:57:24
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

const ll mod=(ll)1e9+7;

ll power(long long x, unsigned ll y, ll mod) {
    ll res = 1; 
    x = x % mod;   
    if (x == 0) return 0;  
    while (y > 0) {        
        if (y & 1)
            res = (res*x) % mod; 
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}

ll modInv(ll a,ll mod) {
    return power(a,mod-2,mod) % mod ;
}

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int ans=(n)*(n-1);
    int res=0;
    ll xx=1<<30;
    xx-=1;
    vector<bool> used(n+1,false);
    for(int i=29;i>=0;i--) {
        int p=(1<<(i+1))-1;
        int count=0;
        int cnt=0;
        int q=xx^p;
        for(int j=0;j<n;j++) {
            int x=arr[j];
            
                if((x&q)==0) {
                    if(!used[j]) {
                        if(x&(1<<i)) {
                            count++;
                            used[j]=true;
                        }
                    }
                }
                else if(x&q) {
                    if(x&(1<<i)) {
                        cnt++;
                    }
                }
        
        }
        res+=count*(count+cnt-1);
        res+=cnt*(count-1);
    }
    ans-=res;
    ans+=mod;
    ans%=mod;
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}