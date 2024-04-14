#include "Collider.hpp"

using namespace entities;

Collider::Collider(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, 300.0f, pTexture) {} 

void Collider::initialize() {
    this->pSprite->setOrigin(0.f,this->pSprite->getTexture()->getSize().y/2);
    this->pSprite->setScale(-1.f,1.f);
    this->resetPos();

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}