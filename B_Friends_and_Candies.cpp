/*
author:Karan
created:10.06.2021 20:27:44
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        ll sum=0;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%n) {
            cout<<"-1"<<endl;
        }
        else {
            int k=0;
            for(int i=0;i<n;i++) {
                if(a[i]>(sum/n)) {
                    k++;
                }
            }
            cout<<k<<endl;
        }
    }   
}