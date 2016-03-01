
CC = g++
LIB = `sdl-config --libs` -lm -lSDL_ttf -lSDL_image -lstdc++
FLAGS = `sdl-config --cflags` -Wall -c -ggdb

OBJ = main.o
EXE = run

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(LIB)  -o $(EXE)
	
clean:
	 rm -rf *.o $(EXE)

