#include "CollisionManager.hpp"

using namespace components;

CollisionManager::CollisionManager(std::string strName) : Component  (strName, ComponentType::SCRIPT) {}

void CollisionManager::perform() {
    TestUnit* pUnitOwner = (TestUnit*)this->pOwner;
    TestUnitInput* pUnitInput = (TestUnitInput*)this->getOwner()->getComponents(ComponentType::INPUT)[0];

    if(pUnitInput == NULL && pUnitOwner == NULL) {
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

/*
if (this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width >= target->getSize().x)
{
    this->sprite.setPosition(target->getSize().x - this->sprite.getGlobalBounds().width,this->sprite.getGlobalBounds().top);
    setcollisionState_R(true);
}

//Top
if (this->sprite.getGlobalBounds().top <= 0.f)
{
    setcollisionState_T(true);
    this->sprite.setPosition(this->sprite.getGlobalBounds().left, 0.f);
}

//Bottom
if (this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height >= target->getSize().y)
{
    this->sprite.setPosition(this->sprite.getGlobalBounds().left, target->getSize().y - this->sprite.getGlobalBounds().height);
    setcollisionState_D(true);
}
*/