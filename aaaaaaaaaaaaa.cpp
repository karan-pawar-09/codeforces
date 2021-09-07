
#include<bits/stdc++.h>
using namespace std;

vector<int> printDivisors(int n)
{
    // Note that this loop runs till square root
    vector<int> ans;
    for (int i=1; i<=(n); i++)
    {
        if (n%i == 0)
        {
                ans.push_back(i);
        }
    }
    return ans;
}

/* Driver program to test above function */
int main()
{int t;
cin>>t;
while(t--){
    int a;
    cin>>a;
     vector<int> arr;
    arr=printDivisors(a);

        sort(arr.begin(), arr.end(), greater<int>());

        int q=arr.size();
        int k=(q-1)/2;
        vector<int> diameter;
        for(int i=0;i<k;i++){
            diameter.push_back(abs((arr[2*k-i])-(arr[i])));
        }
    int red=0,green=0;
    for(int i=(diameter.size()-1);i>=0;i=i-2){
        if(i!=0){
        red+=(diameter[i]*diameter[i])-(diameter[i-1]*diameter[i-1]);
        }
        else{
            red+=(diameter[i]*diameter[i]);
        }
    }
    red=abs(red);
    green=abs((diameter[0]*diameter[0])-red);
    cout<<red<<" "<<green;cout<<endl;
}

}
