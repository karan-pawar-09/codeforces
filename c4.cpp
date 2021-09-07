#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        long long n;
        cin>>n;
        int k=2;
        int q;
        for(int k=2;k<100000;k++) {
            if((n%int((pow(2,k)+.5)-1))==0) {
               // cout<<n%int((pow(2,k)+.5)-1)<<" "<<k<<endl;
                q=k;
                break;
            }
        }
        
        int r=int(pow(2,q)-.5);
      //  cout <<r<< endl;
        //long x=(n/((pow(2,q)+.5)-1));
       // cout<<x<<endl;
       cout<<(n/r)<<endl;
    }
}