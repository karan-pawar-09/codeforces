#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX  = 1000000; 
vector <int> primes; 
void sieve() { 
    int n = MAX;
    int nNew = (n)/2; 
    bool marked[nNew + 100]; 
    memset(marked, false, sizeof(marked)); 
    int tmp=sqrt(n); 
    for (int i=1; i<=(tmp-1)/2; i++) 
        for (int j=(i*(i+1))<<1; j<=nNew; j=j+2*i+1) 
            marked[j] = true; 

    primes.push_back(2); 
    for (int i=1; i<=nNew; i++) 
        if (marked[i] == false) 
            primes.push_back(2*i + 1); 
} 
void primeLcm(vector<ll>arr, int n ) { 
    int factors[MAX] = {0}; 
    for (int i=0; i<n; i++) { 
        ll copy = arr[i]; 
        int sqr = sqrt(copy); 
        for (int j=0; primes[j]<=sqr; j++) { 
            if (copy%primes[j] == 0) { 
                while (copy%primes[j] == 0) 
                    copy = copy/primes[j]; 

                factors[primes[j]] = 1; 
            } 
        } 
        if (copy > 1) 
            factors[copy] = 1; 
    } 
    if (factors[2] == 1) 
        cout << 2 << " "; 
    for (int i=3; i<=MAX; i=i+2) 
        if (factors[i] == 1) 
            cout << i << " "; 
} 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        primeLcm(arr,n);
    }
}