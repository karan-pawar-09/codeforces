/*
author:Karan
created:25.07.2021 10:54:07
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
    
}
int ETF (int a) {
    int num=a;
    for(int i=2;i*i<=a;i++) {
        if(a%i==0) {
            while(a%i==0) {
                a/=i;
            }
            num-=num/i;
        }
    }
    if(a>1){
        num-=num/a;
    }
    return num;
}
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int n=(int)1e5;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
ll ncr(int n, int r) {
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}
ll modExp(ll a, ll p) {
    a %= M;
    ll res=1;
    while(p > 0) {
        if(p & 1) res = res * a % M;
        a = a * a % M;
        p >>= 1;
    }
    return res;
 }
 ll modInv(ll a) {
    return modExp(a,M-2) % M ;
 }
 bool pairSort(const pair<pair<int,int>,int> &a,const pair<pair<int,int>,int> &b) {
     return (a.first.second < b.first.second);
 }
 #define item long long
 // struct item {
 //     ll seg,pref,suf,sum;
 // };
 struct segtree {
     ll size;
     vector<item> items;
     item NEUTRAL_ELEMENT=(ll)INT_MIN;
     item merge(item a,item b) {
         return max(a,b);
     }
     item single(ll v) {
         return v;       
     }
     void init(ll n) {
         size=1;
         while(size<n) {
             size*=2;
         }
         items.resize(2*size);
     }
     void build(vector<ll> &a,ll x,ll lx,ll rx) {
         if(rx-lx==1) {
             if(lx<((ll)a.size())) {
                 items[x]=single(a[lx]);
             }
             return;
         }
         ll m=lx+(rx-lx)/2;
         build(a,2*x+1,lx,m);
         build(a,2*x+2,m,rx);
         items[x]=merge(items[2*x+1],items[2*x+2]);
     }
     void build(vector<ll> &a) {
         build(a,0,0,size);
     }
     void set(ll i,ll v,ll x,ll lx,ll rx) {
         if(rx-lx==1) {
             items[x]=single(v);
             return;
         }
         ll m=lx+(rx-lx)/2;
         if(i<m) {
             set(i,v,2*x+1,lx,m);
         }
         else {
             set(i,v,2*x+2,m,rx);
         }
         items[x]=merge(items[2*x+1],items[2*x+2]);
     }
     void set(ll i,ll v) {
         set(i,v,0,0,size);
     }
     item calc(ll l,ll r,ll x,ll lx,ll rx) {
         if(lx>=r|l>=rx) return NEUTRAL_ELEMENT;
         if(lx>=l&&rx<=r) return items[x];
         ll m=lx+(rx-lx)/2;
         item s1=calc(l,r,2*x+1,lx,m);
         item s2=calc(l,r,2*x+2,m,rx);
         return merge(s1,s2);
     }
     item calc(ll l,ll r) {
         return calc(l,r,0,0,size);
     }
     ll solve(ll k,ll lx, ll rx,ll root,ll l) {
         if(l>=rx) {
             return -1;
         }
         if(items[root]<k) {
             return -1;
         }
         if(rx-lx==1) {
             return lx;
         }
         ll m=lx+(rx-lx)/2;
         ll res=solve(k,lx,m,2*root+1,l);
         if(res==-1) {
             res=solve(k,m,rx,2*root+2,l);
         }
         return res;
     }
     ll solve(ll k,ll l) {
         return solve(k,0,size,0,l);
     }
 };


 ll find_set(ll v) {
     if (v == parent[v])
         return v;
     return parent[v] = find_set(parent[v]);
 }
 
 void make_set(ll v) {
     parent[v] = v;
     magnitude[v] = 1;
 }
 
 void union_sets(ll a, ll b) {
     a = find_set(a);
     b = find_set(b);
     if (a != b) {
         if (magnitude[a] < magnitude[b])
             swap(a, b);
         parent[b] = a;
         magnitude[a] += magnitude[b];
     }
 }

 (a+b-1)/b  //ceil

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

 void radix_sort(vector<pair<pair<int,int>,int>> &a) {
     int n=a.size();
     {
         vector<int> cnt(n);
         for(int i=0;i<n;i++) {
             cnt[a[i].first.second]++;
         }
         vector<pair<pair<int,int>,int>> a_new(n);
         vector<int>pos(n);
         pos[0]=0;
         for(int i=1;i<n;i++) {
             pos[i]=pos[i-1]+cnt[i-1];
         }
         for(int i=0;i<n;i++) {
             a_new[pos[a[i].first.second]]=a[i];
             pos[a[i].first.second]++;
         }
         a=a_new;
     }
     {
         vector<int> cnt(n);
         for(int i=0;i<n;i++) {
             cnt[a[i].first.first]++;
         }
         vector<pair<pair<int,int>,int>> a_new(n);
         vector<int>pos(n);
         pos[0]=0;
         for(int i=1;i<n;i++) {
             pos[i]=pos[i-1]+cnt[i-1];
         }
         for(int i=0;i<n;i++) {
             a_new[pos[a[i].first.first]]=a[i];
             pos[a[i].first.first]++;
         }
         a=a_new;
     }
 }
 int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     string s;
     cin>>s;
     s+="$";
     int n=s.size();
     vector<int> p(n),c(n);
     {
         vector<pair<char,int>> a(n);
         for(int i=0;i<n;i++) {
             a[i]={s[i],i};
         }
         sort(all(a));
         for(int i=0;i<n;i++) {
             p[i]=a[i].second;
         }
         c[p[0]]=0;
         for(int i=1;i<n;i++) {
             if(a[i].first==a[i-1].first) {
                 c[p[i]]=c[p[i-1]];
             }
             else {
                 c[p[i]]=c[p[i-1]]+1;
             }
         }
     }
     int k=0;
     while((1<<k)<n) {
         vector<pair<pair<int,int>,int>> a(n);
         for(int i=0;i<n;i++) {
             a[i]={{c[i],c[(i+(1<<k))%n]},i};
         }
         radix_sort(a);
         for(int i=0;i<n;i++) {
             p[i]=a[i].second;
         }
         c[p[0]]=0;
         for(int i=1;i<n;i++) {
             if(a[i].first==a[i-1].first) {
                 c[p[i]]=c[p[i-1]];
             }
             else {
                 c[p[i]]=c[p[i-1]]+1;
             }
         }
         k++;
     }
     for(int i=0;i<n;i++) {
         cout<<p[i]<<" ";
     }
 }