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

template<typename T>
Box<T>::Box(const Point<T, 3>& min, const Point<T, 3>& max)
    : m_Min(min)
    , m_Max(max)
{
}

template<typename T>
bool Box<T>::Contains(const Point<T, 3>& point) const
{
    if (point.x < m_Min.x || point.x > m_Max.x)
        return false;
    if (point.y < m_Min.y || point.y > m_Max.y)
        return false;
    if (point.z < m_Min.z || point.z > m_Max.z)
        return false;

    return true;
}

template<typename T>
Vector<T, 3> Box<T>::GetSize() const
{
    return m_Max - m_Min;
}

template<typename T>
T Box<T>::GetSurfaceArea() const
{
    T width = m_Max.x - m_Min.x;
    T height = m_Max.y - m_Min.y;
    T depth = m_Max.z - m_Min.z;

    return width * height * 2 +
           width * depth * 2 +
           height * depth * 2;
}

template<typename T>
Box<T> Box<T>::Union(const Box& a, const Box& b)
{
    T minX, minY, minZ;
    T maxX, maxY, maxZ;

    minX = std::min(a.m_Min.x, b.m_Min.x);
    minY = std::min(a.m_Min.y, b.m_Min.y);
    minZ = std::min(a.m_Min.z, b.m_Min.z);

    maxX = std::max(a.m_Max.x, b.m_Max.x);
    maxY = std::max(a.m_Max.y, b.m_Max.y);
    maxZ = std::max(a.m_Max.z, b.m_Max.z);

    return { Point<T, 3>(minX, minY, minZ), Point<T, 3>(maxX, maxY, maxZ) };
}

