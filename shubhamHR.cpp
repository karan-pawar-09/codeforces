#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
string findSubstring(string s, int k) 
{
        int l=0;
    for(int i=0;s[i]!='\0';i++)
        l++;
     
    int a[l];
    int x=0,i=0,count=0;

    while(s[i]!= '\0')
    {
        count=0;
        for(i=x;i<(x+k);i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' )
                count++;
        }
        a[x++]= count;
    }
    
    int max=a[0],index=0;
    for(int i=0;i<x;i++)
    {
        if(max<a[i])
        {
            max= a[i];
            index = i;
        }
    }
    string subs=s.substr(index,k);
    return subs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string s;
    getline(cin, s);
    int k;
    cin>>k;
    string result = findSubstring(s, k);
    cout << result << "\n";
    fout.close();
    return 0;
}
