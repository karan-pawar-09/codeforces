/*
author:Karan
created:11.07.2021 12:05:25
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
        string s;
        cin>>s;
        int l=0;
        int r=s.size()-1;
        vector<int> arr;
        while(l<=r) {
            if(s[l]>s[r]) {
                arr.push_back(s[l]);
                l++;
            }
            else {
                arr.push_back(s[r]);
                r--;
            }
        }
        bool ans=true;
        for(int i=1;i<arr.size();i++) {
            if((arr[i]+1)!=arr[i-1]) {
                ans=false;
                break;
            }
        }
        if(arr[arr.size()-1]!='a') {
            ans=false;
        }
        ans?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
}