#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool pairSort(const pair<pair<int,int>,int> &a,const pair<pair<int,int>,int> &b) { 
    return (a.first.second < b.first.second); 
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<pair<pair<int,int>,int>> arr;        
        for(int i=0;i<n;i++) {
            int w,h;
            cin>>w>>h;
            arr.push_back(make_pair(make_pair(w,-h),i+1));
            arr.push_back(make_pair(make_pair(h,-w),i+1));
        }
        sort(arr.begin(),arr.end(),pairSort);
        sort(arr.begin(),arr.end());        
        int element=-1;
        int minhight=(int)1e9+7;
        vector<int> ans(n,-1);
        for(int i=0;i<arr.size();i++) {
            int w=arr[i].first.first;
            int h=-arr[i].first.second;
            int index=arr[i].second;
            if(h>minhight) {
                if(ans[index-1]==-1) {
                    ans[index-1]=element;
                }
            }
            else {
                minhight=h;
                element=index;
            }
        }
        for(int i=0;i<n;i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}