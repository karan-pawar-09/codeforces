    #include<bits/stdc++.h>
    using namespace std;
    int main() {
        string t;
        cin>>t;
        int count=0;
        for(int i=0;i<t.size();i++) {
            if((t[i]=='a'||t[i]=='e'||t[i]=='i'||t[i]=='o'||t[i]=='u')){
                t[i]='1';
            }
            else{
                t[i]='0';
            }
        }
        ;
        int r=0,l=t.size()-1;
       /* while(t[r]!='0'){
            r++;
        }
        while(t[l]!='0'){
            l--;
        }
        */
        for(int i = 0;i<t.size();i++){
        if(t[i]=='1')
            continue;
        else{
            r = i;
            break;
        }
    }
 
    for(int i = t.size()-1;i>=0;i--){
        if(t[i]=='1')
            continue;
        else{
            l = i;
            break;
        }
    }


        for(int i=r+1;i<l;i++) {
            if(t[i]=='1'){
                count++;
            }
        }
        if(r<=l) {
        cout<<count;
        }
        else{
            cout<<"0";
        }
    }