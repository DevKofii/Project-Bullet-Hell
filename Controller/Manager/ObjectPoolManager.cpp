#include "ObjectPoolManager.hpp"

using namespace managers;
using namespace poolables;

void ObjectPoolManager::registerObjectPool(GameObjectPool* pPool) {
    this->mapObjectPool[pPool->getTag()] = pPool;
    pPool->initalize();
}

void ObjectPoolManager::unregisterObjectPool(GameObjectPool* pPool) {
    //delete mapObjectPool[];
    
    this->mapObjectPool.erase(pPool->getTag());
}

GameObjectPool* ObjectPoolManager::getPool(PoolTag ETag) {
    if(this->mapObjectPool[ETag] != NULL)
        return this->mapObjectPool[ETag];

    else {
        //std::cout << "[ERROR] : Object [" << std::to_string(1) << "] NOT found." << std::endl;
        return NULL;
    }
}

ObjectPoolManager* ObjectPoolManager::P_SHARED_INSTANCE = NULL;

ObjectPoolManager::ObjectPoolManager() {}

ObjectPoolManager::ObjectPoolManager(const ObjectPoolManager&) {}

ObjectPoolManager* ObjectPoolManager::getInstance() {
    if(P_SHARED_INSTANCE  == NULL) P_SHARED_INSTANCE = new ObjectPoolManager();

    return P_SHARED_INSTANCE;
}