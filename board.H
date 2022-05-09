#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include<iomanip>
#include "cell.H"
#include <cassert>
#include <stdlib.h>
#include <omp.h>

// a contiguous 2-d array
// here the data is stored in row-major order in a 1-d memory space
// managed as a vector.  We overload () to allow us to index this as
// a(irow, icol)

class Board {
public:
  std::vector<char> nums;
  std::vector<bool> give;
  bool solved;

  Board ()
        :

    nums(81,'_'),give(81,true),solved(false)
    {
        // we do the asserts here after the initialization of _data
        // in the initialization list, but if the size is zero, we'll
        // abort here anyway.

    }


  inline void set(int _pos,char _val) {nums[_pos]=_val;}



  Board read(std::string fname){
    Board b_out;
    std::ifstream file;
    file.open(fname);
  
    std::string line{};
    	int it=0;

	{
    while (std::getline(file, line)){
  
      for(int i=0;i<17;i++){

       	if(line[i] != ','){
	  //  std::cout<<it<<" "<<line[i]<<std::endl;
	  b_out.nums[it]=line[i];
	  //std::cout<<b_out._nums[it]<<std::endl;
	  it++;
	}
	
      }
    }
	}
  
 
    
    file.close();
    return b_out;
  }



 friend std::ostream& operator<< (std::ostream& os, Board& b);
};





std::ostream& operator<< (std::ostream& os, Board& b)
{
  int c=0;
  int l=0;
  int t=0;
  std::cout<<"_____________________"<<std::endl;
  for(int i=0;i<81;i++){
   
    //if cell given
      if(c==9){
	c=0;
	t=0;
	std::cout<<"|"<<std::endl;
	  }
        if(l==27){
	l=0;
	
       	std::cout<<"|===================|"<<std::endl;
	  }
	
	 if(t==3){
	   t=0;
	   std::cout<<"||";
	 }
	    else{
	      std::cout<<"|";
	    }
	 /*	 if(!b.give[i]){
	   std::system("color 70");
	   }*/
  os << b.nums[i];
	
	l++;
         c++;
	

	 t++;
  }
  std::cout<<"|"<<std::endl<<"‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"<<std::endl;
    return os;
}



#endif
