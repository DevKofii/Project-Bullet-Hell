#pragma once

#include <SFML/Graphics.hpp>
#include "../../AnimatedTexture.hpp"
#include "../PoolableObject.hpp"
#include "../../Entity/TestEnemy.hpp"
#include "../../Enum/PoolTag.hpp"
#include "../../Component/Script/TestBulletMovement_R.hpp"
#include "../../../Controller/Manager/TextureManager.hpp"

namespace entities {
    class TestEnemy;
}

namespace poolables{
    using namespace models;
    using namespace entities;
    using namespace managers;
    using namespace components;
    class BulletCollision : public PoolableObject {
        private:
            TestEnemy* pEnemy;

        public:
            BulletCollision(std::string strName, AnimatedTexture* pTexture, TestEnemy* pEnemy);

        public:
            void initialize();

        public:
            void onActivate();
            void onRelease();
            PoolableObject* clone();
        
    };
}