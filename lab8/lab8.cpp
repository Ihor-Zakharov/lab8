#include <iostream>
#include <vector>
#include <iomanip>

class Vector
{
private:
    size_t size;
    double* arr;

public:
    Vector(std::initializer_list<double> list) : arr(new double[list.size()]), size(list.size())
    {
        std::copy(list.begin(), list.end(), arr); // iterators are being used
    }

    Vector(const Vector& vector) : arr(new double[vector.size]), size(vector.size)
    {
        std::memcpy(arr, vector.arr, size*sizeof(double));
    }

    Vector()
    {
        size = 3;
        arr = new double[3];
        std::cin >> *this;
    }

    ~Vector()
    {
        delete[] arr;
    }

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

void demo1()
{
    auto a = Vector{ 1, 0, 0 };
    auto b = Vector{ 0, 1, 0 };

    std::cout << "Vector a: " << a << std::endl;
    std::cout << "Vector b: " << b << std::endl;
    std::cout << "Vector product a ^ b: " << (a ^ b) << std::endl;

    auto x = Vector{ 1, 1, 1 };
    auto y = x; // implicit copy constructor call

    std::cout << "Vector x = y: " << x << std::endl;

    std::cout << "x * y: " << (x * y) << std::endl;

    std::cout << "euclidian norm a: " << a.getEuclidianNorm() << std::endl;

    std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "2 * x: " << (2 * x) << std::endl;

    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;

    std::cout << "x == y: " << (x == y) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;

    std::cout << "Assign a" << std::endl;

    std::cin >> a;

    std::cout << a << std::endl;
}

void demo2()
{
    std::cout << "Enter first vector coords" << std::endl;
    auto v1 = Vector();
    std::cout << "Enter second vector coords" << std::endl;
    auto v2 = Vector();

    std::cout << "v1 ^ v2: " << (v1 ^ v2) << std::endl;
    std::cout << "v1 * v2: " << (v1 * v2) << std::endl;
    std::cout << "v1 + v2: " << (v1 + v2) << std::endl;
    std::cout << "2 * v2: " << (2 * v2) << std::endl;
    std::cout << "v1 * 2: " << (v1 * 2) << std::endl;

    std::cout << "v1 < v2: " << (v1 < v2) << std::endl;
    std::cout << "v1 <= v2: " << (v1 <= v2) << std::endl;
    std::cout << "v1 > v2: " << (v1 > v2) << std::endl;
    std::cout << "v1 >= v2: " << (v1 >= v2) << std::endl;

    std::cout << "v1 == v2: " << (v1 == v2) << std::endl;
    std::cout << "v1 euclidian norm: " << (v1.getEuclidianNorm()) << std::endl;
}

int main()
{
    demo2();

    return 0;
}
