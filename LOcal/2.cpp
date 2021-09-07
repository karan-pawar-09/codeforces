#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<bool> is_prime(100000008, true);
    is_prime[0] = is_prime[1] = false;
    for (long i = 2; i<= 100000008; i++) {
    if (is_prime[i] && (long long)i * i <= 100000008) {
        for (long j = i * i; j <= 100000008; j += i)
            is_prime[j] = false;
        }
    }

    int T;
    cin>>T;

    while(T--){
        long aaaa;
        cin>>aaaa;
        vector<long> aa;
        vector<long> arr;
        for(long i=0;i<aaaa;i++) {
            long a;
            cin>>a;
            arr.push_back(a);
            if(is_prime[a]&&aa.size()<=2){
                aa.push_back(a);
            }
        }
        
        if(aa.size()==1) {
            bool ans=true;
            for(int i=0;i<aaaa;i++){
                if(arr[i]%aa[0]!=0) {
                    ans=false;
                    break;
                }
            }
            if(ans){
            cout<<"1"<<endl;
            cout<<aa[0]<<endl;
            }
            else{
                cout<<"0"<<endl;
            }
        }
        else{
            cout<<"0"<<endl;
        }
        
    }
}