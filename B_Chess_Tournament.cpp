/*
    author:Karan
    created:08.09.2021 20:15:22
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int two=0;
    int one=0;
    vector<int> twos;
    int no=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='1') one++;
        else {
            two++;
            twos.push_back(i);
        }
    }
    if(twos.size()) {
        twos.push_back(twos[0]);
    }
    if(two==1 or two==2) {
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;
        if(two==0) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(i==j) cout<<"X";
                    else cout<<"=";
                }
                cout<<endl;
            }
        }
        else {
            vector<vector<char>> ans(n,vector<char>(n,'='));
            // int next=1;
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(i==j) ans[i][j]='X';
                    // else {
                    //     if(s[i]=='2') {
                    //         ans[i][twos[next]]='+';
                    //         ans[twos[next]][i]='-';
                    //         s[i]='1';
                    //     }
                    // }
                }
            }
            for(int i=0;i<twos.size()-1;i++) {
                ans[twos[i]][twos[i+1]]='+';
                ans[twos[i+1]][twos[i]]='-';
            }
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    cout<<ans[i][j];
                }
                cout<<endl;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}