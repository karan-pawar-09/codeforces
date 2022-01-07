/*
    author:Karan
    created:06.01.2022 12:30:28
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

bool is_prime[(int)1e6+7];

ll power(int x,  int y) {
    ll res = 1; 
    x = x ;   
    if (x == 0) return 0;  
    while (y > 0) {        
        if (y & 1)
            res = (res*x) ; 
        y = y>>1;
        x = (x*x);
    }
    return res;
}

bool isGood(int p) {
    string s = to_string(p);
    int sum=0;
    for(int i=0;i<s.size();i++) {
        int k=s[i]-'0';        
        sum+=power(k,(int)s.size());
    }
    if(is_prime[sum] and to_string(sum).size()==s.size()) {
        return true;
    }
    else return false;
}

int32_t main() {
    int x;
    cin>>x;
    int n=(int)1e5+8;
    for(int i=0;i<n;i++) {
        is_prime[i]=true;
    }
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    int res=0;
    for(int i=1;i<=x;i++) {
        if(isGood(i)) {
            res++;
        }
    }
    cout<<res<<endl;
}