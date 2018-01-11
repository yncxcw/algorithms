#include<iostream>
#include<cstdio>
using namespace std;

struct Node{
   int value;
   Node* lptr;
   Node* rptr;
};


bool search(Node* root, int value){

if(root == 0){

return false;

}


if(root->value == value){

return true;

}

if(value < root->value){
  return search(root->lptr,value);
}else{
  return search(root->rptr,value);
}
}


void traverse(Node* root){
 if(root==0)
   return;
 cout<<"traverse"<<endl;
 cout<<root->value<<endl;
 traverse(root->lptr);
 traverse(root->rptr);
}

int node_count(Node* root){
  if(root==0){
   return 0;
  }
  return node_count(root->lptr)+node_count(root->rptr)+1;

}

int node_height(Node* root){
 if(root==0){
   return 0;
  }
  int lheight=node_height(root->lptr);
  int rheight=node_height(root->rptr); 
  return (lheight > rheight ? (lheight + 1):(rheight +1 ));
}

void insert(Node* &root, int value){


if(!root){
root=new Node();
root->value=value;
root->lptr =0;
root->rptr =0;
//cout<<Root<<endl;
return;
}

if(value <= root->value){
 insert(root->lptr,value);
}else{
 insert(root->rptr,value);
}

}


void init(Node* &root,int array[],int size){

if(!array){
  return;
}

for(int i=0;i<11;i++){
 cout<<"insert"<<array[i]<<endl;
 insert(root,array[i]);
 }

}


int main(){

Node *Root=0;


int array[]={10,8,12,5,7,2,3,5,4,9,34};

init(Root,array,11);
cout<<Root->value;
traverse(Root);
insert(Root,6);
traverse(Root);
cout<<search(Root,34)<<endl;
cout<<search(Root,-9)<<endl;
return 0;

}
