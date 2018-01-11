#include<vector>
#include<iostream>

class MyCalendar {


struct interval{
     int s;
     int e;
    };


vector<interval> intervals;

public:
    MyCalendar() {
            
	         }
			    
   bool overlap(int start,int end, interval& intv){
   
   if(!((end <= intv.start) || (start >= intv.end)))
       return true;
   else
       return false;
   
   }			    
   
   bool book(int start, int end) {
    
        for(int i=0;i<intervals.size();i++){
	    //overlap
            if (overlap(start,end,intervals[i])){
	       return false;
	    }
         }

         interval intv;
	 intv.s=start;
	 intv.e=end;
	 intervals.push_back(intv);
         
	 return true;

    
}
};
