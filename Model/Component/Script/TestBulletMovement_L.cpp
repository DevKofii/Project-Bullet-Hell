#include "TestBulletMovement_L.hpp"

using namespace components;

TestBulletMovement_L::TestBulletMovement_L(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fFrameInterval = 0.01f;
    this->fTicks = 0.0f;
    this->fSpeed = 350.0f;
}

void TestBulletMovement_L::perform() {
    PoolableObject* pPoolableOwnerL = (PoolableObject*)this->pOwner;
    


    if(pPoolableOwnerL == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        //std::cout << "Left" << std::endl;

        this->fTicks += this->tDeltaTime.asSeconds();
        float fOffset = this->fSpeed * this->tDeltaTime.asSeconds();

        if(this->fTicks > this->fFrameInterval) {
            //std::cout << pPoolableOwnerL->getSprite()->getPosition().x << std::endl;

            this->fTicks = 0.0f;
            this->pOwner->getSprite()->move(-fOffset, 0.0f);

            float fHalfWidth = this->pOwner->getSprite()->getGlobalBounds().width / 2.0f;
            //Bullet Outside Boundary
            if(-pPoolableOwnerL->getSprite()->getPosition().x >= (SCREEN_WIDTH + fHalfWidth)) {
                ObjectPoolManager::getInstance()->getPool(pPoolableOwnerL->getTag())->releasePoolable(pPoolableOwnerL);
            }
        }
        
    }
}
