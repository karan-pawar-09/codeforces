/*
    author:Karan
    created:06.07.2023 14:28:27
*/

#include<bits/stdc++.h>
using namespace std;
int func(vector<int>& nums, int k) {
    int i = 0, j = 0;
    int n = nums.size();
    int maxi = 0;
    int ii = -1;
    int jj = -1;
    while (j < n) {
        if (nums[j] == 0) {
            k--;
        }
        if (k < 0) {
            if (nums[i] == 0) {
                k++;
            }
            i++;
        }
        j++;
        if (j - i > maxi) {
            ii = i;
            jj = j;
            maxi = j - i;
        }
    }
    cout << ii << " " << jj - 1 << endl;
    return j - i;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<func(arr, k)<<endl;
}