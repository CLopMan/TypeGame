OBJ = game.o main.o 

all: $(OBJ)
	g++ -g -Wall -o TypeGame $^

%.o: src/%.cpp
	g++ -g -Wall -fPIC -c $< -o $@

clean: 
	rm *.o