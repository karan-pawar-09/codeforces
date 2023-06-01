
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()


void solve() {
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    set<int> st;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
        st.insert(b[i]);
    }
    sort(all(a));
    for(int i=0;i<n;i++) {
        if(!st.count(a[i])) {
            cout<<a[i]<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int32_t main() {
    int t=1;
    while(t--) {
        solve();
    }
}