#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib> 

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tux Calculator");

    sf::Image icon;
    if (!icon.loadFromFile("/home/allseeingbird/TuxCalc/Tux-Calculator-main/Icon.png")) {
        std::cerr << "Failed to load icon!" << std::endl;
        return 1;
    }

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    int numa = 0;
    int numc = 0;
    bool numaused = false;
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
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(100.f, 200.f);


    

    button.setFillColor(sf::Color::Black);
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
                        std::system("./calc");
                    }
                }
            }
            
            if (event.type == sf::Event::TextEntered) {

                if (event.text.unicode >= '0' && !numaused == true && event.text.unicode <= '9') {
                    numa = event.text.unicode - '0';
                    text.setString("Enter a first number: " + std::to_string(numa));
                    numaused = true;
                }

             if (event.text.unicode >= '0' && numaused == true && event.text.unicode <= '9') {
                    
                }
                
            }
            if (event.type == sf::Event::TextEntered) {
                    text.setFont(font);  
                    text.setString("Enter a second number: ");
                    text.setCharacterSize(24);  
                    text.setFillColor(sf::Color::White);  
                    text.setPosition(100.f, 130.f); 
                    numa = event.text.unicode - '0';
                    text.setString("Enter a second number: " + std::to_string(numc));
                    numaused = true;

            }
        }
    
        window.clear();
        window.draw(text);
        std::cout << numa;
        window.draw(button);
        window.draw(buttonText);

        window.display();
        
    }

    return 0;
}
