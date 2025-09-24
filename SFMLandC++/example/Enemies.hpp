#pragma once
#include<iostream>
#include<vector>
#include <cstdlib> 
#include <ctime>  

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;

class Enemies{
private:

    sf::CircleShape shape;
    float spawnTime;
    float speed;
    bool needsRespawn;
    void initShape(float radius);

public:
    Enemies(float x, float y, float radius = 5.f,float s = 1.f);

    void update(RenderTarget& window);                 
    void render(RenderTarget& target);

    // Getters
    sf::Vector2f getPosition() const;
    sf::FloatRect getBounds() const;
};