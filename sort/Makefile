testSort : testSort.o ISort.o
	g++ -g -std=c++11 *.o -o testSort
testSort.o : 
	g++ -g -std=c++11 testSort.cpp -c
ISort.o : 
	g++ -g -std=c++11 ISort.cpp -c

.PHONY : clean
clean :
	-rm *.o testSort