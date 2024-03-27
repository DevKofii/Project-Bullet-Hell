#include "TestBullet_L.hpp"

using namespace poolables;

TestBullet_L::TestBullet_L(std::string strName, AnimatedTexture* pTexture, TestUnit* pTestUnit) : PoolableObject(PoolTag::TEST_BULLET_L,strName,pTexture) {
    this->pTestUnit = pTestUnit;
} 

void TestBullet_L::initialize() {
    this->centerOrigin();
    //this->pSprite->setPosition(400.f,220.f);

    TestBulletMovement_L* testBulletMovement = new TestBulletMovement_L(this->strName + " Movement");
    this->attachComponent(testBulletMovement);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

void TestBullet_L::onActivate() {
    this->pSprite->setPosition(this->pTestUnit->getSprite()->getPosition());
}

void TestBullet_L::onRelease() {}

PoolableObject* TestBullet_L::clone() {
    PoolableObject* pClone = new TestBullet_L(this->strName, new AnimatedTexture(*this->pTexture), this->pTestUnit);
    return pClone;
}
