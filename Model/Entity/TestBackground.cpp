#include "TestBackground.hpp"

using namespace entities;

TestBackground::TestBackground(std::string strName, AnimatedTexture* pTexture) : GameObject(strName,0.0f,pTexture) {}

void TestBackground::initialize() {
    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}