#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib> 

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tux Calculator");

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    int numa = 0;
    sf::Font font;
    sf::Text text, buttonText;
    sf::RectangleShape button(sf::Vector2f(300.f, 50.f)); 

    if (!font.loadFromFile("Arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return 1;
    }

    text.setFont(font);  
    text.setString("Enter a first number: ");
    text.setCharacterSize(24);  
    text.setFillColor(sf::Color::White);  
    text.setPosition(100.f, 100.f); 

    buttonText.setFont(font);
    buttonText.setString("Run Program");
    buttonText.setCharacterSize(24);
    buttonText.setFillColor(sf::Color::Black);
    buttonText.setPosition(100.f, 200.f);

    button.setFillColor(sf::Color::Green);
    button.setPosition(100.f, 200.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::FloatRect buttonBounds = button.getGlobalBounds();
                    if (buttonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        std::system("./newexec");
                    }
                }
            }
            
            if (event.type == sf::Event::TextEntered) {

                if (event.text.unicode >= '0' && event.text.unicode <= '9') {
                    numa = event.text.unicode - '0';
                    text.setString("Enter a first number: " + std::to_string(numa));
                }
            }
        }
    
        window.clear();
        window.draw(text);

        window.draw(button);
        window.draw(buttonText);

        window.display();
        
    }

    return 0;
}
