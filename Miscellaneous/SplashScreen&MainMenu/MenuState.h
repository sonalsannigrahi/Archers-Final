#include "TextureManager.h" //NEW INCLUDE
#include <SFML/Graphics.hpp>

#include "gameState.h"  



class MenuState : public GameState  
{
public:
    //constructor (compiler will automatically make a default one)
    MenuState(Game* game);

    //the three functions are teh three things we must do.
    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

private:
    //let's make a view for this just in case we want it
    
    std::vector<sf::Text> buttons;
    sf::Font font;
    const int NUM_BUTTONS = 3;
    
    bool isTextClicked(sf::Text text);

    sf::View view;
    TextureManager menuScreen;  //menuScreen variable
    sf::Sprite menuSprite;

    //this will be used to change the game state to the "Play the actual fucking game" state.
    void loadgame();
};
