/*
    author:Karan
    created:05.02.2022 12:41:27
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

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    int odd=0,even=0;
    int indx=0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i]%2) {
            indx=i+1;
            odd++;
        } else {
            even++;
        }
    }
    if(odd==0) {
        cout<<-1<<endl;
        return;
    }
    int res=0;
    int res1=0;
    for(int i=0;i<n;i++) {
        if(i%2==0) {
            if(arr[i]%2) {
                res++;
            }
        } else {
            if(arr[i]%2==0) {
                res++;
            }
        }
    }
    for(int i=0;i<n;i++) {
        if(i%2) {
            if(arr[i]%2) {
                res1++;
            }
        } else {
            if(arr[i]%2==0) {
                res1++;
            }
        }
    }
    cout<<min(res1,res)<<endl;
    vector<pair<int,int>> ar;
     if(res<=res1) {        
        for(int i=0;i<n;i++) {
            if(i%2==0) {
                if(arr[i]%2) {
                    if(i<=1) {
                        ar.push_back({i+1,indx});
                    } else {
                        ar.push_back({i+1,2});
                    }
                }
            } else {
                if(arr[i]%2==0) {
                    if(i<=1) {
                        ar.push_back({i+1,indx});
                    } else {
                        ar.push_back({i+1,2});
                    }
                }
            }
        }
    } else {
        for(int i=0;i<n;i++) {
            if(i%2) {
                if(arr[i]%2) {
                    if(i<1) {
                        ar.push_back({i+1,indx});
                    } else {
                        ar.push_back({i+1,1});
                    }
                }
            } else {
                if(arr[i]%2==0) {
                    if(i<1) {
                        ar.push_back({i+1,indx});
                    } else {
                        ar.push_back({i+1,1});
                    }
                }
            }
        }
    }
    // assert(ar.size()==min(res,res1));
    for(auto x:ar) {
        cout<<x.first<<" "<<x.second<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}