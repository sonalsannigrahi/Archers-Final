CXX = g++
Dependencies = -lsfml-graphics -lsfml-window -lsfml-system

BackgroundConstants.o: Background/BackgroundConstants.cpp
	$(CXX) -c Background/BackgroundConstants.cpp

Background.o: Background/Background.cpp Background/Background.hpp BackgroundConstants.o
	$(CXX) -c Background/Background.cpp $(Dependencies)

GameConstants.o: Game/GameConstants.cpp
	$(CXX) -c Game/GameConstants.cpp

Game.o: Game/Game.cpp Game/Game.hpp GameConstants.o Background.o
	$(CXX) -c Game/Game.cpp $(Dependencies)

main.o: main.cpp Game.o
	$(CXX) -c main.cpp

archer: main.o
	$(CXX) main.o Game.o GameConstants.o BackgroundConstants.o Background.o -o archer $(Dependencies)

clean: 
	rm -f archer
	rm -f *.o