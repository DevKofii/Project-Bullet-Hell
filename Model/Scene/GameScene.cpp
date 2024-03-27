#include "GameScene.hpp"

using namespace scenes;

GameScene::GameScene() : Scene(SceneTag::GAME_SCENE) {}

void GameScene::onLoadResources() {
    TextureManager::getInstance()->loadGame();
}

void GameScene::onLoadObjects() {
    this->createBackground();
    this->createShip();
    this->createObjectPools();
}

void GameScene::onUnloadResources() {
    TextureManager::getInstance()->unloadAll(); 
}
 
void GameScene::createBackground() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::GAME_BACKGROUND));
    TestBackground* pBackground = new TestBackground("Background", pTexture);
    GameObjectManager::getInstance()->addObject(pBackground);
}

void GameScene::createShip() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::SHIP));
    Ship* pEntity = new Ship("Ship", pTexture);
    GameObjectManager::getInstance()->addObject(pEntity);
}
void GameScene::createObjectPools() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLAYER_BULLET));
    Ship* pShip = (Ship*)GameObjectManager::getInstance()->findObjectByName("Ship");
    PlayerBullet* pBulletReference = new PlayerBullet("Player Bullet", pTexture, pShip);
    GameObjectPool* pBulletPool = new GameObjectPool(PoolTag::PLAYER_BULLET, 3, pBulletReference);
    pBulletPool->initalize();

    ObjectPoolManager::getInstance()->registerObjectPool(pBulletPool);
    GameObjectPool* pRetrievedPool = ObjectPoolManager::getInstance()->getPool(PoolTag::PLAYER_BULLET);
    pRetrievedPool->requestPoolable();
}