#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        set<ll>arr;
        for(int i=0;i<n;i++) {
            int a;
            cin>>a;
            arr.insert(a);
        }
        cout<<arr.size()<<endl;
    }
}   