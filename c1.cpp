#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    vector<int>arr(n);
    while(t--) {
        int n;
        cin>>n;
        if((n/2)%2==1) {
            cout<<"NO";
        }
        else{
            cout<<"YES"<<endl;
            long long sum=0;
            for(int i=0;i<(n/2);i++) {
                cout<<(2+2*i)<<" ";
                sum+=(2+2*i);
            } 
            int w;
            for(int i=0;i<((n/2)-1);i++) {
                cout<<(1+2*i)<<" ";
                w=i;
            }
            w++;
            cout<<((1+2*w)+(n/2));
        }
        cout<<endl;
    }
}
