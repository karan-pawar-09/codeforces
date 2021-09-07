#include<bits/stdc++.h>
using namespace std;

struct Comp {
  bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    if (a.first != b.first) {
      return a.first < b.first;
    }
    return a.second > b.second;
  }

};

int main() {
    Comp comp_functor;
    int n,k;
    cin>>n>>k;
    long long arr[n];
    long long arr1[n];
    vector<pair<long long,long long>> input;
    for(int i=0;i<n;i++) {
        cin>>arr[i]>>arr1[i];
    }
    for(int i=0;i<n;i++) {
        input.push_back( make_pair(arr[i],arr1[i]) );
    }
    
    sort(input.begin(), input.end(), comp_functor);
    for(int i=0;i<k;i++) {
        input[0].first+=input[0].second;
        sort(input.begin(), input.end(), comp_functor);
    }
    cout<<input[0].first;

}