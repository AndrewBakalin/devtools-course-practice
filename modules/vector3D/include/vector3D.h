// Copyright 2017 Zorina Ekaterina

#ifndef __VECTOR3D_H__
#define __VECTOR3D_H__

#include <iostream>
#include <cmath>
using namespace std;

// ������ � ��������� ������������
class Vector3D {
protected:
    double x;
    double y;
    double z;
public:
    Vector3D(double _x = 0.0, double _y = 0.0, double _z = 0.0);
    Vector3D(const Vector3D &v);                // ����������� �����������
    double GetX() const { return x; };            // ������
    double GetY() const { return y; };
    double GetZ() const { return z; };

    bool operator==(const Vector3D &v) const;  // ���������
    bool operator!=(const Vector3D &v) const;  // ���������
    bool IsCloseTo(const Vector3D &v) const;    // ����������� ���������
                                                // ��� �������� ����������
    Vector3D& operator=(const Vector3D &v);     // ������������

                                              // ��������� ��������
    Vector3D  operator+(const Vector3D &v);     // ��������
    Vector3D  operator-(const Vector3D &v);     // ���������
    double Norm();                        // ����� �������
    Vector3D Normalize();                // ������������ �������
    double  operator*(const Vector3D &v);     // ��������� ������������
    Vector3D  operator^(const Vector3D &v);    // ��������� ������-� v(v1, v2)

                                              // ����-�����
    friend istream& operator>>(istream &in, Vector3D &v) {
        in >> v.x >> v.y >> v.z;

        return in;
    }
    friend ostream& operator<<(ostream &out, const Vector3D &v) {
        out << "(" << v.x << ", " << v.y << ", " << v.z << ")" << endl;

        return out;
    }
};


#endif
