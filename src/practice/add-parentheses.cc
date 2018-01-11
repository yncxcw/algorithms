#include<iostream>
#include<vector>

using namespace std;
//fout 


class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        cout<<"intput:  "<<input<<endl;
        vector<int> results;
        for(int i=0;i<=input.size()-1;i++){
            if(input[i]=='*' || input[i]=='+'||input[i]=='-'){
                cout<<"intput[i] "<<i<<input[i]<<endl;
                cout<<"left  "<<input.substr(0,i)<<endl;
                cout<<"right "<<input.substr(i+1)<<endl; 

                vector<int>  left =diffWaysToCompute(input.substr(0,i));
                vector<int>  right=diffWaysToCompute(input.substr(i+1));
                for(auto a : left)
                   for(auto b : right)
                       switch(input[i]){
                           case '*':results.push_back(a*b);break;
                           case '+':results.push_back(a+b);break;
                           case '-':results.push_back(a-b);break;
                       }
                  
            }else{
         
              continue; 
            }
      }
      
      if(results.empty())
          results.push_back(stoi(input));
      
        return results;
        
    }
};


int main(){

 Solution *p=new Solution();
 p->diffWaysToCompute("2-1");





}
