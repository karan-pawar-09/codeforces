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
        vector<ll> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        vector<ll> pos;
        vector<ll> neg;
        for(int i=0;i<n;i++) {
            if(arr[i]<0) {
                neg.push_back(arr[i]);
            }
            else {
                pos.push_back(arr[i]);
            }
        }
        sort(all(pos));
        sort(all(neg));
        if(pos.size()==0) {
            pos.push_back(2*neg.back());
        }
        if(neg.size()==0) {
            neg.push_back(2*pos.front());
        }
        ll sumpos=0;
        ll sumneg=0;
        for(int i=0;i<pos.size();i++) {
            sumpos+=pos[i];
        }
        for(int i=0;i<neg.size();i++) {
            sumneg+=neg[i];
        }
        cout<<sumpos-sumneg<<endl;
    }
}