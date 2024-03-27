#pragma once

#include "iostream"
#include "unordered_map"
#include "../../Model/Scene.hpp"
#include "../../Model/Enum/SceneTag.hpp"

namespace managers {
    using namespace models;
    class SceneManager {
        /* [TODO] :
           Fill this up based on the slides. */
        private:
            std::unordered_map<SceneTag, Scene*> mapScenes;
            Scene* pActiveScene;
            bool bLoading;
            SceneTag ESceneToLoad;

        public:
            void registerScene(Scene* pScene);
            void loadScene(SceneTag ETag);
            void unloadScene();
            void checkLoadScene();
            bool getLoaded(SceneTag ETag);
            Scene* getActiveScene();

        /* * * * * * * * * * * * * * * * * * * * * 
         *       SINGLETON-RELATED CONTENT       * 
         * * * * * * * * * * * * * * * * * * * * */
        private:
            static SceneManager* P_SHARED_INSTANCE;

        private:
            SceneManager();
            SceneManager(const SceneManager&);
            SceneManager& operator = (const SceneManager&);

        public:
            static SceneManager* getInstance();
        /* * * * * * * * * * * * * * * * * * * * */
    };
}
