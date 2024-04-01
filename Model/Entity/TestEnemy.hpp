#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Renderer/Renderer.hpp"
#include "../Component/Input/Bot/BotInput.hpp"
#include "../Component/Script/Bot/BotManager.hpp"
#include "../Component/Script/Bot/FrameAnimationBot.hpp"

namespace entities {
    using namespace models;
    class TestEnemy : public GameObject {
        private:
            const int nFrameStart = 0;
            const int nFrameEnd = 8;

        public:
            TestEnemy(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();

        public:
            int getFrameStart();
            int getFrameEnd();
    };
}