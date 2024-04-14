#pragma once

#include "../Scene.hpp"
#include "../AnimatedTexture.hpp"
#include "../Enum/SceneTag.hpp"
#include "../Entity/TestUnit.hpp"
#include "../Entity/TestEnemy.hpp"
#include "../Entity/TestBackground.hpp"
#include "../Entity/Collider.hpp"
#include "../Entity/Shadow.hpp"
#include "../../Controller/Manager/TextureManager.hpp"

#include "../Pooling/Entity/TestBullet_R.hpp"
#include "../Pooling/Entity/TestBullet_L.hpp"
#include "../../Controller/Manager/ObjectPoolManager.hpp"
#include "../../Controller/Manager/ObjectCollisionManager.hpp"
#include "../../Controller/Pooling/GameObjectPool.hpp"

namespace scenes {
    using namespace managers;
    using namespace entities;
    using namespace models;
    class TestScene : public Scene {
        public:
            TestScene();

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();

        private:
            void createBackground();
            void spawnMisc();
            void spawnUnit();
            void spawnBot();
            void createObjectPools();
    };
}