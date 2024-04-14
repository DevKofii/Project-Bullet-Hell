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
    TestEnemy* pEnemy = (TestEnemy*)GameObjectManager::getInstance()->findObjectByName("TestBot");

    PoolableObject* pBulletR = (PoolableObject*)GameObjectManager::getInstance()->findObjectByName("Test Bullet R");
    PoolableObject* pBulletL = (PoolableObject*)GameObjectManager::getInstance()->findObjectByName("Test Bullet L");
    // GameObjectPool* pRetrievedPool_R = ObjectPoolManager::getInstance()->getPool(PoolTag::TEST_BULLET_R);

    float fOffset = pPlayer->getSpeed() * this->tDeltaTime.asSeconds();
    float fOffset_Bot = 35.0f * this->tDeltaTime.asSeconds();

    //Player
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

    //Bot
        //Left Boundary
        if(pEnemy->getSprite()->getGlobalBounds().intersects(pLeft->getSprite()->getGlobalBounds())) {
            pEnemy->getSprite()->move(-fOffset_Bot,0.f);
            pEnemy->setTag(BotTag::WALK_LEFT);
        }

        //Right Boundary
        if(pEnemy->getSprite()->getGlobalBounds().intersects(pRight->getSprite()->getGlobalBounds())) {
            pEnemy->getSprite()->move(fOffset_Bot,0.f);
            pEnemy->setTag(BotTag::WALK_RIGHT);
        }

        //Top Boundary
        if(pEnemy->getSprite()->getGlobalBounds().intersects(pTop->getSprite()->getGlobalBounds())) {
            pEnemy->getSprite()->move(0.f, -fOffset_Bot);
            pEnemy->setTag(BotTag::WALK_UP);
        }

        //Bottom Boundary
        if(pEnemy->getSprite()->getGlobalBounds().intersects(pBottom->getSprite()->getGlobalBounds())) {
            pEnemy->getSprite()->move(0.f, fOffset_Bot);
            pEnemy->setTag(BotTag::WALK_DOWN);
        }
}