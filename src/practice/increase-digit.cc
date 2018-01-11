#include<iostream>
#include<vector>
class Solution {
public:

    int monotoneIncreasingDigits(int N) {
     std::string n_str = std::to_string(N);
     int marker = n_str.size();
		             
     for(int i = n_str.size()-1; i > 0; i --) {
            if(n_str[i] < n_str[i-1]) {
                  marker = i;
	          n_str[i-1] = n_str[i-1]-1;
	     }
      }
											             
      for(int i = marker; i < n_str.size(); i ++) n_str[i] = '9';
													             
      return stoi(n_str);														             return stoi(n_str);
    }
   
   int monotoneIncreasingDigits2(int N){
    std::string n_str=std::to_string(N);

    //find first violation
    int i;
    for(i=0;i<n_str.size() && n_str[i]<=n_str[i+1];i++);
  
    std::cout<<"first violation: "<<i<<std::endl;
    if(i==n_str.size()-1){
      return N;
    }
    //find firt equal one
    int j;
    for(j=i; j>=0 && n_str[j]==n_str[j-1];j--);

    //find the mark
    n_str[j]-=1;

    //std::cout<<"first mark: "<<j<<std::endl;
    int k;
    for(k=j+1;k<n_str.size();k++){
     n_str[k]='9';
    }
   
    return stoi(n_str);
   }



};


int main(){

Solution *p =new Solution();

std::cout<<p->monotoneIncreasingDigits2(1234)<<std::endl;


}
