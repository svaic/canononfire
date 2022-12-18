#include "Obstacle.hpp"
#include "Rectangle.hpp"
#include "Color.hpp"
#include "DefaultShape.hpp"

Obstacle::Obstacle()
  : MovableObject(RandomUtility::getRandomFloat(-2.5,-1.5),
                  RandomUtility::getRandomFloat(-0.5,0.7),
                  RandomUtility::getRandomFloat(0.005, 0.01),
                  RandomUtility::getRandomFloat(0.1,0.6),
                  RandomUtility::getRandomFloat(0.5,3.0)) {

    canBeDestroyed = RandomUtility::getRandomBool();

    //RectangleShape shape = RectangleShape::createRectangle(1.00, 1.00, Color::BLACK);
    if (canBeDestroyed) {
        add(DefaultShape::redObstacle);
    } else {
        add(DefaultShape::blackObstacle);
    }
}

void Obstacle::changeColor(glm::vec3 color) {
    shapes.clear();
    if (color == Color::BLACK) {
        add(DefaultShape::blackObstacle);
    }
    if (color == Color::GREEN) {
        add(DefaultShape::greenObstacle);
    }
    if (color == Color::RED) {
        add(DefaultShape::redObstacle);
    }
}

void Obstacle::move() {
    MovableObject::moveRandomX(false);
}

bool Obstacle::reduceHealth() {
    if(canBeDestroyed) {
        health -= 0.25;
        if(health <= 0.7 && health > 0.4) {
            changeColor(Color::GREEN);
        } else if (health <= 0.4) {
            changeColor(Color::RED);
        }
        if (health <= 0) return true;
        else return false;
    }

    return false;
}