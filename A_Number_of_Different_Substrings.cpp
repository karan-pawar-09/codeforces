/*
authot:Karan
created:23.05.2021 00:25:10
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void radix_sort(vector<pair<pair<ll,ll>,ll>> &a) {
    ll n=a.size();
    {
        vector<ll> cnt(n);
        for(ll i=0;i<n;i++) {
            cnt[a[i].first.second]++;
        }
        vector<pair<pair<ll,ll>,ll>> a_new(n);
        vector<ll>pos(n);
        pos[0]=0;
        for(ll i=1;i<n;i++) {
            pos[i]=pos[i-1]+cnt[i-1];
        }
        for(ll i=0;i<n;i++) {
            a_new[pos[a[i].first.second]]=a[i];
            pos[a[i].first.second]++;
        }
        a=a_new;
    }
    {
        vector<ll> cnt(n);
        for(ll i=0;i<n;i++) {
            cnt[a[i].first.first]++;
        }
        vector<pair<pair<ll,ll>,ll>> a_new(n);
        vector<ll>pos(n);
        pos[0]=0;
        for(ll i=1;i<n;i++) {
            pos[i]=pos[i-1]+cnt[i-1];
        }
        for(ll i=0;i<n;i++) {
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
    vector<ll> p(n),c(n);
        {
            vector<pair<char,ll>> a(n);
            for(ll i=0;i<n;i++) {
                a[i]={s[i],i};
            }
            sort(all(a));
            for(ll i=0;i<n;i++) {
                p[i]=a[i].second;
            }
            c[p[0]]=0;
            for(ll i=1;i<n;i++) {
                if(a[i].first==a[i-1].first) {
                    c[p[i]]=c[p[i-1]];
                }
                else {
                    c[p[i]]=c[p[i-1]]+1; 
                }
            }
        }
        ll k=0;
        while((1<<k)<n) {
            vector<pair<pair<ll,ll>,ll>> a(n);
            for(ll i=0;i<n;i++) {
                a[i]={{c[i],c[(i+(1<<k))%n]},i};
            }
            radix_sort(a);
            for(ll i=0;i<n;i++) {
                p[i]=a[i].second;
            }
            c[p[0]]=0;
            for(ll i=1;i<n;i++){
                if(a[i].first==a[i-1].first) {
                    c[p[i]]=c[p[i-1]];
                }
                else {
                    c[p[i]]=c[p[i-1]]+1;
                }
            }
            k++;
        }
        vector<ll> lcp(n);
        k=0;
        for(ll i=0;i<n-1;i++) {
            ll pi=c[i];
            ll j=p[pi-1];
            while(s[i+k]==s[j+k]) {
                k++;
            }
            lcp[pi]=k;
            k=max(k-1,0LL);
        }
        ll ans=0;
        for(int i=0;i<n;i++) {
            ans+=n-1-p[i]-lcp[i];
        }
        cout<<ans<<endl;    
}