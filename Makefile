main6: timer6.o main6.o lab2.o
	g++ -o timer6 main6.o timer6.o lab2.o

timer6.o: timer6.cpp timer6.h
	g++ -c timer6.cpp

main6.o: main6.cpp timer6.h
	g++ -c main6.cpp

lab2.o: lab2.cpp lab2.h
	g++ -c lab2.cpp

clean:
	rm timer6 *.o
