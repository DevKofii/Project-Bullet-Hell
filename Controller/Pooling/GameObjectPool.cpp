#include "GameObjectPool.hpp"

using namespace poolables;

GameObjectPool::GameObjectPool(PoolTag ETag, int nPoolSize, PoolableObject* pPoolableReference) {
    this->ETag = ETag;
    this->nPoolSize = nPoolSize;
    this->pPoolableReference = pPoolableReference;
    this->vecAvailableObject = {};
    this->vecUsedObject = {};
    this->pParent = NULL;
}

void GameObjectPool::initalize() {
    //0 to less than pool size 
    // for(int i = 0; i < this->nPoolSize; i++) {
    //     PoolableObject* pClone = this->pPoolableReference->clone();
    //     GameObjectManager::getInstance()->addObject(pClone);
    //     this->setEnabled(pClone,false);
    //     this->vecAvailableObject.push_back(pClone);
    // }

    for(int i = 0; i < this->nPoolSize; i++) {
        PoolableObject* pPoolableObject = this->pPoolableReference->clone();
        
        if(this->pParent != NULL)
            this->pParent->attachChild(pPoolableObject);
        else
            GameObjectManager::getInstance()->addObject(pPoolableObject);
            
        pPoolableObject->setEnabled(false);
        this->vecAvailableObject.push_back(pPoolableObject);
    }
}

PoolableObject* GameObjectPool::requestPoolable() {
    if(this->hasAvailable(1)) {
        PoolableObject* pPoolableObject = this->vecAvailableObject[0];
        this->vecUsedObject.push_back(pPoolableObject);
        this->vecAvailableObject.erase(this->vecAvailableObject.begin());

        this->setEnabled(pPoolableObject,true);
        
        return pPoolableObject;
    }
    return NULL;
}

PoolableObject* GameObjectPool::getPoolable() {
    PoolableObject* pPoolableObject = this->vecAvailableObject[0];
    this->setEnabled(pPoolableObject,true);
    return pPoolableObject;
}

std::vector<PoolableObject*> GameObjectPool::requestPoolableBatch(int nRequestSize) {
    for(int i = 0; i < nRequestSize; i++) {
        if(this->hasAvailable(1)) {
            std::vector<PoolableObject*> pPoolableObject = this->vecAvailableObject;
            //PoolableObject* pPoolableObject = this->vecAvailableObject[0];
            this->vecUsedObject.push_back(pPoolableObject[i]);
            this->vecAvailableObject.erase(this->vecAvailableObject.begin());

            this->setEnabled(pPoolableObject[i],true);

            return pPoolableObject;
        }
        else return {};
    }
}

void GameObjectPool::releasePoolable(PoolableObject* pPoolableObject) {
    int nIndex = -1;
    for(int i = 0; i < this->vecUsedObject.size(); i++) {
        if(this->vecUsedObject[i] == pPoolableObject) {
            nIndex = i;
            break;
        }
    }

    if(nIndex != -1) {
        this->vecUsedObject[nIndex]->setEnabled(false);
        this->vecAvailableObject.push_back(this->vecUsedObject[nIndex]);
        this->vecUsedObject.erase(this->vecUsedObject.begin() + nIndex);
    }
}


bool GameObjectPool::hasAvailable(int nRequestSize) {
    if(this->vecAvailableObject.size() >= nRequestSize) return true;
    return false;
}

int GameObjectPool::getAvailable() {
    return this->vecAvailableObject.size();
}

void GameObjectPool::setEnabled(PoolableObject* pPoolableObject, bool bEnabled) {
    pPoolableObject->setEnabled(bEnabled);
    if(bEnabled == true) pPoolableObject->onActivate();
    else pPoolableObject->onRelease();
}

PoolTag GameObjectPool::getTag() {
    return this->ETag;
}

float GameObjectPool::getSpeed() {
    return this->pPoolableReference->getSpeed();
}

void GameObjectPool::setSpeed(float fSpeed) {
    this->pPoolableReference->setSpeed(fSpeed);
}