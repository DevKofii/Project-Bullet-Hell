#include "BoundsAction.hpp"

using namespace components;

BoundsAction::BoundsAction(std::string strName) : Component  (strName, ComponentType::SCRIPT) {}

void BoundsAction::perform() {
    this->barrierBounds();
}

void BoundsAction::barrierBounds() {
    Barrier* pBarrier = (Barrier*)this->pOwner;
    Edges* pLeft = (Edges*)GameObjectManager::getInstance()->findObjectByName("Left" + std::to_string(pBarrier->getID()));
    Edges* pRight = (Edges*)GameObjectManager::getInstance()->findObjectByName("Right" + std::to_string(pBarrier->getID()));
    Edges* pTop = (Edges*)GameObjectManager::getInstance()->findObjectByName("Top" + std::to_string(pBarrier->getID()));
    Edges* pBottom = (Edges*)GameObjectManager::getInstance()->findObjectByName("Bottom" + std::to_string(pBarrier->getID()));

    TestUnit* pPlayer = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");

    float fOffset = pPlayer->getSpeed() * this->tDeltaTime.asSeconds();

    //Left Boundary
    if(pPlayer->getSprite()->getGlobalBounds().intersects(pLeft->getSprite()->getGlobalBounds())) {
        pPlayer->getSprite()->move(-fOffset,0.f);
    }

    //Right Boundary
    if(pPlayer->getSprite()->getGlobalBounds().intersects(pRight->getSprite()->getGlobalBounds())) {
        pPlayer->getSprite()->move(fOffset,0.f);
    }

    //Top Boundary
    if(pPlayer->getSprite()->getGlobalBounds().intersects(pTop->getSprite()->getGlobalBounds())) {
        pPlayer->getSprite()->move(0.f, -fOffset);
    }

    //Bottom Boundary
    if(pPlayer->getSprite()->getGlobalBounds().intersects(pBottom->getSprite()->getGlobalBounds())) {
        pPlayer->getSprite()->move(0.f, fOffset);
    }

}