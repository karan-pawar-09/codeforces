#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool isGood(int i,int j) {
    if((i>=0)&&(i<8)&&(j>=0)&&(j<8)) {
        return true;
    }
    else {
        return false;
    }
}
bool canmove(int i,int j,vector<vector<bool>> &game) {
    bool ans=false;
    vector<int> a={1,1,0,-1,-1,-1,0,1};
    vector<int> b={0,1,1,1,0,-1,-1,-1};
    for(int k=0;k<8;k++) {
        if(isGood((i+a[k]),(j+b[k]))) {
            if(!game[i+a[k]][j+b[k]]) {
                ans=true;
                break;
            }
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<char>> board(8,vector<char>(8,'.'));
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            cin>>board[i][j];
        }
    }
    vector<vector<bool>>game(8,vector<bool> (8,false));
    vector<int> a={1,1,0,-1,-1,-1,0,1};
    vector<int> b={0,1,1,1,0,-1,-1,-1};
    int posi,posj;
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(board[i][j]=='B') {
                posi=i;
                posj=j;
            }
            if(board[i][j]=='W') {                
                for(int k=0;k<8;k++) {
                    if(isGood((i+a[k]),(j+b[k]))) {                        
                            game[i+a[k]][j+b[k]]=true;                                              
                    }
                }
            }
            if(board[i][j]=='Q') {               
                for(int p=i+1;p<8;p++) {                    
                    game[p][j]=true;
                    if(board[p][j]!='.'&&board[p][j]!='B') {                            
                        break;                                              
                    }                                     
                }
                for(int p=i-1;p>=0;p--) {                    
                    game[p][j]=true;
                    if(board[p][j]!='.'&&board[p][j]!='B') {                            
                        break;                                              
                    }                     
                 }
                for(int p=j+1;p<8;p++) {                    
                    game[i][p]=true;
                    if(board[i][p]!='.'&&board[i][p]!='B') {                            
                        break;                                              
                    }                                                           
                }
                for(int p=j-1;p>=0;p--) {                   
                    game[i][p]=true;
                    if(board[i][p]!='.'&&board[i][p]!='B') {                            
                        break;                                              
                    }                                                           
                }
                int ss=0;
                while(isGood((i-ss),(j-ss))) {
                    if(ss!=0) {
                        game[i-ss][j-ss]=true;
                        if(board[i-ss][j-ss]!='.'&&board[i-ss][j-ss]!='B') {                         
                            break;                                               
                        }   
                    }                                                       
                    ss++;
                }
                ss=0;
                while(isGood((i+ss),(j+ss))) {
                    if(ss!=0) {
                        game[i+ss][j+ss]=true;
                        if(board[i+ss][j+ss]!='.'&&board[i+ss][j+ss]!='B') {                         
                            break;                                               
                        }   
                    }                                                       
                    ss++;
                }                
                ss=0;
                while(isGood((i-ss),(j+ss))) {
                    if((i-ss)!=i&&(j+ss)!=j) {
                        game[i-ss][j+ss]=true;
                        if(board[i-ss][j+ss]!='.'&&board[i-ss][j+ss]!='B') {                        
                            break;                                                    
                        }  
                    }                                       
                    ss++;
                }
                ss=0;
                while(isGood((i+ss),(j-ss))) {
                    if((i+ss)!=i&&(j-ss)!=j) {
                        game[i+ss][j-ss]=true;
                        if(board[i+ss][j-ss]!='.'&&board[i+ss][j-ss]!='B') {                        
                            break;                                                    
                        }
                    }                     
                    ss++;
                }
              
            }
            if(board[i][j]=='R') {
               for(int p=i+1;p<8;p++) {                    
                    game[p][j]=true;
                    if(board[p][j]!='.'&&board[p][j]!='B') {                            
                        break;                                              
                    }                                     
                }
                for(int p=i-1;p>=0;p--) {                    
                    game[p][j]=true;
                    if(board[p][j]!='.'&&board[p][j]!='B') {                            
                        break;                                              
                    }                     
                 }
                for(int p=j+1;p<8;p++) {                    
                    game[i][p]=true;
                    if(board[i][p]!='.'&&board[i][p]!='B') {                            
                        break;                                              
                    }                                                           
                }
                for(int p=j-1;p>=0;p--) {                   
                    game[i][p]=true;
                    if(board[i][p]!='.'&&board[i][p]!='B') {                            
                        break;                                              
                    }                                                           
                }          
            }
            if(board[i][j]=='S') {
                int ss=0;
                while(isGood((i-ss),(j-ss))) {
                    if(ss!=0) {
                        game[i-ss][j-ss]=true;
                        if(board[i-ss][j-ss]!='.'&&board[i-ss][j-ss]!='B') {                         
                            break;                                               
                        }   
                    }                                                       
                    ss++;
                }
                ss=0;
                while(isGood((i+ss),(j+ss))) {
                    if(ss!=0) {
                        game[i+ss][j+ss]=true;
                        if(board[i+ss][j+ss]!='.'&&board[i+ss][j+ss]!='B') {                         
                            break;                                               
                        }   
                    }                                                       
                    ss++;
                }                
                ss=0;
                while(isGood((i-ss),(j+ss))) {
                    if((i-ss)!=i&&(j+ss)!=j) {
                        game[i-ss][j+ss]=true;
                        if(board[i-ss][j+ss]!='.'&&board[i-ss][j+ss]!='B') {                        
                            break;                                                    
                        }  
                    }                                       
                    ss++;
                }
                ss=0;
                while(isGood((i+ss),(j-ss))) {
                    if((i+ss)!=i&&(j-ss)!=j) {
                        game[i+ss][j-ss]=true;
                        if(board[i+ss][j-ss]!='.'&&board[i+ss][j-ss]!='B') {                        
                            break;                                                    
                        }
                    }                     
                    ss++;
                }
            }  
            
        }   

    } 
    if(game[posi][posj]) {
        if(canmove(posi,posj,game)) {
            cout<<"Check"<<endl;
        }
        else {
            cout<<"CheckMate"<<endl;
        }
    }
    else {
        if(canmove(posi,posj,game)) {
            cout<<"Nothing"<<endl;
        }
        else {
            cout<<"StaleMate"<<endl;
        }
    }

}