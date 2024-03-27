#include "ShipControls.hpp"

using namespace components;

ShipControls::ShipControls(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fSpeed = 300.0f;
}

void ShipControls::perform() {
    Ship* pShipOwner = (Ship*)this->pOwner;
    //ShipInput* pInput = (ShipInput*)this->getOwner()->findComponentByName(this->pOwner->getName() + " Input");
    ShipInput* pInput = (ShipInput*)this->getOwner()->getComponents(ComponentType::INPUT)[0];
    
    if(pInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        float fOffset = this->fSpeed * this->tDeltaTime.asSeconds();

        if(pInput->getSpace()) {
            //pInput->resetSpace();
            ObjectPoolManager::getInstance()->getPool(PoolTag::PLAYER_BULLET)->requestPoolable();
        }

        if(pInput->getLeft()) {
            pShipOwner->getSprite()->move(-fOffset, 0.f);
        }
    
        if(pInput->getRight()) {
            pShipOwner->getSprite()->move(fOffset, 0.f);
        }

        if(pInput->getUp()) {
            pShipOwner->getSprite()->move(0.f, -fOffset);
        }
    
        if(pInput->getDown()) {
            pShipOwner->getSprite()->move(0.f, fOffset);
        }
    }
}
