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

TEST(Normal3Test, CanBeCreated)
{
    ASSERT_NO_THROW(SMath::Normal3 v);
}

TEST(Normal3Test, DefaultsToZeroNormal)
{
    SMath::Normal3 v;
    EXPECT_DOUBLE_EQ(v.x, 0.0);
    EXPECT_DOUBLE_EQ(v.y, 0.0);
    EXPECT_DOUBLE_EQ(v.z, 0.0);
}

TEST(Normal3Test, CanBeCreatedScalar)
{
    SMath::Normal3 v(22.0);
    EXPECT_DOUBLE_EQ(v.x, 22.0);
    EXPECT_DOUBLE_EQ(v.y, 22.0);
    EXPECT_DOUBLE_EQ(v.z, 22.0);
}

TEST(Normal3Test, CanBeCreatedPerComponent)
{
    SMath::Normal3 v(1.0, 2.0, 3.0);
    EXPECT_DOUBLE_EQ(v.x, 1.0);
    EXPECT_DOUBLE_EQ(v.y, 2.0);
    EXPECT_DOUBLE_EQ(v.z, 3.0);
}

TEST(Normal3Test, CanBeSetPerComponents)
{
    SMath::Normal3 v;
    v.x = 1.0;
    v.y = 2.0;
    v.z = 3.0;

    EXPECT_DOUBLE_EQ(v.x, 1.0);
    EXPECT_DOUBLE_EQ(v.y, 2.0);
    EXPECT_DOUBLE_EQ(v.z, 3.0);
}

TEST(Normal3Test, CanBeAccessedPerComponent)
{
    SMath::Normal3 v(1.0, 2.0, 3.0);

    EXPECT_DOUBLE_EQ(v[0], 1.0);
    EXPECT_DOUBLE_EQ(v[1], 2.0);
    EXPECT_DOUBLE_EQ(v[2], 3.0);
    EXPECT_DOUBLE_EQ(v.x, 1.0);
    EXPECT_DOUBLE_EQ(v.y, 2.0);
    EXPECT_DOUBLE_EQ(v.z, 3.0);
}

TEST(Normal3Test, CanBeCopyConstructed)
{
    SMath::Normal3 a(22.0);
    SMath::Normal3 b(a);

    EXPECT_DOUBLE_EQ(b.x, 22.0);
    EXPECT_DOUBLE_EQ(b.y, 22.0);
    EXPECT_DOUBLE_EQ(b.z, 22.0);

    b.x = 0.0;
    EXPECT_DOUBLE_EQ(a.x, 22.0);
}

TEST(Normal3Test, CanBeCopied)
{
    SMath::Normal3 a(22.0);
    SMath::Normal3 b = a;

    EXPECT_DOUBLE_EQ(b.x, 22.0);
    EXPECT_DOUBLE_EQ(b.y, 22.0);
    EXPECT_DOUBLE_EQ(b.z, 22.0);

    b.x = 0.0;
    EXPECT_DOUBLE_EQ(a.x, 22.0);
}

TEST(Normal3Test, CanCheckEquality)
{
    EXPECT_EQ(SMath::Normal3(1.0), SMath::Normal3(1.0));
    EXPECT_EQ(SMath::Normal3(0.2), SMath::Normal3(0.2));
    EXPECT_EQ(SMath::Normal3(1.0, 2.0, 3.0), SMath::Normal3(1.0, 2.0, 3.0));
    EXPECT_NE(SMath::Normal3(0.0), SMath::Normal3(1.0));
    EXPECT_NE(SMath::Normal3(0.0), SMath::Normal3(0.00001));
    EXPECT_NE(SMath::Normal3(0.0, 1.0, 2.0), SMath::Normal3(0.0, 1.0, 2.1));
}

TEST(Normal3Test, CanBeAddAssigned)
{
    SMath::Normal3 a(1.0, 2.0, 3.0);
    SMath::Normal3 b(2.0, 3.0, 4.0);
    b += a;

    EXPECT_DOUBLE_EQ(b.x, 3.0);
    EXPECT_DOUBLE_EQ(b.y, 5.0);
    EXPECT_DOUBLE_EQ(b.z, 7.0);
}

