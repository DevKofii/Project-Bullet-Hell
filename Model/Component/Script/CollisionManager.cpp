#include "CollisionManager.hpp"

using namespace components;

CollisionManager::CollisionManager(std::string strName) : Component  (strName, ComponentType::SCRIPT) {}

void CollisionManager::perform() {
    TestUnit* pUnitOwner = (TestUnit*)this->pOwner;
    TestUnitInput* pUnitInput = (TestUnitInput*)this->getOwner()->getComponents(ComponentType::INPUT)[0];
    TestEnemy* pEnemy = (TestEnemy*)GameObjectManager::getInstance()->findObjectByName("TestBot");

    if(pUnitInput == NULL && pUnitOwner == NULL && pEnemy == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        float fOffset  = pUnitOwner->getSpeed() * this->tDeltaTime.asSeconds();

        //Left Boundary
        if(pUnitOwner->getSprite()->getGlobalBounds().left <= 0.f) {
            pUnitOwner->getSprite()->move(fOffset,0.f);
        }

        //Right Boundary
        if(pUnitOwner->getSprite()->getGlobalBounds().left + pUnitOwner->getSprite()->getGlobalBounds().width >= SCREEN_WIDTH) {
            pUnitOwner->getSprite()->move(-fOffset,0.f);
        }

        //Top Boundary
        if(pUnitOwner->getSprite()->getGlobalBounds().top <= 0.f) {
            pUnitOwner->getSprite()->move(0.f,fOffset);
        }

        //Bottom Boundary
        if(pUnitOwner->getSprite()->getGlobalBounds().top + pUnitOwner->getSprite()->getGlobalBounds().height >= SCREEN_HEIGHT) {
            pUnitOwner->getSprite()->move(0.f,-fOffset);
        }

    }
}