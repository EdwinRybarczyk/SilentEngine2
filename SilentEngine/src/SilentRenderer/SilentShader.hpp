#pragma once
#include <iostream>
namespace SilentRenderingEngine
{
    enum shaderType
    {
        vertexShader,
        fragmentShader
    };

    class Shader
    {
        public:
        Shader();
        private:
        unsigned int shaderID;
        unsigned int vertShaderID;
        unsigned int fragShaderID;
        unsigned int getShaderID();

        public:
        
        void loadShader(std::string fileName, shaderType type);
        void load();
        void startProgram();
        void stopProgram();
        ~Shader();
        void bindAttribute(int attribID, std::string varName);

    };
}