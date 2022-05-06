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
  Board a;
  std::string file;

  std::cout<<argc;
  if(argc==2){
     file=argv[1];
  }
  else{
      std::cout<<"which game board?"<<std::endl;
    std::cin>>file;
  }

  int iter=0;
 
   a=a.read(file);
 
   std::cout<<a<<std::endl;
 
  
   solver slvr(a);
    Board solved=slvr.bsolve();


  int x=0;
   int y=7;
   cell c (solved.nums[x+9*y],x,y,true);
   std::vector<char> e=c.required(a);
   cell d =   c.solve(solved);

   //std::cout<<c<<std::endl;
   //std::cout<<d<<std::endl;
   for(int i=0;i<e.size();i++){

     // std::cout<<e[i]<<std::endl;
     }

}
//mark original cells as true make others false and different color
