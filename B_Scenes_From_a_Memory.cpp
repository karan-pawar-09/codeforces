/*
author:Karan
created:27.08.2021 12:12:29
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool isGood(ll a) {
    if(a!=2 and a!=3 and a!=5 and a!=7) {
        return true;
    }
    return false;
}
vector<bool> is_prime;
void solve() {
    ll k;
    cin>>k;
    string s;
    cin>>s;
    bool found=false;
    ll n=s.size();
    ll ans;
    map<ll,ll> M;
    for(ll i=0;i<n;i++) {
        M[s[i]-'0']++;
        if(isGood(s[i]-'0')) {
            ans=s[i]-'0';            
            found=true;
        }
    }
    if(found) {
        cout<<1<<endl<<ans<<endl;
    }
    else {
        string an;
        for(ll i=0;i<n;i++) {
            for(ll j=i+1;j<n;j++) {
                string temp;
                temp.push_back(s[i]);
                temp.push_back(s[j]);
                if(!is_prime[stoi(temp)]) {
                    found=true;
                    an=temp;
                    break;
                }
            }
            if(found) {
                break;
            }
        }
        if(found) {
            cout<<an.size()<<endl<<an<<endl;
        }
        else {
            string an;
            for(ll i=0;i<n;i++) {
                for(ll j=i+1;j<n;j++) {
                    for(ll k=j+1;k<n;k++) {
                        string temp;
                        temp.push_back(s[i]);
                        temp.push_back(s[j]);
                        temp.push_back(s[k]);
                        if(!is_prime[stoi(temp)]) {
                            found=true;
                            an=temp;
                            break;
                        }
                    }
                    if(found) break;
                }
                if(found) break;
            }
            cout<<3<<endl<<an<<endl;
        }
        
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;

    ll n=(ll)1e4;
    is_prime.resize(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    while(t--) {
        solve();
    }
}