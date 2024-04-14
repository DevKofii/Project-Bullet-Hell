#include "Barrier.hpp"

using namespace entities;

Barrier::Barrier(std::string strName, AnimatedTexture* pTexture, int ID) : GameObject(strName,0.0f,pTexture) {
    this->ID = ID;
}

void Barrier::initialize() {
    BoundsAction* pBounds = new BoundsAction(this->strName + " Action");
    this->attachComponent(pBounds);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

int Barrier::getID() {
    return this->ID;
}