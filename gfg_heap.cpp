// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void heapify(int arr[],int size,int index) {
        int largest=index;
        int l=2*index+1;
        int r=2*index+2;
        if(l<size&&arr[l]>arr[largest]) {
            largest =l;
        }
        if(r<size&&arr[r]>arr[largest]) {
            largest=r;
        }
        if(largest!=index) {
            swap(arr[index],arr[largest]);
            heapify(arr,size,largest);
        }
    }
    
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    vector<int> ans;
	    for(int i=n/2-1;i>=0;i--) {
	        heapify(arr,n,i);
	    }
	    
	    for(int i=n-1;k>0;i--) {
	        swap(arr[0],arr[i]);
	        heapify(arr,i,0);
	        ans.push_back(arr[i]);
	        k--;
	    }
	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}