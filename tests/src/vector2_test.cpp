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

TEST(Vector2Test, CanBeCreated)
{
    ASSERT_NO_THROW(SMath::Vector2 v);
}

TEST(Vector2Test, DefaultsToZeroVector)
{
    SMath::Vector2 v;
    EXPECT_DOUBLE_EQ(v.x, 0.0);
    EXPECT_DOUBLE_EQ(v.y, 0.0);
}

TEST(Vector2Test, CanBeCreatedScalar)
{
    SMath::Vector2 v(22.0);
    EXPECT_DOUBLE_EQ(v.x, 22.0);
    EXPECT_DOUBLE_EQ(v.y, 22.0);
}

TEST(Vector2Test, CanBeCreatedPerComponent)
{
    SMath::Vector2 v(1.0, 2.0);
    EXPECT_DOUBLE_EQ(v.x, 1.0);
    EXPECT_DOUBLE_EQ(v.y, 2.0);
}

TEST(Vector2Test, CanBeSetPerComponents)
{
    SMath::Vector2 v;
    v.x = 1.0;
    v.y = 2.0;

    EXPECT_DOUBLE_EQ(v.x, 1.0);
    EXPECT_DOUBLE_EQ(v.y, 2.0);
}

TEST(Vector2Test, CanBeAccessedPerComponent)
{
    SMath::Vector2 v(1.0, 2.0);

    EXPECT_DOUBLE_EQ(v[0], 1.0);
    EXPECT_DOUBLE_EQ(v[1], 2.0);
    EXPECT_DOUBLE_EQ(v.x, 1.0);
    EXPECT_DOUBLE_EQ(v.y, 2.0);
}

TEST(Vector2Test, CanBeCopyConstructed)
{
    SMath::Vector2 a(22.0);
    SMath::Vector2 b(a);

    EXPECT_DOUBLE_EQ(b.x, 22.0);
    EXPECT_DOUBLE_EQ(b.y, 22.0);

    b.x = 0.0;
    EXPECT_DOUBLE_EQ(a.x, 22.0);
}

TEST(Vector2Test, CanBeCopied)
{
    SMath::Vector2 a(22.0);
    SMath::Vector2 b = a;

    EXPECT_DOUBLE_EQ(b.x, 22.0);
    EXPECT_DOUBLE_EQ(b.y, 22.0);

    b.x = 0.0;
    EXPECT_DOUBLE_EQ(a.x, 22.0);
}

TEST(Vector2Test, CanCheckEquality)
{
    EXPECT_EQ(SMath::Vector2(1.0), SMath::Vector2(1.0));
    EXPECT_EQ(SMath::Vector2(0.2), SMath::Vector2(0.2));
    EXPECT_EQ(SMath::Vector2(1.0, 2.0), SMath::Vector2(1.0, 2.0));
    EXPECT_NE(SMath::Vector2(0.0), SMath::Vector2(1.0));
    EXPECT_NE(SMath::Vector2(0.0), SMath::Vector2(0.00001));
    EXPECT_NE(SMath::Vector2(0.0, 1.0), SMath::Vector2(0.1, 1.0));
}

TEST(Vector2Test, CanBeAdded)
{
    SMath::Vector2 a(1.0, 2.0);
    SMath::Vector2 b(2.0, 3.0);

    SMath::Vector2 c = a + b;
    EXPECT_DOUBLE_EQ(c.x, 3.0);
    EXPECT_DOUBLE_EQ(c.y, 5.0);
}

TEST(Vector2Test, CanBeAddAssigned)
{
    SMath::Vector2 a(1.0, 2.0);
    SMath::Vector2 b(2.0, 3.0);
    b += a;

    EXPECT_DOUBLE_EQ(b.x, 3.0);
    EXPECT_DOUBLE_EQ(b.y, 5.0);
}

TEST(Vector2Test, CanBeSubtracted)
{
    SMath::Vector2 a(1.0, 2.0);
    SMath::Vector2 b(2.0, 3.0);

    SMath::Vector2 c = a - b;
    EXPECT_DOUBLE_EQ(c.x, -1.0);
    EXPECT_DOUBLE_EQ(c.y, -1.0);
}

TEST(Vector2Test, CanBeSubtractAssigned)
{
    SMath::Vector2 a(1.0, 2.0);
    SMath::Vector2 b(2.0, 3.0);
    b -= a;

    EXPECT_DOUBLE_EQ(b.x, 1.0);
    EXPECT_DOUBLE_EQ(b.y, 1.0);
}

TEST(Vector2Test, CanBeMultipled)
{
    EXPECT_EQ(SMath::Vector2(1.0) * 2.0, SMath::Vector2(2.0));
    EXPECT_EQ(SMath::Vector2(1.0, 2.0) * 2.0, SMath::Vector2(2.0, 4.0));
}

