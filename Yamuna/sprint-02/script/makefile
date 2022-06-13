CXX = g++
CXXFLAGS = -g -I../include/ -I../src/ -ljsoncpp
LDFLAGS =  -ljsoncpp -lpthread
OBJFILES = ../obj/main.o ../obj/UI.o ../obj/Bus.o
PROGRAM = ../bin/program
RM = rm -rf 

$(PROGRAM): $(OBJFILES)
	$(CXX) -o $(PROGRAM) $(OBJFILES) $(LDFLAGS)

../obj/main.o: ../src/main.cpp
	$(CXX) -o ../obj/main.o -c ../src/main.cpp $(CXXFLAGS)

../obj/UI.o: ../src/UI.cpp
	$(CXX) -o ../obj/UI.o -c ../src/UI.cpp $(CXXFLAGS)

../obj/Bus.o: ../src/Bus.cpp
	$(CXX) -o ../obj/Bus.o -c ../src/Bus.cpp $(CXXFLAGS)

clean:
	$(RM) $(OBJFILES) $(PROGRAM)
