#include "TestBullet_R.hpp"

using namespace poolables;

TestBullet_R::TestBullet_R(std::string strName, AnimatedTexture* pTexture, TestUnit* pTestUnit) : PoolableObject(PoolTag::TEST_BULLET_R,strName,pTexture) {
    this->pTestUnit = pTestUnit;
} 

void TestBullet_R::initialize() {
    this->centerOrigin();
    //this->pSprite->setPosition(400.f,220.f);

    TestBulletMovement_R* testBulletMovement = new TestBulletMovement_R(this->strName + " Movement");
    this->attachComponent(testBulletMovement);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

void TestBullet_R::onActivate() {
    this->pSprite->setPosition(this->pTestUnit->getSprite()->getPosition());
}

void TestBullet_R::onRelease() {}

PoolableObject* TestBullet_R::clone() {
    PoolableObject* pClone = new TestBullet_R(this->strName, new AnimatedTexture(*this->pTexture), this->pTestUnit);
    return pClone;
}
