#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector <int> v;
     for(int i=0;i<n;i++)
    {
        v.push_back(a[i]);
    }
    
  
    
   
    v.clear();
    //v.erase(v.begin(),v.end());
     for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
        //v[i]=v[i+1]-v[i];
    }
}