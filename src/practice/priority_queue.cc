#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){

priority_queue<int> queue;

for(int n: {1,3,2,9,7,6,5})
  queue.push(n);

while(!queue.empty()){
  cout<<queue.top()<<endl;
  queue.pop();
}



return 0;
}
