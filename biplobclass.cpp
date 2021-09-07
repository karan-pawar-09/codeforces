#include<bits/stdc++.h>
using namespace std;
class Movie {
public:
vector<string> names;
vector<string> rating;
int watched=0;
};
int main() {
    Movie a;
    bool k=true;
    string input;
    string rat;
    string app;
    while(k) {
        cout<<"1) Add movie(without_space) and rating\n2) See all movies\n3) Enter Watched movie  name\n4)Watch Count\n5)end\n";
        char i;
        cin>>i;
        switch (i) {
            case '1' :
                
                cin>>input;
                cin>>rat;       
                a.names.push_back(input);
                a.rating.push_back(rat);
                
            break;
            case '2':
                for(int i=0;i<a.names.size();i++) {
                    cout<<a.names[i]<<" "<<a.rating[i]<<endl;
                }
            break;
            case '3':                
                cin>>app;          
                for(int i=0;i<a.names.size();i++) {
                    if(a.names[i]==app) {                      
                        a.watched++;
                    }
                }
            break;
            case '4':
            cout<<a.watched<<endl;
            break;
            case '5':
            k=false;
            break;
            defaut:
            k=false;
            break;
        }
    }
}