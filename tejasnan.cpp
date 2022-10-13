/*
    author:Karan
    created:22.08.2022 10:31:09
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

int check(vector<int> &a, vector<int> &b) {
    int res = 0;
    int count = 0;
    for(int i=45;i<60;i++) {
        res++;
        if(a[i]<b[i]) {
            return 0;
        } else if(a[i] == b[i]) {
            count++;
        }
    }
    if(count == res) {
        return 1;
    } else {
        return 2;
    }
}
void solve() {
    string a, b;
    cin>>a>>b;
    vector<int> afreq(60, 0);
    vector<int> bfreq(60, 0);
    for(auto x: a) {
        afreq[x]++;
    }
    int count = 0;
    for(int i=0;i<b.size();i++) {
        for(int j=i;j<b.size();j++) {
            bfreq[b[j]]++;
            int kk = check(afreq, bfreq);
            if(kk == 0) {
                
            } else if(kk == 1) {
                for(int k=45;k<60;k++) {
                    bfreq[k]=0;
                }
                count++;
                break;
            }
        }
        for(int k=45;k<60;k++) {
            bfreq[k]=0;
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
    //cin>>t;
    while(t--) {
        solve();
    }
}