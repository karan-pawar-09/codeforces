/*
    author:Karan
    created:11.12.2021 15:47:52
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
    int n,a,b;
    cin>>n>>a>>b;
    if(abs(a-b)>1 or (a>(n-2)/2 and b>(n-2)/2)) {
        cout<<-1<<endl;
    }
    else if((n%2) and max(a,b)>(((n-2)/2)+1)) {
        cout<<-1<<endl;
    }
    else if(((n%2)==0) and (a>(n-2)/2 or b>(n-2)/2)) {
        cout<<-1<<endl;
    }
    else {
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            arr[i]=i+1;
        }
        if(b>a) {
            sort(all(arr),greater<int>());
        }
        int tst=(n-2)/2;
        int rem=tst-a;
        if(n%2) {
            rem++;
        }
        rem+=tst-b;
        for(int i=0;i<=rem;i++) {
            cout<<arr[i]<<" ";
        }
        int start=rem+1;
        int end=n-1;
        while(start<=end) {
            if(start==end) {
                cout<<arr[start]<<" ";
            }
            else {
                cout<<arr[end]<<" ";
                cout<<arr[start]<<" ";
            }
            start++;
            end--;
        }
        cout<<endl;
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