// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
#define int long long
 // } Driver Code Ends


//User function Template for C++

class Solution {
public:
    long long upperbound(vector<long long> arr,long long a,long long x,long long i) {
        long long l=i+1;
        long long r=arr.size();
        while(l+1<r) {
            long long m=l+(r-l)/2;
            if(arr[m]*a<=x) {
                l=m;
            }
            else {
                r=m;
            }
        }
        return l;
    }
    long long lowerbound(vector<long long> arr,long long a,long long y,long long i) {
        long long l=i+1;
        long long r=arr.size()-1;
        while(l+1<r) {
            long long m=l+(r-l)/2;
            if(arr[m]*a>=y) {
                r=m;
            }
            else {
                l=m;
            }
        }
        return r;
    }
	int TotalPairs(vector<int>&nums, int x, int y){
	    int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> arr(n+2);
        arr[0]=(long long)-1e9+7;
        for(int i=1;i<=n;i++) {
            arr[i]=(long long)nums[i-1];
        }
        arr[n+1]=(long long)1e9+7;
        int ans=0;
        for(int i=0;i<n;i++) {
            long long l=lowerbound(arr,(long long) nums[i],(long long) x,(long long) i);
            long long r=upperbound(arr,(long long) nums[i],(long long) y,(long long) i);  
            ans+=max(0LL,r-l+1);          
        }
        return ans;
	}
};

// { Driver Code Starts.
int32_t main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, x, y;
		cin >> n >> x >> y;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.TotalPairs(nums, x, y);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends