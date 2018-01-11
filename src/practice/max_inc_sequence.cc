#include<iostream>
#include<vector>


//dp[i] = dp[j] + 1 for any j<i and array[j] < array[i]

int max_inc_list(std::vector<int>& array){

  std::vector<int> dp(array.size(),1);
  dp[0]=1;
  int max=1;
  for (int i=1;i<array.size();i++){
      dp[i] = 1;
      for(int j=0;j<i;j++){
        if(array[i] > array[j] && dp[j]+1 > dp[i]){
	   dp[i] = dp[j] + 1;
	}
      }
     if(dp[i] > max){
       max = dp[i];
     }
  }
return max;
}

int main(){

int tarray[8]={1,-1,2,-3,4,-5,6,-7};
std::vector<int> array(tarray,tarray+8);

int max = max_inc_list(array);

std::cout<<max<<std::endl;

return 0;
}
