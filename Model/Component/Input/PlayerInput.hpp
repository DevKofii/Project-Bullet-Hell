#pragma once

#include "iostream"
#include "SFML/Graphics.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../GeneralInput.hpp"

namespace components {
    class PlayerInput : public GeneralInput {
        private:
            bool bMovingLeft;
            bool bMovingRight;
            bool bMovingUp;
            bool bMovingDown;

        public:
            PlayerInput(std::string strName);

        public:
            void perform();

        private:
            void processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed);


        public:
            bool getMovingLeft();
            bool getMovingRight();
            bool getMovingUp();
            bool getMovingDown();
    };
}
