/*
    author:Karan
    created:23.08.2022 17:44:02
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

bool check (char c , char k)
{
    if(k >= 'A' && k <= 'Z'){
        if(c >= 'a' && c <= 'z')
        return true;
        return k > c;
    }
    if(c >= 'A' && c <= 'Z') return false;
    return k > c;
}
string fun(string s , char k)
{
    for(int i = 0 ; i <s.size();i++){
        if(check(s[i] , k))
        return s.substr(0 , i) + k + s.substr(i);
    }
}
bool check (char c , char k)
{
    if(k >= 'A' && k <= 'Z'){
        if(c >= 'a' && c <= 'z')
        return true;
        return k > c;
    }
    if(c >= 'A' && c <= 'Z') return false;
    return k > c;
}
string fun(string s , char k)
{
    for(int i = 0 ; i <s.size();i++){
        if(check(s[i] , k))
        return s.substr(0 , i) + k + s.substr(i);
    }
    return "";
}

#include <iostream>
using namespace std;
 
// function to find the maximum length of
// substring having character ch
int findLen(string& A, int n, int k, char ch)
{
    int maxlen = 1;
    int cnt = 0;
    int l = 0, r = 0;
     
    // traverse the whole string
    while (r < n) {
     
        /* if character is not same as ch
           increase count */
        if (A[r] != ch)
            ++cnt;
 
        /* While  count > k  traverse the string
           again until count becomes less than k
           and decrease the count when characters
           are not same */
        while (cnt > k) {
            if (A[l] != ch)
                --cnt;
            ++l;
        }
 
        /* length of substring will be rightIndex -
           leftIndex + 1. Compare this with the maximum
           length and return maximum length */
        maxlen = max(maxlen, r - l + 1);
        ++r;
    }
    return maxlen;
}
 
// function which returns maximum length of substring
int answer(string& A, int n, int k)
{
    int maxlen = 1;

    maxlen = max(maxlen, findLen(A, n, k, 'x'));
    maxlen = max(maxlen, findLen(A, n, k, 'y'));
    
    return maxlen;
}

void solve() {
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<answer(s, s.size(), k)<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}