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

#include "gtest.h"
#include "box.h"

TEST(BoxTest, CanBeCreated)
{
    SMath::Box aabb(SMath::Point3(0.0), SMath::Point3(1.0));

    EXPECT_EQ(aabb.m_Min, SMath::Point3(0.0, 0.0, 0.0));
    EXPECT_EQ(aabb.m_Max, SMath::Point3(1.0, 1.0, 1.0));
}

TEST(BoxTest, CanBeCopied)
{
    SMath::Box aabb0(SMath::Point3(0.0), SMath::Point3(1.0));
    SMath::Box aabb(aabb0);

    EXPECT_EQ(aabb.m_Min, SMath::Point3(0.0, 0.0, 0.0));
    EXPECT_EQ(aabb.m_Max, SMath::Point3(1.0, 1.0, 1.0));
}

TEST(BoxTest, CanCheckIfInBounds)
{
    SMath::Box aabb(SMath::Point3(0.0), SMath::Point3(1.0));

    EXPECT_TRUE(aabb.Contains({ 0.0, 0.0, 0.0 }));
    EXPECT_TRUE(aabb.Contains({ 0.0, 1.0, 1.0 }));
    EXPECT_TRUE(aabb.Contains({ 0.0, 0.0, 1.0 }));
    EXPECT_TRUE(aabb.Contains({ 0.5, 0.6, 0.7 }));
    EXPECT_TRUE(aabb.Contains({ 1.0, 1.0, 1.0 }));

    EXPECT_FALSE(aabb.Contains({ 1.0, 1.0, 1.01 }));
    EXPECT_FALSE(aabb.Contains({ 1.01, 1.0, 1.0 }));
    EXPECT_FALSE(aabb.Contains({ 0.01, 0.0, -0.001 }));
}

TEST(BoxTest, CanGetSize)
{
    SMath::Box aabb(SMath::Point3(0.0), SMath::Point3(1.0));
    EXPECT_EQ(aabb.GetSize(), SMath::Vector3(1.0));

    SMath::Box aabb1(SMath::Point3(-1.0), SMath::Point3(1.0));
    EXPECT_EQ(aabb1.GetSize(), SMath::Vector3(2.0));

    SMath::Box aabb2(SMath::Point3(-1.0), SMath::Point3(0.0));
    EXPECT_EQ(aabb2.GetSize(), SMath::Vector3(1.0));

    SMath::Box aabb3(SMath::Point3(-1.0, 0, 0), SMath::Point3(0.0));
    EXPECT_EQ(aabb3.GetSize(), SMath::Vector3(1.0, 0.0, 0.0));
}

TEST(BoxTest, CanGetSurfaceArea)
{
    SMath::Box aabb(SMath::Point3(0.0), SMath::Point3(1.0));
    EXPECT_EQ(aabb.GetSurfaceArea(), 6.0);

    SMath::Box aabb1(SMath::Point3(-1.0), SMath::Point3(1.0));
    EXPECT_EQ(aabb1.GetSurfaceArea(), 24.0);

    SMath::Box aabb2(SMath::Point3(-1.0), SMath::Point3(0.0));
    EXPECT_EQ(aabb2.GetSurfaceArea(), 6.0);

    SMath::Box aabb3(SMath::Point3(-1.0, 0, 0), SMath::Point3(0.0));
    EXPECT_EQ(aabb3.GetSurfaceArea(), 0.0);
}

TEST(BoxTest, CanGetUnion)
{
    SMath::Box box1(SMath::Point3(1.0, 2.0, 3.0), SMath::Point3(4.0, 5.0, 6.0));
    SMath::Box box2(SMath::Point3(2.0, 3.0, 4.0), SMath::Point3(5.0, 6.0, 7.0));

    SMath::Box b1b2Union = SMath::Box<double>::Union(box1, box2);
    EXPECT_EQ(b1b2Union.m_Min, SMath::Point3(1.0, 2.0, 3.0));
    EXPECT_EQ(b1b2Union.m_Max, SMath::Point3(5.0, 6.0, 7.0));

    b1b2Union = SMath::Box<double>::Union(box2, box1);
    EXPECT_EQ(b1b2Union.m_Min, SMath::Point3(1.0, 2.0, 3.0));
    EXPECT_EQ(b1b2Union.m_Max, SMath::Point3(5.0, 6.0, 7.0));
}

