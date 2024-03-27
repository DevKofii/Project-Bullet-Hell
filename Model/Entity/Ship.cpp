#include "Ship.hpp"

using namespace entities;

Ship::Ship(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, 300.0f, pTexture) {
    this->CNormalColor = sf::Color(0,0,0,255);
}

void Ship::initialize() {
    this->centerOrigin();
    this->pSprite->setColor(this->CNormalColor);
    //this->pSprite->setOrigin(51.f,36.f); // Center Origin | Divide dims by 2
    this->pSprite->setPosition(90.f,210.f);
    //this->pSprite->setPosition(640.f,320.f);
    this->pSprite->setScale(0.5f,0.5f);
    

    ShipInput* shipInput = new ShipInput(this->strName + " Input");
    this->attachComponent(shipInput);

    ShipControls* shipControls = new ShipControls(this->strName + " Movement");
    this->attachComponent(shipControls);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}
