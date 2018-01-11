class Solution {
public:
    vector<int> snums;
 
    int minmum;
    
    void dfs(vector<int>& stack, int target, int index){
        
        if(stack.size() > minmum){
            
             return;
        }
        
        if(target == 0){
            if(stack.size() < this->minmum)
                minmum = stack.size();
            return;
        }
        
        for(int i=index;i>=0;i--){
            if(target < this->snums[i]) continue;
            stack.push_back(snums[i]);
            dfs(stack,target - snums[i],i);
            stack.pop_back();
        }
        
          
        
    }
    
    int numSquares(int n) {
       int p=1;
       while(p*p<INT_MAX)
       {
         snums.push_back(p*p);
         p++;  
       }
    
      cout<<snums.size()<<endl;;
      //find starting searching point
      int index;
      for(index=0;index<snums.size();index++)
      {    
          if(n==snums[index])
              return 1;
          if(snums[index] < n && snums[index+1] > n)
              break;
      }
        
        vector<int> stack;
        this->minmum = snums.size();
        dfs(stack,n,index);
        return this->minmum;
        
    }
};
