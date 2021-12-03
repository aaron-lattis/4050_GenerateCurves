all: subd catrom

subd: subd.cpp
	g++ -Wall -o subd subd.cpp Point.cpp

catrom: catrom.cpp
	g++ -Wall -o catrom catrom.cpp Point.cpp

clean:
	rm subd catrom