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
        std::vector<SilentMaths::vec2f> textureCoords;
        std::vector<unsigned int> indices;
    };
    class SilentEntity
    {
        public:
        SilentModel model;
        float posX,posY,posZ;
        float rotX,rotY,rotZ;
        float scaleX,scaleY,scaleZ;
    };


    SilentEntity loadOBJModel(std::string path);
}