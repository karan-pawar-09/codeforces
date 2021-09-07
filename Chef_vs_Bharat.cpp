/*
author:Karan
created:07.07.2021 11:23:47
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
const ll mod=(ll)1e9+7;
const ll mx=1e5+7;

ll power(long long x, unsigned ll y) {
    ll res = 1; 
    x = x ;   
    if (x == 0) return 0;  
    while (y > 0) {        
        if (y & 1)
            res = (res*x); 
        y = y>>1;
        x = (x*x);
    }
    return res;
}

bool isnextsize(string s) {
    for(ll i=0;i<s.size();i++) {
        if(s[i]!='9') return false;
    }
    return true;
}

ll powerMD(long long x, unsigned ll y, ll mod) {
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
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    vector<ll> digit(18,0);
    digit[1]=9;
    for(ll i=3;i<18;i+=2) {
        digit[i]=power(9,i/2)*10;
        digit[i]+=digit[i-2];
    }
    vector<ll> A(mx,0);
    for(ll i=1;i<10;i++) {
        A[i]=i;
    }
    for(ll i=10;i<mx;i++) {
        string s=to_string(A[i-1]);
        bool upgrade=isnextsize(s);
        ll size=s.size();
        ll no=1;
        if(upgrade) {
            string str;
            str.push_back('1');
            for(ll j=0;j<size;j++) {
                str.push_back('0');
            }
            str.push_back('1');
            A[i]=stoll(str);
        }
        else {
            string str=s;
            ll n=s.size();
            for(ll j=(n/2);j>=0;j--) {
                if(s[j]!='9') {
                    str[j]=s[j]+1;
                    if(j!=(n/2)) str[n-1-j]=s[j]+1;
                    break;
                }
                else {
                    str[j]='0';
                    if(j!=(n/2)) str[n-1-j]='0';
                }
            }
            A[i]=stoll(str);
        }
    }
    vector<ll> Asum(mx,0);
    Asum[0]=0;
    for(ll i=1;i<mx;i++) {
        Asum[i]=Asum[i-1]+A[i];
    }
    ll q,l,r;
    cin>>q;
    while(q--) {
        cin>>l>>r;
        ll base=A[l];
        ll power=Asum[r]-Asum[l];
        ll ans=powerMD(base,power,mod);
        cout<<ans<<endl;
    }
}