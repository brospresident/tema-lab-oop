build: main.cpp Auth/Auth.cpp
	g++ -o main.o -c main.cpp
	g++ -std=c++17 -o Auth.o -c ./Auth/Auth.cpp
	g++ -std=c++17 -o app main.o Auth.o
	rm -rf main.o Auth.o

run:
	./app

remove:
	rm app
