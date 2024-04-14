#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Renderer/Renderer.hpp"
#include "../Component/Script/BoundsAction.hpp"

namespace entities{
    using namespace components;
    using namespace models;
    class Barrier : public GameObject{
        private:
            int ID;

        public:
            Barrier(std::string strName, AnimatedTexture* pTexture, int ID);

        public:
            void initialize();
            int getID();
    };
}