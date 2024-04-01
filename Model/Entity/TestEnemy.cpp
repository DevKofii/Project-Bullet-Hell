#include "TestEnemy.hpp"

using namespace entities;

TestEnemy::TestEnemy(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, 100.0f, pTexture) {}

void TestEnemy::initialize() {
    this->centerOrigin();;
    //this->pSprite->setPosition(90.f,210.f);
    //this->pSprite->setScale(2.0f,2.0f);

    BotInput* pInput = new BotInput(this->strName + " Input");
    this->attachComponent(pInput);
    
    BotManager* pBotManager = new BotManager(this->strName + " Script");
    this->attachComponent(pBotManager);

    FrameAnimationBot* pFrameAnimation = new FrameAnimationBot(this->strName + " Animation");
    this->attachComponent(pFrameAnimation);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

int TestEnemy::getFrameStart() {
    return this->nFrameStart;
}

int TestEnemy::getFrameEnd() {
    return this->nFrameEnd;
}
