FILES_O = main.o solutions.o input_output.o
TARGET = a.exe

$(TARGET): $(FILES_O)
	g++ -o a.exe $(FILES_O)

main.o: main.cpp
	g++ main.cpp -c -o main.o

solutions.o: solutions.cpp
	g++ solutions.cpp -c -o solutions.o

input_output.o: input_output.cpp
	g++ -c -o input_output.o input_output.cpp

clean: 
	rm *.o

