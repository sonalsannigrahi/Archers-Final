CXX = g++
Dependencies = -lsfml-graphics -lsfml-window -lsfml-system

GameConstants.o: Game/GameConstants.cpp
	$(CXX) -c Game/GameConstants.cpp

Game.o: Game/Game.cpp Game/Game.hpp GameConstants.o
	$(CXX) -c Game/Game.cpp $(Dependencies)

main.o: main.cpp GameConstants.o Game.o
	$(CXX) -c main.cpp

archer: GameConstants.o Game.o main.o
	$(CXX) main.o Game.o GameConstants.o -o archer $(Dependencies)

clean: 
	rm -f archer
	rm -f *.o