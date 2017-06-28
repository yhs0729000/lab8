tetris:tetris.o genMino.o 
	g++ -o tetris tetris.o genMino.o Mino.o MinoI.o MinoS.o MinoL.o Minoten.o

tetris.o:tetris.cpp all.o
	g++ -c tetris.cpp  

genMino.o:genMino.cpp all.o  
	g++ -c genMino.cpp  

all.o:genMino.h MinoI.h MinoS.h MinoL.h Minoten.h
	g++ -c genMino.h

Mino.o:Mino.cpp Mino.h
	g++ -c Mino.cpp

MinoI.o:MinoI.cpp MinoI.h
	g++ -c MinoI.cpp

MinoS.o:MinoS.cpp MinoS.h
	g++ -c MinoS.cpp

MinoL.o:MinoL.cpp MinoL.h
	g++ -c MinoL.cpp

Minoten.o:Minoten.cpp Minoten.h
	g++ -c Minoten.cpp

