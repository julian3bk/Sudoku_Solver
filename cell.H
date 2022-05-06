#ifndef CELL
#define CELL

#include <iostream>
#include <vector>


#include "board.H"

class cell {
public:
  char val;
  
  int x,y;
  bool given;
  


  cell()
    : val{0}, x{0}, y{0},given{true}
  {}
    
  cell(char _val, int _x, int _y, bool _g)
    : val{_val}, x{_x}, y{_y}, given{_g}
  {}

  cell(char _val, int _x, int _y)
    : val{_val}, x{_x}, y{_y}, given{true}
  {}


  inline void set_val(char _val) {val = _val;}
  
  inline void set_x(int _x) {x = _x;}
  
  inline void set_y(int _y) {y = _y;}

  inline void set_g(bool _g) {given = _g;}


  std::vector<char> required(Board b){
    cell _cell;
    std::vector<char> num {'1','2','3','4','5','6','7','8','9'};
    std::vector<char> _required;
  
    int row=y;
    int column=x;
 
    bool needc=true;
    bool needr=true;
    bool needb=true;

   
    for(int i=0;i<9;i++){
     
      for(int j=0;j<9;j++){

	if(b.nums[column+j*9]==num[i]){
	  needc=false;
	}
	if(b.nums[row*9+j]==num[i]){
	  needr=false;
	}
      }
      if(needc){
	_required.push_back(num[i]);
	       
	
      }
      needc=true;
      if(needr){
	_required.push_back(num[i]);
	
      }
      needr=true;

      for(int k=0;k<3;k++){
        for(int l=0;l<3;l++){
	  if(x>=k*3 && x<=k*3+2 && y>=l*3 && y<=l*3+2){
	    for(int m=0;m<3;m++){
	      for(int n=0;n<3;n++){
	
		if(b.nums[k*3+9*m+27*l+n]==num[i]){
		  needb=false;
		 
		}
	
	      }
	    }
	  }
	}
      }
      if(needb){
	
	_required.push_back(num[i]);
      }

      needb=true;
    }

    return _required;

  }


  std::vector<char> forbid(Board b){
    cell _cell;
    std::vector<char> num {'1','2','3','4','5','6','7','8','9'};
    std::vector<char> _forbid;
  
    int row=y;
    int column=x;
 
    bool needc=true;
    bool needr=true;
    bool needb=true;

    //loop over numbers
    for(int i=0;i<9;i++){
      if(val!='_'){
	needc=false;
	needr=false;
	needb=false;
      }
      else{
	for(int j=0;j<9;j++){

	  if(b.nums[column+j*9]==num[i]){
	    needc=false;
	  }
	  if(b.nums[row*9+j]==num[i]){
	    needr=false;
	  }
	
	}
	for(int k=0;k<3;k++){
	  for(int l=0;l<3;l++){
	    if(x>=k*3 && x<=k*3+2 && y>=l*3 && y<=l*3+2){
	 
	      for(int m=0;m<3;m++){
		for(int n=0;n<3;n++){
		  if(b.nums[k*3+9*m+27*l+n]==num[i]){
		    needb=false;
		  
		  }
	
		}
	      }
	    }
	  }
	}
      }
      if(!needc){
	_forbid.push_back(num[i]);
      }
      needc=true;
      if(!needr){
       	_forbid.push_back(num[i]);
      }
      needr=true;

  
      if(!needb){
	_forbid.push_back(num[i]);
      }
	
      needb=true;
    }

    return _forbid;

  }

  cell solve(Board b){
    int row=y;
    int column=x;
    
    cell _cell(val,x,y,given);
    std::vector<char> num {'1','2','3','4','5','6','7','8','9'};
    char ex;
    bool changed=false;


    //loop over numbers
    for(int i=0;i<9;i++){
      bool three = false;
      int rforb=0;
      int cforb=0;
      int bforb=0;
   
      //check if triple required
      int inst=0;
      std::vector<char> _required=_cell.required(b);
      for(int j=0;j<_required.size();j++){

	if(num[i]==_required[j]){
	  inst++;	  
	}
      }
      if(inst==3){
	three = true;
      }
    
      //drives loops over 9 cells
      for(int j=0;j<9;j++){
	//check if octuple forbiden in collumn
	if(j != row){
	 
	  cell r (b.nums[j*9+column],column,j);
	  std::vector<char> list=r.forbid(b);
	  bool repeat=false;
 	  for(int k=0;k<list.size();k++){
	  
	    if(list[k]==num[i] && !repeat){
	   
	      cforb++;
	    
	      repeat=true;
	    }
	  }
	      
	}
	//check if octuple forbiden in row
	if(j != column){
	  cell c (b.nums[row*9+j],j,row);
	  std::vector<char> list=c.forbid(b);
	  bool repeat=false;
	  for(int k=0;k<list.size();k++){
	    if(list[k]==num[i] && !repeat){
	      rforb++;
			
	      repeat=true;
	    }
	  }
	}
     
      }
      //check if octuple forbiden in box
      for(int k=0;k<3;k++){
        for(int l=0;l<3;l++){

	  //choose box
	  if(column>=k*3 && column<=k*3+2 && row>=l*3 && row<=l*3+2){
	    bool repeat=false;
	    for(int m=0;m<3;m++){
	      for(int n=0;n<3;n++){
	      	 
		cell c (b.nums[k*3+9*m+27*l+n],m+k*3,3*l+n);
		std::vector<char> list=c.forbid(b);
		if( (k*3+9*m+27*l+n)!= row*9+column){
	
	
	
		  for(int k=0;k<list.size();k++){
	
		    //  std::cout<<"k"<<list[k]<<" i "<<num[i]<<std::endl;
		    if(list[k]==num[i] && !repeat){
		      bforb++;
		      repeat=true;
		      //std::cout<<num[i]<<std::endl;     
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
      
      //  std::cout<<num[i]<<" b  "<<bforb<<"  c  "<<cforb<<"  r  "<<rforb<<" three  "<<three<<std::endl;
      if((bforb==8 || cforb==8 || rforb==8)&&three){
	ex=num[i];
	changed=true;
      }
   
    }

    if(changed){
      _cell.val= ex;
    }
    return _cell;
    
  }
  friend std::ostream& operator<< (std::ostream& os, cell& c);
};

std::ostream& operator<< (std::ostream& os, cell& c){
  os<<c.val;
  return os;
}
#endif
