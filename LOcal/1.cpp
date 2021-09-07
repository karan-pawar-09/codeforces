//Karan Babasaheb Pawar
// Sch id=1912134
#include<bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin>>a;
    vector<int> arr(a);
    for(int i=0;i<a;i++) {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    cout<<arr.back();
}