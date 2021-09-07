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
        set<ll> available;
        ll k=0;
        for(int i=0;i<n;i++) {
            if(arr[i]>k) {
                for(int j=k+1;j<arr[i];j++) {
                    available.insert(j);
                }
                cout<<arr[i]<<" ";
                k=arr[i];
            }            
            else {
                cout<<(*(available.begin()))<<" ";
                available.erase(available.begin());
            }
        }  
        cout<<endl;      
        available.clear();
        k=0;
        for(int i=0;i<n;i++) {
            if(arr[i]>k) {
                for(int j=k+1;j<arr[i];j++) {
                    available.insert(j);
                }
                cout<<arr[i]<<" ";
                k=arr[i];
            }            
            else {
                auto it=available.end();
                it--;
                cout<<(*it)<<" ";
                available.erase(it);
            }
        }   
        cout<<endl;
    }
}