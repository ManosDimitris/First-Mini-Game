#pragma once
#include<iostream>
#include<vector>
#include <cstdlib> 


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;

class bullets
{
private:
        CircleShape shape;
        float speed;
public:
    
    bullets(float x, float y, float speed);
    virtual ~bullets();

    //Main function
    void Udpate();
    void Render(RenderTarget& targer);
    CircleShape getShape();
};



