#include "player_box.hpp"

PLayerBox::PLayerBox(sf::RenderWindow* window, double pos_x, double pos_y, double length, double W, double H)
{
    this->window = window;
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->length = length;

    this->W = W;
    this->H = H;

    this->IntTime = 0.0;
    this->IntTime_margin = 0.5;

    this->angriness = 0.0;
    this->MAX_SPEED = 120.0;
    this->MAX_TIME_TO_ANGRY = 2.0;
    this->MAX_TIME_TO_CALM = 1.0;
    this->under_pressure = false;
}


void PLayerBox::move_to_left()
{
    pos_x -= 5.0;
    if(pos_x < length/2){
        pos_x = length/2;
    }
}


void PLayerBox::move_to_right()
{
    pos_x += 5.0;
    if(pos_x > W - length/2){
        pos_x = W - length/2;
    }
}

void PLayerBox::resolve_event(sf::Event event, double mouse_x, double mouse_y)
{
    if(event.type == sf::Event::KeyPressed)
    {
        if( event.key.code == sf::Keyboard::Left ){
            move_to_left();
        }
        if( event.key.code == sf::Keyboard::Right ){
            move_to_right();
        }
    }
    if(event.type == sf::Event::MouseButtonPressed){
        ///std::cout<<"YO1"<<std::endl;

        if(event.mouseButton.button == sf::Mouse::Left){
            ///std::cout<<"YO2"<<std::endl;

            if(under_pressure == false){
                ///std::cout<<"YO3"<<std::endl;

                if(mouse_x > pos_x && mouse_y > pos_y){
                    ///std::cout<<"YO4"<<std::endl;

                    double dist = sqrt( pow(mouse_x - pos_x, 2.0) + pow(mouse_y - pos_y, 2.0) );
                    if(dist < 200.0){

                        ///std::cout<<"YO5"<<std::endl;

                        under_pressure = true;
                    }
                }
            }
        }
    }
    if(event.type == sf::Event::MouseButtonReleased){
        if(event.mouseButton.button == sf::Mouse::Left){
            under_pressure = false;
        }
    }
}

bool PLayerBox::will_throw()
{
    if( under_pressure == false && angriness > 50.0 )
        return true;
    return false;
}

FIRE_BALL* PLayerBox::hurl(double mouse_x, double mouse_y)
{
    double diag = sqrt(pow(mouse_x - pos_x,2.0) + pow(mouse_y - pos_y,2.0));
    double cos_theta = (mouse_x - pos_x)/diag;
    double sin_theta = (mouse_y - pos_y)/diag;

    Vector2D pos(pos_x,pos_y);
    Vector2D vel(MAX_SPEED * cos_theta, MAX_SPEED * sin_theta);
    vel = (angriness/100) * vel;

    angriness = 0.0;
    under_pressure = false;

    srand(time(NULL));

    int R = rand()%255 + 1;
    int G = rand()%255 + 1;
    int B = rand()%255 + 1;

    FIRE_BALL* nball = new FIRE_BALL("Player", 20.0,30.0,pos,vel,sf::Color(R,G,B));
    return nball;
}



void PLayerBox::update(double duration)
{
    if(under_pressure == true){
        angriness += 100 * duration / MAX_TIME_TO_ANGRY;
        if(angriness > 100.0){
            angriness = 100.0;
        }
    }
    else{
        angriness -= 100 * duration / MAX_TIME_TO_CALM;
        if(angriness < 0.0){
            angriness = 0.0;
        }
    }
}









void PLayerBox::DRAW_ARROW(double mouse_x, double mouse_y)
{
    if(under_pressure == false)
        return;

    if(angriness < 50.0)
        return;
}




FIRE_BALL* PLayerBox::run(double duration, double mouse_x, double mouse_y)
{
    ///std::cout << angriness << std::endl;
    update(duration);


    IntTime += duration;
    if( IntTime > IntTime_margin ){
        IntTime -= IntTime_margin;
        DRAW_ARROW(mouse_x, mouse_y);
    }



    if(will_throw()){
        return hurl(mouse_x, mouse_y);
    }
    else
        return nullptr;
}











