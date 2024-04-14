#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../GeneralInput.hpp"

namespace components {
    class BackgroundInput : public GeneralInput {
        private:
            bool bInteract;
            bool bQuit;

        public:
            BackgroundInput(std::string strName);

        public:
            void perform();

        private:
            void processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed);

        public:
            bool getInteract();
            bool getQuit();
            void setInteract(bool bPressed);
    };
}