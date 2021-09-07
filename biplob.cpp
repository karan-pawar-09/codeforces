#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=1;
    vector<int> a;
    while(t){
        cout<<"P- Print"<<endl<<"A- Add no"<<endl<<"M- Mean of nos"<<endl<<"S- Smallest no"<<endl<<"L- Largest no"<<endl<<"Q- Quit"<<endl;
        cout<<"Enter your choice"<<endl;

        char Choice;
        cin>>Choice;
        switch(Choice){
        case 'P': case 'p':
            if(a.size()){
            for(int i=0;i<a.size();i++){
                cout<<a[i]<<" ";
            }
            }
           else{
                cout<<"List is empty"<<endl;
            }
            cout<<endl;
            break;
        case 'A':case 'a':
            int n;
            cin>>n;
            a.push_back(n);
            cout<<n<<" added"<<endl;
            break;
        case 'M': case 'm':
            {double sum=0;
            for(int i=0;i<a.size();i++){
                sum+=a[i];
            }
            cout<<(sum/a.size())<<endl;}
            break;
        case 'S': case 's':
            cout<<(*(min_element(a.begin(),a.end())))<<endl;
            break;
        case 'L': case 'l':
            cout<<*(max_element(a.begin(),a.end()))<<endl;
            break;
        case 'Q': case 'q':
            cout<<"Program ended !!!!";
            t=0;
            break;

        default:
             cout<<"Unknown selection, Please try again"<<endl;
            break;
        }
        cout<<"---------------------------------------------------------------------------------------------"<<endl;
    }
}
