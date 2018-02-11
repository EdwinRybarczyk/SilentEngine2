#include "../SilentMaths/SilentVectors.hpp"
#include <iostream>
#include <vector>
namespace SilentEntities
{
    class SilentModel
    {
        public:
        std::vector<SilentMaths::vec3f> vertices;
        std::vector<SilentMaths::vec3f> normals;
        std::vector<SilentMaths::vec3f> textureCoords;
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