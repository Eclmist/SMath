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
        Ray(const Point<T, 3>& origin = { T(0) }, const Vector<T, 3>& direction = { T(1) });
        ~Ray() = default;

    public:
        inline Point<T, 3> operator()(T t) const { return m_Origin + m_Direction * t; }

        inline Point<T, 3> GetOrigin() const { return m_Origin; }
        inline Vector<T, 3> GetDirection() const { return m_Direction; }

        inline void SetOrigin(Point<T, 3> origin) { m_Origin = origin; }
        inline void SetDirection(Vector<T, 3> direction) { m_Direction = direction.Normalized(); }

    public:
        bool operator==(const Ray& r) const;
        bool operator!=(const Ray& r) const;

    private:
        Point<T, 3> m_Origin;
        Vector<T, 3> m_Direction;
    };

    #include "ray_impl.h"
}
