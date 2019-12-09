CXX = g++
Dependencies = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

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

LightningConstants.o: Lightning/LightningConstants.cpp
	$(CXX) -c Lightning/LightningConstants.cpp

Lightning.o: Lightning/Lightning.cpp Lightning/Lightning.hpp LightningConstants.o
	$(CXX) -c Lightning/Lightning.cpp $(Dependencies)	

RainConstants.o: Rain/RainConstants.cpp
	$(CXX) -c Rain/RainConstants.cpp

Rain.o: Rain/Rain.cpp Rain/Rain.hpp RainConstants.o
	$(CXX) -c Rain/Rain.cpp $(Dependencies)	

BalloonConstants.o: Balloon/BalloonConstants.cpp
	$(CXX) -c Balloon/BalloonConstants.cpp

Balloon.o: Balloon/Balloon.cpp Balloon/Balloon.hpp BalloonConstants.o
	$(CXX) -c Balloon/Balloon.cpp $(Dependencies)	

fireworksconstants.o: Fireworks/fireworksconstants.cpp
	$(CXX) -c Fireworks/fireworksconstants.cpp

fireworks.o: Fireworks/fireworks.cpp
	$(CXX) -c Fireworks/fireworks.cpp $(Dependencies)

bow.o: Character/bow.cpp 
	$(CXX) -c Character/bow.cpp $(Dependencies)

GameConstants.o: Game/GameConstants.cpp
	$(CXX) -c Game/GameConstants.cpp

GameFPS.o: Game/GameFPS.cpp
	$(CXX) -c Game/GameFPS.cpp

Game.o: Game/Game.cpp Game/Game.hpp GameConstants.o GameFPS.o Background.o Water.o Birds.o Lightning.o Rain.o Balloon.o fireworks.o bow.o
	$(CXX) -c Game/Game.cpp $(Dependencies)

main.o: main.cpp Game.o
	$(CXX) -c main.cpp

archer: main.o
	$(CXX) main.o Game.o Background.o Water.o Birds.o Lightning.o Rain.o Balloon.o fireworks.o bow.o -o archer $(Dependencies)

clean: 
	rm -f archer
	rm -f *.o