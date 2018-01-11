#include<iostream>
#include<vector>

using namespace std;

int main(){


vector<int> nums={1,1,1};
vector<pair<int,int>>={{1,0},
                       {0,1},
                       {-1,0},
                       {0,-1},
                      };

for(auto i : nums){
   if(i == 1){
    cout<<"here";
    continue;
  }
  else{
    break;
 }
 
}


return 0;
}
