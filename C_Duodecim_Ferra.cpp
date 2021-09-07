#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ncr(int n, int r) {
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l;
    cin>>l;
    cout<<ncr(l-1,11)<<endl;
}   