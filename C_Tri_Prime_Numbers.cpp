#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=1000000;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    int t;
    cin>>t;
    vector<int> arr(n,0);
    int ans=0;
    for(int i=1;i<n;i++) {
        if(is_prime[i]) {
            ans++;
        }
        arr[i]=ans;
    }
    while(t--) {
        ll q;
        cin>>q;
        int sq = (int)sqrt(q);
        cout<<arr[sq]<<endl;
    }
}