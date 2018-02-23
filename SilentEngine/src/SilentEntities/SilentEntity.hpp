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
        unsigned int IndBufferID;
        public:
        SilentModel model;
        float posX,posY,posZ;
        float rotX,rotY,rotZ;
        float scaleX,scaleY,scaleZ;

        public:
        void load();
        void unload();
        unsigned int getVAOID();
        unsigned int getIndID();
        unsigned int getVertID();
    };


    SilentEntity loadOBJModel(std::string path);
}