#pragma once
#include "SilentMaths.hpp"
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
    };


    template <class T> class Matrix3
    {
        public:
        T data[9];


        /*
            0,1,2,
            3,4,5,
            6,7,8
        */

        Matrix3()
        {
            this->data = 
            {
                0,0,0,
                0,0,0,
                0,0,0
            };
        }

        Matrix3 operator +=(Matrix3 rhs)
        {
            this->data[0] += rhs.data[0];
            this->data[1] += rhs.data[1];
            this->data[2] += rhs.data[2];
            this->data[3] += rhs.data[3];
            this->data[4] += rhs.data[4];
            this->data[5] += rhs.data[5];
            this->data[6] += rhs.data[6];
            this->data[7] += rhs.data[7];
            this->data[8] += rhs.data[8];
            return *this;
        }

        Matrix3 operator -=(Matrix3 rhs)
        {
            this->data[0] -= rhs->data[0];
            this->data[1] -= rhs->data[1];
            this->data[2] -= rhs->data[2];
            this->data[3] -= rhs->data[3];
            this->data[4] -= rhs->data[4];
            this->data[5] -= rhs->data[5];
            this->data[6] -= rhs->data[6];
            this->data[7] -= rhs->data[7];
            this->data[8] -= rhs->data[8];
            return *this;
        }

        Matrix3 operator *=(Matrix3 rhs)
        {
            T temp[9];
            memcpy(temp, this->data, sizeof(T)*9);
            //this->data[0] = temp[0]*rhs->data[0]+temp[1]*rhs->data[1]
            //this->data[0] = dotProduct3(temp[0],rhs.data[0],temp[1],rhs.data[3])
        }

    };


    template <class T> class Matrix4 
    {
        public:
        T data[16];

        /*
            0 , 1, 2, 3,
            4 , 5, 6, 7,
            8 , 9,10,11,
            12,13,14,15
        */

        Matrix4()
        {
            this->data = 
            {
                1,0,0,0,
                0,1,0,0,
                0,0,1,0,
                0,0,0,1
            };
        }

        Matrix4 operator +=(Matrix4 rhs)
        {
            this->data[0] += rhs.data[0];
            this->data[1] += rhs.data[1];
            this->data[2] += rhs.data[2];
            this->data[3] += rhs.data[3];
            this->data[4] += rhs.data[4];
            this->data[5] += rhs.data[5];
            this->data[6] += rhs.data[6];
            this->data[7] += rhs.data[7];
            this->data[8] += rhs.data[8];
            this->data[9] += rhs.data[9];
            this->data[10] += rhs.data[10];
            this->data[11] += rhs.data[11];
            this->data[12] += rhs.data[12];
            this->data[13] += rhs.data[13];
            this->data[14] += rhs.data[14];
            this->data[15] += rhs.data[15];
            return *this;
        }

        Matrix4 operator -=(Matrix4 rhs)
        {
            this->data[0] -= rhs->data[0];
            this->data[1] -= rhs->data[1];
            this->data[2] -= rhs->data[2];
            this->data[3] -= rhs->data[3];
            this->data[4] -= rhs->data[4];
            this->data[5] -= rhs->data[5];
            this->data[6] -= rhs->data[6];
            this->data[7] -= rhs->data[7];
            this->data[8] -= rhs->data[8];
            this->data[9] -= rhs->data[9];
            this->data[10] -= rhs->data[10];
            this->data[11] -= rhs->data[11];
            this->data[12] -= rhs->data[12];
            this->data[13] -= rhs->data[13];
            this->data[14] -= rhs->data[14];
            this->data[15] -= rhs->data[15];
            return *this;
        }

        Matrix4 operator *=(Matrix4 rhs)
        {
            return *this;
        }
    };
}