#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Enum/PoolTag.hpp"

namespace poolables {
    using namespace models;
    
    class PoolableObject : public GameObject {
        protected:
            GameObject* pOwner;
            PoolTag ETag;

        public:
            PoolableObject(PoolTag ETag, std::string strName, AnimatedTexture* pTexture); 
            ~PoolableObject();

        public:
            void attachOwner(GameObject* pOwner);
            void detachOwner();

        public:
            virtual void initialize()       = 0;
            virtual void onActivate()       = 0;
            virtual void onRelease()        = 0;
            virtual PoolableObject* clone() = 0;

        public:
            GameObject* getOwner();
            PoolTag getTag();
    };
}
