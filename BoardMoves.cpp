#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        long n;
        cin>>n;
        long k=n/2;
        long long int sum=0;
        if(n==1) {
            cout<<"0"<<endl;
        }
        else {
            for(long long i=1;i<=k;i++) {
                sum+=8*i*i;
            }
            cout<<sum<<endl;
        }
    }
}