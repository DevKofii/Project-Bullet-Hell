#pragma once

#include "iostream"
#include "SFML/Graphics.hpp"
#include "../Input/PlayerInput.hpp"
#include "../Component.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../GameObject.hpp"

/* [TODO] :
   Include ALL necessary classes. */

namespace components {
    class PlayerMovement : public Component {
        private:
            float fSpeed;

        public:
            PlayerMovement(std::string strName);

        public:
            void perform();
    };
}
