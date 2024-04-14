#include "TestScene.hpp"

using namespace scenes;

TestScene::TestScene() : Scene(SceneTag::TEST_SCENE) {}

void TestScene::onLoadResources() {
    TextureManager::getInstance()->loadTest();
}

void TestScene::onLoadObjects() {
    this->createBackground();
    //this->spawnMisc();
    this->createBarrier();
    //this->spawnBot();
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

void TestScene::spawnMisc() {
    AnimatedTexture* pTexture;
    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BULLET_COLLIDER));
    Collider* pCollider = new Collider("Collider", pTexture);
    this->registerObject(pCollider);

    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::SHADOW));
    Shadow* pShadow = new Shadow("Shadow", pTexture);
    this->registerObject(pShadow);
}

void TestScene::createBarrier() {
    AnimatedTexture* pTexture0 = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BARRIER));
    AnimatedTexture* pTexture1 = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::EDGE_LEFT));
    AnimatedTexture* pTexture2 = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::EDGE_TOP));

    Barrier* pMainBarrier;
    Edges* pLeft;
    Edges* pRight;
    Edges* pTop;
    Edges* pBottom;

    for(auto i = 1; i <= 6; i++) {
        pMainBarrier = new Barrier("Barrier" + std::to_string(i), pTexture0, i);
        pLeft = new Edges("Left" + std::to_string(i), pTexture1);
        pRight = new Edges("Right" + std::to_string(i), pTexture1);
        pTop = new Edges("Top" + std::to_string(i), pTexture2);
        pBottom = new Edges("Bottom" + std::to_string(i), pTexture2);
        switch(i){
            case 1:
                pMainBarrier->setPosition({B1_X, B1_Y});
                pLeft->setPosition({L1_L_X, L1_L_Y});
                pRight->setPosition({L1_R_X, L1_R_Y});
                pTop->setPosition({L1_T_X, L1_T_Y});
                pBottom->setPosition({L1_B_X, L1_B_Y});
                break;
            case 2:
                pMainBarrier->setPosition({B2_X, B2_Y});
                pLeft->setPosition({L2_L_X, L2_L_Y});
                pRight->setPosition({L2_R_X, L2_R_Y});
                pTop->setPosition({L2_T_X, L2_T_Y});
                pBottom->setPosition({L2_B_X, L2_B_Y});
                break;
            case 3:
                pMainBarrier->setPosition({B3_X, B3_Y});
                pLeft->setPosition({L3_L_X, L3_L_Y});
                pRight->setPosition({L3_R_X, L3_R_Y});
                pTop->setPosition({L3_T_X, L3_T_Y});
                pBottom->setPosition({L3_B_X, L3_B_Y});
                break;
            case 4:
                pMainBarrier->setPosition({B4_X, B4_Y});
                pLeft->setPosition({L4_L_X, L4_L_Y});
                pRight->setPosition({L4_R_X, L4_R_Y});
                pTop->setPosition({L4_T_X, L4_T_Y});
                pBottom->setPosition({L4_B_X, L4_B_Y});
                break;
            case 5:
                pMainBarrier->setPosition({B5_X, B5_Y});
                pLeft->setPosition({L5_L_X, L5_L_Y});
                pRight->setPosition({L5_R_X, L5_R_Y});
                pTop->setPosition({L5_T_X, L5_T_Y});
                pBottom->setPosition({L5_B_X, L5_B_Y});
                break;
            case 6:
                pMainBarrier->setPosition({B6_X, B6_Y});
                pLeft->setPosition({L6_L_X, L6_L_Y});
                pRight->setPosition({L6_R_X, L6_R_Y});
                pTop->setPosition({L6_T_X, L6_T_Y});
                pBottom->setPosition({L6_B_X, L6_B_Y});
                break;
        }
        this->registerObject(pMainBarrier);
        this->registerObject(pLeft);
        this->registerObject(pRight);
        this->registerObject(pTop);
        this->registerObject(pBottom);
    }
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
    TestEnemy* pTestBot = new TestEnemy("TestBot", pTexture, 0);
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


