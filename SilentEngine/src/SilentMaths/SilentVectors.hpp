namespace SilentMaths
{
    template <class T> class Vector3 
    {
        public:
        T x,y,z;
        
        Vector3 operator +=(Vector3 rhs)
        {
            this->x += rhs.x;
            this->y += rhs.y;
            this->z += rhs.z;
            return *this;
        }

        Vector3 operator -=(Vector3 rhs)
        {
            this->x -= rhs.x;
            this->y -= rhs.y;
            this->z -= rhs.z;
            return *this;
        }

        Vector3 operator *=(Vector3 rhs)
        {
            this->x *= rhs.x;
            this->y *= rhs.y;
            this->z *= rhs.z;
            return *this;
        }

        Vector3 operator /=(Vector3 rhs)
        {
            this->x /= rhs.x;
            this->y /= rhs.y;
            this->z /= rhs.z;
            return *this;
        }
    };

    template <class T> class Vector2 
    {
        public:
        T x,y;
        
        Vector2 operator +=(Vector2 rhs)
        {
            this->x += rhs.x;
            this->y += rhs.y;
            return *this;
        }

        Vector2 operator -=(Vector2 rhs)
        {
            this->x -= rhs.x;
            this->y -= rhs.y;
            return *this;
        }

        Vector2 operator *=(Vector2 rhs)
        {
            this->x *= rhs.x;
            this->y *= rhs.y;
            return *this;
        }

        Vector2 operator /=(Vector2 rhs)
        {
            this->x /= rhs.x;
            this->y /= rhs.y;
            return *this;
        }
    };
}