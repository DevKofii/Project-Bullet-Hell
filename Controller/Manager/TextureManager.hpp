#pragma once
#include "iostream"
#include "unordered_map"
#include "SFML/Graphics.hpp"
#include "../../Model/Enum/AssetType.hpp"

namespace managers{
    class TextureManager{
        private:
            std::unordered_map<AssetType, std::vector<sf::Texture*>> mapTexture;
            std::vector<AssetType> vecAssetTypes;

        public:
            void loadAll();
            void loadMainMenu();
            void loadGame();
            void loadTest();
            void unloadAll();

        public:
            std::vector<sf::Texture*> getTexture(AssetType EKey);
            sf::Texture* getTextureAt(AssetType EKey, int nFrame);

        private:
            static TextureManager* P_SHARED_INSTANCE;
            TextureManager();
            TextureManager(const TextureManager&);
            TextureManager& operator = (const TextureManager&);

        public:
            static TextureManager* getInstance();

    };
}