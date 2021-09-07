#include <bits/stdc++.h>

using namespace std;

// Complete the palindromeIndex function below.
int palindromeIndex(string s) {
    
    int n=s.size();
    //cout<<n<<endl;
    int r=n-1;
    int l=0;
    while(l<r) {
        if(s[l]!=s[r]) {
            if(s[l]==s[r-1]){
                return r;
                break;
            }
            else{
                return l;
                break;
            }
        }
        else{
            l++;
            r--;
        }
    }
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        cout<< result << "\n";
    }

    fout.close();

    return 0;
}