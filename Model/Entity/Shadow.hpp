#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Renderer/Renderer.hpp"

namespace entities {
    using namespace models;
    class Shadow : public GameObject {
        public:
            Shadow(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
    };
}