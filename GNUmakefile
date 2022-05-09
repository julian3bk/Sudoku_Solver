DEBUG ?= FALSE



ifeq (${DEBUG}, TRUE)
  CXXFLAGS := -g
else
  CXXFLAGS :=  -DNDEBUG -O3
endif


All : solve.o driver.o guess.o testing


driver.o : driver.cpp board.H cell.H solver.H
	g++ -o driver.o ${CXXFLAGS} driver.cpp

solve.o : solve.cpp board.H cell.H solver.H
	g++ -o solve.o ${CXXFLAGS} solve.cpp

guess.o : solve_guess.cpp board.H cell.H solver.H guess.H
	g++ -o guess.o ${CXXFLAGS} solve_guess.cpp

testing :driver.o
	./driver.o > /dev/null
	@if [ $?==0 ]; then echo "tests passed"; fi
	@echo "done"

clean:
	rm -f *.o solve driver guess
