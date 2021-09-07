#include<bits/stdc++.h>
using namespace std;
int answer(long long a) {
    long p=a;
    int ans=1;
    int kk=0;
    for(long long i=2;i*i<=p;i++) {
        int count=0;
        if(p%i==0){
            
            while(p%i==0){
                p/=i;
                count++;                
            }
        }
        ans*=(count+1);        
    }
    if(p>1){
        ans*=2;
    }
    return ans;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        long long a;
        cin>>a;
        cout<<answer(a)<<endl;
    }
}