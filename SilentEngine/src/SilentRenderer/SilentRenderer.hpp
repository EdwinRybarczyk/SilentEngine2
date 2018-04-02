#ifndef SILENT_RENDERER
#define SILENT_RENDERER
#include "../SilentEntities/SilentEntity.hpp"
namespace SilentRenderingEngine
{
    class SilentRenderer
    {
        public:
        SilentRenderer();
        ~SilentRenderer();
        void prepare();
        void renderEntity(SilentEntities::SilentEntity entity);
        void render();
    };
}

#endif