/*
    author:Karan
    created:06.07.2023 20:42:46
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

struct TrieNode {
    ll value;
    TrieNode* child[2];
    TrieNode() {
        this->value = 0;
        this->child[0] = this->child[1] = NULL;
    }
};

void insert(TrieNode* root, ll pre_xor) {
    TrieNode* temp = root;
    for (ll i = 31;i >= 0;i--) {
        bool curr = pre_xor & (1 << i);
        if (temp->child[curr] == NULL) {
            temp->child[curr] = new TrieNode();
        }
        temp = temp->child[curr];
    }
    temp->value = pre_xor;
}
ll query(TrieNode* root, ll pre_xor) {
    TrieNode* temp = root;
    for (ll i = 31;i >= 0;i--) {
        bool curr = pre_xor & (1 << i);
        if (temp->child[1 - curr] != NULL) {
            temp = temp->child[1 - curr];
        }
        else if (temp->child[curr] != NULL) {
            temp = temp->child[curr];
        }
    }
    return pre_xor ^ (temp->value);
}
ll maxSubarrayXOR(ll N, vector<ll>& arr) {
    TrieNode* root = new TrieNode();
    insert(root, 0);
    ll result = INT_MIN, pre_xor = 0;
    for (ll i = 0;i < N;i++) {
        pre_xor = pre_xor ^ arr[i];
        insert(root, pre_xor);
        result = max(result, query(root, pre_xor));
    }
    return result;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << maxSubarrayXOR(n, arr) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}