#include "BotManager.hpp"

using namespace components;

BotManager::BotManager(std::string strName) : Component  (strName, ComponentType::SCRIPT) {
    this->ETag = BotTag::IDLE;
    this->fSpeed = 30.0f;
    this->delayTimer.restart();
    this->delayTimerMax = 1.0f;
    this->delayTimerMaxLonger = 2.0f;
    this->select = 0;
    this->curState = StateTag::EXIT;
}

void BotManager::perform() {
    TestUnit* pPlayer = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");
    TestEnemy* pEnemy = (TestEnemy*)GameObjectManager::getInstance()->findObjectByName("TestBot");
    Collider* pCollide = (Collider*)GameObjectManager::getInstance()->findObjectByName("Collider");
    Shadow* pShadow = (Shadow*)GameObjectManager::getInstance()->findObjectByName("Shadow");

    //Set Scale
    pShadow->setScale({7.5f,7.5f});

    //Set pos
    pCollide->setPosition(pEnemy->getPosition());
    pShadow->setPosition(pEnemy->getPosition());

    //Set Transparency
    //pShadow->getSprite()->setColor(sf::Color(255,255,255,10));
    //pCollide->getSprite()->setColor(sf::Color(255,255,255,20));
    pShadow->getSprite()->setColor(sf::Color::Transparent);
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
    Collider* pCollide = (Collider*)GameObjectManager::getInstance()->findObjectByName("Collider");
    float fOffset = this->fSpeed * this->tDeltaTime.asSeconds();

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

        case BotTag::CHASE:
            if(this->isValidFOV()) {
                //std::cout << "I SEE YOU!" << std::endl;
                pEnemy->setMove(true);
                this->chaseTarget();
            }
            else {
                this->selectState();
            }
            break;

        default:
            break;
    }

    switch(this->getState()) {
        case StateTag::ENTER:
            if(this->isValidCollider()) {
                if(this->getDelayTimerLonger()) {
                    pEnemy->setAttack(false);
                    this->setState(StateTag::EXIT);
                }
                else {
                    this->attack();
                }
            }
            break;
        case StateTag::EXIT:
            if(this->isValidCollider()) {
                this->setState(StateTag::ENTER);
            }
            break;
    }
}

void BotManager::checkCollision() {
    TestEnemy* pEnemy = (TestEnemy*)GameObjectManager::getInstance()->findObjectByName("TestBot");
    TestUnit* pPlayer = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");
    Shadow* pShadow = (Shadow*)GameObjectManager::getInstance()->findObjectByName("Shadow");

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

    //FieldOfView Collision
    if(this->isValidFOV()) { 
        pEnemy->setTag(BotTag::CHASE);
    }
}


bool BotManager::isValidFOV() {
    TestUnit* pPlayer = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");
    Shadow* pShadow = (Shadow*)GameObjectManager::getInstance()->findObjectByName("Shadow");

    return pPlayer->getSprite()->getGlobalBounds().intersects(pShadow->getSprite()->getGlobalBounds());
}

bool BotManager::isValidCollider() {
    TestUnit* pPlayer = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");
    Collider* pCollide = (Collider*)GameObjectManager::getInstance()->findObjectByName("Collider");

    return pPlayer->getSprite()->getGlobalBounds().intersects(pCollide->getSprite()->getGlobalBounds());
}

void BotManager::chaseTarget() {
    TestUnit* pPlayer = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");
    Collider* pCollide = (Collider*)GameObjectManager::getInstance()->findObjectByName("Collider");
    TestEnemy* pEnemy = (TestEnemy*)this->pOwner;
    
    sf::Vector2f distance = ((pPlayer->getPosition()) - pEnemy->getPosition());
    sf::Vector2f normalized_dist = this->normalize(distance);

    sf::Vector2f moveSpeed = (normalized_dist * 10.0f * ((float) this->tDeltaTime.asMilliseconds() / 60));
    pEnemy->getSprite()->move(moveSpeed); 

    //Change Scale
        //Left Side
        if(pPlayer->getPosition().x < pEnemy->getPosition().x) {
            pEnemy->getSprite()->setScale(-2.0f,2.0f);
            pCollide->getSprite()->setScale(-1.0f,1.0f);
        }
        //Right Side
        if(pPlayer->getPosition().x > pEnemy->getPosition().x) {
            pEnemy->getSprite()->setScale(2.0f,2.0f);
            pCollide->getSprite()->setScale(1.0f,1.0f);
        }
}

void BotManager::attack() {
    TestEnemy* pEnemy = (TestEnemy*)GameObjectManager::getInstance()->findObjectByName("TestBot");
    TestUnit* pPlayer = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");

    //Left Side
        if(pPlayer->getPosition().x < pEnemy->getPosition().x && pEnemy->getAttack() == false) {
            ObjectPoolManager::getInstance()->getPool(PoolTag::TEST_BULLET_L_BOT)->requestPoolable();
            //pEnemy->setAttack(true);
        }
    //Right Side
        if(pPlayer->getPosition().x > pEnemy->getPosition().x && pEnemy->getAttack() == false) {
            ObjectPoolManager::getInstance()->getPool(PoolTag::TEST_BULLET_R_BOT)->requestPoolable();
            //pEnemy->setAttack(true);
        }
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

const bool BotManager::getDelayTimerLonger() {
    //std::cout << this->delayTimer.getElapsedTime().asSeconds() << std::endl;
    if(this->delayTimer.getElapsedTime().asSeconds() >= this->delayTimerMaxLonger)
    {
        this->delayTimer.restart();
        return true;
    }
    return false;
}

StateTag BotManager::getState() { 
    return this->curState;
}

void BotManager::setState(StateTag ETag) {
    this->curState = ETag;
}