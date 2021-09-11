/*
    author:Karan
    created:11.09.2021 17:34:40
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool check(vector<vector<char>> &a ,vector<vector<char>> &b) {
    if(a.size()!=b.size()) return false;
    if(a[0].size()!=b[0].size()) return false;
    bool k=true;
    for(int i=0;i<a.size();i++) {
        for(int j=0;j<a[0].size();j++) {
            if(a[i][j]!=b[i][j]) {
                k=false;
                break;
            }
        }
        if(!k) break;
    }
    if(!k) return false;
    return true;
}
vector<vector<char>> rotate(vector<vector<char>> &mat) {    
    vector<vector<char>> arr(mat[0].size(),vector<char>(mat.size()));
    int len=0;
    for(int i=mat[0].size()-1;i>=0;i--) {
        int kk=0;
        for(int j=0;j<mat.size();j++) {
            arr[len][kk]=mat[j][i];
            kk++;
        }
        len++;
    }
    return arr;
}
void solve() {
    int n;
    cin>>n;
    vector<string> s(n),t(n);
    int stop=n;
    int sbottom=0;
    int ttop=n;
    int tbottom=0;
    int sright=0;
    int sleft=n;
    int tright=0;
    int tleft=n;
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++) cin>>t[i];
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(s[i][j]=='#') {
                stop=min(stop,i);
                sbottom=max(sbottom,i);
                sright=max(sright,j);
                sleft=min(sleft,j);
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(t[i][j]=='#') {
                ttop=min(ttop,i);
                tbottom=max(tbottom,i);
                tright=max(j,tright);
                tleft=min(tleft,j);
            }
        }
    }

    vector<vector<char>> arr(abs(sbottom-stop+1));
    vector<vector<char>> ar(abs(tbottom-ttop+1));
    int temp=0;
    for(int i=stop;i<=sbottom;i++) {
        for(int j=sleft;j<=sright;j++) {
            arr[temp].push_back(s[i][j]);
        }
        temp++;
    }
    temp=0;
    for(int i=ttop;i<=tbottom;i++) {
        for(int j=tleft;j<=tright;j++) {
            ar[temp].push_back(t[i][j]);
        }
        temp++;
    }
    bool ans=false;
    if(check(arr,ar)) ans=true;
    ar=rotate(ar);
    if(check(arr,ar)) ans=true;
    ar=rotate(ar);
    if(check(arr,ar)) ans=true;
    ar=rotate(ar);
    if(check(arr,ar)) ans=true;
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}