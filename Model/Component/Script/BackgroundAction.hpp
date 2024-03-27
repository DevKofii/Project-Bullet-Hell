#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Input/BackgroundInput.hpp"
#include "../Component.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../Enum/SceneTag.hpp"
#include "../../GameObject.hpp"
#include "../../../Controller/Manager/SceneManager.hpp"

namespace components {
    using namespace managers;
    class BackgroundAction : public Component {
        public:
            BackgroundAction(std::string strName);

        public:
            void perform();
    };
}