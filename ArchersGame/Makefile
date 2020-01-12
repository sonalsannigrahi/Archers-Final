CXX = g++
Dependencies = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

all_but_main = collision.o fire_ball.o fire_balls.o gravity.o player_box.o RETRO_GAME.o RETRO_GAME_SETTINGS.o target.o target_creator.o targets.o trace.o trace_constants.o VECTOR_2D.o

HPPFILES = ARCADE_ARCHER/collision.hpp ARCADE_ARCHER/fire_ball.hpp ARCADE_ARCHER/fire_balls.hpp ARCADE_ARCHER/gravity.hpp ARCADE_ARCHER/player_box.hpp ARCADE_ARCHER/RETRO_GAME.hpp ARCADE_ARCHER/RETRO_GAME_SETTINGS.hpp ARCADE_ARCHER/STATES.hpp ARCADE_ARCHER/target.hpp ARCADE_ARCHER/target_creator.hpp ARCADE_ARCHER/targets.hpp ARCADE_ARCHER/trace.hpp ARCADE_ARCHER/trace_constants.hpp ARCADE_ARCHER/VECTOR_2D.hpp 


Classes = Background.o Water.o Birds.o Lightning.o Rain.o Balloon.o fireworks.o bow.o Opponent.o Spear.o StaticOpponent.o Setting.o Arrow.o text.o EndGame.o Encryption.o $(all_but_main)


all : collision.o fire_ball.o fire_balls.o gravity.o player_box.o RETRO_GAME.o RETRO_GAME_SETTINGS.o target.o target_creator.o targets.o trace.o trace_constants.o VECTOR_2D.o archer


Encryption.o: Encryption/Encryption.cpp
	$(CXX) -c Encryption/Encryption.cpp

BackgroundConstants.o: Background/BackgroundConstants.cpp Encryption.o
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

textconstants.o: Text/textconstants.cpp
	$(CXX) -c Text/textconstants.cpp

text.o: Text/text.cpp
	$(CXX) -c Text/text.cpp $(Dependencies)

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


SpearConstants.o: Opponent/SpearConstants.cpp
	$(CXX) -c Opponent/SpearConstants.cpp

Spear.o: Opponent/Spear.cpp Opponent/Spear.hpp SpearConstants.o
	$(CXX) -c Opponent/Spear.cpp $(Dependencies)


StaticConstants.o: Opponent/StaticConstants.cpp
	$(CXX) -c Opponent/StaticConstants.cpp

StaticOpponent.o: Opponent/StaticOpponent.cpp Opponent/StaticOpponent.hpp StaticConstants.o
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


Game.o: Game/Game.cpp Game/Game.hpp  ARCADE_ARCHER/STATES.hpp GameConstants.o GameFPS.o $(Classes)
	$(CXX) -c Game/Game.cpp $(Dependencies)


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






main.o: main.cpp Game.o ARCADE_ARCHER/RETRO_GAME.o ARCADE_ARCHER/RETRO_GAME_SETTINGS.o $(HPPFILES)
	$(CXX) -c main.cpp $(Dependencies)




archer: main.o

	$(CXX) main.o Game.o $(Classes) -o archer $(Dependencies)


clean: 
	rm -f archer
	rm -f *.o
