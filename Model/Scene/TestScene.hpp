#pragma once

#include "../Scene.hpp"
#include "../AnimatedTexture.hpp"
#include "../Enum/SceneTag.hpp"
#include "../Entity/TestUnit.hpp"
#include "../Entity/TestEnemy.hpp"
#include "../Entity/TestBackground.hpp"
#include "../Entity/Collider.hpp"
#include "../Entity/Shadow.hpp"
#include "../Entity/Barrier.hpp"
#include "../Entity/Edges.hpp"
#include "../../Controller/Manager/TextureManager.hpp"

#include "../Pooling/Entity/TestBullet_R.hpp"
#include "../Pooling/Entity/TestBullet_L.hpp"
#include "../Pooling/Entity/TestBullet_R_Bot.hpp"
#include "../Pooling/Entity/TestBullet_L_Bot.hpp"
#include "../../Controller/Manager/ObjectPoolManager.hpp"
#include "../../Controller/Manager/ScoreManager.hpp"
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
            void createBarrier();
            void spawnUnit();
            void spawnBot();
            void createObjectPools();
            void loadScores();
    };
}