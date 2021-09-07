/*
author:Karan
created:08.07.2021 12:22:44
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

string countVoted(vector<string> validCandidates, vector<string> voteCasted) {
    map<string,int> M;
    for(int i=0;i<validCandidates.size();i++) {
        M[validCandidates[i]]=0;
    }
    M["invalidVotes"]=0;
    for(int i=0;i<voteCasted.size();i++) {
        if(M.find(voteCasted[i])!=M.end()) {
            M[voteCasted[i]]++;
        }
        else {
            M["invalidVotes"]++;
        }
    }
    string ans;
    int maxi=M["invalidVotes"];
    string winner="invalidVotes";
    for(auto x:M) {
        ans+=x.first+"="+to_string(x.second)+" ";
        if(x.second>maxi) {
            maxi=x.second;
            winner=x.first;
        }
    }
    ans+="Winner="+winner;
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n;
    vector<string> validCandidates(n);
    for(int i=0;i<n;i++) {
        cin>>validCandidates[i];
    }
    cin>>m;
    vector<string> voteCasted(m);
    for(int i=0;i<m;i++) {
        cin>>voteCasted[i];
    }
    string ans=countVoted(validCandidates,voteCasted);
    cout<<ans;
}   