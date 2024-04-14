#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Input/TestUnitInput.hpp"
#include "../../Entity/TestUnit.hpp"
#include "../../Entity/TestEnemy.hpp"
#include "../../Entity/Barrier.hpp"
#include "../../Entity/Edges.hpp"
#include "../Component.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../GameObject.hpp"
#include "../../../Controller/Manager/ObjectCollisionManager.hpp"
#include "../../../Controller/Manager/GameObjectManager.hpp"


namespace components {
    using namespace managers;
    using namespace models;
    using namespace entities;
    class BoundsAction : public Component {
        public:
            BoundsAction(std::string strName);

        public:
            void perform();
            void barrierBounds();
    };
}