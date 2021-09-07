#include<bits/stdc++.h>
using namespace std;
bool sgn(long a) {
    if(a>0) {
        return true;
    }
    else{
        return false;
    }
}
int main() {
    int t;
    cin>>t;
    
    while(t--) {
        int n;
        cin>>n;
        long arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        long long sum = 0;
		for (int i = 0; i < n; ++i) {
			long cur = arr[i];
			int j = i;
			while (j < n && sgn(arr[i]) == sgn(arr[j])) {
				cur = max(cur, arr[j]);
				++j;
			}
			sum += cur;
			i = j - 1;
		}
		cout << sum << endl;
	
    }
}