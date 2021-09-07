/*
author:Karan
created:31.05.2021 22:20:44
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        for(int j=0;j<n;j++) {
            cin>>b[j];
        }
        long double sum=0;
        for(int i=0;i<n;i++) {
            sum+=(a[i]-((double)a[i]/b[i])*b[i])*(a[i]-((double)a[i]/b[i])*b[i]);
        }
        cout<<sum<<endl;
    }
}