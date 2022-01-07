/*
    author:Karan
    created:05.01.2022 23:23:44
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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> arr(n);
    ll sum=0;
    vector<bool> dir(n,false);
    vector<pair<ll,ll>> check;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        if(k-arr[i]<arr[i]) {
            dir[i]=true;
        }
        if(((k-arr[i])%2 != (arr[i]%2)))
            check.push_back({abs(k-arr[i]-arr[i]),i});
        sum+=arr[i];
    }
    vector<pair<ll,ll>> v;
    for(ll i=0;i<n;i++) {
        v.push_back({k-(2*arr[i]),i});
    }
    sort(all(v));
    ll x=m;
    ll req=0;
    vector<bool> used(n,false);    
    map<ll,pair<ll,ll>> M;
    for(ll i=0;i<n;i++) M[i]={0,0};
    for(ll i=0;i<n;i++) {
        ll kk=min(arr[v[i].second],k-arr[v[i].second]);
        req+=kk;
    }    
    if(req>=x) {
        for(ll i=0;i<n;i++) {
            ll kk=min(arr[v[i].second],k-arr[v[i].second]);
            if(m>=kk) {
                m-=kk;
                sum-=arr[v[i].second];
                used[v[i].second]=true;
                if(!dir[v[i].second]) {
                    M[v[i].second].first=kk;
                    M[v[i].second].second=0;
                }
                else {
                    M[v[i].second].second=kk;
                    M[v[i].second].first=0;
                }
            }
        }
        ll kkkk=max(sum-m,0LL);
        cout<<max(sum-m,0LL)<<endl;
        for(ll i=0;i<n;i++) {
            if(!used[i]) {
                if(m<=0) break;
                else {
                    int xx=min(m,arr[i]);
                    m-=xx;
                    M[i].first=xx;
                    M[i].second=0;
                }
            }
        }
        ll check=0;
        for(int i=0;i<n;i++) check+=M[i].first+M[i].second;
        assert(check==x);
        for(ll i=0;i<n;i++) cout<<M[i].first<<" "<<M[i].second<<endl;
    } else {
        sort(all(check));
        if((x-req)%2==0) {
            cout<<0<<endl;
            map<ll,pair<ll,ll>> MM;
            for(ll i=0;i<n;i++) MM[i]={0,0};
            for(ll i=0;i<n;i++) {
                {
                    if(dir[i]) {
                        MM[i]={0,k-arr[i]};
                    } else {
                        MM[i]={arr[i],0};
                    }
                } 
            }
            MM[0].first+=(x-req)/2;
            MM[0].second+=(x-req)/2;
            ll check=0;
            for(int i=0;i<n;i++) check+=MM[i].first+MM[i].second;
            assert(check==x);
            for(ll i=0;i<n;i++) cout<<MM[i].first<<" "<<MM[i].second<<endl;
        } else {
            if(check.size()>0 and check[0].first<=(x-req)) {
                if(dir[check[0].second]) {
                    dir[check[0].second]=false;
                } else {
                    dir[check[0].second]=true;
                }
                cout<<0<<endl;
                map<ll,pair<ll,ll>> MM;
                for(ll i=0;i<n;i++) MM[i]={0,0};
                m=x;
                for(ll i=0;i<n;i++) {
                    if(i!=check[0].second) {
                        if(dir[i]) {
                            MM[i]={0,k-arr[i]};
                            m-=k-arr[i];
                        } else {
                            MM[i]={arr[i],0};
                            m-=arr[i];
                        }
                    } else {
                        if(dir[i]) {
                            MM[i]={0,k-arr[i]};
                            m-=k-arr[i];
                        } else {
                            MM[i]={arr[i],0};
                            m-=arr[i];
                        }
                    }
                }
                MM[0].first+=m/2;
                MM[0].second+=m/2;
                ll check=0;
                for(int i=0;i<n;i++) check+=MM[i].first+MM[i].second;
                assert(check==x);
                for(ll i=0;i<n;i++) cout<<MM[i].first<<" "<<MM[i].second<<endl;
            } else {
                cout<<1<<endl;
                map<ll,pair<ll,ll>> MM;
                for(ll i=0;i<n;i++) MM[i]={0,0};
                m=x;
                for(ll i=0;i<n;i++) {
                    {
                        if(dir[i]) {
                            MM[i]={0,k-arr[i]};
                            m-=k-arr[i];
                        } else {
                            MM[i]={arr[i],0};
                            m-=arr[i];
                        }
                    } 
                }
                MM[0].first+=m/2;
                MM[0].second+=m/2;
                MM[0].second++;
                ll check=0;
                for(int i=0;i<n;i++) check+=MM[i].first+MM[i].second;
                assert(check==x);
                for(ll i=0;i<n;i++) cout<<MM[i].first<<" "<<MM[i].second<<endl;
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




 