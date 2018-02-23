#include "SilentRenderer.hpp"
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
namespace SilentRenderingEngine
{
    SilentRenderer::SilentRenderer()
    {

    }

    SilentRenderer::~SilentRenderer()
    {

    }

    void SilentRenderer::prepare()
    {
        //Enable depth testing
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        //Enable backface culling
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    }

    void SilentRenderer::renderEntity(SilentEntities::SilentEntity entity)
    {
        glBindVertexArray(entity.getVAOID());
        glEnableVertexAttribArray(0);
        
        glDrawElements(
            GL_TRIANGLES,
            entity.model.vertices.size(),
            GL_UNSIGNED_INT,
            0
        );

        glBindVertexArray(0);
    }

    void SilentRenderer::render()
    {
        
    }
}