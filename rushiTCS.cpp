/*
    author:Karan
    created:29.08.2022 11:02:32
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'


string removeRConChars(int k, string s) {
    string res = "";
    if (k == 1) {
        return res;
    }
    stack<pair<char, int> > st;
    for (int i = 0; i < s.length(); i++) {
        if (st.empty() == true) {
            st.push(make_pair(s[i], 1));
        }
        else {
            if (s[i] == (st.top()).first) {
                st.push(
                    { s[i], st.top().second + 1 });
                if (st.top().second == k) {
                    int x = k;
                    while (x) {
                        st.pop();
                        x--;
                    }
                }
            }
            else {
                st.push(make_pair(s[i], 1));
            }
        }
    }
    while (!st.empty()) {
        res += st.top().first;
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    string s;
    int r;
    cin>>s>>r;
    cout<<removeRConChars(r, s)<<endl;
}

int32_t main() {
    int t=1;
    while(t--) {
        solve();
    }
}