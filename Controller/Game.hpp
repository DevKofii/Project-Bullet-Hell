#pragma once

#include "iostream"
#include "SFML/Graphics.hpp"
#include "Manager/TextureManager.hpp"
#include "Manager/GameObjectManager.hpp"
#include "Manager/SceneManager.hpp"
#include "../Model/Enum/AssetType.hpp"
#include "../Model/Scene/MainMenuScene.hpp"
#include "../Model/Scene/GameScene.hpp"
#include "../Model/Scene/TestScene.hpp"

namespace controllers {
    using namespace managers;
    using namespace entities;
    using namespace scenes;
    class Game {
        private: 
            sf::RenderWindow CWindow;

            // GameObject CTest;

            void processEvents();
            void update(sf::Time tDeltaTime);
            void render();
            void processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed);

        public:
            Game();
            void run();

    };
}