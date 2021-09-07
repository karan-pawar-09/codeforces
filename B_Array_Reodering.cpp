/*
author:Karan
created:04.06.2021 20:09:15
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
        vector<int> ar(n);
        vector<int> a,b;
        for(int i=0;i<n;i++) {
            cin>>ar[i];
            if(ar[i]%2) {
                b.push_back(ar[i]);
            }
            else {
                a.push_back(ar[i]);
            }
        }
        vector<int>arr;
        for(int i=0;i<a.size();i++) {
            arr.push_back(a[i]);
        }
        for(int i=0;i<b.size();i++) {
            arr.push_back(b[i]);
        }
        int ans=0;       
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(__gcd(arr[i],2*arr[j])>1) {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }   
}