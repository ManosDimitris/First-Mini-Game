#include "game.hpp"

// HELPER FUNCTIONS
void Game::initVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.height = 720;
    this->videoMode.width = 1080;
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

    float radius = rand() % 13 + 9;
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

void Game::UpdatePlayerPos(const Vector2i &mousePos)
{
    sf::Vector2f currentPos = player.getPosition();
    float lerpSpeed = 0.2f; // 0 < speed <= 1
    float newX = currentPos.x + (mousePos.x - currentPos.x) * lerpSpeed;
    float newY = currentPos.y + (mousePos.y - currentPos.y) * lerpSpeed;
    player.setPosition(newX, newY);
}

void Game::UpdateEnemies()
{

    // Move the enemies and respawn them if they are killed(player taps on them)
    size_t i = 0;
    for (size_t e = 0; e < enemies.size(); ++e)
    {
        enemies[e].update(*this->window);

        for (size_t b = 0; b < Bullets.size(); ++b)
        {
            if (enemies[e].getBounds().intersects(Bullets[b].getShape().getGlobalBounds()))
            {
                this->points += 1;

                
                enemies.erase(enemies.begin() + e);

                
                Bullets.erase(Bullets.begin() + b);

                
                this->initEnemy();

                
                --e;   
                break; 
            }
        }
    }

    if (enemies.size() == 0)
        this->gameOver = true;
}

void Game::initGameOverText()
{
    this->gameOverText.setFont(this->font);
    this->gameOverText.setCharacterSize(70);
    this->gameOverText.setFillColor(sf::Color::Red);
    this->gameOverText.setString("YOU WIN!");

    this->gameOverText.setPosition(this->window->getPosition().x / 2, this->window->getPosition().y / 2);
}

void Game::renderText()
{

    this->PointsUi.setFont(this->font);
    this->PointsUi.setCharacterSize(15);
    this->PointsUi.setFillColor(sf::Color(219, 219, 219));

    this->gameOverText.setPosition(10.f, 10.f);
    this->window->draw(this->PointsUi);
}

void Game::initBullet()
{
    bullets tmp = bullets(player.getPosition().x - 5.0f,
                          player.getPosition().y,
                          -5.0f);
    this->Bullets.push_back(tmp);
}

void Game::UpdateBullets()
{
    for (size_t i = 0; i < Bullets.size(); ++i)
    {
        Bullets[i].Udpate(); // Fix typo if needed
        if (Bullets[i].getShape().getPosition().y < 0)
        {
            Bullets.erase(Bullets.begin() + i);
            --i;
        }
    }
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
    if (!this->font.loadFromFile("/home/mdimitris/Downloads/Roboto/static/Roboto-Black.ttf"))
    {
        exit(1);
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
        case sf::Event::Closed:
            this->window->close();
            break;

        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
            {
                this->window->close();
            }
            else if (this->ev.key.code == sf::Keyboard::Space)
            {

                this->initBullet();
                std::cout << "Bullet fired!\n";
            }
            break;

        default:
            break;
        }
    }
}

const bool Game::running()
{
    return this->window->isOpen();
}

void Game::updateText()
{
    stringstream ss;
    ss << "Points :" << this->points;

    this->PointsUi.setString(ss.str());
}

void Game::Update()
{
    this->PollEvents();
    Vector2i mousePos = UpdateMousePos();
    this->UpdatePlayerPos(mousePos);
    this->UpdateEnemies();
    this->UpdateBullets();
    this->updateText();
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
        this->renderText();
        for (auto &e : enemies)
        {
            e.render(*this->window);
        }
        for (auto &b : Bullets)
        {
            b.Render(*this->window);
        }
        this->window->draw(this->player);
    }
    this->window->display();
}