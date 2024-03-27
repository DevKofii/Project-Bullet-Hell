#include "TextureManager.hpp"
using namespace managers;

void TextureManager::loadAll() {}

void TextureManager::loadMainMenu() {
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/TitleScreen.png");
    this->mapTexture[AssetType::TITLE_SCREEN].push_back(pTexture);
}

void TextureManager::loadGame() {
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Background.png");
    this->mapTexture[AssetType::GAME_BACKGROUND].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Space Impact/Player/this_ship_be_otp.png");
    this->mapTexture[AssetType::SHIP].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Space Impact/Player/bullet.png");
    this->mapTexture[AssetType::PLAYER_BULLET].push_back(pTexture);
}

void TextureManager::loadTest() {
    sf::Texture* pTexture = new sf::Texture();

    //Load Background
    pTexture->loadFromFile("View/Image/Background.png");
    this->mapTexture[AssetType::TEST_BACKGROUND].push_back(pTexture);

    //Load Unit Idle Tex
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/char/anims/idle/idle.png");
    this->mapTexture[AssetType::TEST_UNIT].push_back(pTexture);

    //load Unit Move Tex
    for(int i = 1; i <= 8; i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/char/anims/move/frame" + std::to_string(i) + ".png");
        this->mapTexture[AssetType::TEST_UNIT].push_back(pTexture);
    }

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/parts/bullet/bullet.png");
    this->mapTexture[AssetType::TEST_BULLET].push_back(pTexture);
}

void TextureManager::unloadAll() {
    for(AssetType EType : this->vecAssetTypes) {
        std::vector<sf::Texture*> vecTextures = this->mapTexture[EType];
        for(int i = 0; i < vecTextures.size(); i++) {
            delete this->mapTexture[EType][i];
        }
    }

    this->vecAssetTypes.clear();
    this->mapTexture.clear();
}

std::vector<sf::Texture*> TextureManager::getTexture(AssetType EKey) {
    return this->mapTexture[EKey];
}

sf::Texture* TextureManager::getTextureAt(AssetType EKey, int nFrame) {
    return this->mapTexture[EKey][nFrame];
}


TextureManager* TextureManager::P_SHARED_INSTANCE = NULL;

TextureManager::TextureManager() {}

TextureManager::TextureManager(const TextureManager&) {}

TextureManager* TextureManager::getInstance() {
    // If instance does not exist, create a new instance of that object by
    // allocating new memory.
    if(P_SHARED_INSTANCE  == NULL) P_SHARED_INSTANCE = new TextureManager();

    //Return Shared Instance
    return P_SHARED_INSTANCE;
}
