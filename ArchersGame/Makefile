CXX = g++
Dependencies = -lsfml-graphics -lsfml-window -lsfml-system

BackgroundConstants.o: Background/BackgroundConstants.cpp
	$(CXX) -c Background/BackgroundConstants.cpp

Background.o: Background/Background.cpp Background/Background.hpp BackgroundConstants.o
	$(CXX) -c Background/Background.cpp $(Dependencies)

WaterConstants.o: Water/WaterConstants.cpp
	$(CXX) -c Water/WaterConstants.cpp

Water.o: Water/Water.cpp Water/Water.hpp WaterConstants.o
	$(CXX) -c Water/Water.cpp $(Dependencies)

BirdsConstants.o: Birds/BirdsConstants.cpp
	$(CXX) -c Birds/BirdsConstants.cpp

Birds.o: Birds/Birds.cpp Birds/Birds.hpp BirdsConstants.o
	$(CXX) -c Birds/Birds.cpp $(Dependencies)

GameConstants.o: Game/GameConstants.cpp
	$(CXX) -c Game/GameConstants.cpp

GameFPS.o: Game/GameFPS.cpp
	$(CXX) -c Game/GameFPS.cpp

Game.o: Game/Game.cpp Game/Game.hpp GameConstants.o GameFPS.o Background.o Water.o
	$(CXX) -c Game/Game.cpp $(Dependencies)

main.o: main.cpp Game.o
	$(CXX) -c main.cpp

archer: main.o
	$(CXX) main.o Game.o GameConstants.o BackgroundConstants.o Background.o Water.o -o archer $(Dependencies)

clean: 
	rm -f archer
	rm -f *.o