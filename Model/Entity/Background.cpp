#include "Background.hpp"

using namespace entities;

Background::Background(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, 0.0f, pTexture) {}
void Background::initialize() {
    BackgroundInput* backgroundInput = new BackgroundInput(this->strName + " Input");
    this->attachComponent(backgroundInput);

    BackgroundAction* backgroundAction = new BackgroundAction(this->strName + " Movement");
    this->attachComponent(backgroundAction);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}