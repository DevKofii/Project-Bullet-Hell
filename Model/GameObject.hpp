#pragma once

#include "AnimatedTexture.hpp"
#include "Enum/AssetType.hpp"
#include "Component/Component.hpp"
#include "Component/GeneralInput.hpp"
#include "Component/Renderer/Renderer.hpp"

namespace models {
    using namespace components;
    class GameObject {
        protected:
            bool bEnabled;
            std::string strName;
            sf::Sprite* pSprite;
            AnimatedTexture* pTexture;
            float fSpeed;
            std::vector<Component*> vecComponents;
            int nCurrentFrame;

            bool bOrientRight;
            bool bOrientLeft;

            GameObject* pParent;
            std::vector<GameObject*> vecChildren;

        public:
            GameObject(std::string strName, AnimatedTexture* pTexture);
            GameObject(std::string strName, float fSpeed, AnimatedTexture* pTexture);

        public:
            virtual void initialize() = 0;
            virtual void processEvents(sf::Event CEvent);
            virtual void update(sf::Time tDeltaTime);
            virtual void draw(sf::RenderWindow* pWindow);

        public:
            void attachComponent(Component* pComponent);
            void detachComponent(Component* pComponent);
            void attachChild(GameObject* pChild);
            void detachChild(GameObject* pChild);
            Component* findComponentByName(std::string strName);
            std::vector<Component*> getComponents(ComponentType EType);
            sf::Sprite* getSprite();
            void centerOrigin();

        public:
            bool getEnabled();
            void setEnabled(bool bEnabled);
            std::string getName();
            void setTexture(AnimatedTexture* pTexture);

            void setSpeed(float fSpeed);
            float getSpeed();
            void setFrame(int nFrame);

            void setOrientationRight(bool bRight);
            void setOrientationLeft(bool bLeft);
            bool getOrientationRight();
            bool getOrientationLeft();

            GameObject* getParent();
            void setParent(GameObject* pParent);

            virtual sf::Vector2f getPosition();
            virtual void setPosition(sf::Vector2f vecPosition);
            virtual void setScale(sf::Vector2f vecScale);
            void resetPos();
    };
}
