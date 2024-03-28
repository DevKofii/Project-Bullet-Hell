#include "ObjectCollisionManager.hpp"

using namespace managers;

void ObjectCollisionManager::addObject(GameObject* pGameObject) {
    this->mapGameObject[pGameObject->getName()] = pGameObject;
    this->vecGameObject.push_back(pGameObject);
}

void ObjectCollisionManager::setActiveUnit(std::string strName) {
    this->bDetect = true;
    this->EObjectToTest = strName;
}

void ObjectCollisionManager::checkCollision() {
    if(this->bDetect) {
        this->pActiveObject = this->mapGameObject[this->EObjectToTest];
    }

    if(this->pActiveObject != NULL) {
        for(GameObject* pGameObject : this->vecGameObject) {
            if(pGameObject->getName() != this->pActiveObject->getName()) {
                // if(this->pActiveObject->getSprite()->getGlobalBounds().intersects(pGameObject->getSprite()->getGlobalBounds())) {
                //     std::cout << "Collision Detected" << std::endl;
                // }
                if(this->pActiveObject->getSprite()->getGlobalBounds().width < pGameObject->getSprite()->getGlobalBounds().width) std::cout << "Collision Detected" << std::endl;
            }
        }
    }
}

ObjectCollisionManager* ObjectCollisionManager::P_SHARED_INSTANCE = NULL;
ObjectCollisionManager::ObjectCollisionManager() {}
ObjectCollisionManager::ObjectCollisionManager(const ObjectCollisionManager&) {}
ObjectCollisionManager* ObjectCollisionManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new ObjectCollisionManager();

    return P_SHARED_INSTANCE;
}