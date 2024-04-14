#include "TestEnemy.hpp"

using namespace entities;

TestEnemy::TestEnemy(std::string strName, AnimatedTexture* pTexture, int ID) : GameObject(strName, 300.0f, pTexture) {
    this->ETag = BotTag::IDLE;
    this->random = 0;
    this->ID = ID;
    this->move = false;
}

void TestEnemy::initialize() {
    this->centerOrigin();
    
    BotManager* pBotManager = new BotManager(this->strName + " Script");
    this->attachComponent(pBotManager);

    FrameAnimationBot* pFrameAnimation = new FrameAnimationBot(this->strName + " Animation");
    this->attachComponent(pFrameAnimation);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

int TestEnemy::getRandom() {
    return this->random;
}

void TestEnemy::setRandom() {
    srand(time(NULL));
    int temp_select = (rand() % (7 - 1 + 1)) + 1;
    if(this->random == temp_select) temp_select = (rand() % (7 - 1 + 1)) + 1;

    this->random = temp_select;
}

bool TestEnemy::getMove() {
    return this->move; 
}

void TestEnemy::setMove(bool move) {
    this->move = move;
}

BotTag TestEnemy::getTag() {
    return this->ETag;
}

void TestEnemy::setTag(BotTag ETag) {
    this->ETag = ETag;
}

int TestEnemy::getID() {
    return this->ID;
}