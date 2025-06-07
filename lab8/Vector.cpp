#pragma once
#include "vector.h"

size_t Vector::getSize()
{
    return size;
};

double Vector::getEuclidianNorm() const
{
    double sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i] * arr[i];
    }

    return sqrt(sum);
};

void Vector::assignValue(int index, double value)
{
    if (index < 0 || index >= size)
    {
        throw 505;
        return;
    }

    arr[index] = value;
};

double Vector::operator[](unsigned int index) const
{
    if (index >= size)
    {
        throw 505;
    }

    return arr[index];
};

Vector operator^(const Vector& v1, const Vector& v2)
{
    if (v1.size != 3 || v2.size != 3)
    {
        std::cerr << "Operation is not defined" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    double i = v1[1] * v2[2] - v1[2] * v2[1];
    double j = v2[0] * v1[2] - v1[0] * v2[2];
    double k = v1[0] * v2[1] - v1[1] * v2[0];

    return Vector{ i, j, k };
};

std::ostream& operator<<(std::ostream& out, const Vector& vector)
{
    for (int i = 0; i < vector.size; ++i)
    {
        out << vector[i];

        if (i != vector.size - 1)
        {
            out << ", ";
        }
    }

    return out;
};

std::istream& operator>> (std::istream& is, const Vector& v)
{
    for (int i = 0; i < v.size; i++)
    {
        is >> v.arr[i];
    }

    return is;
}

double operator * (const Vector& v1, const Vector& v2)
{
    if (v1.size != v2.size)
    {
        std::cerr << "Operation is not defined" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    double sum = 0;

    for (int i = 0; i < v1.size; i++)
    {
        sum += v1[i] * v2[i];
    }

    return sum;
};

Vector operator + (const Vector& v1, const Vector& v2)
{
    if (v1.size != v2.size)
    {
        throw 505;
    }

    Vector newVector = v1;

    for (int i = 0; i < v1.size; i++)
    {
        newVector.assignValue(i, v1[i] + v2[i]); // assign value with a[i]
    }

    return newVector;
}

Vector operator * (const Vector& v, double scalar)
{
    Vector newVector = v;

    for (int i = 0; i < v.size; i++)
    {
        newVector.assignValue(i, v[i] * scalar); // assign value with a[i]
    }

    return newVector;
}

Vector operator * (double scalar, const Vector& v)
{
    Vector newVector = v;

    for (int i = 0; i < v.size; i++)
    {
        newVector.assignValue(i, v[i] * scalar); // assign value with a[i]
    }

    return newVector;
}

bool operator <= (const Vector& v1, const Vector& v2)
{
    if (v1.size != v2.size)
    {
        std::cerr << "Operation is not defined" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return v1.getEuclidianNorm() <= v2.getEuclidianNorm();
}

bool operator < (const Vector& v1, const Vector& v2)
{
    if (v1.size != v2.size)
    {
        std::cerr << "Operation is not defined" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return v1.getEuclidianNorm() < v2.getEuclidianNorm();
}

bool operator >= (const Vector& v1, const Vector& v2)
{
    if (v1.size != v2.size)
    {
        std::cerr << "Operation is not defined" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return v1.getEuclidianNorm() >= v2.getEuclidianNorm();
}

bool operator > (const Vector& v1, const Vector& v2)
{
    if (v1.size != v2.size)
    {
        std::cerr << "Operation is not defined" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return v1.getEuclidianNorm() > v2.getEuclidianNorm();
}

bool operator == (const Vector& v1, const Vector& v2)
{
    if (v1.size != v2.size)
    {
        std::cerr << "Operation is not defined" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    for (int i = 0; i < v1.size; i++)
    {
        if (v1[i] != v2[i])
        {
            return false;
        }
    }

    return true;
}
