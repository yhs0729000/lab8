main6: timer6.o main.o 
	g++ -o timer6 main.o timer6.o 

timer6.o: timer6.cpp timer6.h
	g++ -c timer6.cpp

main6.o: main.cpp timer6.h
	g++ -c main.cpp

clean:
	rm timer6 *.o
