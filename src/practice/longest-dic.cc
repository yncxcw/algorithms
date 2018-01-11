#include<iostream>
#include<map>
#include<vector>
//#include<sort>

using namespace std;

class Solution {
public:

    static bool sort_find2(string& a, string& b ){
      if(a.size() < b.size())
         return true;
       else if(a.size() > b.size())
        return false;
       else{
        return a > b;
       }
    }
   
 string longestWord(vector<string>& words) {
     map<string,int> wmap;
     sort(words.begin(),words.end(),sort_find2);
     outputs(words);
     for(auto word : words)	
          wmap[word]=1;

     for(int i=words.size()-1;i>=0;i--){
          string word=words[i];
	  bool find=true;	
	  for(int len=word.size();len>=1;len--){
	     string tword=word.substr(0,len);
	     if(wmap.find(tword)==wmap.end()){
	         find=false;
		 break;			
	     }
	  }
         if(find){
           cout<<"find"<<endl;
	   return word;
	 } 
    }

    string empty;
    return empty;
  }
 
  void outputs(std::vector<string>& outputs){
       for(auto output : outputs){
         std::cout<<output<<" ";
       }
       std::cout<<std::endl;
    
    }
};

int main(){

 string array[13]={"m","mo","moc","moch","mocha","l","la","lat","latt","latte","c","ca","cat"};
 
 vector<string> svector(array,array+13);
 Solution *p=new Solution();
 cout<<p->longestWord(svector)<<endl; 
 return 0;
}
