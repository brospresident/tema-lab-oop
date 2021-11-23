build: main.cpp Auth/Auth.cpp Auth/Register.cpp FileWriter/FileWriter.cpp User/User.cpp
	g++ -o main.o -c main.cpp
	g++ -std=c++17 -o FileWriter.o -c ./FileWriter/FileWriter.cpp
	g++ -std=c++17 -o User.o -c ./User/User.cpp
	g++ -std=c++17 -o Auth.o -c ./Auth/Auth.cpp
	g++ -std=c++17 -o Register.o -c ./Auth/Register.cpp
	g++ -std=c++17 -o app main.o Auth.o Register.o FileWriter.o User.o
	rm -rf main.o Auth.o Register.o FileWriter.o User.o

run:
	./app

remove:
	rm app
