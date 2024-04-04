#pragma once

#include "iostream"
#include "SFML/Graphics.hpp"
#include "Manager/TextureManager.hpp"
#include "Manager/GameObjectManager.hpp"
#include "Manager/ObjectCollisionManager.hpp"
#include "Manager/SceneManager.hpp"
#include "../Model/Enum/AssetType.hpp"
#include "../Model/Scene/MainMenuScene.hpp"
#include "../Model/Scene/GameScene.hpp"
#include "../Model/Scene/TestScene.hpp"
#include "cmath"
// #include "wall.h"
// #include "ray.h"

namespace controllers {
    using namespace managers;
    using namespace entities;
    using namespace scenes;
    class Game {
        protected:
            const float    ray_density = 1000;
            const Color    ray_color = Color(255, 255, 255, 10);
            const Color    wall_color = Color::Red;

            bool side; // 0 = right, 1 = left
            
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
            int random(int max);

    };
}


class wall {
    public:
        Vector2f start;
        Vector2f end;
        wall() {};
        wall(Vector2f pos1, Vector2f pos2);
};

class ray
{
    public:
        Vector2f m_end;

        ray() {};
        ray(float x, float y);
        void calc_hit(Vector2f wall1, Vector2f wall2);
        void reset();
    private:
        Vector2f m_relative_end;
};
