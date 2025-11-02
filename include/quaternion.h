/*
    This file is part of SMath, an open-source math library for graphics
    applications.

    Copyright (c) 2020-2023 Samuel Van Allen - All rights reserved.

    Spectre is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "vectordata.h"

namespace SMath
{
    template<typename T = double>
    class Quaternion : public VectorData<T, 4>
    {
        static_assert(std::is_arithmetic_v<T>, "Quaternion only works with arithmetic types");
        static_assert(std::is_floating_point_v<T>, "Quaternion only works with floating types");

    public:
        Quaternion();
        Quaternion(T v);
        Quaternion(T x, T y, T z, T w = 1.0);
        Quaternion(const T* data);
        Quaternion(const Quaternion& copy);
        Quaternion(const VectorData<T, 4>& data);

        Quaternion operator+() const;
        Quaternion operator-() const;

        Quaternion operator+(const Quaternion& b) const;
        Quaternion operator-(const Quaternion& b) const;
        Quaternion operator*(const Quaternion& b) const;

        Quaternion operator*(T s) const;
        Quaternion operator/(T s) const;

        Quaternion& operator+=(const Quaternion& b);
        Quaternion& operator-=(const Quaternion& b);
        Quaternion& operator*=(const Quaternion& b);
        Quaternion& operator*=(T s);
        Quaternion& operator/=(T s);

        bool operator==(const Quaternion& b) const;
        bool operator!=(const Quaternion& b) const;

        inline T operator[](int i) const { return this->m_Data[i]; }
        inline T& operator[](int i) { return this->m_Data[i]; }

    public:
        T Magnitude() const;
        T SquareMagnitude() const;
        void Normalize();
        Quaternion Normalized() const;
        Quaternion Conjugate() const;
        Quaternion Inverse() const;

        Vector<T, 3> Rotate(const Vector<T, 3>& v) const;
        void ToAxisAngle(Vector<T, 3>& axis, T& angle) const;
        Vector<T, 3> ToEuler() const;

    public:
        static Quaternion FromAxisAngle(const Vector<T, 3>& axis, T angle);
        static Quaternion FromEuler(T pitch, T yaw, T roll);
        static Quaternion FromEuler(const Vector<T, 3>& euler);
        static Quaternion Identity();

        static T Dot(const Quaternion& a, const Quaternion& b);
        static Quaternion Slerp(const Quaternion& a, const Quaternion& b, T t);
        static Quaternion Lerp(const Quaternion& a, const Quaternion& b, T t);
    };

    #include "quaternion_impl.h" 
}

