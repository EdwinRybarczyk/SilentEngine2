#include "SilentEntity.hpp"
#include <string.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
using namespace SilentMaths;
namespace SilentEntities
{
    void SilentEntity::load()
    {
        //Create vao
        unsigned int vaoID;
        glGenVertexArrays(3, &vaoID);
        this->vaoID = vaoID;
        glBindVertexArray(vaoID);

        //load indices
        
        unsigned int indiceBuffer;
        glGenBuffers(1,&indiceBuffer);
        this->IndBufferID = indiceBuffer;
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indiceBuffer);
        glBufferData(
            GL_ELEMENT_ARRAY_BUFFER, 
            this->model.indices.size()*sizeof(unsigned int), 
            this->model.indices.data(), 
            GL_STATIC_DRAW
        );
        glVertexAttribPointer(0,1,GL_UNSIGNED_INT,false,0,0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        //load vertex data
        unsigned int vertexBuffer;
        glGenBuffers(1,&vertexBuffer);
        this->vertBufferID = vertexBuffer;
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glBufferData(
            GL_ARRAY_BUFFER, 
            this->model.vertices.size()*sizeof(float), 
            this->model.vertices.data(), 
            GL_STATIC_DRAW
        );
        glVertexAttribPointer(1,3,GL_FLOAT,false,0,0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindVertexArray(0);
    }

    void SilentEntity::unload()
    {
        glBindVertexArray(0);
    }

    unsigned int SilentEntity::getVAOID()
    {
        return this->vaoID;
    }

    unsigned int SilentEntity::getIndID()
    {
        return this->IndBufferID;
    }

    unsigned int SilentEntity::getVertID()
    {
        return this->vertBufferID;
    }

    SilentEntity loadOBJModel(std::string path)
    {
        
        //temporary
        std::vector<SilentMaths::vec3f> tempVertices;
        std::vector<SilentMaths::vec3f> tempNormals;
        std::vector<SilentMaths::vec3f> tempUVs;

        //Processed here
        std::vector<SilentMaths::vec3f> vertices;
        std::vector<SilentMaths::vec3f> normals;
        std::vector<SilentMaths::vec3f> textureCoords;

        SilentModel model;

        FILE * objFile = fopen(path.data(), "r");
        if(objFile == NULL)
        {
            printf("Couldn't open file %s\n",path.data());
            exit(0);
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
                tempVertices.push_back(vector);
            }

            else if(strcmp(buffer, "vn") == 0)
            {
                vec3f vector;
                fscanf(objFile, "%f %f %f\n", &vector.x, &vector.y, &vector.z);
                tempNormals.push_back(vector);
            }

            else if(strcmp(buffer, "vt") == 0)
            {
                vec3f vector;
                fscanf(objFile, "%f %f\n", &vector.x, &vector.y);
                tempUVs.push_back(vector);
            }

            else if(strcmp(buffer, "f") == 0)
            {
                unsigned int vIndex[3], uvIndex[3], nIndex[3];

                int formatted = fscanf(objFile, "%u/%u/%u %u/%u/%u %u/%u/%u\n",
                    &vIndex[0],&uvIndex[0],&nIndex[0],
                    &vIndex[1], &uvIndex[1], &nIndex[1],
                    &vIndex[2],&uvIndex[2],&nIndex[2]);

                if(formatted != 9)
                {
                    printf("Unable to process faces of the obj file %s\n",path.data());
                }
                
                model.vertices.push_back(tempVertices[vIndex[0]-1].x);
                model.vertices.push_back(tempVertices[vIndex[0]-1].y);
                model.vertices.push_back(tempVertices[vIndex[0]-1].z);

                model.vertices.push_back(tempVertices[vIndex[1]-1].x);
                model.vertices.push_back(tempVertices[vIndex[1]-1].y);
                model.vertices.push_back(tempVertices[vIndex[1]-1].z);

                model.vertices.push_back(tempVertices[vIndex[2]-1].x);
                model.vertices.push_back(tempVertices[vIndex[2]-1].y);
                model.vertices.push_back(tempVertices[vIndex[2]-1].z);

                model.indices.push_back(model.indices.size());
                model.indices.push_back(model.indices.size());
                model.indices.push_back(model.indices.size());

            }        
        }

        /*
        for(unsigned int i = 0; i < model.indices.size(); i++)
        {
            printf("%i\n",model.indices[i]);
        }
        */

        SilentEntity entity;
        entity.model = model;
        
        entity.posX = 0;
        entity.posY = 0;
        entity.posZ = 0;
        entity.rotX = 0;
        entity.rotY = 0;
        entity.rotZ = 0;
        entity.scaleX = 1;
        entity.scaleY = 1;
        entity.scaleZ = 1;
        return entity;
    }
}