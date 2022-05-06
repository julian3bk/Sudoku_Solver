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

int main(){
  Board board;
  std::string file{"./boards/board.dat"};
 
 
   board=board.read(file);
   std::cout<<"testing reading from file"<<std::endl;
   assert(board.nums[0]=='5');
  
 
  
 


  int x=6;
   int y=5;
   cell c (board.nums[x+9*y],x,y,true);
   std::vector<char> req {'1','1','2','3','3','4','4','4','5','5','5','6','7','7','8','8','8','9','9','9'};
   std::vector<char> e=c.required(board);
   
  std::cout<<"testing required values check"<<std::endl;
  assert(req==e);

   
   for(int i=0;i<e.size();i++){

     std::cout<<e[i]<<std::endl;
     }

   std::cout<<"testing cell solution"<<std::endl;
   cell d =   c.solve(board);
   assert(d.val=='8');

   
  solver slvr(board);
    Board solved=slvr.bsolve();
    Board answer;
     std::string file2{"./boards/solution.dat"};
     answer=answer.read(file2);
     std::cout<<answer;
 std::cout<<"testing full solution"<<std::endl;
 for(int i=0;i<81;i++){
   std::cout<<i<<std::endl;
   assert(answer.nums[i] ==solved.nums[i]);
       }
   
   //std::cout<<c<<std::endl;
   //std::cout<<d<<std::endl;
  

}
