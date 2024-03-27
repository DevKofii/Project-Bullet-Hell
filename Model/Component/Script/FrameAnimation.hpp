#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../../AnimatedTexture.hpp"
#include "../Input/TestUnitInput.hpp"
#include "../../Entity/TestUnit.hpp"
#include "../Component.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../GameObject.hpp"

namespace components {
    using namespace models;
    using namespace entities;
    class FrameAnimation : public Component {
        private:
            float fFrameInterval;
            float fTicks;
            int nFrame;
    
        public:
            FrameAnimation(std::string strName);

        public:
            void perform();
    };
}
