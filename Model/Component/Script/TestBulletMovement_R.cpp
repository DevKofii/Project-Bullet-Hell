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

    Barrier* p1 = (Barrier*)GameObjectManager::getInstance()->findObjectByName("Barrier1");
    Barrier* p2 = (Barrier*)GameObjectManager::getInstance()->findObjectByName("Barrier2");
    Barrier* p3 = (Barrier*)GameObjectManager::getInstance()->findObjectByName("Barrier3");
    Barrier* p4 = (Barrier*)GameObjectManager::getInstance()->findObjectByName("Barrier4");
    Barrier* p5 = (Barrier*)GameObjectManager::getInstance()->findObjectByName("Barrier5");
    Barrier* p6 = (Barrier*)GameObjectManager::getInstance()->findObjectByName("Barrier6");

    if(pPoolableOwner == NULL && pOwner == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else { 
        this->fTicks += this->tDeltaTime.asSeconds();
        float fOffset = this->fSpeed * this->tDeltaTime.asSeconds();

        if(this->fTicks > this->fFrameInterval) {
            this->fTicks = 0.0f;

            pPoolableOwner->getSprite()->move(fOffset, 0.0f);

            float fHalfWidth = pPoolableOwner->getSprite()->getGlobalBounds().width / 2.0f;
            //Bullet Outside Boundary
            if(pPoolableOwner->getSprite()->getPosition().x >= (SCREEN_WIDTH + fHalfWidth)) {
                ObjectPoolManager::getInstance()->getPool(pPoolableOwner->getTag())->releasePoolable(pPoolableOwner);
            }

            //Bullet Hits Left Barrier
            if(pPoolableOwner->getSprite()->getGlobalBounds().intersects(p1->getSprite()->getGlobalBounds()) ||
            pPoolableOwner->getSprite()->getGlobalBounds().intersects(p2->getSprite()->getGlobalBounds()) || 
            pPoolableOwner->getSprite()->getGlobalBounds().intersects(p3->getSprite()->getGlobalBounds()) || 
            pPoolableOwner->getSprite()->getGlobalBounds().intersects(p4->getSprite()->getGlobalBounds()) || 
            pPoolableOwner->getSprite()->getGlobalBounds().intersects(p5->getSprite()->getGlobalBounds()) || 
            pPoolableOwner->getSprite()->getGlobalBounds().intersects(p6->getSprite()->getGlobalBounds())) {
                ObjectPoolManager::getInstance()->getPool(pPoolableOwner->getTag())->releasePoolable(pPoolableOwner);
            }
            
            //Player Bullet Hits Enemy
            if(pPoolableOwner->getName() == "Test Bullet R") {
                if(pPoolableOwner->getSprite()->getGlobalBounds().intersects(pEnemy->getSprite()->getGlobalBounds())) {
                    //std::cout << "Hits Enemy" << std::endl;
                    ObjectPoolManager::getInstance()->getPool(pPoolableOwner->getTag())->releasePoolable(pPoolableOwner);
                    pEnemy->setPosition({690.f,210.f});
                }
            }
            
            //Enemy Bullet Hits Player
            else {
                if(pPoolableOwner->getSprite()->getGlobalBounds().intersects(pPlayer->getSprite()->getGlobalBounds())) {
                    //std::cout << "Hits Player" << std::endl;
                    ObjectPoolManager::getInstance()->getPool(pPoolableOwner->getTag())->releasePoolable(pPoolableOwner);
                    pPlayer->setPosition({90.f,210.f});
                }
            }
        }
    }
}
