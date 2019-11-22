CXX = g++
Dependencies = -lsfml-graphics -lsfml-window -lsfml-system

GameConstants.o: Game/GameConstants.cpp
	$(CXX) -c Game/GameConstants.cpp

GameFPS.o: Game/GameFPS.cpp
	$(CXX) -c Game/GameFPS.cpp

Game.o: Game/Game.cpp Game/Game.hpp GameConstants.o GameFPS.o
	$(CXX) -c Game/Game.cpp $(Dependencies)

main.o: main.cpp GameConstants.o GameFPS.o Game.o
	$(CXX) -c main.cpp

archer: GameConstants.o GameFPS.o Game.o main.o
	$(CXX) main.o Game.o GameConstants.o GameFPS.o -o archer $(Dependencies)

clean: 
	rm -f archer
	rm -f *.o