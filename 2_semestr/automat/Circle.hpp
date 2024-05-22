#include <iostream>
#include <SFML/Graphics.hpp>

#define WIDTH 1600
#define HEIGHT 900
#define DAMPING 0.65
#define HORIZONTAL_DAMPING 0.99996f
#define SPHERE_COEF 0.5
#define AIR_DENSITY 1.3
#define GROUND_HEIGHT 870

float G = 9.81 / .04f;

class Circle {
public:
	sf::CircleShape circle_;
	float vx_ = 40.f;
	float vy_ = 0;
	float radius_;


	Circle(float r, float x, float y) : radius_(r) {
		sf::Texture circleTexture;
		circleTexture.loadFromFile("../ext/metall_ball.png");

		circle_.setRadius(radius_);
		circle_.setOrigin(sf::Vector2f(radius_, radius_));
		circle_.setPosition(x, y);
		circle_.setTexture(&circleTexture);
	}

	float airResistance() const {
		float SphereArea = 3.14f * radius_ * radius_;
		float current_speed = sqrt(vy_ * vy_ + vx_ * vx_);
		float AirResistance = (SPHERE_COEF * SphereArea * AIR_DENSITY * (current_speed / 100.f) * (current_speed / 100.f)) / 2.f;
		return AirResistance / 30000.f;
	}

    void update(float t) {
        float a = G * (2 - 1 / (1 + airResistance()));

        vy_ += a * t;
        vx_ = vx_ * HORIZONTAL_DAMPING;

        circle_.move(0, vy_ * t);
        circle_.move(vx_ * t, 0);

        check_border_collision();
    }

    void check_border_collision() {
        if (circle_.getPosition().y + circle_.getRadius() >= GROUND_HEIGHT) { // UP
            circle_.setPosition(circle_.getPosition().x, GROUND_HEIGHT - circle_.getRadius());
            vy_ = -vy_ * DAMPING;
            vx_ = vx_ * DAMPING;
        }

        if (circle_.getPosition().y - circle_.getRadius() <= 0) { // DOWN
            circle_.setPosition(circle_.getPosition().x, circle_.getRadius());
            vy_ = -vy_ * DAMPING;
        }

        if (circle_.getPosition().x + circle_.getRadius() >= WIDTH) {
            circle_.setPosition(WIDTH - circle_.getRadius(), circle_.getPosition().y);
            vx_ = -vx_ * DAMPING;
        }

        if (circle_.getPosition().x - circle_.getRadius() <= 0) {
            circle_.setPosition(circle_.getRadius(), circle_.getPosition().y);
            vx_ = -vx_ * DAMPING;
        }
    }
};