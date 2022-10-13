/*
    author:Karan
    created:14.06.2022 22:04:46
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


ll power(long long x, unsigned ll y) {
    ll res = 1; 
    x = x;   
    if (x == 0) return 0;  
    while (y > 0) {        
        if (y & 1)
            res = (res*x); 
        y = y>>1;
        x = (x*x);
    }
    return res;
}
ll po[40];
map<int,int> M;
bool isGood(ll a, ll b, vector<ll>& arr) {
    if((arr[b]*po[b-a])>arr[a]) return true; 
    else return false;
}
int binarysearch(vector<int> zeros, int x) {
    int r=zeros.size()-1;
    int l=-1;
    while(l+1<r) {
        int m=(l+r)/2;
        if(zeros[m]>=x) {
            r=m;
        } else {
            l=m;
        }
    }
    return zeros[r];
}
void solve() {
    ll n,k;
    cin>>n>>k;
    M.clear();
    vector<ll> arr(n);
    vector<int> zeros;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i]==0) {
            zeros.push_back(i);
        }
    }
    zeros.push_back(1e9);
    ll ans=0;
    vector<bool> dp(n+10,false);
    
    for(ll i=0;i<(n-k);i++) {
        bool temp=true;
        if(i>0 && dp[i-1]) {
            if(isGood(i,i+k,arr) && ((arr[i+k]*2) > arr[i+k-1])) {

            } else {
                temp=false;
            }
        } else {
            for(ll j=i+1;j<=i+k;j++) {
                
                if((arr[j]*2)<=(arr[j-1])) {
                    temp=false;
                    i=j-1;
                    break;
                }
                if((j-i) <=30) {
                    if(isGood(i,j,arr)) {
                
                    } else {
                        temp=false;
                        break;
                    }
                }
            }
        }
        if(temp) {
            dp[i]=true;
            ans++;
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    po[0]=1;
    for(ll i=1;i<40;i++) {
        po[i]=po[i-1]*2ll;
    }
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}