#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Input/TestUnitInput.hpp"
#include "../../Entity/TestUnit.hpp"
#include "../../Entity/TestEnemy.hpp"
#include "../Component.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../GameObject.hpp"
#include "../../../Controller/Manager/ObjectCollisionManager.hpp"
#include "../../../Controller/Manager/GameObjectManager.hpp"


namespace components {
    using namespace managers;
    using namespace models;
    using namespace entities;
    class CollisionManager : public Component {
        public:
            CollisionManager(std::string strName);

        public:
            void perform();
    };
}