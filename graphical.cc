#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tux Calculator");

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    int numa = 0;
    sf::Font font;
    sf::Text text, text2;
    if (!font.loadFromFile("Arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return 1;
    }

    text.setFont(font);  
    text.setString("Enter a first number: ");
    text.setCharacterSize(24);  
    text.setFillColor(sf::Color::White);  
    text.setPosition(100.f, 100.f); 

     text2.setString("Text 2");
    text2.setFont(font);
    text2.setCharacterSize(24);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(100.f, 150.f);
   

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::TextEntered) {
                // Handle ASCII characters entered (including numbers)
                if (event.text.unicode >= '0' && event.text.unicode <= '9') {
                    // Convert character to integer
                    numa = event.text.unicode - '0';
                    text.setString("Enter a first number: " + std::to_string(numa));
                   
                }

                
               
                                
                
            }
        }
    
        window.clear();
        window.draw(text);

        window.display();
        
    }
  

    return 0;
  }

