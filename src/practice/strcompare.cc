#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution {
public:

    
    
    bool compare(string s, string t){
        map<char,char> smap;
        string temp;
        if(s==t){
          return true;    
        }
        for(int i=0;i<s.size();i++){
              char tchar;
              //build new key mapping
              if(smap.find(s[i])==smap.end()){
                  smap[s[i]]=t[i];
                  tchar=t[i];
              }else{
                  
                  tchar=smap[s[i]];
              }
              cout<<"tchar"<<tchar<<"  "<<"ti"<<t[i]<<endl; 
              if(tchar!=t[i]){
                 cout<<"r1"<<endl;
                 return false;
               }
              temp+=tchar;     
              
        }
        
        if(temp==t){
           cout<<"r2"<<endl;
           return true;
        }
        else{
           cout<<"r3"<<endl;
           return false;
        }
        
        
    }
    bool isIsomorphic(string s, string t) {
        
        return compare(s,t);
       
        
    }
};


int main(){
Solution *p = new Solution();

cout<<p->isIsomorphic("aa","ab")<<endl;


return 0;

}
