/*
    author:Karan
    created:14.08.2022 13:36:14
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
    string s;
    getline(cin, s);
    int k;
    cin>>k;
    string temp;
    int count = 0;
    int n=s.size();
    for(int i=0;i<n;i++) {
        if(s[i]!= ' ') {
            temp.push_back(s[i]);
            if(i==(n-1)) {
                int size = temp.size();
                {
                    string res;
                    for(int j=size-(k%size);j<size;j++) {
                        res+=temp[j];
                    }
                    for(int j=0;j<size-(k%size);j++) {
                        res+=temp[j];
                    }
                    if(res==temp) {
                        count++;
                    }
                }
            }
        } else {
            while(s[i]==' ') {
                i++;
            } i--;
            int size = temp.size();
            {
                string res;
                for(int j=size-(k%size);j<size;j++) {
                    res+=temp[j];
                }
                for(int j=0;j<size-(k%size);j++) {
                    res+=temp[j];
                }
                if(res==temp) {
                    count++;
                }
            }
            temp.clear();
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

