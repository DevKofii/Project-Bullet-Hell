#include "TestBullet_L_Bot.hpp"

using namespace poolables;

TestBullet_L_Bot::TestBullet_L_Bot(std::string strName, AnimatedTexture* pTexture, TestEnemy* pEnemy) : PoolableObject(PoolTag::TEST_BULLET_L_BOT,strName,pTexture) {
    this->pEnemy = pEnemy;
} 

void TestBullet_L_Bot::initialize() {
    this->centerOrigin();
    //this->pSprite->setPosition(400.f,220.f);

    TestBulletMovement_L* testBulletMovement = new TestBulletMovement_L(this->strName + " Movement");
    this->attachComponent(testBulletMovement);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

void TestBullet_L_Bot::onActivate() {
    this->pSprite->setPosition(this->pEnemy->getSprite()->getPosition());
}

void TestBullet_L_Bot::onRelease() {}

PoolableObject* TestBullet_L_Bot::clone() {
    PoolableObject* pClone = new TestBullet_L_Bot(this->strName, new AnimatedTexture(*this->pTexture), this->pEnemy);
    return pClone;
}
