#include "player_box.hpp"

PLayerBox::PLayerBox(sf::RenderWindow* window, double pos_x, double pos_y, double length, double W, double H):
    healthBar(window)
{
    this->score = 0;

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

void PLayerBox::score_inc()
{
    score += 1;
}

int PLayerBox::get_score()
{
    return score;
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

                if(mouse_y > pos_y){
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

    FIRE_BALL* nball = new FIRE_BALL(1000000.0, "PLAYER", 20.0,30.0,pos,vel,sf::Color(R,G,B));
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
    

    double radius = 200;

    Vector2D e_n(mouse_x - pos_x, mouse_y - pos_y);
    e_n.normalize();

    Vector2D e_t = e_n;
    e_t.turn(pi/2);


    Vector2D point = radius * (angriness / 100) * e_n;

    std::cout << point.get_x() << " " << point.get_y() << std::endl;

    double arrow_width = 10;
    double arrow_height = 40;

    Vector2D point_r = point - arrow_width * e_t;
    Vector2D point_l = point + arrow_width * e_t;

    Vector2D point_top = point + arrow_height * e_n;

    ///DRAWING



    sf::ConvexShape convex;

    // resize it to 5 points
    convex.setPointCount(3);


    std::cout << point_top.get_x() << " " << point_top.get_y() << std::endl; 

    // define the points
    convex.setPoint(0, sf::Vector2f(pos_x + point_l.get_x(), window->getSize().y - (pos_y + point_l.get_y()   )       ));
    convex.setPoint(1, sf::Vector2f(pos_x + point_top.get_x(), window->getSize().y - (pos_y + point_top.get_y()    )    ));
    convex.setPoint(2, sf::Vector2f(pos_x + point_r.get_x(), window->getSize().y - (pos_y + point_r.get_y()  )           ));

    convex.setFillColor(sf::Color(255,255,0,100));

    window->draw(convex);
    ///std::cout << "DRAWING" << std::endl;
}



std::vector<FIRE_BALL*> PLayerBox::resolve_collision(FIRE_BALL* ball)
{
    std::vector<FIRE_BALL*> fire_balls_vect;

    std::vector< std::pair<Vector2D, Vector2D> > lines;

    Vector2D point_1(pos_x + length/2, pos_y + length/2);
    Vector2D point_2(pos_x - length/2, pos_y + length/2);
    Vector2D point_3(pos_x - length/2, pos_y - length/2);
    Vector2D point_4(pos_x + length/2, pos_y - length/2);

    Vector2D e_x(1.0,0.0);
    Vector2D e_y(0.0,1.0);

    lines.push_back(std::make_pair(point_1,point_2));
    lines.push_back(std::make_pair(point_2,point_3));
    lines.push_back(std::make_pair(point_3,point_4));
    lines.push_back(std::make_pair(point_4,point_1));

    double dist = INFINITY;
    Vector2D center(ball->getPos());
    double radius = ball->getRadius();

    for(int i=0;i<lines.size();i++){
        Vector2D point_a = lines[i].first;
        Vector2D point_b = lines[i].second;

        double distance;

        if( (center - point_a) * (point_b - point_a) < 0 ){
            distance = (center - point_a).len();
        }
        if( (center - point_b) * (point_a - point_b) < 0 ){
            distance = (center - point_b).len();
        }
        else{
            distance = ( (center - point_a) - ( ((center - point_a) * (point_b - point_a)) / (point_b - point_a).len() ) * (point_b - point_a) ).len();
        }
        dist = std::min(dist, distance);
    }
    ///std::cout<< dist << " " << radius <<  std::endl;

    if(ball->getWhoThrowedIt() == "Opponent" && ball->getRadius() > 15.0 && dist < radius)
    {
        int N_cnt = 5;

        for(int i=0;i<N_cnt;i++){
            /// RANDOM COLORS
            int R = rand()%255 + 1;
            int G = rand()%255 + 1;
            int B = rand()%255 + 1;

            double RADIUS = ball->getRadius();

            Vector2D pos = Vector2D( fRand(-RADIUS,RADIUS), fRand(-RADIUS,RADIUS) );
            pos += ball->getPos();

            /// IN RADIANS

            double theta_max = 10 * ( 2 * pi / 360 );

            double theta = fRand(-theta_max, theta_max);

            Vector2D vel = ball->getVel();
            vel.turn(theta);

            FIRE_BALL* n_ball = new FIRE_BALL(2.0 * 10 , "Opponent" ,ball->getMass()/N_cnt, 10.0, pos, vel, sf::Color(R,G,B));
            fire_balls_vect.push_back(n_ball);
        }
        healthBar.inc_health(-20);
    }
    return fire_balls_vect;
}

void PLayerBox::resolve_collisions(FIRE_BALLS& fireBalls)
{
    std::vector<FIRE_BALL*> fire_balls = fireBalls.getBALLS();
    for(int i=0;i<fire_balls.size();i++)
    {
        ///std::cout << 1 << std::endl;
        std::vector<FIRE_BALL* > fire_ball_vect = resolve_collision(fire_balls[i]);
        ///std::cout << 2 << std::endl;
        if(fire_ball_vect.size() > 0)
        {
            ///std::cout<<  "HOHOHOHOHO" <<std::endl;
            for(int j=0;j<fire_ball_vect.size();j++){
                fireBalls.AddBall(fire_ball_vect[j]);
            }
            ///std::cout << 3 << std::endl;
            fireBalls.RemBall(fire_balls[i]);
            ///std::cout << 4 << std::endl;
            fire_balls[i] = fire_balls[ fire_balls.size() - 1 ];
            fire_balls.pop_back();
            ///std::cout << 5 << std::endl;
        }
    }
}





FIRE_BALL* PLayerBox::run(double duration, double mouse_x, double mouse_y)
{
    ///std::cout << angriness << std::endl;
    update(duration);

    /**
    IntTime += duration;
    if( IntTime > IntTime_margin ){
        IntTime -= IntTime_margin;
        DRAW_ARROW(mouse_x, mouse_y);
    }
    **/

    DRAW_ARROW(mouse_x, mouse_y);


    if(will_throw()){
        return hurl(mouse_x, mouse_y);
    }
    else
        return nullptr;
}







void PLayerBox::show_health()
{
    healthBar.show();
}





