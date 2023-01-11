/*
    author:Karan
    created:07.01.2023 19:43:07
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

char* modify_variableName(const char* s) { 
    int n = strlen(s);
    int count = 0;
    int caps = 0;
    for(int i=0;i<n;i++) {
        if(s[i] != '_') {
            count++;
        }
        if(s[i]>='A' && s[i] <='Z') {
            caps++;
        }
    }
    if(caps == 0) {
      
        char* ans = (char*)malloc(sizeof(char) * count);
        int indx = 0;
        for(int i=0;i<n;i++) {
            if(i > 0 && s[i-1] == '_') {
                ans[indx] = (char)('A'+(s[i]-'a'));
                indx++;
            } else {
                if(s[i] != '_') {
                    ans[indx] = s[i];
                    indx++;
                }
            }
        }
        return ans;
    } else {
        
        char* ans = (char*)malloc(sizeof(char) * (caps+n));
        int indx = 0;
        for(int i=0;i<n;i++) {
            if(i<n-1 && (s[i+1] >= 'A' && s[i+1] <='Z')) {
                ans[indx] = s[i];
                indx++;
                ans[indx] = '_';
                indx++;
                ans[indx] = (char)('a'+(s[i+1]-'A'));
                indx++;
                i++;
            } else {
                ans[indx++] = s[i];
            }
        }
        return ans;
    }
}
void solve() {
const char* s= "this_is_test";
    
cout<<modify_variableName(s)<<endl;
    const char* s1 = "thisIsTest";
    cout<<modify_variableName(s1)<<endl;
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