#include<bits/stdc++.h>
using namespace std;
int main() {
     vector<int> arr(4);
    for(int i=0;i<4;i++){
        int n;
        cin>>n;
        arr[i].push_back(n);
        int t;
        cin>>t;
        arr[i].push_back(t);
    }
    int k;
    cin>>k;
    arr[3].push_back(k);
   for(int i=0;i<arr.size();i++){
   	for(int j=0;j<arr[i].size();j++){
   		cout<<arr[i][j];
	   }
	   cout<<endl;
   }
}