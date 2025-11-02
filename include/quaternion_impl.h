/*
    This file is part of SMath, an open-source math library for graphics
    applications.

    Copyright (c) 2020-2026 Samuel Huang - All rights reserved.
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

#include <cmath>
#include <cassert>

template<typename T>
Quaternion<T>::Quaternion()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 1;
}

template<typename T>
Quaternion<T>::Quaternion(T v)
{
    this->x = v;
    this->y = v;
    this->z = v;
    this->w = v;
}

template<typename T>
Quaternion<T>::Quaternion(T x, T y, T z, T w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

template<typename T>
Quaternion<T>::Quaternion(const T* data)
{
    this->x = data[0];
    this->y = data[1];
    this->z = data[2];
    this->w = data[3];
}

template<typename T>
Quaternion<T>::Quaternion(const Quaternion& copy)
{
    this->x = copy.x;
    this->y = copy.y;
    this->z = copy.z;
    this->w = copy.w;
}

template<typename T>
Quaternion<T>::Quaternion(const VectorData<T, 4>& data)
{
    this->x = data.x;
    this->y = data.y;
    this->z = data.z;
    this->w = data.w;
}

template<typename T>
Quaternion<T> Quaternion<T>::operator+() const
{
    return *this;
}

template<typename T>
Quaternion<T> Quaternion<T>::operator-() const
{
    return Quaternion(-this->x, -this->y, -this->z, -this->w);
}

template<typename T>
Quaternion<T> Quaternion<T>::operator+(const Quaternion& b) const
{
    return Quaternion(this->x + b.x, this->y + b.y, this->z + b.z, this->w + b.w);
}

template<typename T>
Quaternion<T> Quaternion<T>::operator-(const Quaternion& b) const
{
    return Quaternion(this->x - b.x, this->y - b.y, this->z - b.z, this->w - b.w);
}

template<typename T>
Quaternion<T> Quaternion<T>::operator*(const Quaternion& b) const
{
    // Hamilton product: q1 * q2
    return Quaternion(
        this->w * b.x + this->x * b.w + this->y * b.z - this->z * b.y,
        this->w * b.y - this->x * b.z + this->y * b.w + this->z * b.x,
        this->w * b.z + this->x * b.y - this->y * b.x + this->z * b.w,
        this->w * b.w - this->x * b.x - this->y * b.y - this->z * b.z
    );
}

template<typename T>
Quaternion<T> Quaternion<T>::operator*(T s) const
{
    return Quaternion(this->x * s, this->y * s, this->z * s, this->w * s);
}

template<typename T>
Quaternion<T> Quaternion<T>::operator/(T s) const
{
    assert(s != 0);
    T inv = T(1) / s;
    return Quaternion(this->x * inv, this->y * inv, this->z * inv, this->w * inv);
}

// Assignment operators
template<typename T>
Quaternion<T>& Quaternion<T>::operator+=(const Quaternion& b)
{
    this->x += b.x;
    this->y += b.y;
    this->z += b.z;
    this->w += b.w;
    return *this;
}

template<typename T>
Quaternion<T>& Quaternion<T>::operator-=(const Quaternion& b)
{
    this->x -= b.x;
    this->y -= b.y;
    this->z -= b.z;
    this->w -= b.w;
    return *this;
}

template<typename T>
Quaternion<T>& Quaternion<T>::operator*=(const Quaternion& b)
{
    *this = *this * b;
    return *this;
}

template<typename T>
Quaternion<T>& Quaternion<T>::operator*=(T s)
{
    this->x *= s;
    this->y *= s;
    this->z *= s;
    this->w *= s;
    return *this;
}

template<typename T>
Quaternion<T>& Quaternion<T>::operator/=(T s)
{
    assert(s != 0);
    T inv = T(1) / s;
    this->x *= inv;
    this->y *= inv;
    this->z *= inv;
    this->w *= inv;
    return *this;
}

template<typename T>
bool Quaternion<T>::operator==(const Quaternion& b) const
{
    return this->x == b.x && this->y == b.y && this->z == b.z && this->w == b.w;
}

template<typename T>
bool Quaternion<T>::operator!=(const Quaternion& b) const
{
    return !(*this == b);
}

template<typename T>
T Quaternion<T>::Magnitude() const
{
    return std::sqrt(SquareMagnitude());
}

template<typename T>
T Quaternion<T>::SquareMagnitude() const
{
    return Dot(*this, *this);
}

template<typename T>
void Quaternion<T>::Normalize()
{
    T mag = Magnitude();
    assert(mag != 0);
    T inv = T(1) / mag;
    this->w *= inv;
    this->x *= inv;
    this->y *= inv;
    this->z *= inv;
}

template<typename T>
Quaternion<T> Quaternion<T>::Normalized() const
{
    T mag = Magnitude();
    assert(mag != 0);
    T inv = T(1) / mag;
    return Quaternion(this->x * inv, this->y * inv, this->z * inv, this->w * inv);
}

template<typename T>
Quaternion<T> Quaternion<T>::Conjugate() const
{
    return Quaternion(-this->x, -this->y, -this->z, this->w);
}

template<typename T>
Quaternion<T> Quaternion<T>::Inverse() const
{
    T sqMag = SquareMagnitude();
    assert(sqMag != 0);
    T inv = T(1) / sqMag;
    return Quaternion(-this->x * inv, -this->y * inv, -this->z * inv, this->w * inv);
}

template<typename T>
Vector<T, 3> Quaternion<T>::Rotate(const Vector<T, 3>& v) const
{
    // Use formula: v' = q * v * q^-1
    // More efficient: v' = v + 2 * cross(q.xyz, cross(q.xyz, v) + q.w * v)
    Vector<T, 3> qVec(this->x, this->y, this->z);
    Vector<T, 3> cross1 = Vector<T, 3>::Cross(qVec, v);
    Vector<T, 3> cross2 = Vector<T, 3>::Cross(qVec, cross1 + v * this->w);
    return v + cross2 * T(2);
}

template<typename T>
void Quaternion<T>::ToAxisAngle(Vector<T, 3>& axis, T& angle) const
{
    Quaternion q = *this;

    // Ensure unit quaternion
    if (std::abs(q.SquareMagnitude() - T(1)) > T(1e-6))
        q.Normalize();

    angle = T(2) * std::acos(q.w);

    T s = std::sqrt(T(1) - q.w * q.w);
    if (s < T(1e-6))
    {
        axis = Vector<T, 3>(1, 0, 0);
    }
    else
    {
        axis = Vector<T, 3>(q.x / s, q.y / s, q.z / s);
    }
}

template<typename T>
Vector<T, 3> Quaternion<T>::ToEuler() const
{
    Vector<T, 3> euler;

    T sinr_cosp = T(2) * (this->w * this->x + this->y * this->z);
    T cosr_cosp = T(1) - T(2) * (this->x * this->x + this->y * this->y);
    euler.x = std::atan2(sinr_cosp, cosr_cosp);

    T sinp = T(2) * (this->w * this->y - this->z * this->x);
    if (std::abs(sinp) >= T(1))
        euler.y = std::copysign(T(Pi) / T(2), sinp);
    else
        euler.y = std::asin(sinp);

    T siny_cosp = T(2) * (this->w * this->z + this->x * this->y);
    T cosy_cosp = T(1) - T(2) * (this->y * this->y + this->z * this->z);
    euler.z = std::atan2(siny_cosp, cosy_cosp);

    return euler;
}

template<typename T>
Quaternion<T> Quaternion<T>::FromAxisAngle(const Vector<T, 3>& axis, T angle)
{
    T halfAngle = angle / T(2);
    T s = std::sin(halfAngle);
    Vector<T, 3> normalizedAxis = axis.Normalized();

    return Quaternion(
        normalizedAxis.x * s,
        normalizedAxis.y * s,
        normalizedAxis.z * s,
        std::cos(halfAngle)
    );
}

template<typename T>
Quaternion<T> Quaternion<T>::FromEuler(T pitch, T yaw, T roll)
{
    T cy = std::cos(roll * T(0.5));
    T sy = std::sin(roll * T(0.5));
    T cp = std::cos(yaw * T(0.5));
    T sp = std::sin(yaw * T(0.5));
    T cr = std::cos(pitch * T(0.5));
    T sr = std::sin(pitch * T(0.5));

    return Quaternion(
        sr * cp * cy - cr * sp * sy,
        cr * sp * cy + sr * cp * sy,
        cr * cp * sy - sr * sp * cy,
        cr * cp * cy + sr * sp * sy
    );
}

template<typename T>
Quaternion<T> Quaternion<T>::FromEuler(const Vector<T, 3>& euler)
{
    return FromEuler(euler.x, euler.y, euler.z);
}

template<typename T>
Quaternion<T> Quaternion<T>::Identity()
{
    return Quaternion(T(1), T(0), T(0), T(0));
}

template<typename T>
T Quaternion<T>::Dot(const Quaternion& a, const Quaternion& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

template<typename T>
Quaternion<T> Quaternion<T>::Slerp(const Quaternion& a, const Quaternion& b, T t)
{
    T dot = Dot(a, b);

    // If the dot product is negative, slerp won't take the shorter path
    // We can fix this by reversing one quaternion
    Quaternion end = b;
    if (dot < T(0))
    {
        end = -b;
        dot = -dot;
    }

    // Quaternions are very close, use linear interpolation
    // If this is not done, the math below can create nans/infs
    if (dot > T(0.9995f))
    {
        return Lerp(a, end, t);
    }

    T theta = std::acos(dot);
    T sinTheta = std::sin(theta);
    T wa = std::sin((T(1) - t) * theta) / sinTheta;
    T wb = std::sin(t * theta) / sinTheta;

    return a * wa + end * wb;
}

template<typename T>
Quaternion<T> Quaternion<T>::Lerp(const Quaternion& a, const Quaternion& b, T t)
{
    Quaternion result = a * (T(1) - t) + b * t;
    result.Normalize();
    return result;
}