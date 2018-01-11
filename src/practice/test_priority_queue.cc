#include <functional>
#include <queue>
#include <vector>
#include <iostream>


struct task{
  int   id;
  int   time;
  
  bool operator < (const task t2) const {return time > t2.time;}
};


bool compare_less(task a, task b){

  return a.time < b.time;
}


template<typename T>void output_queue(T& q){

while(!q.empty()){
 
  std::cout<<q.top().id<<std::endl;
  q.pop(); 
}


}




int main(){

std::priority_queue<task> q;

for(int i=0;i<10;i++){
   task t={
     .id=i,
     .time=i
  };
q.push(t); 
}

output_queue(q);
}
