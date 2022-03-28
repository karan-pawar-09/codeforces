/*
    author:Karan
    created:19.03.2022 20:58:01
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

ll findMaxGCD(vector<ll>& arr, ll n)
{
    // Calculating MAX in array
    ll high = 0;
    for (ll i = 0; i < n; i++)
        high = max(high, arr[i]);

    // Maintaining count array
    ll count[high + 1] = { 0 };
    for (ll i = 0; i < n; i++)
        count[arr[i]]++;

    // Variable to store the
    // multiples of a number
    ll counter = 0;

    // Iterating from MAX to 1
    // GCD is always between
    // MAX and 1. The first
    // GCD found will be the
    // highest as we are
    // decrementing the potential
    // GCD
    for (ll i = high; i >= 1; i--)
    {
        ll j = i;
        counter = 0;

        // Iterating from current
        // potential GCD
        // till it is less than
        // MAX
        while (j <= high)
        {
            // A multiple found

            if (count[j] >= 2)
                return j;

            else if (count[j] == 1)
                counter++;

            // Incrementing potential
            // GCD by itself
            // To check i, 2i, 3i....
            j += i;

            // 2 multiples found,
            // max GCD found
            if (counter == 2)
                return i;
        }
    }
    return 1;
}

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (ll i = 0;i < n;i++) {
        cin >> arr[i];
    }
    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        vector<ll> ar;
        for (ll i = l;i <= r;i++) {
            ar.push_back(arr[i]);
        }
        cout << findMaxGCD(ar, n) << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}