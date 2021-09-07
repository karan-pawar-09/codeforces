#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        long a[3];
        long b[3];
        for(int i=0;i<3;i++) {
            cin>>a[i];
        }
        for(int i=0;i<3;i++) {
            cin>>b[i];
        }
        long long ans=0;
        if(b[1]!=0) {
            if(b[1]>=a[2]) {
                ans+=a[2]*2;
                b[1]-=a[2];
            }
            else{
                ans+=b[1]*2;
                b[1]=0;
            }
        }
        if(a[1]>b[0]+b[1]){
            ans-=2*min((a[1]-b[0]-b[1]),b[2]);
        }
        cout<<ans<<endl;
    }
}