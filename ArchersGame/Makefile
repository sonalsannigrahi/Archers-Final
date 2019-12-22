CXX = g++
Dependencies = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
Classes = Background.o Water.o Birds.o Lightning.o Rain.o Balloon.o fireworks.o bow.o Opponent.o Spear.o StaticOpponent.o Setting.o Arrow.o EndGame.o

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

fireworks.o: Fireworks/fireworks.cpp fireworksconstants.o
	$(CXX) -c Fireworks/fireworks.cpp $(Dependencies)


bow.o: Character/bow.cpp 
	$(CXX) -c Character/bow.cpp $(Dependencies)


SettingConstants.o: Setting/SettingConstants.cpp
	$(CXX) -c Setting/SettingConstants.cpp

Setting.o: Setting/Setting.cpp Setting/Setting.hpp SettingConstants.o
	$(CXX) -c Setting/Setting.cpp $(Dependencies)


OpponentConstants.o: Opponent/OpponentConstants.cpp
	$(CXX) -c Opponent/OpponentConstants.cpp

Opponent.o: Opponent/Opponent.cpp Opponent/Opponent.hpp OpponentConstants.o
	$(CXX) -c Opponent/Opponent.cpp $(Dependencies)


OpponentConstants.o: Opponent/OpponentConstants.cpp
	$(CXX) -c Opponent/OpponentConstants.cpp

Opponent.o: Opponent/Opponent.cpp Opponent/Opponent.hpp OpponentConstants.o
	$(CXX) -c Opponent/Opponent.cpp $(Dependencies)


SpearConstants.o: Opponent/SpearConstants.cpp
	$(CXX) -c Opponent/SpearConstants.cpp

Spear.o: Opponent/Spear.cpp Opponent/Spear.hpp SpearConstants.o
	$(CXX) -c Opponent/Spear.cpp $(Dependencies)


StaticOpponent.o: Opponent/StaticOpponent.cpp Opponent/StaticOpponent.hpp 
	$(CXX) -c Opponent/StaticOpponent.cpp $(Dependencies)


ArrowConstants.o: Arrow/ArrowConstants.cpp
	$(CXX) -c Arrow/ArrowConstants.cpp

Arrow.o: Arrow/Arrow.cpp Arrow/Arrow.hpp ArrowConstants.o
	$(CXX) -c Arrow/Arrow.cpp $(Dependencies)



EndGame.o: EndGame/EndGame.cpp EndGame/EndGame.hpp 
	$(CXX) -c EndGame/EndGame.cpp $(Dependencies)



GameConstants.o: Game/GameConstants.cpp
	$(CXX) -c Game/GameConstants.cpp

GameFPS.o: Game/GameFPS.cpp
	$(CXX) -c Game/GameFPS.cpp

Game.o: Game/Game.cpp Game/Game.hpp GameConstants.o GameFPS.o $(Classes)
	$(CXX) -c Game/Game.cpp $(Dependencies)




main.o: main.cpp Game.o
	$(CXX) -c main.cpp




archer: main.o
	$(CXX) main.o Game.o $(Classes) -o archer $(Dependencies)

clean: 
	rm -f archer
	rm -f *.o