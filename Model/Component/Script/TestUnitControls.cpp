#include "TestUnitControls.hpp"

using namespace components;

TestUnitControls::TestUnitControls(std::string strName) : Component  (strName, ComponentType::SCRIPT) {
    this->fSpeed = 300.0f;
}

void TestUnitControls::perform() {
    TestUnit* pUnitOwner = (TestUnit*)this->pOwner;
    TestUnitInput* pUnitInput = (TestUnitInput*)this->getOwner()->getComponents(ComponentType::INPUT)[0];

    if(pUnitInput == NULL && pUnitOwner == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        float fOffset  = this->fSpeed * this->tDeltaTime.asSeconds();

        //Movement
        if(pUnitInput->getUp()) pUnitOwner->getSprite()->move(0.f,-fOffset);
        if(pUnitInput->getDown()) pUnitOwner->getSprite()->move(0.f,fOffset);

        if(pUnitInput->getLeft()) {
            pUnitOwner->getSprite()->setScale(-2.0f,2.0f);
            pUnitOwner->getSprite()->move(-fOffset,0.f);
            pUnitOwner->setOrientationLeft(pUnitInput->getLeft());
            pUnitOwner->setOrientationRight(false);
            
        }
        if(pUnitInput->getRight()) {
            pUnitOwner->getSprite()->setScale(2.0f,2.0f);
            pUnitOwner->getSprite()->move(fOffset,0.f);
            pUnitOwner->setOrientationRight(pUnitInput->getRight());
            pUnitOwner->setOrientationLeft(false);
        }

        //Actions
        if(pUnitInput->getShoot()) { 
            pUnitInput->resetShoot();
            if(pUnitOwner->getOrientationRight()) {
                ObjectPoolManager::getInstance()->getPool(PoolTag::TEST_BULLET_R)->requestPoolable();
            }
            else if(pUnitOwner->getOrientationLeft()) {
                ObjectPoolManager::getInstance()->getPool(PoolTag::TEST_BULLET_L)->requestPoolable();
            }

        }
    }
}