TEST(Normal3Test, CanBeSubtractAssigned)
{
    SMath::Normal3 a(1.0, 2.0, 3.0);
    SMath::Normal3 b(2.0, 3.0, 4.0);
    b -= a;

    EXPECT_DOUBLE_EQ(b.x, 1.0);
    EXPECT_DOUBLE_EQ(b.y, 1.0);
    EXPECT_DOUBLE_EQ(b.z, 1.0);
}

TEST(Normal3Test, CanBeMultipled)
{
    EXPECT_EQ(SMath::Normal3(1.0) * 2.0, SMath::Normal3(2.0));
    EXPECT_EQ(SMath::Normal3(1.0, 2.0, 3.0) * 2.0, SMath::Normal3(2.0, 4.0, 6.0));
}

TEST(Normal3Test, CanBeMultiplyAssigned)
{
    SMath::Normal3 a(1.0, 2.0, 3.0);
    a *= {1.0, 0.5, 0.5};
    EXPECT_EQ(a, SMath::Normal3(1.0, 1.0, 1.5));
    a *= 2.0;
    EXPECT_EQ(a, SMath::Normal3(2.0, 2.0, 3.0));
    a *= -1.0;
    EXPECT_EQ(a, -SMath::Normal3(2.0, 2.0, 3.0));
    a *= 0.0;
    EXPECT_EQ(a, SMath::Normal3(0.0));
}

TEST(Normal3Test, CanBeDivided)
{
    EXPECT_EQ(SMath::Normal3(1.0) / 2.0, SMath::Normal3(0.5));
    EXPECT_EQ(SMath::Normal3(1.0, 2.0, 3.0) / 2.0, SMath::Normal3(0.5, 1.0, 1.5));
}

TEST(Normal3Test, CanBeDivideAssigned)
{
    SMath::Normal3 a(1.0, 2.0, 3.0);
    a /= {1.0, 0.5, 0.5};
    EXPECT_EQ(a, SMath::Normal3(1.0, 4.0, 6.0));
    a /= 2.0;
    EXPECT_EQ(a, SMath::Normal3(0.5, 2.0, 3.0));
    a /= -1.0;
    EXPECT_EQ(a, -SMath::Normal3(0.5, 2.0, 3.0));
}

TEST(Normal3Test, CanBeNegated)
{
    SMath::Normal3 a(-1.0);
    SMath::Normal3 b = (SMath::Normal3)(-a);
    EXPECT_DOUBLE_EQ(b.x, 1.0);
    EXPECT_DOUBLE_EQ(b.y, 1.0);
    EXPECT_DOUBLE_EQ(b.z, 1.0);
}

TEST(Normal3Test, DoesNotChangeWithPveSign)
{
    SMath::Normal3 a(-1.0);
    SMath::Normal3 b = +a;
    EXPECT_DOUBLE_EQ(b.x, -1.0);
    EXPECT_DOUBLE_EQ(b.y, -1.0);
    EXPECT_DOUBLE_EQ(b.z, -1.0);
}

TEST(Normal3Test, CanComputeMagnitude)
{
    SMath::Normal3 a(1.0, 2.0, 3.0);
    SMath::Normal3 b(1.0, 0.0, 0.0);
    SMath::Normal3 c(0.0, 2.0, 0.0);
    SMath::Normal3 d(0.0, 0.0, 3.0);

    EXPECT_DOUBLE_EQ(a.Magnitude(), std::sqrt(14.0));
    EXPECT_DOUBLE_EQ(b.Magnitude(), 1.0);
    EXPECT_DOUBLE_EQ(c.Magnitude(), 2.0);
    EXPECT_DOUBLE_EQ(d.Magnitude(), 3.0);
}

