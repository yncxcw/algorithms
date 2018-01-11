#include<iostream>


void max_sequence(int array[],int array_len)
{

//initialize
int *dp      =new int[array_len];
dp[0]        =array[0];
int maxsum   =array[0];


//dp
for(int i=1;i<array_len;i++){
   dp[i]=std::max(array[i],dp[i-1]+array[i]);
   if (dp[i] > maxsum){
       maxsum=dp[i];
   }

}
std::cout<<maxsum<<std::endl;
}


int main(){

int array[6]={0,-2,3,5,-1,2};

max_sequence(array,6);

return 0;

}