TEST(Vector2Test, CanBeMultiplyAssigned)
{
    SMath::Vector2 a(1.0, 2.0);
    a *= {1.0, 0.5};
    EXPECT_EQ(a, SMath::Vector2(1.0, 1.0));
    a *= 2.0;
    EXPECT_EQ(a, SMath::Vector2(2.0, 2.0));
    a *= -1.0;
    EXPECT_EQ(a, -SMath::Vector2(2.0, 2.0));
    a *= 0.0;
    EXPECT_EQ(a, SMath::Vector2(0.0));
}

TEST(Vector2Test, CanBeDivided)
{
    EXPECT_EQ(SMath::Vector2(1.0) / 2.0, SMath::Vector2(0.5));
    EXPECT_EQ(SMath::Vector2(1.0, 2.0) / 2.0, SMath::Vector2(0.5, 1.0));
}

TEST(Vector2Test, CanBeDivideAssigned)
{
    SMath::Vector2 a(1.0, 2.0);
    a /= {1.0, 0.5};
    EXPECT_EQ(a, SMath::Vector2(1.0, 4.0));
    a /= 2.0;
    EXPECT_EQ(a, SMath::Vector2(0.5, 2.0));
    a /= -1.0;
    EXPECT_EQ(a, -SMath::Vector2(0.5, 2.0));
}

TEST(Vector2Test, CanBeNegated)
{
    SMath::Vector2 a(-1.0);
    SMath::Vector2 b = -a;
    EXPECT_DOUBLE_EQ(b.x, 1.0);
    EXPECT_DOUBLE_EQ(b.y, 1.0);
}

TEST(Vector2Test, DoesNotChangeWithPveSign)
{
    SMath::Vector2 a(-1.0);
    SMath::Vector2 b = +a;
    EXPECT_DOUBLE_EQ(b.x, -1.0);
    EXPECT_DOUBLE_EQ(b.y, -1.0);
}

TEST(Vector2Test, CanComputeMagnitude)
{
    SMath::Vector2 a(1.0, 2.0);
    SMath::Vector2 b(1.0, 0.0);
    SMath::Vector2 c(0.0, 2.0);
    SMath::Vector2 d(0.0, 3.0);

    EXPECT_DOUBLE_EQ(a.Magnitude(), std::sqrt(5.0));
    EXPECT_DOUBLE_EQ(b.Magnitude(), 1.0);
    EXPECT_DOUBLE_EQ(c.Magnitude(), 2.0);
    EXPECT_DOUBLE_EQ(d.Magnitude(), 3.0);
}

TEST(Vector2Test, CanComputeSquareMagnitude)
{
    SMath::Vector2 a(1.0, 2.0);
    SMath::Vector2 b(1.0, 0.0);
    SMath::Vector2 c(0.0, 2.0);
    SMath::Vector2 d(0.0, 3.0);

    EXPECT_DOUBLE_EQ(a.SquareMagnitude(), 5.0);
    EXPECT_DOUBLE_EQ(b.SquareMagnitude(), 1.0);
    EXPECT_DOUBLE_EQ(c.SquareMagnitude(), 4.0);
    EXPECT_DOUBLE_EQ(d.SquareMagnitude(), 9.0);
}

TEST(Vector2Test, CanBeNormalized)
{
    SMath::Vector2 b(1.1, 0.0);
    SMath::Vector2 c(0.0, 2.0);
    EXPECT_EQ(b.Normalized(), SMath::Vector2(1.0, 0.0));
    EXPECT_EQ(c.Normalized(), SMath::Vector2(0.0, 1.0));
    EXPECT_NE(b, SMath::Vector2(1.0, 0.0));
    EXPECT_NE(c, SMath::Vector2(0.0, 1.0));

    b.Normalize();
    c.Normalize();
    EXPECT_EQ(b, SMath::Vector2(1.0, 0.0));
    EXPECT_EQ(c, SMath::Vector2(0.0, 1.0));

    SMath::Vector2 a(2.0, 2.0);
    a.Normalize();
    EXPECT_DOUBLE_EQ(a.x, 0.70710678118654746);
    EXPECT_DOUBLE_EQ(a.y, 0.70710678118654746);
}

TEST(Vector2Test, CanComputeDotProduct)
{
    EXPECT_DOUBLE_EQ(SMath::Vector2::Dot({ 1.0 }, { 2.0 }), 4.0);
    EXPECT_DOUBLE_EQ(SMath::Vector2::Dot({ 1.0, 2.0 }, { 2.0, 2.0 }), 6.0);
    EXPECT_DOUBLE_EQ(SMath::Vector2::Dot({ -1.0 }, { 2.0 }), -4.0 );
    EXPECT_DOUBLE_EQ(SMath::Vector2::Dot({ 1.0, 0.0 }, { 0.0, 1.0 }), 0.0);
    EXPECT_DOUBLE_EQ(SMath::Vector2::AbsDot({ -1.0 }, { 2.0 }), 4.0);
    EXPECT_DOUBLE_EQ(SMath::Vector2::AbsDot({ 1.0 }, { 2.0 }), 4.0);
}

