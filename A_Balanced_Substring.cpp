/*
    author:Karan
    created:08.09.2021 20:05:26
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
    vector<int> a(n,0);
    vector<int> b(n,0);
    if(s[0]=='a') {
        a[0]=1;
    }
    else {
        b[0]=1;
    }
    for(int i=1;i<n;i++) {
        if(s[i]=='a') {
            a[i]=a[i-1]+1;
            b[i]=b[i-1];
        }
        else {
            a[i]=a[i-1];
            b[i]=b[i-1]+1;
        }
    }
    int ans=false;
    int a1,a2;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int bno=b[j];
            int ano=a[j];
            if(i>0) {
                bno-=b[i-1];
                ano-=a[i-1];
            }
            if(ano==bno) {
                a1=i+1;
                a2=j+1;
                ans=true;
                break;
            }
        }
        if(ans) break;
    }
    if(ans) {
        cout<<a1<<" "<<a2<<endl;
    }
    else {
        cout<<-1<<" "<<-1<<endl;
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