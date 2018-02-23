#pragma once
#include "../SilentMaths/SilentVectors.hpp"
#include <iostream>
#include <vector>
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

        public:
        SilentModel model;
        //float posX,posY,posZ;
        SilentMaths::vec3f position;
        SilentMaths::vec3f rotation;
        SilentMaths::vec3f scale;

        public:
        void load();
        void unload();


        unsigned int getVAOID();
        unsigned int getIndID();
        unsigned int getVertID();
        unsigned int getTextureID();
        void setTextureID(unsigned int ID);
    };


    SilentEntity loadOBJModel(std::string modelPath, std::string texturePath);
}