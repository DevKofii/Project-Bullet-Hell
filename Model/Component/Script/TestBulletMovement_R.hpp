#pragma once

#include "../../../Config/Settings.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../Pooling/PoolableObject.hpp"
#include "../Component.hpp"
#include "../../../Controller/Manager/ObjectPoolManager.hpp"

namespace components {
    using namespace models;
    using namespace managers;
    using namespace poolables;
    class TestBulletMovement_R : public Component {
        private:
            float fFrameInterval;
            float fTicks;
            float fSpeed;

        public:
            TestBulletMovement_R(std::string strName);

        public:
            void perform();
    };
}
