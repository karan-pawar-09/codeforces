#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        long r,g,b,w;
        cin>>r>>g>>b>>w;
        int sum=r%2+g%2+b%2+w%2;
        int k=3;;
        r-=1;
        g-=1;
        b-=1;
        w+=3;
        if(r>=0&&g>=0&&b>=0) {
            k=r%2+g%2+b%2+w%2;
        }
        int ans=min(sum,k);
        if(ans<=1) {
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}