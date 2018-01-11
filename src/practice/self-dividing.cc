#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool judge(int N){
        cout<<N<<endl;
        int M = N;
	while(N){
           int res=N%10;
           if(res == 0)
	       return false;
	   else if(M%res!=0)
	       return false;
	   else{
	       N/=10;
	       continue;
	   }
	}
        return true;
}

vector<int> selfDividingNumbers(int left, int right) {
																			        vector<int> results;
for(int i=left;i<=right;i++){
  if(judge(i)){	
    results.push_back(i);	
   } 
  }
   return results; 
 }




};

int main(){

 Solution *p=new Solution();
 vector<int> results=p->selfDividingNumbers(1,22);
}
