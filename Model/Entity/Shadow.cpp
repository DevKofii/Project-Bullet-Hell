#include "Shadow.hpp"

using namespace entities;

Shadow::Shadow(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, 300.0f, pTexture) {}

void Shadow::initialize() {
    this->centerOrigin();
    this->pSprite->setScale(1.3f,1.3f);
    this->resetPos();

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

