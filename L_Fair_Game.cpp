#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) {
        cin>>vec[i];
    }
    vector<int> ans(101,0);
    int no=0;
    int sum=0;   
    for(int i=0;i<n;i++) {
        ans[vec[i]]++;
    }
    vector<int>answ;
    vector<int>kk;
    for(int i=0;i<101;i++) {
        if(ans[i]!=0) {
            no++;
            sum+=ans[i];
            answ.push_back(i);
            kk.push_back(ans[i]);
        }
    }
    if(no==2&&sum==n&&kk[0]==kk[1]){
        cout<<"YES"<<endl;
        for(int i=0;i<answ.size();i++) {
            cout<<answ[i]<<" ";
        }
    }
    else{
        cout<<"NO";
    }
}