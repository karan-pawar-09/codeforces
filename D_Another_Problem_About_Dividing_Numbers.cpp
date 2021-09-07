/*
author:Karan
created:10.06.2021 21:26:05
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int primeFactors(int n) {
    int ans=0;
    while (n % 2 == 0) {
        ans++;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)  {       
        while (n % i == 0) {
            ans++;
            n = n/i;
        }
    }
    if (n > 2)
        ans++;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int a,b,k;
        cin>>a>>b>>k;
        if(k<=primeFactors(a)+primeFactors(b)&&k>=2||k==1&&(a!=b&&min(a,b)==__gcd(a,b))) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}