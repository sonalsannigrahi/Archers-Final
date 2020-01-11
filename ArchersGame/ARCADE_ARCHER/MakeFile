Dependencies = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

HPPFILES = collision.hpp fire_ball.hpp fire_balls.hpp gravity.hpp player_box.hpp RETRO_GAME.hpp RETRO_GAME_SETTINGS.hpp STATES.hpp target.hpp target_creator.hpp targets.hpp trace.hpp trace_constants.hpp VECTOR_2D.hpp 

all_but_main = collision.o fire_ball.o fire_balls.o gravity.o player_box.o RETRO_GAME.o RETRO_GAME_SETTINGS.o STATES.o target.o target_creator.o targets.o trace.o trace_constants.o VECTOR_2D.o main.o

all : collision.o fire_ball.o fire_balls.o gravity.o player_box.o RETRO_GAME.o RETRO_GAME_SETTINGS.o STATES.o target.o target_creator.o targets.o trace.o trace_constants.o VECTOR_2D.o main.o main

GCC = g++

collision.o : collision.cpp $(HPPFILES)
	$(GCC) -c collision.cpp $(Dependencies)

fire_ball.o : fire_ball.cpp $(HPPFILES)
	$(GCC) -c fire_ball.cpp $(Dependencies)

fire_balls.o : fire_balls.cpp $(HPPFILES)
	$(GCC) -c fire_balls.cpp $(Dependencies)

gravity.o : gravity.cpp $(HPPFILES)
	$(GCC) -c gravity.cpp $(Dependencies)

player_box.o : player_box.cpp $(HPPFILES)
	$(GCC) -c player_box.cpp $(Dependencies)

RETRO_GAME.o : RETRO_GAME.cpp $(HPPFILES)
	$(GCC) -c RETRO_GAME.cpp $(Dependencies)

RETRO_GAME_SETTINGS.o : RETRO_GAME_SETTINGS $(HPPFILES)
	$(GCC) -c RETRO_GAME_SETTINGS.cpp $(Dependencies)

STATES.o : STATES.cpp $(HPPFILES)
	$(GCC) -c STATES.cpp $(Dependencies)

target.o : target.cpp $(HPPFILES)
	$(GCC) -c target.cpp $(Dependencies)

target_creator.o : target_creator.cpp $(HPPFILES)
	$(GCC) -c target_creator.cpp $(Dependencies)

targets.o : targets.cpp $(HPPFILES)
	$(GCC) -c targets.o $(Dependencies)

trace.o : trace.cpp $(HPPFILES)
	$(GCC) -c trace.cpp $(Dependencies)

trace_constants.o : trace_constants.cpp $(HPPFILES)
	$(GCC) -c trace_constants.cpp $(Dependencies)

VECTOR_2D.o : VECTOR_2D.cpp $(HPPFILES)
	$(GCC) -c VECTOR_2D  $(Dependencies)

main.o : main.cpp $(HPPFILES)
	$(GCC) -c main.cpp $(Dependencies)

main : $(all_but_main)
	$(GCC) $(all_but_main) -o main $(Dependencies)

clean: $(all_but_main)
	rm *.o

