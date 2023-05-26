/*
    author:Karan
    created:25.05.2023 21:29:46
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

//constants
const ll mod = 998244353;
const ll mx = (1e6+10);
ll fact[mx];

ll mul(ll a, ll b) {
    return ((a%mod)*(b%mod))%mod;
}
ll mul(ll a, ll b, ll c) {
    return (mul(a, b)%mod * c%mod)%mod;
}

bool isGood(ll a, ll b, ll n) {
    if(a == -1 || b == -1) {
        return true;
    }
    bool ab = false;
    bool bb = false;
    if(a <= n/2) {
        ab = true;
    }
    if(b <= n/2) {
        bb = true;
    }
    return (ab != bb);
}

vector<ll> makeArray(vector<ll> &arr) {
    ll n = arr.size()/2;
    vector<ll> ar;
    for(ll i=0;i<arr.size();i+=2) {
        if(arr[i] != -1 && arr[i+1] != -1) {
            ar.push_back(min(arr[i], arr[i+1]));
        } else if(arr[i] != -1 || arr[i+1] != -1) {
            ll p;
            if(arr[i] != -1) {
                p = arr[i];
            } else {
                p = arr[i+1];
            }
            if(p <= arr.size()/2) {
                ar.push_back(p);
            } else {
                ar.push_back(-1);
            }
        } else {
            ar.push_back(-1);
        }
    }
    return ar;
}

ll fun(vector<ll> &arr) {
    if(((ll) arr.size()) == 1) {
        if((arr[0] == 1) || (arr[0] == -1)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    // To multiply in final ans
    ll interchange = 1;
    for(ll i=0;i<arr.size();i+=2) {
        if((arr[i] == -1) && (arr[i+1] == -1)) {
            interchange = mul(interchange, 2);
        }
        if(isGood(arr[i], arr[i+1], arr.size())) {

        } else {
            return 0;
        }
    }
    vector<ll> ar = makeArray(arr);
    // To multiply in final ans
    ll val = fun(ar);
    // To multiply fact[countlose] in final ans
    ll countlose = arr.size()/2;
    for(ll i=0;i<arr.size();i++) {
        if(arr[i] > (ll)(arr.size()/2)) {
            countlose --;
        }
    }
    return mul(fact[countlose],  val,  interchange);
}

void solve() {
    ll k;
    cin >> k;
    ll n = 1 << k;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<fun(arr)<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    fact[0] = 1;
    fact[1] = 1;
    for(ll i=2;i<mx;i++) {
        fact[i] = mul(i, fact[i-1]);
    }
    ll t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}