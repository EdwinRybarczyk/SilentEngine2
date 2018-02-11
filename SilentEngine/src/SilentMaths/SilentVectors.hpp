namespace SilentMaths
{
    class vec3f
    {
        public:
        float x,y,z;
        vec3f operator +=(vec3f rhs)
        {
            this->x += rhs.x;
            this->y += rhs.y;
            this->z += rhs.z;
            return *this;
        }
        vec3f operator -=(vec3f rhs)
        {
            this->x -= rhs.x;
            this->y -= rhs.y;
            this->z -= rhs.z;
            return *this;
        }
        vec3f operator *=(vec3f rhs)
        {
            this->x *= rhs.x;
            this->y *= rhs.y;
            this->z *= rhs.z;
            return *this;
        }
        vec3f operator /=(vec3f rhs)
        {
            this->x /= rhs.x;
            this->y /= rhs.y;
            this->z /= rhs.z;
            return *this;
        }
    };

    class vec3i
    {
        public:
        int x,y,z;
        vec3i operator +=(vec3i rhs)
        {
            this->x += rhs.x;
            this->y += rhs.y;
            this->z += rhs.z;
            return *this;
        }
        vec3i operator -=(vec3i rhs)
        {
            this->x -= rhs.x;
            this->y -= rhs.y;
            this->z -= rhs.z;
            return *this;
        }
        vec3i operator *=(vec3i rhs)
        {
            this->x *= rhs.x;
            this->y *= rhs.y;
            this->z *= rhs.z;
            return *this;
        }
        vec3i operator /=(vec3i rhs)
        {
            this->x /= rhs.x;
            this->y /= rhs.y;
            this->z /= rhs.z;
            return *this;
        }
    };

    class vec2f
    {
        public:
        float x,y;
        vec2f operator +=(vec2f rhs)
        {
            this->x += rhs.x;
            this->y += rhs.y;
            return *this;
        }
        vec2f operator -=(vec2f rhs)
        {
            this->x -= rhs.x;
            this->y -= rhs.y;
            return *this;
        }
        vec2f operator *=(vec2f rhs)
        {
            this->x *= rhs.x;
            this->y *= rhs.y;
            return *this;
        }
        vec2f operator /=(vec2f rhs)
        {
            this->x /= rhs.x;
            this->y /= rhs.y;
            return *this;
        }
    };

    class vec2i
    {
        public:
        int x,y;
        vec2i operator +=(vec2i rhs)
        {
            this->x += rhs.x;
            this->y += rhs.y;
            return *this;
        }
        vec2i operator -=(vec2i rhs)
        {
            this->x -= rhs.x;
            this->y -= rhs.y;
            return *this;
        }
        vec2i operator *=(vec2i rhs)
        {
            this->x *= rhs.x;
            this->y *= rhs.y;
            return *this;
        }
        vec2i operator /=(vec2i rhs)
        {
            this->x /= rhs.x;
            this->y /= rhs.y;
            return *this;
        }
    };
}