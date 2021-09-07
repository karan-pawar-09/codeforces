#include<bits/stdc++.h>
using namespace std;
int main() {
    string a;
    cin>>a;
    vector<char> ans;
    for(int i=0;i<a.size();i++){
        if(a[i]>46){
            ans.push_back(a[i]);
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<(ans.size()-1);i++){
        cout<<ans[i]<<"+";
    }
    cout<<ans[(ans.size()-1)];
   /* char a=6;
    cout<<int(a);*/
}
