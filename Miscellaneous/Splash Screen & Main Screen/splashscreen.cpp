 1 #include "StdAfx.h"
 2 #include "SplashScreen.h"
 3 
 4 
 5 void SplashScreen::Show(sf::RenderWindow & renderWindow)
 6 {
 7   sf::Image image;
 8   if(image.LoadFromFile("images/SplashScreen.png") != true)
 9   {
10     return;
11   }
12 
13   sf::Sprite sprite(image);
14   
15   renderWindow.Draw(sprite);
16   renderWindow.Display();
17 
18   sf::Event event;
19   while(true)
20   {
21     while(renderWindow.GetEvent(event))
22     {
23       if(event.Type == sf::Event::EventType::KeyPressed 
24         || event.Type == sf::Event::EventType::MouseButtonPressed
25         || event.Type == sf::Event::EventType::Closed )
26       {
27         return;
28       }
29     }
30   }
31 }