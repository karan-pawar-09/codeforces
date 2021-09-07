/*
authot:Karan
created:20.05.2021 21:28:10
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;        
        int a[n];
        map <ll,vector<ll>> value;
        for (int i = 0 ; i < n; i++){
            cin >> a[i];
            value[a[i]].push_back(i+1);
        }
        long long final_ans = 0;
        for(auto x:value) {
            vector<ll> arr=x.second;
            int size=arr.size();
            vector<ll> pre(size,0);
            pre[size-1]=n-arr[size-1]+1;
            for(int i=size-2;i>=0;i--) {
                pre[i]=pre[i+1]+(n-arr[i]+1);
            }
            for(int i=1;i<size;i++) {
                final_ans+=arr[i-1]*pre[i];
            }
        }

        cout << final_ans << endl;
    }
}