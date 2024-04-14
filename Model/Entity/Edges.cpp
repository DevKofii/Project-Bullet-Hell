#include "Edges.hpp"

using namespace entities;

Edges::Edges(std::string strName, AnimatedTexture* pTexture) : GameObject(strName,0.0f,pTexture) {}

void Edges::initialize() {
    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}