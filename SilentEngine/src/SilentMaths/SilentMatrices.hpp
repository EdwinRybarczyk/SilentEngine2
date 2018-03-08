#pragma once
namespace SilentMaths
{
    class mat4x4f
    {
        public:
        float data[15] = {};
        mat4x4f()
        {
            this->data[0] = 1;
            this->data[5] = 1;
            this->data[10] = 1;
            this->data[15] = 1;
        }
        mat4x4f operator +=(mat4x4f rhs)
        {
            /*
            this->x += rhs.x;
            this->y += rhs.y;
            this->z += rhs.z;
            */
            return *this;
        }
    };
}