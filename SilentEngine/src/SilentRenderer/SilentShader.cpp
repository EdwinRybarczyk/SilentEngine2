#include "SilentShader.hpp"
#include <GL/glew.h>
#include <GL/gl.h>
namespace SilentRenderingEngine
{
    char* readAllText(const char* path)
    {
        //Text buffer to be returned
        char* text;
        //File to be read from
        FILE *f;
        //If opening of the file fails
        if((f = fopen(path,"r"))==NULL)
        {
            //output about file not existing
            printf("File %s doesn't exist!\n",path);
            //Close the program
            exit(-1);
        }
        //Seek the end of the file
        fseek(f,0,SEEK_END);
        //Allocate enough space for the entire file
        text = (char*)malloc(ftell(f));
        //Rewind the file back to beginning
        fseek(f,0,SEEK_SET);
        //Declare counter for the character array
        long count = 0;
        //Initialise buffer for single character
        char c;
        //Iterate for as long as the character is not
        //the end of the file
        while((c = fgetc(f))!=EOF)
        {
            //Add the character
            text[count++] = (char)c;
        }
        text[count] = '\0';
        //Close the file
        fclose(f);
        //Return the source
        return text;
    }

    Shader::Shader()
    {

    }

    void Shader::loadShader(std::string fileName, shaderType type)
    {
        std::string source = readAllText(fileName.data());
        const char* sourceData = source.data();
        int sourceLength = source.size();
        unsigned int shaderID;
        if(type == vertexShader)
        {
            shaderID = glCreateShader(GL_VERTEX_SHADER);
            this->vertShaderID = shaderID;
        }
        else if(type == fragmentShader)
        {
            shaderID = glCreateShader(GL_FRAGMENT_SHADER);
            this->fragShaderID = shaderID;
        }
        glShaderSource(shaderID, 1, &sourceData,&sourceLength);
        glCompileShader(shaderID);
        int success = 0;
        glGetShaderiv(shaderID,GL_COMPILE_STATUS,&success);
        if(success == GL_FALSE)
        {
            printf("failed to compile shader \"%s\"\n",fileName.data());
        }
    }

    void Shader::load()
    {
        this->shaderID = glCreateProgram();
        glAttachShader(this->shaderID,this->vertShaderID);
        glAttachShader(this->shaderID,this->fragShaderID);



        glLinkProgram(this->shaderID);
        glValidateProgram(this->shaderID);
    }

    void Shader::startProgram()
    {
        glUseProgram(this->shaderID);
    }

    void Shader::stopProgram()
    {
        glUseProgram(0);
    }

    void Shader::bindAttribute(int attribID, std::string varName)
    {
        glBindAttribLocation(this->shaderID, attribID, varName.data());
    }

    Shader::~Shader()
    {
        stopProgram();
        glDetachShader(this->shaderID, this->vertShaderID);
        glDetachShader(this->shaderID, this->fragShaderID);
        glDeleteShader(this->vertShaderID);
        glDeleteShader(this->fragShaderID);
        glDeleteProgram(this->shaderID);
    }
}