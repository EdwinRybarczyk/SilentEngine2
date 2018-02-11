#include "SilentEntity.hpp"
#include <string.h>
using namespace SilentMaths;
namespace SilentEntities
{
    SilentEntity loadOBJModel(std::string path)
    {
        SilentModel model;

        FILE * objFile = fopen(path.data(), "r");
        if(objFile == NULL)
        {
            printf("Couldn't open file %s\n",path.data());
        }

        while(1)
        {
            char buffer[1000];
            int line = fscanf(objFile, "%s", buffer);
            if(line == EOF)
            {
                break;
            }
            if(strcmp(buffer, "v") == 0)
            {
                vec3f vector;
                fscanf(objFile, "%f %f %f\n", &vector.x, &vector.y, &vector.z);
                model.vertices.push_back(vector);
            }

            else if(strcmp(buffer, "vt") == 0)
            {
                vec2f vector;
                fscanf(objFile, "%f %f\n", &vector.x, &vector.y);
                model.textureCoords.push_back(vector);
            }

            else if(strcmp(buffer, "vn") == 0)
            {
                vec3f vector;
                fscanf(objFile, "%f %f %f\n", &vector.x, &vector.y, &vector.z);
                model.normals.push_back(vector);
            }

            else if(strcmp(buffer, "f") == 0)
            {
            }
            
        }

        SilentEntity entity;
        entity.model = model;
        return entity;
    }
}