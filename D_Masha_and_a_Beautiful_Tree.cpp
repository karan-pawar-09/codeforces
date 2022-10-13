/*
    author:Karan
    created:13.10.2022 13:50:51
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

int res;

void merge(vector<int>& arr, int start, int end) {
    int mid = (start + end) / 2;
    int absdiff = abs(arr[start] - arr[mid]);
    int n = (end - start) / 2;
    if ((absdiff != n) || arr[start] == -1 || arr[mid] == -1) {
        for (int i = start;i < end;i++) {
            arr[i] = -1;
        }
    }
    else {
        if (arr[start] <= arr[mid]) {

        }
        else {
            res++;
            for (int i = start;i < mid;i++) {
                swap(arr[i], arr[mid + (i - start)]);
            }
        }
    }
}

void mergesort(vector<int>& arr, int start, int end) {
    if (end - start <= 1) {
        return;
    }
    mergesort(arr, start, (start + end) / 2);
    mergesort(arr, (start + end) / 2, end);
    merge(arr, start, end);
}

void solve() {
    int n;
    cin >> n;
    res = 0;
    vector<int> arr(n);
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    mergesort(arr, 0, n);
    if (arr[0] == -1) cout << -1 << endl;
    else cout << res << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}