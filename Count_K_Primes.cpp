/*
author:Karan
created:29.05.2021 14:23:37
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N=(int)2e5+5;
    int seive[N];
    memset(seive,0,N);
    for(int i=2;i<=N;i++) {
        if(seive[i]==0) {
            for(int j=i;j<=N;j+=i) {
                seive[j]++;
            }
        }
    }

    int t;
    cin>>t;   
    while(t--) {
        int a,b,k;
        cin>>a>>b>>k;
        int ans=0;
        for(int i=a;i<=b;i++) {
            if(seive[i]==k) {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}