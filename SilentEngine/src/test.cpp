#include "SilentSystem/SilentWindow.hpp"
#include "SilentRenderer/SilentRenderer.hpp"
#include "SilentRenderer/SilentShader.hpp"
using namespace SilentSystem;
using namespace SilentEntities;
using namespace SilentRenderingEngine;
int main()
{
    SilentWindow window;
    window.api = OpenGL;
    window.doubleBuffering = true;
    window.width = 600;
    window.height = 400;
    window.title = "Sample Window";
    window.createWindow();

    Shader shaderProgram;
    shaderProgram.loadShader("src/SilentRenderer/vertexShader.txt",vertexShader);
    shaderProgram.loadShader("src/SilentRenderer/fragmentShader.txt",fragmentShader);
    shaderProgram.load();
    shaderProgram.bindAttribute(0,"position");
    shaderProgram.bindAttribute(1,"texCoord");

    SilentRenderer renderer;
    SilentEntity sampleEntity = loadOBJModel("src/plane.obj","src/WolfeTexture.png");
    sampleEntity.loadToVao();


    while(window.windowOpen)
    {
        renderer.prepare();
        shaderProgram.startProgram();
        renderer.renderEntity(sampleEntity);
        shaderProgram.stopProgram();
        window.updateWindow();
    }
    return 0;
}