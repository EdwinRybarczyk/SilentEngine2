#pragma once
#include "../SilentMaths/SilentVectors.hpp"
#include "../SilentMaths/SilentMatrices.hpp"
#include <iostream>
#include <vector>
namespace SilentEntities
{
    struct MeshInfo
    {
        unsigned int vaoID;
        unsigned int vertexBuffer;
        unsigned int textureCoordinateBuffer;
        unsigned int indiceBuffer;
        unsigned int texture;
    };

    class SilentModel
    {
        public:
        MeshInfo                    info;
        std::vector<float>          vertices;
        std::vector<float>          normals;
        std::vector<float>          textureCoords;
        std::vector<unsigned int>   indices;
    };

    class SilentEntity
    {
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
        void rotate(float angle, SilentMaths::Vector3<float> rotation);
        void scale();
    };


    SilentEntity loadOBJModel(std::string modelPath, std::string texturePath);
}