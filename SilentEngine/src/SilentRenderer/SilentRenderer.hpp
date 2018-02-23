#pragma once
#include "../SilentEntities/SilentEntity.hpp"
namespace SilentRenderingEngine
{
    class SilentRenderer
    {
        public:

        public:
        SilentRenderer();
        ~SilentRenderer();
        void prepare();
        void renderEntity(SilentEntities::SilentEntity entity);
        void render();
    };
}