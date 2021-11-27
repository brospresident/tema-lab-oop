build: main.cpp Auth/Auth.cpp Auth/Register.cpp FileWriter/FileWriter.cpp User/User.cpp
	g++ -o main.o -c main.cpp
	g++ -std=c++17 -o FileWriter.o -c ./FileWriter/FileWriter.cpp
	g++ -std=c++17 -o UserWriter.o -c ./FileWriter/UserWriter.cpp
	g++ -std=c++17 -o FileReader.o -c ./FileReader/FileReader.cpp
	g++ -std=c++17 -o UserReader.o -c ./FileReader/UserReader.cpp
	g++ -std=c++17 -o Operator.o -c ./User/Operator.cpp
	g++ -std=c++17 -o User.o -c ./User/User.cpp
	g++ -std=c++17 -o Auth.o -c ./Auth/Auth.cpp
	g++ -std=c++17 -o Register.o -c ./Auth/Register.cpp
	g++ -std=c++17 -o Login.o -c ./Auth/Login.cpp
	g++ -std=c++17 -o RSA.o -c ./RSA/RSA.cpp
	g++ -std=c++17 -o app main.o Auth.o Register.o FileWriter.o User.o RSA.o UserWriter.o Login.o FileReader.o UserReader.o Operator.o
	rm -rf main.o Auth.o Register.o FileWriter.o User.o RSA.o UserWriter.o Login.o FileReader.o UserReader.o Operator.o

run:
	./app

remove:
	rm app
