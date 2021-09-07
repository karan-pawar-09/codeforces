#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        set<int> a;
        for(int i=0;i<n;i++){
            a.insert(arr[i]);
        }
    auto it=a.end();
    it--;
    int max=*it;
    int i=1;
 
       while(x||(a.find(i) != a.end())){
           if (a.find(i) == a.end()){
             x--;
            }	
            ++i;
       }
    if (a.find(i) == a.end()){
        cout<<(i-1)<<endl;
    }
    else {
        cout<<(i)<<endl;
    }
    
    }
}