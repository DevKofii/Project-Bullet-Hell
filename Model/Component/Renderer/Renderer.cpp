#include "Renderer.hpp"

using namespace components;

Renderer::Renderer(std::string strName) : Component(strName, ComponentType::RENDERER) {
    this->vecDrawables = {};
}

void Renderer::perform() {
    for(sf::Drawable* pDrawable : this->vecDrawables)
        this->pWindow->draw(*pDrawable);
}

void Renderer::assignTargetWindow(sf::RenderWindow* pWindow) {
    this->pWindow = pWindow;
}

void Renderer::assignDrawable(sf::Drawable* pDrawable) {
    this->vecDrawables.push_back(pDrawable);
}

void Renderer::flip() {
    sf::Sprite* pSprite = (sf::Sprite*)this->vecDrawables[0];
    pSprite->setScale(-pSprite->getScale().x, pSprite->getScale().y);
}
