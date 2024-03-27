#pragma once

#include "../Scene.hpp"
#include "../Enum/SceneTag.hpp"
#include "../Entity/Background.hpp"
#include "../../Controller/Manager/TextureManager.hpp"

namespace scenes {
    using namespace managers;
    using namespace entities;
    class MainMenuScene : public Scene {
        public:
            MainMenuScene();

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();
        
        private:
            void createBackground();
    };
}
