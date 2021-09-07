/*
author:Karan
created:19.08.2021 13:49:37
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool isGood(vector<ll> &ar) {
    for(ll i=0;i<ar.size();i++) {
        if(ar[i]>0) return false;
    }
    return true;
}

void solve() {
    string s;
    cin>>s;
    ll n=s.size();
    string second="";

    vector<bool> present(130,false);
    vector<ll> freq(130,0);

    for(ll i=n-1;i>=0;i--) {
        if(present[s[i]]==false) {
            second.push_back(s[i]);
            present[s[i]]=true;
        }
        freq[s[i]]++;
    }

    reverse(all(second));
    
    bool ans=true;
    for(ll i=0;i<second.size();i++) {
        if(freq[second[i]]%(i+1)) {
            ans=false;
            break;
        }
    }

    string first;
    vector<ll> firstfreq(130,0);
    for(ll i=0;i<second.size();i++) {
        firstfreq[second[i]]=freq[second[i]]/(i+1);
    }
    ll breakpt=0;
    for(ll i=0;i<n;i++) {
        if(isGood(firstfreq)) break;
        firstfreq[s[i]]--;
        breakpt++;
    }
    for(ll i=0;i<breakpt;i++) {
        first.push_back(s[i]);
    }
    freq[second[0]]=0;
    vector<string> check;
    set<char> ommit;
    check.push_back(first);
    ll init=0;
    ommit.insert(second[0]);
    for(ll i=1;i<second.size();i++) {        
        for(ll j=0;j<second.size();j++) {
            firstfreq[second[j]]=freq[second[j]]/(j+1);
        }
        string temp;
        init+=check.back().size();
        for(ll j=0;j<check.back().size();j++) {
            if(isGood(firstfreq)) {
                break;
            }
            if(ommit.find(check.back()[j])==ommit.end()) {
                temp.push_back(check.back()[j]);
                firstfreq[check.back()[j]]--;
            }
            else {
                firstfreq[check.back()[j]]--;
            }
        }
        freq[second[i]]=0;
        ommit.insert(second[i]);
        check.push_back(temp);
    }
    if(!ans) {
        cout<<-1<<endl;
    }
    else {
        string temp;
        for(ll i=0;i<check.size();i++) {
            temp+=check[i];
        }
        if(temp==s) {
            cout<<first<<" "<<second<<endl;
        }
        else {
            cout<<-1<<endl;
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
    while(t--) {
        solve();
    }
}