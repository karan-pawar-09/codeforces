/*
author:Karan
created:22.07.2021 20:09:29
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const int N = 1e5+7;
int n, m;
char s[N], t[N];

int32_t main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int q;
    scanf("%d",&q);    
    while(q--) {  
        scanf("%s %s", s, t);

        n = (int)strlen(s);
        m = (int)strlen(t);

        bool ans=false;
        int j=m-1;
        int i=n-1;
        if(n<m) {
            
        }
        else{
            while((s[i]!=t[j])) {
                i-=2;
            }
            while((i>=0)&&(j>=0)) {
                if(s[i]==t[j]) {
                    i--;
                    j--;
                }
                else {
                    i-=2;
                }
            }
            if(j==-1) ans=true;
        }

        if(ans) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
}
