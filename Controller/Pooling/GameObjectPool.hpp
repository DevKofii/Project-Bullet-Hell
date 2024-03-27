#pragma once

#include "../../Model/Enum/PoolTag.hpp"
#include "../../Model/Pooling/PoolableObject.hpp"
#include "../../Controller/Manager/GameObjectManager.hpp"
#include "../../Model/GameObject.hpp"

namespace poolables {
    using namespace managers;
    using namespace models;
    class GameObjectPool {
        private:
            PoolTag ETag;
            int nPoolSize;
            PoolableObject* pPoolableReference;
            std::vector<PoolableObject*> vecAvailableObject;
            std::vector<PoolableObject*> vecUsedObject;
            float fSpeed;

            GameObject* pParent;

        public:
            GameObjectPool(PoolTag ETag, int nPoolSize, PoolableObject* pPoolableReference);

        public:
            void initalize();
            PoolableObject* requestPoolable();
            std::vector<PoolableObject*> requestPoolableBatch(int nRequestSize);
            void releasePoolable(PoolableObject* pPoolableObject);

        private:
            bool hasAvailable(int nRequestSize);
            void setEnabled(PoolableObject* pPoolableObject, bool bEnabled);

        public:
            PoolTag getTag();
            float getSpeed();
            void setSpeed(float fSpeed);
            int getAvailable();
    };
}