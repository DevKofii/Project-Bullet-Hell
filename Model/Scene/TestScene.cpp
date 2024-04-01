#include "TestScene.hpp"

using namespace scenes;

TestScene::TestScene() : Scene(SceneTag::TEST_SCENE) {}

void TestScene::onLoadResources() {
    TextureManager::getInstance()->loadTest();
}

void TestScene::onLoadObjects() {
    this->createBackground();
    this->spawnBot();
    this->spawnUnit();
    this->createObjectPools();
}

void TestScene::onUnloadResources() {
    TextureManager::getInstance()->unloadAll(); 
}

void TestScene::createBackground() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::TEST_BACKGROUND));
    TestBackground* pTestBackground = new TestBackground("TestBackground", pTexture);
    GameObjectManager::getInstance()->addObject(pTestBackground);
}

void TestScene::spawnUnit() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::TEST_UNIT));
    TestUnit* pTestUnit = new TestUnit("TestUnit", pTexture);
    pTestUnit->setFrame(0);
    pTestUnit->setOrientationRight(true);
    pTestUnit->setOrientationLeft(false);
    pTestUnit->setScale({2.0f,2.0f});
    pTestUnit->setPosition({90.f,210.f});
    GameObjectManager::getInstance()->addObject(pTestUnit);
}

void TestScene::spawnBot() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::TEST_UNIT));
    TestEnemy* pTestBot = new TestEnemy("TestBot", pTexture);
    pTestBot->setFrame(0);
    pTestBot->setOrientationRight(false);
    pTestBot->setOrientationLeft(true);
    pTestBot->setScale({-2.0f,2.0f});
    pTestBot->setPosition({690.f,210.f});
    GameObjectManager::getInstance()->addObject(pTestBot);
}

void TestScene::createObjectPools() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::TEST_BULLET));
    TestUnit* pTestUnit = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");

    TestBullet_R* pTestBulletRef_R = new TestBullet_R("Test Bullet R",pTexture,pTestUnit);
    GameObjectPool* pTestBulletPool_R = new GameObjectPool(PoolTag::TEST_BULLET_R, 3, pTestBulletRef_R);
    pTestBulletPool_R->initalize();
    ObjectPoolManager::getInstance()->registerObjectPool(pTestBulletPool_R);

    TestBullet_L* pTestBulletRef_L = new TestBullet_L("Test Bullet L",pTexture,pTestUnit);
    GameObjectPool* pTestBulletPool_L = new GameObjectPool(PoolTag::TEST_BULLET_L, 3, pTestBulletRef_L);
    pTestBulletPool_L->initalize();
    ObjectPoolManager::getInstance()->registerObjectPool(pTestBulletPool_L);
    
    // GameObjectPool* pRetrievedPool_R = ObjectPoolManager::getInstance()->getPool(PoolTag::TEST_BULLET_R);
    // pRetrievedPool_R->requestPoolable();

    // GameObjectPool* pRetrievedPool_L = ObjectPoolManager::getInstance()->getPool(PoolTag::TEST_BULLET_L);
    // pRetrievedPool_L->requestPoolable();
}


