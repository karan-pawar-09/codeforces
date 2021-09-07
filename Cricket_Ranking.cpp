/*
author:Karan
created:24.07.2021 14:14:05
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        vector<int> a(3);
        vector<int> b(3);
        for(int i=0;i<3;i++) {
            cin>>a[i];
        }
        for(int i=0;i<3;i++) {
            cin>>b[i];
        }
        int as=0;
        int bs=0;
        for(int i=0;i<3;i++) {
            if(a[i]>b[i]) {
                as++;
            }
            else {
                bs++;
            }
        }
        as>bs?cout<<"A"<<endl:cout<<"B"<<endl;
    }
}