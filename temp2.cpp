// sfml_circle.cpp
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");
    sf::CircleShape circle(60.f);
    circle.setPosition(220.f, 160.f);

    while (window.isOpen()) {
        for (sf::Event e; window.pollEvent(e); )
            if (e.type == sf::Event::Closed) window.close();

        window.clear();     // clears back buffer
        window.draw(circle); // records draw commands
        window.display();   // GPU rasterizes + presents
    }
}
