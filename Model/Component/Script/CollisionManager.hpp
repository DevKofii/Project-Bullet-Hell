#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Input/TestUnitInput.hpp"
#include "../../Entity/TestUnit.hpp"
#include "../Component.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../GameObject.hpp"


namespace components {
    using namespace models;
    using namespace entities;
    class CollisionManager : public Component {
        public:
            CollisionManager(std::string strName);

        public:
            void perform();
    };
}