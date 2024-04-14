#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../../../AnimatedTexture.hpp"
#include "../../../Entity/TestEnemy.hpp"
#include "../../Component.hpp"
#include "../../../Enum/ComponentType.hpp"
#include "../../../GameObject.hpp"

namespace components {
    using namespace models;
    using namespace entities;
    class FrameAnimationBot : public Component {
        private:
            float fFrameInterval;
            float fTicks;
            int nFrame;
    
        public:
            FrameAnimationBot(std::string strName);

        public:
            void perform();
    };
}
