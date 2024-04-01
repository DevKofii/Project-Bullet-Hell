#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../../../Enum/ComponentType.hpp"
#include "../../GeneralInput.hpp"

namespace components{
    class BotInput : public GeneralInput {
        private:
            bool bUp;
            bool bDown;
            bool bLeft;
            bool bRight;
            bool bShoot;
        
        public:
            BotInput(std::string strName);

        public:
            void perform();

        public:
            void resetAll();

            bool getUp();
            bool getDown();
            bool getLeft();
            bool getRight();
            bool getShoot();

            void setUp(bool bPressed);
            void setDown(bool bPressed);
            void setLeft(bool bPressed);
            void setRight(bool bPressed);
    };
}