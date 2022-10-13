/*
    author:Karan
    created:23.08.2022 17:22:15
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

// C++ program count total number of
// paths to reach B from B
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

// Function to count the number of
// steps in a tetrahedron
int countPaths(int n)
{
	// initially coming to B is B->B
	int count = 1;

	// cannot reach A, D or C
	int count1 = 0;

	// iterate for all steps
	for (int i = 1; i <= n; i++) {

		// recurrence relation
		int temp1 = count1 * 3;

		int temp2 = (count1 * 2 + count);

		// memoize previous values
		count = temp1;
		count1 = temp2;
	}

	// returns steps
	return count;
}


void solve() {
    int n;
    cin>>n;
    cout<<countPaths(n)<<endl;
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

