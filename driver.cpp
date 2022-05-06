#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include<iomanip>
#include <charconv>


#include "cell.H"
#include "board.H"

int main(){
  Board a;

  std::string file {"board.dat"};
  int iter=0;
 
   a=a.read(file);
 
   std::cout<<a<<std::endl;
 
   int x=1;
   int y=7;
   cell c (a.nums[x+9*y],x,y,true);
   std::vector<char> e=c.forbid(a);
   cell d =   c.solve(a);

   std::cout<<c<<std::endl;
   std::cout<<d<<std::endl;
   

  

   for(int i=0;i<e.size();i++){

     //  std::cout<<e[i]<<std::endl;
     } 
     Board solved=a.bsolve();
     std::cout<<solved<<std::endl;
  
}
//mark original cells as true make others false and different color
