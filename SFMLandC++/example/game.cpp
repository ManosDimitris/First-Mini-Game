#include "game.hpp"

// HELPER FUNCTIONS
void Game::initVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new RenderWindow(this->videoMode, "Examples", Style::Titlebar | Style::Close);
    // FPS limit for better performance
    this->window->setFramerateLimit(60);
}

void Game::initPlayer()
{
    Vector2u size = this->window->getSize();
    Vector2f center(size.x / 2.f, size.y / 2.f);

    this->player = CircleShape(40.f, 3);
    this->player.setFillColor(Color(150, 50, 250));
    this->player.setOutlineThickness(4.f);
    this->player.setOutlineColor(Color(250, 150, 100));

    // if Origin isnt set to the center of the object it cannot be centered in the window correctly
    this->player.setOrigin(this->player.getRadius(), this->player.getRadius());
    this->player.setPosition(center);
}

void Game::initEnemy()
{
    
    float radius = rand() % 10 + 3;
    float x = radius + rand() % static_cast<int>(this->window->getSize().x - 2 * radius);
    float y = radius + rand() % static_cast<int>(this->window->getSize().y - 2 * radius);
    float speed = rand() % 5 + 1.0f;
    enemies.push_back(Enemies(x, y, radius, speed));
}

Vector2i Game::UpdateMousePos()
{
    this->mouse = Mouse::getPosition(*this->window);

    return this->mouse;
}

void Game::UpdatePlayerPos()
{
    Vector2i i = UpdateMousePos();
    this->player.setPosition(static_cast<float>(i.x), static_cast<float>(i.y));
}

void Game::UpdateEnemies()
{

    // Move the enemies and respawn them if they are killed(player taps on them)
    size_t i = 0;
    for (size_t i = 0; i < enemies.size(); i++)
    {
        enemies[i].update(*this->window);
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (enemies[i].getBounds().intersects(this->player.getGlobalBounds()))
            {
                enemies.erase(enemies.begin() + i);
                this->initEnemy();
            }
        }
    }
    if (enemies.size() == 0)
        this->gameOver = true;
}

void Game::initGameOverText()
{

    if (!this->font.loadFromFile("/home/mdimitris/Downloads/Roboto/static/Roboto-Black.ttf"))
    {
        exit(1);
    }
    this->gameOverText.setFont(this->font);
    this->gameOverText.setCharacterSize(70);
    this->gameOverText.setFillColor(sf::Color::Red);
    this->gameOverText.setString("YOU WIN!");

    this->gameOverText.setPosition(this->window->getPosition().x / 2, this->window->getPosition().y / 2);
}

// Constructo/ Deconstructor
Game::Game()
{
    this->gameOver = false;
    this->initVariables();
    this->initWindow();
    this->initPlayer();
    for (int i = 0; i < N; i++)
    {
        this->initEnemy();
    }
}

Game::~Game()
{
    delete this->window;
}

// MAIN FUNCTIONS

void Game::PollEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case Event::Closed:
            this->window->close();
            break;
        case Event::KeyPressed:
            if (this->ev.key.code == Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}

const bool Game::running()
{
    return this->window->isOpen();
}

void Game::Update()
{
    this->UpdateMousePos();
    this->PollEvents();
    this->UpdatePlayerPos();
    this->UpdateEnemies();
}

void Game::Render()
{

    this->window->clear(Color(0, 0, 0, 225));
    if (this->gameOver == true)
    {
        initGameOverText();
        this->window->draw(this->gameOverText);
    }
    else
    {
        for (auto &e : enemies)
        {
            e.render(*this->window);
        }
        this->window->draw(this->player);
    }
    this->window->display();
}