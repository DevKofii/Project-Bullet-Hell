#include "TestBulletMovement_L.hpp"

using namespace components;

TestBulletMovement_L::TestBulletMovement_L(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fFrameInterval = 0.01f;
    this->fTicks = 0.0f;
    this->fSpeed = 350.0f;
}

void TestBulletMovement_L::perform() {
    PoolableObject* pPoolableOwnerL = (PoolableObject*)this->pOwner;
    TestEnemy* pEnemy = (TestEnemy*)GameObjectManager::getInstance()->findObjectByName("TestBot");
    TestUnit* pPlayer = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");
    
    Barrier* p1 = (Barrier*)GameObjectManager::getInstance()->findObjectByName("Barrier1");
    Barrier* p2 = (Barrier*)GameObjectManager::getInstance()->findObjectByName("Barrier2");
    Barrier* p3 = (Barrier*)GameObjectManager::getInstance()->findObjectByName("Barrier3");
    Barrier* p4 = (Barrier*)GameObjectManager::getInstance()->findObjectByName("Barrier4");
    Barrier* p5 = (Barrier*)GameObjectManager::getInstance()->findObjectByName("Barrier5");
    Barrier* p6 = (Barrier*)GameObjectManager::getInstance()->findObjectByName("Barrier6");

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

            //Bullet Hits Right Barrier
            if(pPoolableOwnerL->getSprite()->getGlobalBounds().intersects(p1->getSprite()->getGlobalBounds()) ||
            pPoolableOwnerL->getSprite()->getGlobalBounds().intersects(p2->getSprite()->getGlobalBounds()) || 
            pPoolableOwnerL->getSprite()->getGlobalBounds().intersects(p3->getSprite()->getGlobalBounds()) || 
            pPoolableOwnerL->getSprite()->getGlobalBounds().intersects(p4->getSprite()->getGlobalBounds()) || 
            pPoolableOwnerL->getSprite()->getGlobalBounds().intersects(p5->getSprite()->getGlobalBounds()) || 
            pPoolableOwnerL->getSprite()->getGlobalBounds().intersects(p6->getSprite()->getGlobalBounds())) {
                ObjectPoolManager::getInstance()->getPool(pPoolableOwnerL->getTag())->releasePoolable(pPoolableOwnerL);
            }

            //Player Bullet Hits Enemy
            if(pPoolableOwnerL->getName() == "Test Bullet L") {
                if(pPoolableOwnerL->getSprite()->getGlobalBounds().intersects(pEnemy->getSprite()->getGlobalBounds())) {
                    //std::cout << "Hits Enemy" << std::endl;
                    ObjectPoolManager::getInstance()->getPool(pPoolableOwnerL->getTag())->releasePoolable(pPoolableOwnerL);
                    pEnemy->setPosition({690.f,210.f});
                    ScoreManager::getInstance()->addPlayerScore();

                    std::cout << "Player: " << ScoreManager::getInstance()->returnPlayerScore() << std::endl;
                    std::cout << "Enemy: " << ScoreManager::getInstance()->returnEnemyScore() << std::endl << std::endl;
                }
            }
            
            //Enemy Bullet Hits Player
            else {
                if(pPoolableOwnerL->getSprite()->getGlobalBounds().intersects(pPlayer->getSprite()->getGlobalBounds())) {
                    //std::cout << "Hits Player" << std::endl;
                    ObjectPoolManager::getInstance()->getPool(pPoolableOwnerL->getTag())->releasePoolable(pPoolableOwnerL);
                    pPlayer->setPosition({90.f,210.f});
                    ScoreManager::getInstance()->addEnemyScore();

                    std::cout << "Player: " << ScoreManager::getInstance()->returnPlayerScore() << std::endl;
                    std::cout << "Enemy: " << ScoreManager::getInstance()->returnEnemyScore() << std::endl << std::endl;
                }
            }
        }
        
    }
}
