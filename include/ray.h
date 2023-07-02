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

#include "linalg.h"

namespace SMath
{
    template <typename T>
    class Ray
    {
    public:
        Ray(const Point<T, 3>& origin = {},
            const Vector<T, 3>& direction = { T(0), T(0), T(1) },
            T tMin = Epsilon,
            T tMax = std::numeric_limits<T>::max());
        ~Ray() = default;

    public:
        inline Point<T, 3> operator()(T t) const { return m_Origin + m_Direction * t; }

    public:
        bool operator==(const Ray& r) const;
        bool operator!=(const Ray& r) const;

    public:
        Point<T, 3> m_Origin;
        Vector<T, 3> m_Direction;

        T m_TMin;
        T m_TMax;
    };

    #include "ray_impl.h"
}
