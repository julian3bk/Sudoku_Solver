#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include<iomanip>
#include <charconv>


#include "cell.H"
#include "board.H"
#include "solver.H"

int main(int argc, char *argv[]){
  Board board;
  std::string file;

  std::cout<<argc;
  if(argc==2){
     file=argv[1];
  }
  else{
      std::cout<<"which game board?"<<std::endl;
    std::cin>>file;
  }

   board=board.read(file);
 
   std::cout<<board<<std::endl;
 
  
   solver slvr(board);
    Board solved=slvr.bsolve();



}
