// C++ program to find out maximum profit by
// buying and selling a share atmost k times
// given stock price of n days

/*
    author:Karan
    created:19.08.2022 19:02:38
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


// Function to find out maximum profit by buying
// & selling a share atmost k times given stock
// price of n days
int maxProfit(vector<int> price, int n, int k)
{
	// table to store results of subproblems
	// profit[t][i] stores maximum profit using
	// atmost t transactions up to day i (including
	// day i)
	int profit[k + 1][n + 1];

	// For day 0, you can't earn money
	// irrespective of how many times you trade
	for (int i = 0; i <= k; i++)
		profit[i][0] = 0;

	// profit is 0 if we don't do any transaction
	// (i.e. k =0)
	for (int j = 0; j <= n; j++)
		profit[0][j] = 0;

	// fill the table in bottom-up fashion
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j < n; j++) {
			int max_so_far = INT_MIN;

			for (int m = 0; m < j; m++)
				max_so_far = max(max_so_far,
								price[j] - price[m] + profit[i - 1][m]);

			profit[i][j] = max(profit[i][j - 1], max_so_far);
		}
	}

	return profit[k][n - 1];
}

// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) {
    int n, k;
    cin>>n>>k;
    vector<int> price(n);
    for(int i=0;i<n;i++) {
        cin>>price[i];
    }

	cout <<maxProfit(price, n, k)<<endl;

    }
}
