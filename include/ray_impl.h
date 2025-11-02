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
SMath::Ray<T>::Ray(
    const Point<T, 3>& origin,
    const Vector<T, 3>& direction,
    T tMin,
    T tMax)
    : m_Origin(origin)
    , m_Direction(direction)
    , m_TMin(tMin)
    , m_TMax(tMax)
{
    m_Direction.Normalize();
}

template <typename T>
bool SMath::Ray<T>::operator==(const Ray& r) const
{
    return m_Origin == r.m_Origin && m_Direction == r.m_Direction;
}

template <typename T>
bool SMath::Ray<T>::operator!=(const Ray& r) const
{
    return !(*this == r);
}

