#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Renderer/Renderer.hpp"

namespace entities{
    using namespace components;
    using namespace models;
    class Edges : public GameObject{
        public:
            Edges(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
    };
}