#include <bits/stdc++.h>
using namespace std;

int ROW,COL;

bool isvalid(int row, int col, int prevRow, int prevCol) {	
	return (row >= 0) && (row < ROW) &&	(col >= 0) && (col < COL) && !(row== prevRow && col == prevCol);
}

int rowNum[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int colNum[] = {-1, 0, 1, -1, 1, -1, 0, 1};

set<string> s;

void DFS(vector<vector<char>> & mat, int row, int col, int prevRow, int prevCol, string word, string path, int index, int n) {
	if (index > n || mat[row][col] != word[index])
		return;
	path += string(1, word[index]) + "(" + to_string(row)+ ", " + to_string(col) + ") ";
	if (index == n)	{
        s.insert(path);
		return;
	}
	for (int k = 0; k < 8; ++k)
		if (isvalid(row + rowNum[k], col + colNum[k],prevRow, prevCol))
			DFS(mat, row + rowNum[k], col + colNum[k], row, col, word, path, index+1, n);
}

int findWords(vector<vector<char>> & mat,int m,int n, string word) {
    ROW=m;
    COL=n;
	s.clear();
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (mat[i][j] == word[0])
				DFS(mat, i, j, -1, -1, word, "", 0, (word.size() - 1));

    return s.size();
}

int main() {   
    int m,n;
    cin>>m>>n;
    int mat[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
	char* word;
	cin>>word;
	cout<<findWords(mat,m,n, word);
	return 0;
}