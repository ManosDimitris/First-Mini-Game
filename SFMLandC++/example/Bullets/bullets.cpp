#include "bullets.hpp"


bullets::bullets(float x, float y, float speed){
    this->speed = speed;
    this->shape.setRadius(5.f); 
    this->shape.setFillColor(Color::Red);
    this->shape.setPosition(x,y);

}


bullets::~bullets(){

}

void bullets::Udpate(){
    this->shape.move(0.f,this->speed);
}

void bullets::Render(RenderTarget & target){
    target.draw(this->shape);
}

CircleShape bullets::getShape(){
    return this->shape;
}