/*
    This file is part of SMath, an open-source math library for graphics
    applications.

    Copyright (c) 2020-2023 Samuel Van Allen - All rights reserved.
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
    template<typename T>
    class Box
    {
    public:
        Box(const Point<T, 3>& min, const Point<T, 3>& max);
        ~Box() = default;

    public:
        bool Contains(const Point<T, 3>& point) const;
        Vector<T, 3> GetSize() const;
        T GetSurfaceArea() const;

    public:
        static Box Union(const Box& a, const Box& b);

    public:
        Point<T, 3> m_Min;
        Point<T, 3> m_Max;
    };

    #include "box_impl.h" 
}

