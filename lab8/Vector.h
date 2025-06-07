#pragma once

class Vector
{
private:
    size_t size;
    double* arr;

public:
    Vector(std::initializer_list<double> list);

    Vector(const Vector& vector);

    Vector();

    size_t getSize();
    double getEuclidianNorm() const;
    void assignValue(int index, double value);

    double operator [] (const unsigned int index) const;
    friend Vector operator ^ (const Vector&, const Vector&);
    friend double operator * (const Vector& , const Vector&);
    friend std::ostream& operator<<(std::ostream& out, const Vector& vector);
    friend Vector operator + (const Vector& v1, const Vector& v2);
    friend Vector operator * (const Vector& v, double scalar);
    friend Vector operator * (double scalar, const Vector& v);

    friend bool operator <= (const Vector& v1, const Vector& v2);
    friend bool operator < (const Vector& v1, const Vector& v2);
    friend bool operator > (const Vector& v1, const Vector& v2);
    friend bool operator >= (const Vector& v1, const Vector& v2);

    friend bool operator == (const Vector& v1, const Vector& v2);

    friend std::istream& operator >> (std::istream& is, const Vector& v);
};
