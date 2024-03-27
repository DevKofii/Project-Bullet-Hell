#include "GameObjectManager.hpp"

using namespace managers;
using namespace models;

void GameObjectManager::processEvents(sf::Event CEvent) {
    for(GameObject* pGameObject : this->vecGameObject) {
        if(pGameObject->getEnabled()) pGameObject->processEvents(CEvent);
    }
}

void GameObjectManager::update(sf::Time tDeltaTime) {
    for(GameObject* pGameObject : this->vecGameObject) {
        if(pGameObject->getEnabled()) pGameObject->update(tDeltaTime);
    }
}

void GameObjectManager::draw(sf::RenderWindow* pWindow) {
    for(GameObject* pGameObject : this->vecGameObject) {
        if(pGameObject->getEnabled()) pGameObject->draw(pWindow);
    }
}

void GameObjectManager::addObject(GameObject* pGameObject) {
    this->mapGameObject[pGameObject->getName()] = pGameObject;
    this->vecGameObject.push_back(pGameObject);
    pGameObject->initialize();
}

void GameObjectManager::deleteAllObjects() {
    for(GameObject* pGameObject : this->vecGameObject) delete pGameObject;
    for(auto i = this->mapGameObject.begin(); i != this->mapGameObject.end(); i++) delete i->second;

    this->vecGameObject.clear();
    this->mapGameObject.clear();
}

GameObject* GameObjectManager::findObjectByName(std::string strName) {
    if(this->mapGameObject[strName] != NULL) return this->mapGameObject[strName];
    else return NULL;
}

/* * * * * * * * * * * * * * * * * * * * *
 *       SINGLETON-RELATED CONTENT       *
 * * * * * * * * * * * * * * * * * * * * */

/* [TODO][2] :
   Please make this a Singleton class.
   Place the Singleton-related content
   underneath this comment. */

GameObjectManager* GameObjectManager::P_SHARED_INSTANCE = NULL;

GameObjectManager::GameObjectManager() {}

GameObjectManager::GameObjectManager(const GameObjectManager&) {}

GameObjectManager* GameObjectManager::getInstance() {
    // If instance does not exist, create a new instance of that object by
    // allocating new memory.
    if(P_SHARED_INSTANCE  == NULL) P_SHARED_INSTANCE = new GameObjectManager();

    //Return Shared Instance
    return P_SHARED_INSTANCE;
}