/*
author:Karan
created:24.08.2021 14:38:29
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

long int getMaxUnit(int num,vector<int> boxes,int unitSize, vector<int> unitPerBox,long trucksize) {
    if(num!=unitPerBox) {
        cout<<"WA"<<endl;
    }
    vector<pair<long int,long int>> arr;
    for(int i=0;i<unitSize&& i<num;i++) {
        arr.push_back({unitPerBox[i],boxes[i]});
    }
    sort(all(arr),greater<pair<long int,long int>>());
    int total=0;
    long int ans=0;
    for(int i=0;i<num&&i<unitSize;i++) {
        long int val=min(trucksize-total,arr[i].second)*arr[i].first;
        total+=min(trucksize-total,arr[i].second);
        ans+=val;
        if(total>=trucksize) {
            break;
        }        
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int num;
    
    int unitsize;

    long trucksize;
    cin>>num>>unitsize;
    vector<int> unitPerBox(unitsize);
    vector<int> boxes(unitsize);
    for(int i=0;i<unitsize;i++) {
        cin>>boxes[i];
    }
    for(int i=0;i<unitsize;i++) {
        cin>>unitPerBox[i];
    }
    cin>>trucksize;
    cout<<getMaxUnit(num,boxes,unitsize,unitPerBox,trucksize)<<endl;
}