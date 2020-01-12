Dependencies = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

HPPFILES = ARCADE_ARCHER/collision.hpp ARCADE_ARCHER/fire_ball.hpp ARCADE_ARCHER/fire_balls.hpp ARCADE_ARCHER/gravity.hpp ARCADE_ARCHER/player_box.hpp ARCADE_ARCHER/RETRO_GAME.hpp ARCADE_ARCHER/RETRO_GAME_SETTINGS.hpp ARCADE_ARCHER/STATES.hpp ARCADE_ARCHER/target.hpp ARCADE_ARCHER/target_creator.hpp ARCADE_ARCHER/targets.hpp ARCADE_ARCHER/trace.hpp ARCADE_ARCHER/trace_constants.hpp ARCADE_ARCHER/VECTOR_2D.hpp ARCADE_ARCHER/BOX_PARTICLE.hpp ARCADE_ARCHER/BOX_PARTICLES.hpp

all_but_main = collision.o fire_ball.o fire_balls.o gravity.o player_box.o RETRO_GAME.o RETRO_GAME_SETTINGS.o target.o target_creator.o targets.o trace.o trace_constants.o VECTOR_2D.o BOX_PARTICLE.o BOX_PARTICLES.o main.o

all : collision.o fire_ball.o fire_balls.o gravity.o player_box.o RETRO_GAME.o RETRO_GAME_SETTINGS.o target.o target_creator.o targets.o trace.o trace_constants.o VECTOR_2D.o BOX_PARTICLE.o BOX_PARTICLES.o main.o main

CXX = g++

collision.o : ARCADE_ARCHER/collision.cpp $(HPPFILES)
	$(CXX) -c ARCADE_ARCHER/collision.cpp $(Dependencies)

fire_ball.o : ARCADE_ARCHER/fire_ball.cpp $(HPPFILES)
	$(CXX) -c ARCADE_ARCHER/fire_ball.cpp $(Dependencies)

fire_balls.o : ARCADE_ARCHER/fire_balls.cpp $(HPPFILES)
	$(CXX) -c ARCADE_ARCHER/fire_balls.cpp $(Dependencies)

gravity.o : ARCADE_ARCHER/gravity.cpp $(HPPFILES)
	$(CXX) -c ARCADE_ARCHER/gravity.cpp $(Dependencies)

player_box.o : ARCADE_ARCHER/player_box.cpp $(HPPFILES)
	$(CXX) -c ARCADE_ARCHER/player_box.cpp $(Dependencies)

RETRO_GAME.o : ARCADE_ARCHER/RETRO_GAME.cpp $(HPPFILES)
	$(CXX) -c ARCADE_ARCHER/RETRO_GAME.cpp $(Dependencies)

RETRO_GAME_SETTINGS.o : ARCADE_ARCHER/RETRO_GAME_SETTINGS.cpp $(HPPFILES)
	$(CXX) -c ARCADE_ARCHER/RETRO_GAME_SETTINGS.cpp $(Dependencies)

target.o : ARCADE_ARCHER/target.cpp $(HPPFILES)
	$(CXX) -c ARCADE_ARCHER/target.cpp $(Dependencies)

target_creator.o : ARCADE_ARCHER/target_creator.cpp $(HPPFILES)
	$(CXX) -c ARCADE_ARCHER/target_creator.cpp $(Dependencies)

targets.o : ARCADE_ARCHER/targets.cpp $(HPPFILES)
	$(CXX) -c ARCADE_ARCHER/targets.cpp $(Dependencies)

trace.o : ARCADE_ARCHER/trace.cpp $(HPPFILES)
	$(CXX) -c ARCADE_ARCHER/trace.cpp $(Dependencies)

trace_constants.o : ARCADE_ARCHER/trace_constants.cpp $(HPPFILES)
	$(CXX) -c ARCADE_ARCHER/trace_constants.cpp $(Dependencies)

VECTOR_2D.o : ARCADE_ARCHER/VECTOR_2D.cpp $(HPPFILES)
	$(CXX) -c ARCADE_ARCHER/VECTOR_2D.cpp  $(Dependencies)

BOX_PARTICLE.o : ARCADE_ARCHER/BOX_PARTICLE.cpp $(HPPFILES)
	$(CXX) -c ARCADE_ARCHER/BOX_PARTICLE.cpp $(Dependencies)

BOX_PARTICLES.o : ARCADE_ARCHER/BOX_PARTICLES.cpp $(HPPFILES)
	$(CXX) -c ARCADE_ARCHER/BOX_PARTICLES.cpp $(Dependencies)
