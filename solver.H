#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include<iomanip>

#include <cassert>

#include "cell.H"
#include "board.H"

struct solver{

  Board board;
  // std::vector<cell> {81};

  solver(Board _board):
    board(_board)
  {}
    

Board bsolve(){
    Board _bsolve=board;
    int cycle=1;
    int prev;
    while(!_bsolve.solved){
    
    for(int x=0;x<9;x++){
      for(int y=0;y<9;y++){

	if(_bsolve.nums[9*y+x]=='_'){
	  cell _cell(_bsolve.nums[9*y+x],x,y);
	  cell _so=_cell.solve(_bsolve);
	   _bsolve.nums[9*y+x]=_so.val;
	   _bsolve.give[9*y+x]=false;
	
	}
      }
    }
    _bsolve.solved=true;
    int unsolved=0;
    for(int i=0;i<81;i++){
 
      if(_bsolve.nums[i]=='_'){
	     unsolved++;
	_bsolve.solved=false;
      }

    }

    
        std::cout<<"cycle"<<cycle<<" unsolved  "<<unsolved<<std::endl;
    cycle++;
    std::cout<<_bsolve<<std::endl;

    if(prev==unsolved){
      std::cout<<"Can not be solved by this method"<<std::endl;
      break;
    }

    prev=unsolved;
    }
    return _bsolve;
  }

Board one_cycle(){
    Board _bsolve=board;
  
  
    
    for(int x=0;x<9;x++){
      for(int y=0;y<9;y++){

	if(_bsolve.nums[9*y+x]=='_'){
	  cell _cell(_bsolve.nums[9*y+x],x,y);
	  cell _so=_cell.solve(_bsolve);
	   _bsolve.nums[9*y+x]=_so.val;
	   _bsolve.give[9*y+x]=false;
	
	}
      }
    }
    _bsolve.solved=true;
    int unsolved=0;
    for(int i=0;i<81;i++){
 
      if(_bsolve.nums[i]=='_'){
	     unsolved++;
	_bsolve.solved=false;
      }

    }
     
    
    return _bsolve;
  }

  

};

#endif
