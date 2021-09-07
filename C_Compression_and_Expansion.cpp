/*
author:Karan
created:31.05.2021 13:12:33
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> st;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            if (a[i] == 1) {
                st.push_back(1);
            } else {
                while (st.back() != a[i] - 1) {
                    st.pop_back();
                }
                ++st.back();
            }
            for(int j=0;j<st.size();j++) {
                if(j) {
                    cout<<"."<<st[j];
                }
                else {
                    cout<<st[j];
                }
            }
            cout<<endl;
        }
    }
}