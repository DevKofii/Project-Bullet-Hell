#pragma once

#include "iostream"
#include "unordered_map"
#include "../../Model/Enum/UnitTag.hpp"
#include "../../Model/GameObject.hpp"

namespace managers {
    using namespace models;

    class ObjectCollisionManager {
        private:
            std::unordered_map<std::string, GameObject*> mapGameObject;
            std::vector<GameObject*> vecGameObject;
            GameObject* pActiveObject;
            bool bDetect;
            std::string EObjectToTest;
        
        public:
            void addObject(GameObject* pGameObject);
            void setActiveUnit(std::string strName);

            void checkCollision();
            
        private:
            static ObjectCollisionManager* P_SHARED_INSTANCE;
            ObjectCollisionManager();
            ObjectCollisionManager(const ObjectCollisionManager&);
            ObjectCollisionManager& operator = (const ObjectCollisionManager&);

        public:
            static ObjectCollisionManager* getInstance();
    };
}