TEST(Normal3Test, CanComputeSquareMagnitude)
{
    SMath::Normal3 a(1.0, 2.0, 3.0);
    SMath::Normal3 b(1.0, 0.0, 0.0);
    SMath::Normal3 c(0.0, 2.0, 0.0);
    SMath::Normal3 d(0.0, 0.0, 3.0);

    EXPECT_DOUBLE_EQ(a.SquareMagnitude(), 14.0);
    EXPECT_DOUBLE_EQ(b.SquareMagnitude(), 1.0);
    EXPECT_DOUBLE_EQ(c.SquareMagnitude(), 4.0);
    EXPECT_DOUBLE_EQ(d.SquareMagnitude(), 9.0);
}

TEST(Normal3Test, CanBeNormalized)
{
    SMath::Normal3 b(1.1, 0.0, 0.0);
    SMath::Normal3 c(0.0, 2.0, 0.0);
    SMath::Normal3 d(0.0, 0.0, -3.0);
    EXPECT_EQ(b.Normalized(), SMath::Normal3(1.0, 0.0, 0.0));
    EXPECT_EQ(c.Normalized(), SMath::Normal3(0.0, 1.0, 0.0));
    EXPECT_EQ(d.Normalized(), SMath::Normal3(0.0, 0.0, -1.0));
    EXPECT_NE(b, SMath::Normal3(1.0, 0.0, 0.0));
    EXPECT_NE(c, SMath::Normal3(0.0, 1.0, 0.0));
    EXPECT_NE(d, SMath::Normal3(0.0, 0.0, -1.0));

    b.Normalize();
    c.Normalize();
    d.Normalize();
    EXPECT_EQ(b, SMath::Normal3(1.0, 0.0, 0.0));
    EXPECT_EQ(c, SMath::Normal3(0.0, 1.0, 0.0));
    EXPECT_EQ(d, SMath::Normal3(0.0, 0.0, -1.0));

    SMath::Normal3 a(2.0, 2.0, 3.0);
    a.Normalize();
    EXPECT_DOUBLE_EQ(a.x, 0.48507125007266594);
    EXPECT_DOUBLE_EQ(a.y, 0.48507125007266594);
    EXPECT_DOUBLE_EQ(a.z, 0.7276068751089989);
}

TEST(Normal3Test, CanComputeDotProduct)
{
    EXPECT_DOUBLE_EQ(SMath::Normal3::Dot({ 1.0 }, { 2.0 }), 6.0);
    EXPECT_DOUBLE_EQ(SMath::Normal3::Dot({ 1.0, 2.0, 3.0 }, { 2.0, 2.0, 1.0 }), 9.0);
    EXPECT_DOUBLE_EQ(SMath::Normal3::Dot({ -1.0 }, { 2.0 }), -6.0);
    EXPECT_DOUBLE_EQ(SMath::Normal3::Dot({ 1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }), 0.0);
    EXPECT_DOUBLE_EQ(SMath::Normal3::AbsDot({ -1.0 }, { 2.0 }), 6.0);
    EXPECT_DOUBLE_EQ(SMath::Normal3::AbsDot({ 1.0 }, { 2.0 }), 6.0);
}

TEST(Normal3Test, CanComputeAngle)
{
    EXPECT_DOUBLE_EQ(SMath::Normal3::Angle({ 1.0 }, { 1.0 }), 0.0);
    EXPECT_DOUBLE_EQ(SMath::Normal3::Angle({ 1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }), 1.5707963267948966);
    EXPECT_DOUBLE_EQ(SMath::Normal3::Angle({ 2.0, 3.0, 4.0 }, { 5.0, 6.0, 7.0 }), 0.1304771607247695);
}

TEST(Normal3Test, CanComputeCrossProduct)
{
    EXPECT_EQ(SMath::Normal3::Cross({ 1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }), SMath::Normal3(0.0, 0.0, 1.0));
    EXPECT_EQ(SMath::Normal3::Cross({ 1.0, 2.0, 3.0 }, { 2.0, 1.0, 0.0 }), SMath::Normal3(-3.0, 6.0, -3.0));
    EXPECT_EQ(SMath::Normal3::Cross({ -1.0, 2.0, 3.0 }, { 5.0, 1.0, 4.0 }), SMath::Normal3(5.0, 19.0, -11.0));
}

