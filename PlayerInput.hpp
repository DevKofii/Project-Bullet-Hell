#pragma once

#include "../Enum/ComponentType.hpp"
#include "GeneralInput.hpp"

namespace components {
    class PlayerInput : public GeneralInput {
        private:
            bool bMovingLeft;
            bool bMovingRight;

        public:
            PlayerInput(std::string strName);

        public:
            void perform();
        
        private:
            void processKeyboardInput(sf::Keyboard::Key inKey, bool bPressed);

        public:
            bool getMovingLeft();
            bool getMovingRight();
    };
}
