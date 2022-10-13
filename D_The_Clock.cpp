/*
    author:Karan
    created:14.06.2022 20:44:48
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

bool isPalindrome(string s) {
    int n=s.size();
    for(int i=0;i<s.size()/2;i++) {
        if(s[i]!=s[n-1-i]) return false;
    }
    return true;
}
string toString(int a) {
    if(a<10) {
        return("0"+to_string(a));
    } else {
        return to_string(a);
    }
}
void solve() {
    string s;
    int x;
    cin>>s>>x;
    
    int hour = stoi(s.substr(0,2));
    int min = stoi(s.substr(3,2));
    set<pair<int,int>> st;
    while(st.find(make_pair(hour,min))==st.end()) {
        st.insert({hour,min});
        min+=x;
        if(min>=60) {
            hour+=min/60;
            min%=60;
        }
        if(hour>=24) {
            hour%=24;
        }
    }
    vector<string> arr;
    for(auto x:st) {
        arr.push_back(toString(x.first)+toString(x.second));
    }
    int count=0;
    for(auto x: arr) {
        if(isPalindrome(x)) {
            count++;
        }
    }
    cout<<count<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}