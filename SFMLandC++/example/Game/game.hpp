#pragma once
#include<iostream>
#include<vector>
#include<cstdlib>
#include"../Enemies/Enemies.hpp"
#include "ctime"
#include <sstream>
#include"../Bullets/bullets.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#define N 10

using namespace std;
using namespace sf;

class Game{
private:

    RenderWindow* window;
    VideoMode videoMode;
    Event ev;
    Vector2i mouse ;
    bool gameOver;
    Text gameOverText;
    Text PointsUi;
    Font font;
    unsigned long points = 0;

    //Game objects
    CircleShape player;
    vector<Enemies> enemies;
    vector<bullets> Bullets;


    void initVariables();
    void initWindow();
    void initPlayer();
    void initEnemy();
    void UpdateEnemies();
    void initGameOverText();
    void renderText();
    void initBullet();
    void UpdateBullets();
    public:
    
    
    Game();
    virtual ~Game();
    
    Vector2i UpdateMousePos();
    void PollEvents();
    const bool running();
    void updateText();
    void Update();
    void Render();

    void UpdatePlayerPos(const Vector2i &mousePos);
};