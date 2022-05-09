#ifndef GUESS_H
#define GUESS_H

#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include<iomanip>
#include <omp.h>

#include <cassert>

#include "cell.H"
#include "board.H"
#include "solver.H"

class guess{
public:
  Board board;


  guess(Board _board)
    :board(_board)
  {}



 
    Board solve1guess (){
    solver slvr(board);
    Board solved=slvr.bsolve();
    Board gsolved;
    int nguess=1;

    if(solved.solved==false){
      for(int x=0;x<9;x++){
	for(int y=0;y<9;y++){
	  int i=y*9+x;
	  if(solved.nums[i]=='_'){
	    cell cl(solved.nums[i],x,y);
	    std::vector<char> need =cl.required(solved);
	    std::vector<char> forbid =cl.forbid(solved);
	    for(int j=0;j<need.size();j++){
	      bool fail=false;
	      for(int k=0;k<forbid.size();k++){
		if(forbid[k]==need[j]){
		  fail=true;
		  break;
		}
	      }
	      if(!fail){
		std::cout<<" "<<std::endl<<"guess number "<<nguess<<std::endl;
		nguess ++;
		solved.set(x+9*y,need[j]);
	        solver gsolver(solved);
		gsolved=gsolver.bsolve();
	      }
	      if(gsolved.solved==true){
		break;
	      }
	    }
	  
	  }
	  if(gsolved.solved==true){
	    break;
	  }
	}
        if(gsolved.solved==true){
	  break;
	  solved=gsolved;
	}
      }
    }

    return solved;
  }
 


    Board solve2guess (){
    solver slvr(board);
    Board solved=slvr.bsolve();
    Board gsolved;
    int nguess=1;

    if(solved.solved==false){
      for(int x=0;x<9;x++){
	for(int y=0;y<9;y++){
	  int i=y*9+x;
	  if(solved.nums[i]=='_'){
	    cell cl(solved.nums[i],x,y);
	    std::vector<char> need =cl.required(solved);
	    std::vector<char> forbid =cl.forbid(solved);
	    for(int j=0;j<need.size();j++){
	      bool fail=false;
	      for(int k=0;k<forbid.size();k++){
		if(forbid[k]==need[j]){
		  fail=true;
		  break;
		}
	      }
	      if(!fail){
		std::cout<<" "<<std::endl<<"guess number "<<nguess<<std::endl;
		nguess ++;
		solved.set(x+9*y,need[j]);
	        guess gsolver(solved);
		gsolved=gsolver.solve1guess();
	      }
	      if(gsolved.solved==true){
		break;
	      }
	    }
	  
	  }
	  if(gsolved.solved==true){
	    break;
	  }
	}
        if(gsolved.solved==true){
	  break;
	  solved=gsolved;
	}
      }
    }

    return solved;
  }
  Board solve3guess (){
    solver slvr(board);
    Board solved=slvr.bsolve();
    Board gsolved;
    int nguess=1;

    if(solved.solved==false){
      for(int x=0;x<9;x++){
	for(int y=0;y<9;y++){
	  int i=y*9+x;
	  if(solved.nums[i]=='_'){
	    cell cl(solved.nums[i],x,y);
	    std::vector<char> need =cl.required(solved);
	    std::vector<char> forbid =cl.forbid(solved);
	    for(int j=0;j<need.size();j++){
	      bool fail=false;
	      for(int k=0;k<forbid.size();k++){
		if(forbid[k]==need[j]){
		  fail=true;
		  break;
		}
	      }
	      if(!fail){
		std::cout<<" "<<std::endl<<"guess number "<<nguess<<std::endl;
		nguess ++;
		solved.set(x+9*y,need[j]);
	        guess gsolver(solved);
		gsolved=gsolver.solve4guess();
	      }
	      if(gsolved.solved==true){
		break;
	      }
	    }
	  
	  }
	  if(gsolved.solved==true){
	    break;
	  }
	}
        if(gsolved.solved==true){
	  break;
	  solved=gsolved;
	}
      }
    }

    return solved;
  }
  
  Board solve4guess (){
    solver slvr(board);
    Board solved=slvr.bsolve();
    Board gsolved;
    int nguess=1;

    if(solved.solved==false){
      for(int x=8;x>-1;x--){
	for(int y=8;y>-1;y--){
	  int i=y*9+x;
	  if(solved.nums[i]=='_'){
	    cell cl(solved.nums[i],x,y);
	    std::vector<char> need =cl.required(solved);
	    std::vector<char> forbid =cl.forbid(solved);
	    for(int j=0;j<need.size();j++){
	      bool fail=false;
	      for(int k=0;k<forbid.size();k++){
		if(forbid[k]==need[j]){
		  fail=true;
		  break;
		}
	      }
	      if(!fail){
		std::cout<<" "<<std::endl<<"guess number "<<nguess<<std::endl;
		nguess ++;
		solved.set(x+9*y,need[j]);
	        guess gsolver(solved);
		gsolved=gsolver.solve3guess();
	      }
	      if(gsolved.solved==true){
		break;
	      }
	    }
	  
	  }
	  if(gsolved.solved==true){
	    break;
	  }
	}
        if(gsolved.solved==true){
	  break;
	  solved=gsolved;
	}
      }
    }

    return solved;
  }

   

  
};

#endif
