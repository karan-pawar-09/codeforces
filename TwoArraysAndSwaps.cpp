#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        for(int i=0;i<n;i++) {
            cin>>b[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int y=0,z=n-1;
        while(a[y]<b[z]&&k--&&y<n&&z>=0) {            
            int temp=b[z];
            b[z]=a[y];
            a[y]=temp;
            y++;
            z--;
        }
        for(int i=1;i<n;i++) {
            a[i]+=a[i-1];
        }
        cout<<a[n-1]<<endl;
    }
}