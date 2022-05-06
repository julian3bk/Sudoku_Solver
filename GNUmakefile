All : solve.o driver.o


driver.o : driver.cpp board.H cell.H solver.H
	g++ -o driver.o driver.cpp

solve.o : solve.cpp board.H cell.H solver.H
	g++ -o solve.o solve.cpp
testing :driver.o
	./driver.o > /dev/null
	@if [ $?==0 ]; then echo "tests passed"; fi

clean:
	rm -f *.o solve driver
