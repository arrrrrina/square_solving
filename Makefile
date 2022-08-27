FLAGS=-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE
FILES_O = main.o solutions.o input_output.o
TARGET = a.exe

$(TARGET): $(FILES_O)
	g++ -o a.exe $(FILES_O)

main.o: main.cpp
	g++ main.cpp -c -o main.o $(FLAGS)

solutions.o: solutions.cpp
	g++ solutions.cpp -c -o solutions.o $(FLAGS)

input_output.o: input_output.cpp
	g++ -c -o input_output.o input_output.cpp $(FLAGS)

clean: 
	rm *.o a.exe


