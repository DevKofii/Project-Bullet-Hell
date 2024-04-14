#include "BotManager.hpp"

using namespace components;

BotManager::BotManager(std::string strName) : Component  (strName, ComponentType::SCRIPT) {
    this->ETag = BotTag::IDLE;
    this->fSpeed = 40.0f;
    this->delayTimer.restart();
    this->delayTimerMax = 1.3f;
    this->select = 0;
}

void BotManager::perform() {
    TestEnemy* pEnemy = (TestEnemy*)GameObjectManager::getInstance()->findObjectByName("TestBot");
    Collider* pCollide = (Collider*)GameObjectManager::getInstance()->findObjectByName("Collider");
    Shadow* pShadow = (Shadow*)GameObjectManager::getInstance()->findObjectByName("Shadow");

    //Set Scale
    pShadow->setScale({2.5f,2.5f});

    //Set pos
    pCollide->setPosition(pEnemy->getPosition());
    pShadow->setPosition(pEnemy->getPosition());

    //Set Transparency
    pShadow->getSprite()->setColor(sf::Color(255,255,255,10));
    pCollide->getSprite()->setColor(sf::Color::Transparent);

    if(pEnemy == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        this->performState();
        this->checkCollision();
    }
}

void BotManager::selectState() {
    TestEnemy* pEnemy = (TestEnemy*)this->pOwner;
    pEnemy->setRandom();

    switch(pEnemy->getRandom()) {
        case 1: // WALK_LEFT
            pEnemy->setTag(BotTag::WALK_LEFT);
            break;
        case 2: // WALK_RIGHT
            pEnemy->setTag(BotTag::WALK_RIGHT);
            break;
        case 3: // WALK_UP
            pEnemy->setTag(BotTag::WALK_UP);
            break;
        case 4: // WALK_DOWN
            pEnemy->setTag(BotTag::WALK_DOWN);
            break;
        default: // CATCH ERROR?
            pEnemy->setTag(BotTag::IDLE);
            break;
    }
}

void BotManager::performState() {
    TestEnemy* pEnemy = (TestEnemy*)GameObjectManager::getInstance()->findObjectByName("TestBot");
    float fOffset = this->fSpeed * this->tDeltaTime.asSeconds();

    Collider* pCollide = (Collider*)GameObjectManager::getInstance()->findObjectByName("Collider");

    switch(pEnemy->getTag()) {
        case BotTag::IDLE:
            pEnemy->setMove(false);
            if(this->getDelayTimer()) {
                this->selectState();
            }
            else {
                pEnemy->getSprite()->move(0.f,0.f);
            }
            break;

        case BotTag::WALK_LEFT:
            if(this->getDelayTimer()) {
                pEnemy->setMove(false);
                this->selectState();
            }
            else {
                pEnemy->setMove(true);
                pEnemy->getSprite()->setScale(-2.0f,2.0f);
                pEnemy->getSprite()->move(-fOffset,0.f);
                pCollide->getSprite()->setScale(-1.0f,1.0f);
            }
            break;

        case BotTag::WALK_RIGHT:
            if(this->getDelayTimer()) {
                pEnemy->setMove(false);
                this->selectState();
            }
            else {
                pEnemy->setMove(true);
                pEnemy->getSprite()->setScale(2.0f,2.0f);
                pEnemy->getSprite()->move(fOffset,0.f);
                pCollide->getSprite()->setScale(1.0f,1.0f);
            }
            break;
        
        case BotTag::WALK_UP:
            if(this->getDelayTimer()) {
                pEnemy->setMove(false);
                this->selectState();
            }
            else {
                pEnemy->setMove(true);
                pEnemy->getSprite()->move(0.f, -fOffset);
            }
            break;
        
        case BotTag::WALK_DOWN:
            if(this->getDelayTimer()) {
                pEnemy->setMove(false);
                this->selectState();
            }
            else {
                pEnemy->setMove(true);
                pEnemy->getSprite()->move(0.f, fOffset);
            }
            break;
        default:
            break;
    }
}

void BotManager::checkCollision() {
    TestEnemy* pEnemy = (TestEnemy*)GameObjectManager::getInstance()->findObjectByName("TestBot");
    TestUnit* pPlayer = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");
    Shadow* pShadow = (Shadow*)GameObjectManager::getInstance()->findObjectByName("Shadow" + std::to_string(pEnemy->getID()));

    float fOffset  = this->fSpeed * this->tDeltaTime.asSeconds();
    //Left Boundary
    if(pEnemy->getSprite()->getGlobalBounds().left <= 0.f) {
        if(this->getDelayTimer()) {
            this->selectState();
        }
        else {
            pEnemy->getSprite()->move(fOffset,0.f);
            pEnemy->setTag(BotTag::WALK_RIGHT);
        }
    }

    //Right Boundary
    if(pEnemy->getSprite()->getGlobalBounds().left + pEnemy->getSprite()->getGlobalBounds().width >= SCREEN_WIDTH) {
        if(this->getDelayTimer()) {
            this->selectState();
        }
        else {
            pEnemy->getSprite()->move(-fOffset,0.f);
            pEnemy->setTag(BotTag::WALK_LEFT);
        }
    }

    //Top Boundary
    if(pEnemy->getSprite()->getGlobalBounds().top <= 0.f) {
        if(this->getDelayTimer()) {
            this->selectState();
        }
        else {
            pEnemy->getSprite()->move(0.f,fOffset);
            pEnemy->setTag(BotTag::WALK_DOWN);
        }
    }

    //Bottom Boundary
    if(pEnemy->getSprite()->getGlobalBounds().top + pEnemy->getSprite()->getGlobalBounds().height >= SCREEN_HEIGHT) {
        if(this->getDelayTimer()) {
            this->selectState();
        }
        else {
            pEnemy->getSprite()->move(0.f,-fOffset);
            pEnemy->setTag(BotTag::WALK_UP);
        }
    }
}

void BotManager::chaseTarget() {
    TestUnit* pPlayer = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");
    TestEnemy* pEnemy = (TestEnemy*)this->pOwner;
    Shadow* pShadow = (Shadow*)GameObjectManager::getInstance()->findObjectByName("Shadow" + std::to_string(pEnemy->getID()));
    
    sf::Vector2f distance = ((pPlayer->getPosition()) - pEnemy->getPosition());
    sf::Vector2f normalized_dist = this->normalize(distance);

    sf::Vector2f moveSpeed = (normalized_dist * 5.0f * ((float) this->tDeltaTime.asMilliseconds() / 60));
    pEnemy->getSprite()->move(moveSpeed); 
}

sf::Vector2f BotManager::normalize(sf::Vector2f vec) {
    float magnitude = sqrtf(vec.x * vec.x + vec.y * vec.y);
    if (magnitude != 0) 
    {
        vec.x /= magnitude;
        vec.y /= magnitude;
    }
    return vec;
}

void BotManager::setTag(BotTag ETag) {
    this->ETag = ETag; 
}

const bool BotManager::getDelayTimer() {
    //std::cout << this->delayTimer.getElapsedTime().asSeconds() << std::endl;
    if(this->delayTimer.getElapsedTime().asSeconds() >= this->delayTimerMax)
    {
        this->delayTimer.restart();
        return true;
    }
    return false;
}