#pragma once

#include "iostream"
#include "unordered_map"
#include "../../Model/Enum/AssetType.hpp"
#include "../../Model/GameObject.hpp"

namespace managers {
    using namespace models;

    class GameObjectManager {
        private:
            std::unordered_map<std::string, GameObject*> mapGameObject;
            std::vector<GameObject*> vecGameObject;
        
        public:
            void processEvents(sf::Event CEvent);
            void update(sf::Time tDeltaTime);
            void draw(sf::RenderWindow* pWindow);

            void addObject(GameObject* pGameObject);
            void deleteAllObjects();
            GameObject* findObjectByName(std::string strName);
            
        private:
            static GameObjectManager* P_SHARED_INSTANCE;
            GameObjectManager();
            GameObjectManager(const GameObjectManager&);
            GameObjectManager& operator = (const GameObjectManager&);

        public:
            static GameObjectManager* getInstance();
    };
}
