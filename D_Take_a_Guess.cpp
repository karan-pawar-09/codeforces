/*
author:Karan
created:02.09.2021 17:20:22
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    int n,x;
    cin>>n>>x;
    int k,p;
    cout<<"and 1 2"<<endl;
    cout.flush();
    cin>>k;
    cout<<"or 1 2"<<endl;
    cout.flush();
    cin>>p;

    int oneplustwo=k+p;

    cout<<"and 1 3"<<endl;
    cout.flush();
    cin>>k;
    cout<<"or 1 3"<<endl;
    cout.flush();
    cin>>p;

    int oneplusthree=k+p;

    cout<<"and 2 3"<<endl;
    cout.flush();
    cin>>k;
    cout<<"or 2 3"<<endl;
    cout.flush();
    cin>>p;

    int twoplusthree=k+p;

    int one=(oneplustwo+oneplusthree-twoplusthree)/2;

    vector<int> ans(n,-1);
    ans[0]=one;
    ans[1]=oneplustwo-one;
    ans[2]=oneplusthree-one;

    {
        for(int i=3;i<n;i++) {
            cout<<"and 1 "<<i+1<<endl;
            cout.flush();
            cin>>k;
            cout<<"or 1 "<<i+1<<endl;
            cout.flush();
            cin>>p;
            ans[i]=k+p-one;
        }
        sort(all(ans));
        cout<<"finish "<<ans[x-1]<<endl;
        cout.flush();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;

    while(t--) {
        solve();
    }
}