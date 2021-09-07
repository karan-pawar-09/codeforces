#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() 
{
    int t;   cin>>t;
    while(t--)
    {
        int n;    cin>>n;
        string s;   cin>>s;
        string st;
        string r="BAZINGA";
        int k=0;
        for(int i=0;i<n;i++)
        {   
            if(k<7) {
                if(s[i]==r[k])
                {
                    st.push_back(r[k]);
                    k++;
                }
            }
        }
        if(st.compare(r)==0)    cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
    }
    
    return 0;
}