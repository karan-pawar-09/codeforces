/*
author:Karan
created:20.08.2021 11:02:29
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n=(int)items.size();
    vector<pair<int,string>> price;
    vector<pair<int,string>> relevance;
    vector<string> name;
    map<string,pair<int,int>> items;
    for(auto x: items) {
        price.push_back({x.second.second,x.first});
        relevance.push_back({x.second.first,x.first});
        name.push_back(x.first);
    }
    if(sortOrder==0) {
        sort(price.begin(),price.end());
        sort(relevance.begin(),relevance.end());
        sort(name.begin(),name.end());
    }
    else {
        sort(price.begin(),price.end(),greater<pair<int,string>>());
        sort(relevance.begin(),relevance.end(),greater<pair<int,string>>());
        sort(name.begin(),name.end(),greater<string>());
    }
    vector<string> ans;
    if(sortParameter==0) {
        for(int i=(itemsPerPage*(pageNumber-1));i<n && i<(itemsPerPage*(pageNumber));i++) {
            ans.push_back(name[i]);
        }
    }
    else if(sortParameter==1) {
        for(int i=(itemsPerPage*(pageNumber-1));i<n && i<(itemsPerPage*(pageNumber));i++) {
            ans.push_back(relevance[i]);
        }
    }
    else {
        for(int i=(itemsPerPage*(pageNumber-1));i<n && i<(itemsPerPage*(pageNumber));i++) {
            ans.push_back(price[i]);
        }
    }
    return ans;
}