#pragma once
#include "iostream"
#include "SFML/Graphics.hpp"

namespace Singleton{
    class Template{
        public:
            void test();

        private:
            static Template* P_SHARED_INSTANCE;
            Template();
            Template(const Template&);
            Template& operator = (const Template&);

        public:
            static Template* getInstance();

    };
}


