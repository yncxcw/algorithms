#include<iostream>
#include<list>

using namespace std;

class Graph
{
  int V;               //No .of vertices


  list<int> *adj;     //adjacent adday


public:
  Graph(int v);

  void addEdge(int v, int w);

  //travsese from a given source s
  void BFS(int s); 

  //traverse from a given source s
  void DFS(int s);

  void DFSUtil(int v, bool visited[]);

  bool DFSCycle();

  void printGraph();

  bool DFSCycleUtil(int v, bool visited[], bool stack[]);

};



Graph::Graph(int V)
{
  this->V  =V;
  this->adj=new list<int>[V];

}

void Graph::printGraph(){

 for(int i=0;i<this->V;i++){
     cout<<"node: "<<i<<endl;
   for(list<int>::iterator j=this->adj[i].begin();j!=this->adj[i].end();j++)
     cout<<" "<<*j<<" ";
   cout<<endl;
 }
 cout<<endl;

}

void Graph::addEdge(int v, int w){

  this->adj[v].push_back(w);
}

bool Graph::DFSCycle(){

  bool *visited=new bool[V];
  bool *stack  =new bool[V];

  for(int i=0;i<V;i++){
    visited[i]=false;
    stack[i]=false;  
  }
  
 for(int i=0;i<V;i++){
     for(int l=0;l<V;l++){
       stack[l]=false;
     }
     DFSCycleUtil(i,visited,stack);
   }
 
 return true;
}



bool Graph::DFSCycleUtil(int v, bool visited[],bool stack[]){

 bool find=false;
 if(!visited[v]){

  visited[v]=true;
  stack[v]=true;

 for(list<int>::iterator j=this->adj[v].begin();j!=this->adj[v].end();j++){
     if(!visited[*j] && this->DFSCycleUtil(*j,visited,stack))
        return true;
     else if(stack[*j]){
       cout<<"find one, the cycle is:"<<endl;
       for(int i=0;i<V;i++)
         if(stack[i])
            cout<<i<<" ";
       cout<<*j<<endl;
       return true;

    }
  }

 }

  stack[v]=false;
  return find;

}

void Graph::DFSUtil(int v, bool visited[]){
    visited[v]=true;
    cout<<v<<"   "<<endl;
    for (list<int>::iterator j=this->adj[v].begin();j!=this->adj[v].end();j++){
         if(!visited[*j])
            DFSUtil(*j,visited);
    }



}


void Graph::DFS(int v)
{
   bool *visited =new bool[V];
   for (int i=0;i<V;i++)
       visited[i]=false;

   for(int i=0;i < V;i++)
    if(visited[i] == false) 
       DFSUtil(v,visited);

}

void Graph::BFS(int s){

  bool *visited=new bool[this->V];
  for(int i=0;i<V;i++){
      visited[i]=false;
  }  


  list<int> queue;
  //starting from the point s
  visited[s]=true; 
  //push back s to the queue
  queue.push_back(s);

  while(!queue.empty()){
    //get first element;
    s=queue.front();
    //do sth. here
    cout<<s<<" "<<endl;
    //finish doing sth.
    queue.pop_front();
    //access its adjacent vertices
    for(list<int>::iterator i=this->adj[s].begin();i!=this->adj[s].end();i++){
       if(!visited[*i]){
           visited[*i]=true;
           queue.push_back(*i);
        }
     } 
   }
}


int main(){

    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(3, 1);
    g.addEdge(2, 3);
    g.addEdge(1, 4);
    g.addEdge(4, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";

    g.printGraph();
    g.DFSCycle();
 
    return 0;

}
