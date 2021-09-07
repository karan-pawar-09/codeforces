#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
ll answerr=0;
 
int main() {	
	int n, i, a, b, cnt; 
	scanf("%d", &n);
    vector<int> arr(n);
	for (i = 0; i < n; i++) {
		cin>>arr[i];
    }
	a = b = 0, cnt = 0;
	for (i = 0; i < n; i++) {
		if (arr[i] != a || arr[i] != b) {
			cnt++;
			if (arr[i] == a) {
				b = arr[i]; 
            }
			else if (arr[i] == b) {
				a = arr[i];
            }
			else if (i + 1 < n && arr[i + 1] == a) {
				a = arr[i];
            }
			else {
				b = arr[i];
            }
		}
    }
	cout<<cnt<<endl;
	return 0;
}