#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[])
{
   
    sf::RenderWindow window(sf::VideoMode(640,480), "Deck Tester" );

    while (window.isOpen()){

        sf::Event winEvent;
        while (window.pollEvent(winEvent)){

            if (winEvent.type == sf::Event::Closed){
                window.close();
            }
        }

    }

    return 0;
}
