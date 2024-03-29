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

#include "gtest.h"
#include "linalg.h"

TEST(LinearAlgebraTest, CanMultiplyMatricesWithVectors3x3)
{
    SMath::Vector3 a = { 1.0, 1.0, 1.0 };
    SMath::Vector3 b = { 1.3432, 2.942, 4.1231 };
    SMath::Vector3 c = { -1.592, 1.149, -5.234 };
    SMath::Vector3 d = { -1.20, -3.049, 1.38 };
    SMath::Vector3 e = { 0, 0, 0 };
    SMath::Vector3 f = { 99999, 99999, 99998 };

    SMath::Matrix3x3 i = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
    EXPECT_EQ(i * a, a);
    EXPECT_EQ(i * b, b);
    EXPECT_EQ(i * c, c);
    EXPECT_EQ(i * d, d);
    EXPECT_EQ(i * e, e);
    EXPECT_EQ(i * f, f);

    SMath::Matrix3x3 m1 = { 1, 2, 3, -4, -5, -6, 7, 8, 9 };
    EXPECT_EQ(m1 * a, SMath::Vector3(6, -15, 24));
    EXPECT_EQ(m1 * b, SMath::Vector3(19.5965, -44.8214, 70.0463));
    EXPECT_EQ(m1 * c, SMath::Vector3(-14.996, 32.027, -49.058));
    EXPECT_EQ(m1 * d, SMath::Vector3(-3.158, 11.765, -20.372));
    EXPECT_EQ(m1 * e, e);
    EXPECT_EQ(m1 * f, SMath::Vector3(599991, -1499979, 2399967));
}

TEST(LinearAlgebraTest, CanMultiplyMatricesWithVectors4x4)
{
    SMath::Vector4 a = { 1.0, 1.0, 1.0, 1.0 };
    SMath::Vector4 b = { 1.3432, 2.942, 4.1231, 2.235 };
    SMath::Vector4 c = { -1.592, 1.149, -5.234, -4.42 };
    SMath::Vector4 d = { -1.20, -3.049, 1.38, 1.231 };
    SMath::Vector4 e = { 0, 0, 0, 0 };
    SMath::Vector4 f = { 99999, 99999, 99998, -100000 };

    SMath::Matrix4x4 i = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
    EXPECT_EQ(i * a, a);
    EXPECT_EQ(i * b, b);
    EXPECT_EQ(i * c, c);
    EXPECT_EQ(i * d, d);
    EXPECT_EQ(i * e, e);
    EXPECT_EQ(i * f, f);

    SMath::Matrix4x4 m1 = { 1, 2, 3, -4, -5, -6, 7, 8, 9, -10, 11, -12, 13, 14.2, 15, -16.5 };
    EXPECT_EQ(m1 * a, SMath::Vector4(2, 4, -2, 25.7));
    EXPECT_EQ(m1 * b, SMath::Vector4(10.6565, 22.3737, 1.2029, 84.207));
    EXPECT_EQ(m1 * c, SMath::Vector4(2.684, -70.932, -30.352, -9.9602));
    EXPECT_EQ(m1 * d, SMath::Vector4(-8.082, 43.802, 20.098, -58.5073));
    EXPECT_EQ(m1 * e, e);
    EXPECT_EQ(m1 * f, SMath::Vector4(999991, -1200003, 2199979, 5869942.8));
}

TEST(LinearAlgebraTest, CanAddVectorToPoint)
{
    SMath::Point3 a(1.0, 2.0, 3.0);
    SMath::Vector3 b(2.0, 3.0, 4.0);
    SMath::Point3 c = a + b;
    EXPECT_DOUBLE_EQ(c.x, 3.0);
    EXPECT_DOUBLE_EQ(c.y, 5.0);
    EXPECT_DOUBLE_EQ(c.z, 7.0);
}

TEST(LinearAlgebraTest, CanGetVectorBetweenPoints)
{
    SMath::Point3 a(1.0, 2.0, 3.0);
    SMath::Point3 b(2.0, 3.0, 4.0);
    SMath::Vector3 c = a - b;
    EXPECT_DOUBLE_EQ(c.x, -1.0);
    EXPECT_DOUBLE_EQ(c.y, -1.0);
    EXPECT_DOUBLE_EQ(c.z, -1.0);
}

