#pragma once

#include <SFML/Graphics.hpp>
#include "../../AnimatedTexture.hpp"
#include "../PoolableObject.hpp"
#include "../../Entity/Ship.hpp"
#include "../../Enum/PoolTag.hpp"
#include "../../Component/Script/BulletMovement.hpp"
#include "../../../Controller/Manager/TextureManager.hpp"

namespace poolables{
    using namespace models;
    using namespace entities;
    using namespace managers;
    using namespace components;
    class PlayerBullet : public PoolableObject {
        private:
            Ship* pShip;

        public:
            PlayerBullet(std::string strName, AnimatedTexture* pTexture, Ship* pShip);

        public:
            void initialize();

        public:
            void onActivate();
            void onRelease();
            PoolableObject* clone();
        
    };
}