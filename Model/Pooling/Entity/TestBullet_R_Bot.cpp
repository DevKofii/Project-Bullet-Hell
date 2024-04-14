#include "TestBullet_R_Bot.hpp"

using namespace poolables;

TestBullet_R_Bot::TestBullet_R_Bot(std::string strName, AnimatedTexture* pTexture, TestEnemy* pEnemy) : PoolableObject(PoolTag::TEST_BULLET_R_BOT,strName,pTexture) {
    this->pEnemy = pEnemy;
} 

void TestBullet_R_Bot::initialize() {
    this->centerOrigin();
    //this->pSprite->setPosition(400.f,220.f);

    TestBulletMovement_R* testBulletMovement = new TestBulletMovement_R(this->strName + " Movement");
    this->attachComponent(testBulletMovement);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

void TestBullet_R_Bot::onActivate() {
    this->pSprite->setPosition(this->pEnemy->getSprite()->getPosition());
}

void TestBullet_R_Bot::onRelease() {}

PoolableObject* TestBullet_R_Bot::clone() {
    PoolableObject* pClone = new TestBullet_R_Bot(this->strName, new AnimatedTexture(*this->pTexture), this->pEnemy);
    return pClone;
}
