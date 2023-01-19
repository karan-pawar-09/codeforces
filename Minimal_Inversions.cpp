/*
    author:Karan
    created:18.01.2023 20:58:53
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

ll _mergeSort(ll arr[], ll temp[], ll left, ll right);
ll merge(ll arr[], ll temp[], ll left, ll mid,
          ll right);
 
// This function sorts the
// input array and returns the
// number of inversions in the array
ll mergeSort(ll arr[], ll array_size)
{
    ll temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}
 
// An auxiliary recursive function
// that sorts the input array and
// returns the number of inversions in the array.
ll _mergeSort(ll arr[], ll temp[], ll left, ll right)
{
    ll mid, inv_count = 0;
    if (right > left) {
        // Divide the array into two parts and
        // call _mergeSortAndCountInv()
        // for each of the parts
        mid = (right + left) / 2;
 
        // Inversion count will be sum of
        // inversions in left-part, right-part
        // and number of inversions in merging
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
 
        // Merge the two parts
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
 
// This function merges two sorted arrays
// and returns inversion count in the arrays.
ll merge(ll arr[], ll temp[], ll left, ll mid,
          ll right)
{
    ll i, j, k;
    ll inv_count = 0;
 
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
 
            // this is tricky -- see above
            // explanation/diagram for merge()
            inv_count = inv_count + (mid - i);
        }
    }
 
    // Copy the remaining elements of left subarray
    // (if there are any) to temp
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    // Copy the remaining elements of right subarray
    // (if there are any) to temp
    while (j <= right)
        temp[k++] = arr[j++];
 
    // Copy back the merged elements to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}

ll getNumOfInversions(vector<ll> A) {
  ll N = A.size();
  if (N <= 1) {
    return 0;
  }
 
  vector<pair<ll, ll>> sortList;
  ll result = 0;
 
  // Heapsort, O(N*log(N))
  for (ll i = 0; i < N; i++) {
    sortList.emplace_back(A[i], i);
    push_heap(sortList.begin(), sortList.end());
  }
 
  // Create a sorted list of indexes
  vector<ll> x;
  while (!sortList.empty()) {
    // O(log(N))
    pair<ll, ll> v = sortList.front();
    pop_heap(sortList.begin(), sortList.end());
    sortList.pop_back();
 
    // Find the current minimum's index
    // the index y can represent how many minimums on the left
    ll y = lower_bound(x.begin(), x.end(), v.second) - x.begin();
 
    // i can represent how many elements on the left
    // i - y can find how many bigger nums on the left
    result += v.second - y;
 
    x.insert(lower_bound(x.begin(), x.end(), v.second), v.second);
  }
 
  return result;
}

void solve() {
    ll n;
    cin>>n;
    ll arr[n], temp[n];
    map<ll, ll> M;
    map<ll, ll> N;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        temp[i] = arr[i];
        M[arr[i]]++;
    }

    ll res = mergeSort(temp, n);
    ll p = res;
    ll ans = res;

    for(ll i=n-1;i>=0;i--) { 
        res -= (ll) (M[arr[i]+1]);
        res += N[arr[i]];
        ans = min(res, ans);
        M[arr[i]]--;
        N[arr[i]+1]++;
    }
    cout<<p - ans<<endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}