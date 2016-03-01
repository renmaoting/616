# Change the following values to suit your system.

CFLAGS=`sdl-config --cflags` -g -W -Wall -Weffc++ -Wextra -pedantic -O0
SDL_LIB=`sdl-config --libs` -lSDL_ttf -lSDL_image
CCC=g++

OBJECTS = manager.o generateFrames.o world.o sprite.o frame.o ioManager.o 

run: main.o $(OBJECTS)
	$(CCC) $(CFLAGS) main.cpp -o run $(OBJECTS) $(SDL_LIB)

main.o: main.cpp generateFrames.h
	$(CCC) $(CFLAGS) -c main.cpp

generateFrames.o: generateFrames.cpp generateFrames.h
	$(CCC) $(CFLAGS) -c generateFrames.cpp

manager.o: manager.cpp manager.h
	$(CCC) $(CFLAGS) -c manager.cpp

world.o: world.cpp world.h
	$(CCC) $(CFLAGS) -c world.cpp

sprite.o: sprite.cpp sprite.h 
	$(CCC) $(CFLAGS) -c sprite.cpp

frame.o: frame.cpp sprite.h
	$(CCC) $(CFLAGS) -c frame.cpp

ioManager.o: ioManager.cpp ioManager.h
	$(CCC) $(CFLAGS) -c ioManager.cpp

clean:
	rm -f run *.o
	rm -f *~
	rm -f frames/*.bmp
