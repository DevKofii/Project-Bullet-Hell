#pragma once

#include "iostream"
#include "unordered_map"
#include "../../Model/Enum/PoolTag.hpp"
#include "../Pooling/GameObjectPool.hpp"

namespace managers {
    //using namespace models;
    using namespace poolables;
    class ObjectPoolManager {
        private:
            std::unordered_map<PoolTag, GameObjectPool*> mapObjectPool;
        
        public:
            void registerObjectPool(GameObjectPool* pPool);
            void unregisterObjectPool(GameObjectPool* pPool);
            GameObjectPool* getPool(PoolTag ETag);

        private:
            static ObjectPoolManager* P_SHARED_INSTANCE;
            ObjectPoolManager();
            ObjectPoolManager(const ObjectPoolManager&);
            ObjectPoolManager& operator = (const ObjectPoolManager&);

        public:
            static ObjectPoolManager* getInstance();
    };
}