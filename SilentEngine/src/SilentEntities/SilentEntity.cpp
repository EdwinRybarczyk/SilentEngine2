#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <string.h>
#include <SDL2/SDL_image.h>
#include "SilentEntity.hpp"
#include "../SilentMaths/SilentVectors.hpp"
//using namespace SilentMaths;
namespace SilentEntities
{
    void SilentEntity::loadToMemory()
    {
        //Create VAO
        unsigned int vaoID;
        glGenVertexArrays(2, &vaoID);
        this->model.info.vaoID = vaoID;
        glBindVertexArray(vaoID);

        //Load vertex data
        unsigned int vertexBuffer;
        glGenBuffers(1,&vertexBuffer);
        this->model.info.vertexBuffer = vertexBuffer;
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glBufferData(
            GL_ARRAY_BUFFER, 
            this->model.vertices.size()*sizeof(float), 
            this->model.vertices.data(), 
            GL_STATIC_DRAW
        );
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        //load texture coords
        unsigned int textureBuffer;
        glGenBuffers(1,&textureBuffer);
        this->model.info.textureCoordinateBuffer = textureBuffer;
        glBindBuffer(GL_ARRAY_BUFFER, textureBuffer);
        glBufferData(
            GL_ARRAY_BUFFER, 
            this->model.textureCoords.size()*sizeof(float), 
            this->model.textureCoords.data(), 
            GL_STATIC_DRAW
        );
        glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,0,(void*)0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        //load indices
        unsigned int indiceBuffer;
        glGenBuffers(1,&indiceBuffer);
        this->model.info.indiceBuffer = indiceBuffer;
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indiceBuffer);
        glBufferData(
            GL_ELEMENT_ARRAY_BUFFER, 
            this->model.indices.size()*sizeof(unsigned int), 
            this->model.indices.data(), 
            GL_STATIC_DRAW
        );
        
        glBindVertexArray(0);
    }

    void SilentEntity::unloadFromVao()
    {
        glBindVertexArray(0);
    }


    void SilentEntity::translate()
    {
        
    }

    void SilentEntity::rotate(float angle, SilentMaths::Vector3<float> rotation)
    {
    }

    void SilentEntity::scale()
    {
        
    }

    SilentEntity loadOBJModel(std::string modelPath, std::string texturePath)
    {
        
        //temporary
        std::vector<SilentMaths::Vector3<float> > tempVertices;
        std::vector<SilentMaths::Vector3<float> > tempNormals;
        std::vector<SilentMaths::Vector2<float> > tempUVs;

        SilentModel model;

        FILE * objFile = fopen(modelPath.data(), "r");
        if(objFile == NULL)
        {
            printf("Couldn't open file %s\n",modelPath.data());
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
                SilentMaths::Vector3<float> vector;
                fscanf(objFile, "%f %f %f\n", &vector.x, &vector.y, &vector.z);
                tempVertices.push_back(vector);
            }

            else if(strcmp(buffer, "vn") == 0)
            {
                SilentMaths::Vector3<float> vector;
                fscanf(objFile, "%f %f %f\n", &vector.x, &vector.y, &vector.z);
                tempNormals.push_back(vector);
            }

            else if(strcmp(buffer, "vt") == 0)
            {
                SilentMaths::Vector2<float> vector;
                fscanf(objFile, "%f %f\n", &vector.x, &vector.y);
                vector.x = 1 - vector.x;
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
                    printf("Unable to process faces of the obj file %s\n",modelPath.data());
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



                model.textureCoords.push_back(tempUVs[uvIndex[0]-1].x);
                model.textureCoords.push_back(tempUVs[uvIndex[0]-1].y);

                model.textureCoords.push_back(tempUVs[uvIndex[1]-1].x);
                model.textureCoords.push_back(tempUVs[uvIndex[1]-1].y);

                model.textureCoords.push_back(tempUVs[uvIndex[2]-1].x);
                model.textureCoords.push_back(tempUVs[uvIndex[2]-1].y);

                model.indices.push_back(model.indices.size());
                model.indices.push_back(model.indices.size());
                model.indices.push_back(model.indices.size());

            }        
        }
        

        //Load texture
        SDL_Surface* surface = IMG_Load(texturePath.data());
        unsigned int textureID;
        glGenTextures(1,&textureID);
        glBindTexture(GL_TEXTURE_2D,textureID);

        int imageMode = GL_RGB;

        if(surface->format->BytesPerPixel == 4)
        {
            imageMode = GL_RGBA;
        }

        glTexImage2D(GL_TEXTURE_2D,0,imageMode,surface->w,surface->h,0,imageMode,
            GL_UNSIGNED_BYTE, surface->pixels);

        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

        glBindTexture(GL_TEXTURE_2D,0);

        SilentEntity entity;
        entity.model.info.texture = textureID;
        entity.position = SilentMaths::mat4x4f();
        return entity;
    }
}