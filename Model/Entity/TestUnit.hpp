#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Input/TestUnitInput.hpp"
#include "../Component/Script/TestUnitControls.hpp"
#include "../Component/Script/FrameAnimation.hpp"
#include "../Component/Script/CollisionManager.hpp"
#include "../Component/Renderer/Renderer.hpp"

namespace entities {
    using namespace models;
    class TestUnit : public GameObject {
        private:
            const int nFrameStart = 0;
            const int nFrameEnd = 8;

        public:
            TestUnit(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();

        public:
            int getFrameStart();
            int getFrameEnd();
    };
}