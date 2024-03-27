#pragma once

#include <SFML/Graphics.hpp>
#include "../../AnimatedTexture.hpp"
#include "../PoolableObject.hpp"
#include "../../Entity/TestUnit.hpp"
#include "../../Enum/PoolTag.hpp"
#include "../../Component/Script/TestBulletMovement_R.hpp"
#include "../../../Controller/Manager/TextureManager.hpp"

namespace entities {
    class TestUnit;
}

namespace poolables{
    using namespace models;
    using namespace entities;
    using namespace managers;
    using namespace components;
    class TestBullet_R : public PoolableObject {
        private:
            TestUnit* pTestUnit;

        public:
            TestBullet_R(std::string strName, AnimatedTexture* pTexture, TestUnit* pTestUnit);

        public:
            void initialize();

        public:
            void onActivate();
            void onRelease();
            PoolableObject* clone();
        
    };
}