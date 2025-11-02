/*
    This file is part of SMath, an open-source math library for graphics
    applications.

    Copyright (c) 2020-2026 Samuel Huang - All rights reserved.

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

template <typename T>
SMath::Matrix<T, 4> SMath::Transform<T>::GetTranslationMatrix(const Vector<T, 3>& translation)
{
    return { 1, 0, 0, translation.x,
             0, 1, 0, translation.y,
             0, 0, 1, translation.z,
             0, 0, 0, 1 };
}

template <typename T>
SMath::Matrix<T, 4> SMath::Transform<T>::GetScaleMatrix(const Vector<T, 3>& scale)
{
    return { scale.x, 0, 0, 0,
             0, scale.y, 0, 0,
             0, 0, scale.z, 0,
             0, 0, 0, 1 };
}

template <typename T>
SMath::Matrix<T, 4> SMath::Transform<T>::GetRotationMatrix(const Quaternion<T>& rotation)
{
    const double x2 = rotation.x + rotation.x;
    const double y2 = rotation.y + rotation.y;
    const double z2 = rotation.z + rotation.z;
    const double xx = rotation.x * x2;
    const double yy = rotation.y * y2;
    const double zz = rotation.z * z2;
    const double xy = rotation.x * y2;
    const double xz = rotation.x * z2;
    const double yz = rotation.y * z2;
    const double wx = rotation.w * x2;
    const double wy = rotation.w * y2;
    const double wz = rotation.w * z2;

    SMath::Matrix<T, 4> out;
    out.m_Data2D[0][0] = 1.0f - (yy + zz);
    out.m_Data2D[0][1] = xy - wz;
    out.m_Data2D[0][2] = xz + wy;
    out.m_Data2D[0][3] = 0.0f;

    out.m_Data2D[1][0] = xy + wz;
    out.m_Data2D[1][1] = 1.0f - (xx + zz);
    out.m_Data2D[1][2] = yz - wx;
    out.m_Data2D[1][3] = 0.0f;

    out.m_Data2D[2][0] = xz - wy;
    out.m_Data2D[2][1] = yz + wx;
    out.m_Data2D[2][2] = 1.0f - (xx + yy);
    out.m_Data2D[2][3] = 0.0f;

    out.m_Data2D[3][0] = 0.0f;
    out.m_Data2D[3][1] = 0.0f;
    out.m_Data2D[3][2] = 0.0f;
    out.m_Data2D[3][3] = 1.0f;

    return out;
}

template <typename T>
SMath::Matrix<T, 4> SMath::Transform<T>::GetPerspectiveMatrixLH(T fovy, T aspect, T znear, T zfar)
{
    T f = 1.0 / tan(fovy / 2.0);

    Matrix<T, 4> projection;
    projection.m_Data2D[0][0] = f / aspect;
    projection.m_Data2D[1][1] = f;
    projection.m_Data2D[2][2] = zfar / (zfar - znear);
    projection.m_Data2D[3][2] = 1.0;
    projection.m_Data2D[2][3] = -znear * zfar / (zfar - znear);
    projection.m_Data2D[3][3] = 0.0;

    return projection;
}

template <typename T>
SMath::Matrix<T, 4> SMath::Transform<T>::GetPerspectiveMatrixRH(T fovy, T aspect, T znear, T zfar)
{
    T f = 1.0 / tan(fovy / 2.0);

    Matrix<T, 4> projection;
    projection.m_Data2D[0][0] = f / aspect;
    projection.m_Data2D[1][1] = f;
    projection.m_Data2D[2][2] = zfar / (znear - zfar);
    projection.m_Data2D[3][2] = -1.0;
    projection.m_Data2D[2][3] = znear * zfar / (znear - zfar);
    projection.m_Data2D[3][3] = 0.0;

    return projection;
}

