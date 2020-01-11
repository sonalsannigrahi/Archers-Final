#include "player_box.hpp"

PLayerBox::PLayerBox(sf::RenderWindow* window, double pos_x, double pos_y, double length, double W, double H)
{
    this->window = window;
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->length = length;

    this->W = W;
    this->H = H;
    /**
    this->IntTime = 0.0;
    this->IntTime_margin = 0.5;
    **/
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

    FIRE_BALL* nball = new FIRE_BALL(20.0,30.0,pos,vel,sf::Color(R,G,B));
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







/**

void PLayerBox::DRAW_PATH(double mouse_x, double mouse_y)
{
    if(under_pressure == false)
        return;

    if(angriness < 50.0)
        return;

    double diag = sqrt(pow(mouse_x - pos_x,2.0) + pow(mouse_y - pos_y,2.0));
    double cos_theta = (mouse_x - pos_x)/diag;
    double sin_theta = (mouse_y - pos_y)/diag;

    Vector2D Pos(pos_x,pos_y);
    Vector2D Vel(MAX_SPEED * cos_theta, MAX_SPEED * sin_theta);

    Vel = (angriness/100) * Vel;

    double radius = 10.0;
    /// CYAN (0,255,255)


    double N_TIME = 5;

    double TIME = 3.0;
    double DT = 0.005;

    int cnt = 0;

    double current = 0.0;

    while(current <= TIME){
        double eps = 1e-6;
        if( abs(current-0.6)<eps || abs(current-1.2)<eps || abs(current-1.8)<eps || abs(current-2.4)<eps || abs(current-3.0)<eps ){

            int L = 10;
            for(int i = (int)floor((Pos.get_x()-radius)/L); i <= (int)ceil((Pos.get_x()+radius)/L); i++){
                for(int j = (int)floor((Pos.get_y()-radius)/L); j <= (int)ceil((Pos.get_y()+radius)/L); j++){
                    double center_x = (i - 0.5) * L;
                    double center_y = (j - 0.5) * L;
                    double dist = sqrt(pow(center_x - Pos.get_x(),2.0)+pow(center_y - Pos.get_y(),2.0));
                    if(dist <= radius){
                        sf::RectangleShape shape(sf::Vector2f(L,L));
                        shape.setFillColor(sf::Color(255, 0, 0));
                        shape.setPosition(center_x - L/2, H - (center_y + L/2));

                        ///std::cout<<"WHAT"<<std::endl;

                        window->draw(shape);
                    }
                }
            }
            sf::RectangleShape shape(sf::Vector2f(L,L));
            shape.setFillColor(sf::Color(0, 255, 255));
            shape.setPosition(Pos.get_x() - L/2, H - (Pos.get_y() + L/2));

            ///std::cout<<"WHAT"<<std::endl;

            window->draw(shape);
            cnt++;
        }

        Vector2D G(0.0,-10.0);
        Vel += G * DT;
        Pos += Vel * DT;
        current += DT;
    }
    std::cout << cnt << std::endl;
}


**/



FIRE_BALL* PLayerBox::run(double duration, double mouse_x, double mouse_y)
{
    ///std::cout << angriness << std::endl;
    update(duration);
    /**
    IntTime += duration;
    if( IntTime > IntTime_margin ){
        IntTime -= IntTime_margin;
        DRAW_PATH(mouse_x, mouse_y);
    }
    **/
    if(will_throw()){
        return hurl(mouse_x, mouse_y);
    }
    else
        return nullptr;
}











