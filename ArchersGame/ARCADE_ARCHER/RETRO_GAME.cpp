#include "RETRO_GAME.hpp"

RetroGame::RetroGame(sf::RenderWindow* window):
    fireBalls(window),
    targets(window,50.0),
    playerBox(window,100.0,30.0,60.0,800.0,600.0),
    boxParticles(window),
    ///healthBar(window)
{
    this->window = window;

    time = clock();

    time_for_trace_cnst = 0.1;
    time_for_trace = 0.0;

    std::cout << "DONE" << std::endl;

}

STATES::STATES_ENUM RetroGame::run()
{
    /**
    double TIME_TOT = 0.0;
    **/

    while(window->isOpen())
    {
        double ElapsedTime = ((double)(clock() - time))/CLOCKS_PER_SEC;
        time = clock();

        /**

        TIME_TOT += ElapsedTime;
        if(TIME_TOT > duration)
            break;
        else{
            std::cout << TIME_TOT << std::endl;
        }

        **/

        window->clear();

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                return STATES::DEAD;
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S){
                return STATES::SETTINGS;
            }
            else{
                double mouse_x = sf::Mouse::getPosition(*window).x;
                double mouse_y = window->getSize().y - sf::Mouse::getPosition(*window).y;
                playerBox.resolve_event(event, mouse_x, mouse_y);
            }
        }
        double mouse_x = sf::Mouse::getPosition(*window).x;
        double mouse_y = window->getSize().y - sf::Mouse::getPosition(*window).y;
        FIRE_BALL* nball = playerBox.run(ElapsedTime, mouse_x, mouse_y);
        if( nball != nullptr ){
            fireBalls.AddBall(nball);
        }


        time_for_trace += ElapsedTime;
        if(time_for_trace > time_for_trace_cnst)
        {
            ///std::cout << "YES" << std::endl;
            time_for_trace -= time_for_trace_cnst;

            TraceConstants traceConstants = TraceConstants(10.0,1.0);

            std::vector<Trace*> n_traces = fireBalls.genTrace( traceConstants );
            ///std::cout<< n_traces.size() << std::endl;
            for(int i=0;i<n_traces.size();i++){
                traces.push_back(n_traces[i]);
            }
        }

        ///std::cout << traces.size() << " ";


        for(int i=0;i<traces.size();i++)
        {
            traces[i]->update(ElapsedTime);
            if( traces[i]->alive() == false ){
                delete traces[i];
                traces[i] = traces[ traces.size() - 1 ];
                traces.pop_back();
            }
        }

        for(int i=0;i<traces.size();i++)
        {
            ///std::cout<<"HA"<<std::endl;
            window->draw(*traces[i]);
        }

        ///TRACING
        ///To make a dynamic N times faster
        int N = 10;
        for(int i=0;i<N;i++)
        {
            ///std::cout<<fireBalls.BALLS.size()<<std::endl;
            fireBalls.update(ElapsedTime);
        }
        fireBalls.show();
        targets.run(ElapsedTime, playerBox, fireBalls, boxParticles);

        playerBox.resolve_collisions(fireBalls);

        boxParticles.run(ElapsedTime);

        window->draw(playerBox);
        playerBox.show_health();
        ///healthBar.show();

        window->display();
        ///std::cout << "YeS" << std::endl;
    }
}






