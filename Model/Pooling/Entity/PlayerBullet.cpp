#include "PlayerBullet.hpp"

using namespace poolables;

PlayerBullet::PlayerBullet(std::string strName, AnimatedTexture* pTexture, Ship* pShip) : PoolableObject(PoolTag::PLAYER_BULLET,strName,pTexture) {
    this->pShip = pShip;
} 

void PlayerBullet::initialize() {
    this->centerOrigin();
    //this->pSprite->setPosition(400.f,220.f);

    BulletMovement* bulletMovement = new BulletMovement(this->strName + " Input");
    this->attachComponent(bulletMovement);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

void PlayerBullet::onActivate() {
    this->pSprite->setPosition(this->pShip->getSprite()->getPosition());
}

void PlayerBullet::onRelease() {}
PoolableObject* PlayerBullet::clone() {
    PoolableObject* pClone = new PlayerBullet(this->strName, new AnimatedTexture(*this->pTexture), this->pShip);
    return pClone;
}
