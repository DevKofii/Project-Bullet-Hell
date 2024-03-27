#pragma once

#include "iostream"
#include "SFML/Graphics.hpp"
#include "../Input/ShipInput.hpp"
#include "../../Entity/Ship.hpp"
#include "../Component.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../GameObject.hpp"
#include "../../Enum/PoolTag.hpp"
#include "../../../Controller/Manager/ObjectPoolManager.hpp"

// namespace entities {
//     class Ship;
// }

namespace components {
    using namespace models;
    using namespace managers;
    using namespace entities;
    class ShipControls : public Component {
        private:
            float fSpeed;
            
        public:
            ShipControls(std::string strName);

        public:
            void perform();
    };
}
