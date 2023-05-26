/*
    author:Karan
    created:24.05.2023 12:57:35
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

bool used[20];
int ar[20];
vector<vector<int>> ans;
void rec(int index, int n) {
    if(index == n) {
        vector<int> temp;
        for(int i=0;i<n;i++) {
            temp.push_back(ar[i]);
        }
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<n;i++) {
        if(!used[i]) {
            ar[index] = i;
            used[i] = true; 
            rec(index+1, n);
            ar[index] = -1;
            used[i] = false;
        }
    }
}

bool diff(string &a, string &b) {
    int count = 0;
    for(int i=0;i<a.size();i++) {
        if(a[i] != b[i]) {
            count++;
        }
    }
    if(count == 1) return true;
    else return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
       
    }
    for(int i=0;i<n;i++) {
        ar[i] = -1;
        used[i] = false;
    }
    rec(0, n);
    for(auto x: ans) {
        bool temp = true;
        
        for(int i=1;i<x.size();i++) {
            if(diff(arr[x[i]], arr[x[i-1]])) {

            } else {
                temp = false;
            }
        }
        if(temp) {
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
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