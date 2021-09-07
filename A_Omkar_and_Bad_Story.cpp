/*
author:Karan
created:06.06.2021 20:07:01
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
        bool pos=false;
        bool neg=false;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i]<0) {
                neg=true;
            }
        }
        if(neg) {
            cout<<"NO"<<endl;
        }
        else {
            bool karan=false;
            vector<int> a;
            set<int> ar;
            for(int i=0;i<n;i++) {
                a.push_back(arr[i]);
            }
            while(!karan) {                
                for(int i=0;i<n;i++) {
                    ar.insert(a[i]);
                }                
                a.clear();
                for(auto x:ar) {
                    a.push_back(x);
                }
                karan=true;
                for(int i=0;i<a.size();i++) {
                    for(int j=i+1;j<a.size();j++) {
                        if(ar.find(abs(a[i]-a[j]))==ar.end()) {
                            ar.insert(abs(a[i]-a[j]));
                            karan=false;
                        }
                    }
                }
            }
            cout<<"YES"<<endl;
            cout<<ar.size()<<endl;
            for(auto x:ar) {
                cout<<x<<" ";
            }
            cout<<endl;
        }
            
    }
}