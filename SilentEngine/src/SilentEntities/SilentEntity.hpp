#pragma once
#include "../SilentMaths/SilentVectors.hpp"
#include "../SilentMaths/SilentMatrices.hpp"
#include <iostream>
#include <vector>
//#include <glm/mat4x4.hpp>
namespace SilentEntities
{
    class SilentModel
    {
        public:
        std::vector<float> vertices;
        std::vector<float> normals;
        std::vector<float> textureCoords;
        std::vector<unsigned int> indices;
    };

    class SilentEntity
    {
        private:
        unsigned int vaoID;
        unsigned int vertBufferID;
        unsigned int texBufferID;
        unsigned int IndBufferID;
        unsigned int textureID;
        //glm::mat4x4 position;

        public:
        SilentMaths::mat4x4f position;
        //Model management
        SilentModel model;
        void loadToVao();
        void unloadFromVao();
        unsigned int getVAOID();
        unsigned int getIndID();
        unsigned int getVertID();
        unsigned int getTextureID();
        void setTextureID(unsigned int ID);

        //Entity management
        void translate();
        void rotate(float angle, SilentMaths::vec3f rotation);
        void scale();
    };


    SilentEntity loadOBJModel(std::string modelPath, std::string texturePath);
}