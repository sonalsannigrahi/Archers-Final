Dependencies = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system


all: vector2d.o trace_constants.o fire_ball.o gravity.o collision.o trace.o  player_box.o fire_balls.o main.o main 

vector2d.o: VECTOR_2D.cpp
	g++ -c VECTOR_2D.cpp 

trace_constants.o: trace_constants.cpp
	g++ -c trace_constants.cpp 

fire_ball.o: fire_ball.cpp VECTOR_2D.hpp fire_ball.hpp
	g++ -c fire_ball.cpp $(Dependencies)

gravity.o: gravity.cpp fire_ball.hpp VECTOR_2D.hpp
	g++ -c gravity.cpp $(Dependencies)

collision.o: collision.cpp fire_ball.hpp VECTOR_2D.hpp
	g++ -c collision.cpp $(Dependencies)

trace.o: trace.cpp trace_constants.hpp
	g++ -c trace.cpp $(Dependencies)

player_box.o: player_box.cpp 
	g++ -c player_box.cpp $(Dependencies)

fire_balls.o: fire_balls.cpp fire_ball.hpp gravity.hpp collision.hpp trace.hpp
	g++ -c fire_balls.cpp $(Dependencies)

main.o: main.cpp player_box.hpp fire_balls.hpp 
	g++ -c main.cpp $(Dependencies)

main: VECTOR_2D.o trace_constants.o fire_ball.o gravity.o collision.o trace.o player_box.o fire_balls.o main.o
	g++ VECTOR_2D.o trace_constants.o fire_ball.o gravity.o collision.o trace.o player_box.o fire_balls.o main.o -o main  $(Dependencies)
	

clean:  VECTOR_2D.o trace_constants.o fire_ball.o gravity.o collision.o trace.o player_box.o fire_balls.o main.o
	rm *.o


	
