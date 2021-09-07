#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
int main() {
    fast;
    long long n=1000007;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (long long j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    vector<long long> seive(n+1);
    seive[0];
    long long k=0;
    for(long long i=1;i<n+1;i++) {
        if(is_prime[i]==true) {
            k++;
        }
        seive[i]=k;
    }
    long q;
    cin>>q;
    while(q--) {
        long long l,r;
        cin>>l>>r;
        if(l>r)
            l=r-l+(r=l);
        cout<<seive[r]-seive[l-1]<<endl;
    }
}