#include "BulletCollision.hpp"

using namespace poolables;

BulletCollision::BulletCollision(std::string strName, AnimatedTexture* pTexture, TestEnemy* pEnemy) : PoolableObject(PoolTag::BULLET_COLLIDER,strName,pTexture) {
    this->pEnemy = pEnemy;
} 

void BulletCollision::initialize() {
    //this->centerOrigin();
    this->pSprite->setOrigin(0.f,this->pSprite->getTexture()->getSize().y/2);
    //this->pSprite->setPosition(400.f,220.f);
    this->pSprite->setScale(-1.f,1.f);

    // TestBulletMovement_R* testBulletMovement = new TestBulletMovement_R(this->strName + " Movement");
    // this->attachComponent(testBulletMovement);

    this->pSprite->setPosition(this->pEnemy->getSprite()->getPosition());

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

void BulletCollision::onActivate() {
    
}

void BulletCollision::onRelease() {}

PoolableObject* BulletCollision::clone() {
    PoolableObject* pClone = new BulletCollision(this->strName, new AnimatedTexture(*this->pTexture), this->pEnemy);
    return pClone;
}
