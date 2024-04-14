#include <iostream>
#include <unordered_map>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Controller/Game.cpp"
#include "Controller/Manager/TextureManager.cpp"
#include "Controller/Manager/GameObjectManager.cpp"
#include "Controller/Manager/ObjectPoolManager.cpp"
#include "Controller/Manager/SceneManager.cpp"

#include "Controller/Pooling/GameObjectPool.cpp"

#include "Model/GameObject.cpp"
#include "Model/AnimatedTexture.cpp"

#include "Model/Entity/Background.cpp"
#include "Model/Entity/Ship.cpp"
#include "Model/Entity/TestBackground.cpp"
#include "Model/Entity/TestUnit.cpp"
#include "Model/Entity/TestEnemy.cpp"
#include "Model/Entity/Collider.cpp"
#include "Model/Entity/Shadow.cpp"
#include "Model/Entity/Barrier.cpp"
#include "Model/Entity/Edges.cpp"

#include "Model/Pooling/PoolableObject.cpp"
#include "Model/Pooling/Entity/PlayerBullet.cpp"
#include "Model/Pooling/Entity/TestBullet_R.cpp"
#include "Model/Pooling/Entity/TestBullet_L.cpp"
#include "Model/Pooling/Entity/TestBullet_R_Bot.cpp"
#include "Model/Pooling/Entity/TestBullet_L_Bot.cpp"

#include "Model/Scene.cpp"
#include "Model/Scene/MainMenuScene.cpp"
#include "Model/Scene/GameScene.cpp"
#include "Model/Scene/TestScene.cpp"

#include "Model/Component/Component.cpp"
#include "Model/Component/GeneralInput.cpp"

#include "Model/Component/Input/PlayerInput.cpp"
#include "Model/Component/Input/BackgroundInput.cpp"
#include "Model/Component/Input/ShipInput.cpp"
#include "Model/Component/Input/TestUnitInput.cpp"

#include "Model/Component/Script/PlayerMovement.cpp"
#include "Model/Component/Script/BackgroundAction.cpp"
#include "Model/Component/Script/BulletMovement.cpp"
#include "Model/Component/Script/ShipControls.cpp"
#include "Model/Component/Script/TestUnitControls.cpp"
#include "Model/Component/Script/TestBulletMovement_R.cpp"
#include "Model/Component/Script/TestBulletMovement_L.cpp"

#include "Model/Component/Script/FrameAnimation.cpp"
#include "Model/Component/Script/CollisionManager.cpp"

#include "Model/Component/Script/BoundsAction.cpp"

#include "Model/Component/Script/Bot/BotManager.cpp"
#include "Model/Component/Script/Bot/FrameAnimationBot.cpp"

#include "Model/Component/Renderer/Renderer.cpp"

using namespace controllers;
int main() {
    Game CGame;
    CGame.run();
    return 0;
}

