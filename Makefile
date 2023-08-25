SOURCES = main.cpp src/draw.cpp src/init.cpp src/enemy.cpp src/input.cpp 
all: ${SOURCES}
	g++ ${SOURCES} -IC:\MSYS2\mingw64\include\SDL2 -LC:\MSYS2\mingw64\lib -I.\src -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o game	