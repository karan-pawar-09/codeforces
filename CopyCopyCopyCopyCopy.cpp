#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        set<long> arr;
        for(int i=0;i<n;i++) {
            long a;
            cin>>a;
            arr.insert(a);
        }
        cout<<arr.size()<<endl;
    }
}