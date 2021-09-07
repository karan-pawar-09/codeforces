#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        ll n=s.size();
        vector<ll> len(n,0);
        vector<ll> next0(n,-1);
        vector<ll> next1(n,-1);
        bool one = false, zero = false;
        ll cnt = 0;
        for (ll i = n - 1; i >= 0; i--) {
            len[i] = cnt;
            if (s[i] == '1')one = true;
            if (s[i] == '0')zero = true;
            if (one && zero) {
                cnt++;
                zero = one = false;
            }
        }
    
        ll n0 = -1, n1 = -1;
        for (ll i = n - 1; i >= 0; i--) {
            next0[i] = n0;
            next1[i] = n1;
            if (s[i] == '1')n1 = i;
            else n0 = i;
        }
        if(n0==-1) {
            cout<<"0"<<endl;
        }
        else if(n1==-1) {
            cout<<"1"<<endl;
        }
        else{
            string ans = "";
            ll curr = n1;
            while (1) {
                ans.push_back(s[curr]);
                ll p0 = next0[curr], p1 = next1[curr];
                if (p0 == -1) {
                    ans.push_back('0'); break;
                }
                if (p1 ==-1) {
                    ans.push_back('1'); break;
                }
                if (len[p0] <= len[p1]) {
                    curr = p0;
                }
                else curr = p1;
            }
            cout<<ans<<endl;
        }
        
    }  
}