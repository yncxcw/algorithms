#include<iostream>

using namespace std;

struct edge_node{
  int adjvex;   //index for this node   
  Node *ptr;    //point to next node
};

struct vetex_node{
  char value;     //value for this node
  edge_node *ptr  //point to its first edge
};


Node *graph  =new Node[10];
bool  visited=new bool[10];

bool is_visit(int node_index){

return visited[node_index];

}

void visit(int node_index){

//do something here;
visited[node_inedx]=true;

}

edge_node* first_adjacent(int node_index){

 return graph[node_index].ptr;
}

edge_node* next_adjacent(edge_node* e_node){

return e_node->ptr;
}

void dfs(int node_index){

  visit(graph[node_index]) 
  //traverse for its siblings
  for(edge_node* e_node=next_adjacent(node_index); e_node!=null;e_node=next_adjacent(e_node)){
     if(!is_visit(e_node->index)){
     dfs(e_node->index);
    }
  }
    
}


queue<int> node_stack;

void bfs(int node_inedx){

//traverse every node
    visit(node_index);
    queue.push(node_index);
    while(!queue.empty()){
        int n_index=queue.top();
        queue.pop()
        for(edge_node *e_node=next_adjacent(n_index);e_node!=null;e_node=next_adjacent(e_node)){
            if(!is_visit(e_node->index)){
                visit(e_node->index);
                queue.push(e_node->index);
            }
        }
    }
    return;
}

