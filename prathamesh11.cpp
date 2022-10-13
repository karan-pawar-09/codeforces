/*
    author:Karan
    created:03.09.2022 18:38:04
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int ans = 0;
    for(int i=0;i<=1000;i++) {
        multiset<int> s;
        int cap = i;
        priority_queue<int> q;
        for(auto x: arr) q.push(x);
        bool isGood = true;
        for(int j=0;j<k;j++) {
            int xx = q.top();
            q.pop();
            s.insert(min(i, xx));
            q.push(xx-min(i, xx));
        }
        if(isGood) {
            int i =1;
            int temp = 0;
            for(auto x: s) {
                temp +=x;
                i++;
                if(i>(k/2)) break;
            }
            ans = max(ans, temp);
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}