#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr={3,2,2,6,1,5,9,4,2,3,6,9};
    cout<<*min_element(arr.begin(),arr.begin()+5);
}