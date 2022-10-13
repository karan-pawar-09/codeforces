#include<bits/stdc++.h>
using namespace std;
int n;
set<vector<string>> res;
int iptr[10], jptr[10];
int isThere[10][10];
void AddAns() {
    vector<string> temp;
    for (int i = 0;i < n;i++) {
        string t = "";
        for (int j = 0;j < n;j++) {
            if (isThere[i][j])
                t += 'Q';
            else t += '.';
        }
        temp.push_back(t);
    }
    res.insert(temp);
}
bool check(int a, int b) {
    if (iptr[a] || jptr[b]) return false;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (isThere[i][j]) {
                if (abs(a - i) == abs(b - j)) {
                    return false;
                }
            }
        }
    }
    return true;
}
void rec(int q ,int iprev,int jprev) {
    if (q == n) {
        AddAns();
        return;
    }
    for (int i = iprev;i < n;i++) {
        int j;
        if(i==iprev) j=jprev;
        else j=0;
        for (;j < n;j++) {
            if (check(i, j)) {
                // cout<<q<<" "<<i<<" "<<j<<endl;
                iptr[i]++;
                jptr[j]++;
                isThere[i][j] = 1;
                // cout<<"++++++++++++" <<iptr[i]<<" "<<jptr[j]<<endl;
                rec(q + 1,i,j);
                iptr[i]--;
                jptr[j]--;
                isThere[i][j] = 0;
                // cout<<"------------" <<iptr[i]<<" "<<jptr[j]<<endl;
            }
        }
    }

    return;
}

vector<vector<string>> solveNQueens(int nn) {
    n = nn;
    res.clear();
    memset(isThere, 0, sizeof(isThere));
    memset(iptr, 0, sizeof(iptr));
    memset(jptr, 0, sizeof(jptr));
    rec(0,0,0);
    vector<vector<string>> ans(res.begin(), res.end());
    return ans;
}


int main() {
    int xx;
    cin >> xx;
    vector<vector<string>> ans = solveNQueens(xx);
    for (auto x : res) {
        for(auto y: x) {
            cout<<y<<" ";
        }
        cout<<endl;
    }
}