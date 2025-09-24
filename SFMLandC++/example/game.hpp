#pragma once
#include<iostream>
#include<vector>
#include<cstdlib>
#include"Enemies.hpp"
#include "ctime"


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
    Font font;
    //Game objects
    CircleShape player;
    vector<Enemies> enemies;

    void initVariables();
    void initWindow();
    void initPlayer();
    void initEnemy();
    void UpdateEnemies();
    void initGameOverText();
    
public:


    Game();
    virtual ~Game();

    Vector2i UpdateMousePos();
    void PollEvents();
    const bool running();
    void Update();
    void Render();

    void UpdatePlayerPos();
};