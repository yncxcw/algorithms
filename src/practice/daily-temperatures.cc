#include<iostream>
#include<vector>


class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
          std::vector<int> days(temperatures.size(),0);
	  for(int i=0; i<temperatures.size();i++){
	      int j=i;
	      while(j<temperatures.size() && temperatures[i]>=temperatures[j])
	          j++;
	      if(j<temperatures.size())
	        days[i]=j-i;
	      else
	        days[i]=0;
									        
	   }
    return days;
  }

 //从后面遍历整个数组，维护一个temperature到day的映射 temp->day
 //每次查找的时候，只需要找打一个min temp[i] for each i > current temperature
  std::vector<int> dailyTemperatures1(std::vector<int>& temperatures) {
      
      std::vector<int> days(temperatures.size(),0);
      std::vector<int> temp(101,INT_MAX);

      for(int i=temperatures.size()-1;i>=0;i--){
         int dtemp=temperatures[i];
	 int wait=INT_MAX;
	 for(int j=dtemp+1;j<=100;j++){
	       wait=std::min(wait,temp[j]);
	 }
        if(wait != INT_MAX)
	   days[i]=wait-i;
  	temp[dtemp]=i;    
      }
     
  return days;
  
  }

    void outputs(std::vector<int>& outputs){
       for(auto output : outputs){
         std::cout<<output<<" ";
       }
       std::cout<<std::endl;
    
    }


};

int main(){

Solution *p =new Solution();
int tarray[8]={73,74,75,71,69,72,76,73};
std::vector<int> input(tarray,tarray+8);
std::vector<int> output=p->dailyTemperatures1(input);
p->outputs(output);
return 0;
}
