namespace SilentMaths
{
    class Matrixf
    {
        Matrixf operator +=(Matrixf rhs)
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