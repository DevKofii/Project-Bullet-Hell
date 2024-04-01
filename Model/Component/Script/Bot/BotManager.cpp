#include "BotManager.hpp"

using namespace components;

BotManager::BotManager(std::string strName) : Component  (strName, ComponentType::SCRIPT) {
    this->ETag = BotTag::IDLE;
    this->fSpeed = 60.0f;
}

void BotManager::perform() {
    TestEnemy* pEnemy = (TestEnemy*)GameObjectManager::getInstance()->findObjectByName("TestBot");
    BotInput* pInput = (BotInput*) this->getOwner()->getComponents(ComponentType::INPUT)[0];

    if(pEnemy == NULL && pInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        this->checkState();
        this->performState();
        this->checkCollision();
    }
}

void BotManager::checkState() {
    BotInput* pInput = (BotInput*) this->getOwner()->getComponents(ComponentType::INPUT)[0];
    if(pInput->getLeft()) {
        std::cout << "Bot State: Going Left" << std::endl;
        this->setTag(BotTag::WALK_LEFT);
    }
    else if(pInput->getRight()) {
        std::cout << "Bot State: Going Right" << std::endl;
        this->setTag(BotTag::WALK_RIGHT);
    }
    else {
        std::cout << "Bot State: IDLE" << std::endl;
        this->setTag(BotTag::IDLE);
    }
}

void BotManager::performState() {
    TestEnemy* pEnemy = (TestEnemy*)GameObjectManager::getInstance()->findObjectByName("TestBot");
    BotInput* pInput = (BotInput*) this->getOwner()->getComponents(ComponentType::INPUT)[0];

    float fOffset  = this->fSpeed * this->tDeltaTime.asSeconds();

    switch(ETag) {
        case BotTag::IDLE:
            pInput->resetAll();
            pInput->setLeft(true);
            break;

        case BotTag::WALK_LEFT:
            pEnemy->getSprite()->setScale(-2.0f,2.0f);
            pEnemy->getSprite()->move(-fOffset,0.f);
            break;

        case BotTag::WALK_RIGHT:
            pEnemy->getSprite()->setScale(2.0f,2.0f);
            pEnemy->getSprite()->move(fOffset,0.f);
            break;
        
        case BotTag::WALK_UP:
            pEnemy->getSprite()->move(0.f, -fOffset);
            break;
        
        case BotTag::WALK_DOWN:
            pEnemy->getSprite()->move(0.f, fOffset);
            break;

        default:
            break;

    }
}

void BotManager::checkCollision() {
    TestEnemy* pEnemy = (TestEnemy*)GameObjectManager::getInstance()->findObjectByName("TestBot");
    BotInput* pInput = (BotInput*) this->getOwner()->getComponents(ComponentType::INPUT)[0];

    float fOffset  = this->fSpeed * this->tDeltaTime.asSeconds();

    //Left Boundary
    if(pEnemy->getSprite()->getGlobalBounds().left <= 0.f) {
        pEnemy->getSprite()->move(fOffset,0.f);
        pInput->resetAll();
        pInput->setRight(true);
    }

    //Right Boundary
    if(pEnemy->getSprite()->getGlobalBounds().left + pEnemy->getSprite()->getGlobalBounds().width >= SCREEN_WIDTH) {
        pEnemy->getSprite()->move(-fOffset,0.f);
        pInput->resetAll();
        pInput->setLeft(true);
    }

    //Top Boundary
    if(pEnemy->getSprite()->getGlobalBounds().top <= 0.f) {
        pEnemy->getSprite()->move(0.f,fOffset);
        pInput->resetAll();
    }

    //Bottom Boundary
    if(pEnemy->getSprite()->getGlobalBounds().top + pEnemy->getSprite()->getGlobalBounds().height >= SCREEN_HEIGHT) {
        pEnemy->getSprite()->move(0.f,-fOffset);
        pInput->resetAll();
    }
}

void BotManager::setTag(BotTag ETag) {
    this->ETag = ETag; 
}