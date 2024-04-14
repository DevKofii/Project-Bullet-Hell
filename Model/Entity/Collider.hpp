#pragma once

#include "../AnimatedTexture.hpp"
#include "../GameObject.hpp"
#include "../Component/Renderer/Renderer.hpp"

namespace entities{
    using namespace models;
    using namespace components;
    class Collider : public GameObject {
        public:
            Collider(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
    };
}