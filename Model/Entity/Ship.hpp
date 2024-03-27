#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Script/ShipControls.hpp"
#include "../Component/Input/ShipInput.hpp"
#include "../Component/Renderer/Renderer.hpp"

namespace entities {
    using namespace models;

    class Ship : public GameObject {
        private:
            sf::Color CNormalColor;

        public:
            Ship(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
    };
}
