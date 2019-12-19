#include <SFML/Graphics.hpp>

class Healthbar {

    private:
        sf::RenderWindow* window;
        sf::Sprite rectangle;
        sf::Sprite filling;
        float health;
        double timer;
        int healthWidth, healthHeight;
    
    public:
        Healthbar(float health = 1);

        void setSize(int width, int height);
        void setWindow(sf::RenderWindow* gameWindow);
        void updateFrame(double time);
};