#include"Enemies.hpp"

void Enemies::initShape(float radius)
{
    this->shape.setRadius(radius);
    this->shape.setPointCount(30);
    this->shape.setFillColor(sf::Color::White);
    this->shape.setOrigin(radius, radius); 
    
}

Enemies::Enemies(float x, float y, float radius, float speed)
{
    this->initShape(radius);
    this->shape.setPosition(x,y);
    this->speed = speed;
    this->needsRespawn = false;
}

void Enemies::update(RenderTarget& window)
{
    this->shape.move(0,this->speed * 1.0f);

    if (this->shape.getPosition().y - this->shape.getRadius() > window.getSize().y) {
        float x = static_cast<float>(rand() % window.getSize().x);
        this->shape.setPosition(x, -this->shape.getRadius()); 
    }

    
}

void Enemies::render(sf::RenderTarget &target)
{
    target.draw(this->shape);
}

sf::Vector2f Enemies::getPosition() const
{
    return this->shape.getPosition();
}

sf::FloatRect Enemies::getBounds() const
{
    return this->shape.getGlobalBounds();
}

