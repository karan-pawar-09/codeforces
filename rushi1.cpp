/*
    author:Karan
    created:31.08.2022 16:19:51
*/

#include<bits/stdc++.h>

int minPenalty(int input1, int input2[]) {
    std::sort(input2, input2+input1);
    int ans = 0;
    for(int i=1;i<input1;i++) {
        ans+=input2[i]-input2[i-1];
    }
    return ans;
}
void solve() {
    int n;
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        std::cin>>arr[i];
    }
    std::cout<<minPenalty(n, arr)<<std::endl;
}

int32_t main() {
    int t=1;
    while(t--) {
        solve();
    }
}