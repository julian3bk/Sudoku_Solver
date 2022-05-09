#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include<iomanip>

#include <cassert>
#include <chrono>

#include "cell.H"
#include "board.H"
#include "guess.H"
#include "solver.H"


int main(int argc, char *argv[]){
  Board board;
  std::string file;
  char nguess='1';
  char* guessin;

  if(argc>=2){
     file=argv[1];
  }
  else{
      std::cout<<"which game board?"<<std::endl;
    std::cin>>file;
  }

  if(argc==3){
    guessin=argv[2];
    nguess=*guessin;
  }
 
   board=board.read(file);
  
    
   std::cout<<board<<std::endl;
 
    std::chrono::steady_clock::time_point begin=std::chrono::steady_clock::now();
    if(nguess=='1'){
   guess gs(board);
    Board solved=gs.solve1guess();
    }
      if(nguess=='2'){
	guess gs(board);
    Board solved2=gs.solve2guess();
      }
       if(nguess=='3'){
   guess gs(board);
    Board solved=gs.solve3guess();
    }
      if(nguess=='4'){
	guess gs(board);
    Board solved2=gs.solve4guess();

    
    }
 
  std::chrono::steady_clock::time_point end =std::chrono::steady_clock::now();
    std::cout<<"Time ellapsed = "<<std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count()<<"[mu s]"<<std::endl;


}
