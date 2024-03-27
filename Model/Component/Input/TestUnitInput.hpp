#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../GeneralInput.hpp"

namespace components{
    class TestUnitInput : public GeneralInput {
        private:
            bool bUp;
            bool bDown;
            bool bLeft;
            bool bRight;
            bool bShoot;
        
        public:
            TestUnitInput(std::string strName);

        public:
            void perform();

        private:
            void processKeyInput(bool bPressed);

        public:
            void resetShoot();

            bool getUp();
            bool getDown();
            bool getLeft();
            bool getRight();
            bool getShoot();
    };
}