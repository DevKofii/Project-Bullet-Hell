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

    switch(ETag) {
        case BotTag::IDLE:
            //std::cout << "Bot State: IDLE" << std::endl;
            break;

        case BotTag::WALK_LEFT:
            //std::cout << "Bot State: Going Left" << std::endl;
            break;

        case BotTag::WALK_RIGHT:
            //std::cout << "Bot State: Going Right" << std::endl;
            break;
        
        case BotTag::WALK_UP:
            //std::cout << "Bot State: Going Up" << std::endl;
            break;
        
        case BotTag::WALK_DOWN:
            //std::cout << "Bot State: Going Down" << std::endl;
            break;

        default:
            break;

    }
    // if(pInput->getLeft()) {
    //     std::cout << "Bot State: Going Left" << std::endl;
    //     //this->setTag(BotTag::WALK_LEFT);
    // }
    // else if(pInput->getRight()) {
    //     std::cout << "Bot State: Going Right" << std::endl;
    //     //this->setTag(BotTag::WALK_RIGHT);
    // }
    // else if(!pInput->getLeft() && !pInput->getRight() && !pInput->getUp() && !pInput->getDown()){
    //     std::cout << "Bot State: IDLE" << std::endl;
    //     //this->setTag(BotTag::IDLE);
    // }
}

void BotManager::selectState() {
    TestEnemy* pEnemy = (TestEnemy*)GameObjectManager::getInstance()->findObjectByName("TestBot");
    BotInput* pInput = (BotInput*) this->getOwner()->getComponents(ComponentType::INPUT)[0];

    srand(time(NULL));
    int select = (rand() % (5 - 1 + 1)) + 1;

    switch(select) {
        case 1: // IDLE
            //Just set tag to idle. It should redirect to this func again
            this->setTag(BotTag::IDLE);
            break;
        case 2: // WALK_LEFT
            this->setTag(BotTag::WALK_LEFT);
            break;
        case 3: // WALK_RIGHT
            this->setTag(BotTag::WALK_RIGHT);
            break;
        case 4: // WALK_UP
            this->setTag(BotTag::WALK_UP);
            break;
        case 5: // WALK_DOWN
            this->setTag(BotTag::WALK_DOWN);
            break;
        default: // CATCH ERROR?
            break;
    }
}

void BotManager::performState() {
    TestEnemy* pEnemy = (TestEnemy*)GameObjectManager::getInstance()->findObjectByName("TestBot");
    BotInput* pInput = (BotInput*) this->getOwner()->getComponents(ComponentType::INPUT)[0];
    float fOffset = this->fSpeed * this->tDeltaTime.asSeconds();

    /*
    Checklist:
    - Limit move distance to a certain range;
    - (i.e. Condition Based: if(randomized_int > )
    */

    this->selectState();

    switch(ETag) {
        case BotTag::IDLE:
            pInput->resetAll();
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
    }

    //Right Boundary
    if(pEnemy->getSprite()->getGlobalBounds().left + pEnemy->getSprite()->getGlobalBounds().width >= SCREEN_WIDTH) {
        pEnemy->getSprite()->move(-fOffset,0.f);
        pInput->resetAll();
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

void BotManager::delay(int ms) {
    clock_t timeDuration = ms + clock();
    while(timeDuration > clock()) {
        //std::cout << "DELAY" << std::endl;
    }
}