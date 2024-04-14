#include "TestBulletMovement_R.hpp"

using namespace components;
using namespace std;

TestBulletMovement_R::TestBulletMovement_R(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fFrameInterval = 0.01f;
    this->fTicks = 0.0f;
    this->fSpeed = 350.0f;
}

sf::Vector2f normalize(sf::Vector2f vec) {
    float magnitude = sqrtf(vec.x * vec.x + vec.y * vec.y);
    if (magnitude != 0) 
    {
        vec.x /= magnitude;
        vec.y /= magnitude;
    }
    return vec;
}


void TestBulletMovement_R::perform() {
    PoolableObject* pPoolableOwner = (PoolableObject*)this->pOwner;
    TestEnemy* pEnemy = (TestEnemy*)GameObjectManager::getInstance()->findObjectByName("TestBot");
    TestUnit* pPlayer = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");

    if(pPoolableOwner == NULL && pOwner == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else { 
        this->fTicks += this->tDeltaTime.asSeconds();
        float fOffset = this->fSpeed * this->tDeltaTime.asSeconds();

        if(this->fTicks > this->fFrameInterval) {
            this->fTicks = 0.0f;

            pPoolableOwner->getSprite()->move(fOffset, 0.0f);
            //pPoolableOwner->getSprite()->move(moveSpeed);

            float fHalfWidth = pPoolableOwner->getSprite()->getGlobalBounds().width / 2.0f;
            //Bullet Outside Boundary
            if(pPoolableOwner->getSprite()->getPosition().x >= (SCREEN_WIDTH + fHalfWidth)) {
                ObjectPoolManager::getInstance()->getPool(pPoolableOwner->getTag())->releasePoolable(pPoolableOwner);
            }

        }
        
    }
}
