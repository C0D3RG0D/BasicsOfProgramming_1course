#include <vector>
#include "Circle.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Bouncy balls");

    std::vector<Circle> balls;
    sf::Texture circleTexture;
    circleTexture.loadFromFile("../ext/metall_ball.png");

    float r1 = 50.f;
    float r2 = 75.f;
    float r3 = 100.f;
    balls.emplace_back(r1, 100.f, 2 * r3 - r1).circle_.setTexture(&circleTexture);
    balls.emplace_back(r2, 500.f, 2 * r3 - r2).circle_.setTexture(&circleTexture);
    balls.emplace_back(r3, 900.f, r3).circle_.setTexture(&circleTexture);

    sf::RectangleShape background(sf::Vector2f(WIDTH, HEIGHT));
    sf::Texture cordSystem;
    cordSystem.loadFromFile("../ext/background.png");
    background.setTexture(&cordSystem);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float t = clock.restart().asSeconds();

        for (auto& ball : balls) {
            ball.update(t);
        }

        window.clear();
        window.draw(background);

        for (const auto& circle : balls) {
            window.draw(circle.circle_);
        }

        window.display();
    }
}
