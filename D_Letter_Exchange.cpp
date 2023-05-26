/*
    author:Karan
    created:06.02.2023 12:49:23
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
    int m; cin >> m;
    vector<string> arr(m);
    map<pair<char,char>,vector<int>> M;
    vector<vector<int>> temp(3);
    for(int i=0;i<m;i++) {
        cin >> arr[i];
        int w=0,I=0,n=0;
        for(char c : arr[i]){
            if(c == 'w') w++;
            else if(c == 'i') I++;
            else n++;
        }
        if(w>1){
            if(I == 0) M[{'w','i'}].push_back(i);
            if(n == 0) M[{'w','n'}].push_back(i);
        }
        else if(I>1){
            if(w == 0) M[{'i','w'}].push_back(i);
            if(n == 0) M[{'i','n'}].push_back(i);
        }
        else if(n>1){
            if(w == 0) M[{'n','w'}].push_back(i);
            if(I == 0) M[{'n','i'}].push_back(i);
        }
    }
    vector<pair<pair<int,char>,pair<int,char>>> ans;
    while(M[{'w','i'}].size() && M[{'i','w'}].size()){
        pair<int,char> p = {M[{'w','i'}].back(),'w'};
        pair<int,char> p2 = {M[{'i','w'}].back(),'i'};
        ans.push_back({p,p2});
        M[{'w','i'}].pop_back();
        M[{'i','w'}].pop_back();
    }
    while(M[{'w','n'}].size() && M[{'n','w'}].size()){
        pair<int,char> p = {M[{'w','n'}].back(),'w'};
        pair<int,char> p2 = {M[{'n','w'}].back(),'n'};
        ans.push_back({p,p2});
        M[{'w','n'}].pop_back();
        M[{'n','w'}].pop_back();
    }
    while(M[{'n','i'}].size() && M[{'i','n'}].size()){
        pair<int,char> p = {M[{'n','i'}].back(),'n'};
        pair<int,char> p2 = {M[{'i','n'}].back(),'i'};
        ans.push_back({p,p2});
        M[{'n','i'}].pop_back();
        M[{'i','n'}].pop_back();
    }
    while(M[{'w','i'}].size() && M[{'i','n'}].size()){
        pair<int,char> p = {M[{'w','i'}].back(),'w'};
        pair<int,char> p2 = {M[{'i','n'}].back(),'i'};
        int x = p2.first;
        ans.push_back({p,p2});
        M[{'w','i'}].pop_back();
        M[{'i','n'}].pop_back();
        M[{'w','n'}].push_back(x);
    }
    while(M[{'n','i'}].size() && M[{'i','w'}].size()){
        pair<int,char> p = {M[{'n','i'}].back(),'n'};
        pair<int,char> p2 = {M[{'i','w'}].back(),'i'};
        int x = p2.first;
        ans.push_back({p,p2});
        M[{'n','i'}].pop_back();
        M[{'i','w'}].pop_back();
        M[{'n','w'}].push_back(x);
    }
    while(M[{'w','n'}].size() && M[{'n','w'}].size()){
        pair<int,char> p = {M[{'w','n'}].back(),'w'};
        pair<int,char> p2 = {M[{'n','w'}].back(),'n'};
        ans.push_back({p,p2});
        M[{'w','n'}].pop_back();
        M[{'n','w'}].pop_back();
    }
    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i.first.first+1 << ' ' << i.first.second << ' ' << i.second.first+1 << ' ' << i.second.second << endl;
    }
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
