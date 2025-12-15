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
#include "linalg.h"

TEST(QuaternionTest, CanBeCreated)
{
    ASSERT_NO_THROW(SMath::Quaternion<double> q);
}

TEST(QuaternionTest, CanCheckIfIdentity)
{
    EXPECT_FALSE(SMath::Quaternion<double>(1, 0, 0, 0).IsIdentity());
    EXPECT_FALSE(SMath::Quaternion<double>(1, 1, 1, 0).IsIdentity());
    EXPECT_FALSE(SMath::Quaternion<double>(2, 0, 0, 0).IsIdentity());
    EXPECT_FALSE(SMath::Quaternion<double>(1, 0, 0, 0).IsIdentity());
    EXPECT_FALSE(SMath::Quaternion<double>(0, 0, 0, 0).IsIdentity());
    EXPECT_FALSE(SMath::Quaternion<double>(-1, 0, 0, 0).IsIdentity());
    EXPECT_FALSE(SMath::Quaternion<double>(0, 0, 0, 1.001).IsIdentity());
    EXPECT_FALSE(SMath::Quaternion<double>(0, 0, 0, 0.999).IsIdentity());
    EXPECT_TRUE(SMath::Quaternion<double>(0, 0, 0, 1).IsIdentity());
}

TEST(QuaternionTest, DefaultsToIdentity)
{
    SMath::Quaternion<double> q;
    EXPECT_TRUE(q.IsIdentity());
}

TEST(QuaternionTest, CanCreateIdentity)
{
    SMath::Quaternion<double> identity = SMath::Quaternion<double>::Identity();
    EXPECT_TRUE(identity.IsIdentity());
}

TEST(QuaternionTest, CanBeCreatedScalar)
{
    SMath::Quaternion<double> q(22.0);
    EXPECT_DOUBLE_EQ(q.x, 22.0);
    EXPECT_DOUBLE_EQ(q.y, 22.0);
    EXPECT_DOUBLE_EQ(q.z, 22.0);
    EXPECT_DOUBLE_EQ(q.w, 22.0);
}

TEST(QuaternionTest, CanBeCreatedPerComponent)
{
    SMath::Quaternion<double> q(1.0, 2.0, 3.0, 4.0);
    EXPECT_DOUBLE_EQ(q.x, 1.0);
    EXPECT_DOUBLE_EQ(q.y, 2.0);
    EXPECT_DOUBLE_EQ(q.z, 3.0);
    EXPECT_DOUBLE_EQ(q.w, 4.0);
}

TEST(QuaternionTest, CanBeSetPerComponents)
{
    SMath::Quaternion<double> q;
    q.x = 1.0;
    q.y = 2.0;
    q.z = 3.0;
    q.w = 4.0;

    EXPECT_DOUBLE_EQ(q.x, 1.0);
    EXPECT_DOUBLE_EQ(q.y, 2.0);
    EXPECT_DOUBLE_EQ(q.z, 3.0);
    EXPECT_DOUBLE_EQ(q.w, 4.0);
}

TEST(QuaternionTest, CanBeAccessedPerComponent)
{
    SMath::Quaternion<double> q(1.0, 2.0, 3.0, 4.0);

    EXPECT_DOUBLE_EQ(q[0], 1.0);
    EXPECT_DOUBLE_EQ(q[1], 2.0);
    EXPECT_DOUBLE_EQ(q[2], 3.0);
    EXPECT_DOUBLE_EQ(q[3], 4.0);
    EXPECT_DOUBLE_EQ(q.x, 1.0);
    EXPECT_DOUBLE_EQ(q.y, 2.0);
    EXPECT_DOUBLE_EQ(q.z, 3.0);
    EXPECT_DOUBLE_EQ(q.w, 4.0);
}

TEST(QuaternionTest, CanBeCopyConstructed)
{
    SMath::Quaternion<double> a(1.0, 2.0, 3.0, 4.0);
    SMath::Quaternion<double> b(a);

    EXPECT_DOUBLE_EQ(b.x, 1.0);
    EXPECT_DOUBLE_EQ(b.y, 2.0);
    EXPECT_DOUBLE_EQ(b.z, 3.0);
    EXPECT_DOUBLE_EQ(b.w, 4.0);

    b.x = 0.0;
    EXPECT_DOUBLE_EQ(a.x, 1.0);
}

TEST(QuaternionTest, CanBeCopied)
{
    SMath::Quaternion<double> a(1.0, 2.0, 3.0, 4.0);
    SMath::Quaternion<double> b = a;

    EXPECT_DOUBLE_EQ(b.x, 1.0);
    EXPECT_DOUBLE_EQ(b.y, 2.0);
    EXPECT_DOUBLE_EQ(b.z, 3.0);
    EXPECT_DOUBLE_EQ(b.w, 4.0);

    b.x = 0.0;
    EXPECT_DOUBLE_EQ(a.x, 1.0);
}

TEST(QuaternionTest, CanCheckEquality)
{
    EXPECT_EQ(SMath::Quaternion<double>(0.0, 0.0, 0.0, 1.0), SMath::Quaternion<double>(0.0, 0.0, 0.0, 1.0));
    EXPECT_EQ(SMath::Quaternion<double>(1.0, 2.0, 3.0, 4.0), SMath::Quaternion<double>(1.0, 2.0, 3.0, 4.0));
    EXPECT_NE(SMath::Quaternion<double>(0.0, 0.0, 0.0, 1.0), SMath::Quaternion<double>(1.0, 0.0, 0.0, 0.0));
    EXPECT_NE(SMath::Quaternion<double>(0.0, 0.0, 0.0, 1.0), SMath::Quaternion<double>(0.00001, 0.0, 0.0, 1.0));
}

TEST(QuaternionTest, CanBeAdded)
{
    SMath::Quaternion<double> a(1.0, 2.0, 3.0, 4.0);
    SMath::Quaternion<double> b(2.0, 3.0, 4.0, 5.0);

    SMath::Quaternion<double> c = a + b;
    EXPECT_DOUBLE_EQ(c.x, 3.0);
    EXPECT_DOUBLE_EQ(c.y, 5.0);
    EXPECT_DOUBLE_EQ(c.z, 7.0);
    EXPECT_DOUBLE_EQ(c.w, 9.0);
}

TEST(QuaternionTest, CanBeAddAssigned)
{
    SMath::Quaternion<double> a(1.0, 2.0, 3.0, 4.0);
    SMath::Quaternion<double> b(2.0, 3.0, 4.0, 5.0);
    b += a;

    EXPECT_DOUBLE_EQ(b.x, 3.0);
    EXPECT_DOUBLE_EQ(b.y, 5.0);
    EXPECT_DOUBLE_EQ(b.z, 7.0);
    EXPECT_DOUBLE_EQ(b.w, 9.0);
}

TEST(QuaternionTest, CanBeSubtracted)
{
    SMath::Quaternion<double> a(1.0, 2.0, 3.0, 4.0);
    SMath::Quaternion<double> b(2.0, 3.0, 4.0, 5.0);

    SMath::Quaternion<double> c = b - a;
    EXPECT_DOUBLE_EQ(c.x, 1.0);
    EXPECT_DOUBLE_EQ(c.y, 1.0);
    EXPECT_DOUBLE_EQ(c.z, 1.0);
    EXPECT_DOUBLE_EQ(c.w, 1.0);
}

TEST(QuaternionTest, CanBeSubtractAssigned)
{
    SMath::Quaternion<double> a(1.0, 2.0, 3.0, 4.0);
    SMath::Quaternion<double> b(2.0, 3.0, 4.0, 5.0);
    b -= a;

    EXPECT_DOUBLE_EQ(b.x, 1.0);
    EXPECT_DOUBLE_EQ(b.y, 1.0);
    EXPECT_DOUBLE_EQ(b.z, 1.0);
    EXPECT_DOUBLE_EQ(b.w, 1.0);
}

TEST(QuaternionTest, CanBeMultipliedByScalar)
{
    SMath::Quaternion<double> a(1.0, 2.0, 3.0, 4.0);
    SMath::Quaternion<double> b = a * 2.0;

    EXPECT_DOUBLE_EQ(b.x, 2.0);
    EXPECT_DOUBLE_EQ(b.y, 4.0);
    EXPECT_DOUBLE_EQ(b.z, 6.0);
    EXPECT_DOUBLE_EQ(b.w, 8.0);
}

TEST(QuaternionTest, CanBeMultiplyAssignedByScalar)
{
    SMath::Quaternion<double> a(1.0, 2.0, 3.0, 4.0);
    a *= 2.0;

    EXPECT_DOUBLE_EQ(a.x, 2.0);
    EXPECT_DOUBLE_EQ(a.y, 4.0);
    EXPECT_DOUBLE_EQ(a.z, 6.0);
    EXPECT_DOUBLE_EQ(a.w, 8.0);
}

TEST(QuaternionTest, CanBeMultipliedByQuaternion)
{
    // Identity quaternion multiplication
    SMath::Quaternion<double> identity(0.0, 0.0, 0.0, 1.0);
    SMath::Quaternion<double> a(0.5, 0.5, 0.5, 0.5);
    SMath::Quaternion<double> result = a * identity;

    EXPECT_DOUBLE_EQ(result.x, a.x);
    EXPECT_DOUBLE_EQ(result.y, a.y);
    EXPECT_DOUBLE_EQ(result.z, a.z);
    EXPECT_DOUBLE_EQ(result.w, a.w);

    // General quaternion multiplication
    SMath::Quaternion<double> q1(2.0, 3.0, 4.0, 1.0);
    SMath::Quaternion<double> q2(3.0, 4.0, 5.0, 2.0);
    SMath::Quaternion<double> q3 = q1 * q2;

    // q1*q2 = (w1*w2 - x1*x2 - y1*y2 - z1*z2,
    //          w1*x2 + x1*w2 + y1*z2 - z1*y2,
    //          w1*y2 - x1*z2 + y1*w2 + z1*x2,
    //          w1*z2 + x1*y2 - y1*x2 + z1*w2)
    EXPECT_DOUBLE_EQ(q3.w, -36.0);  // 1*2 - 2*3 - 3*4 - 4*5
    EXPECT_DOUBLE_EQ(q3.x, 6.0);    // 1*3 + 2*2 + 3*5 - 4*4
    EXPECT_DOUBLE_EQ(q3.y, 12.0);   // 1*4 - 2*5 + 3*2 + 4*3
    EXPECT_DOUBLE_EQ(q3.z, 12.0);   // 1*5 + 2*4 - 3*3 + 4*2
}

TEST(QuaternionTest, CanBeMultiplyAssignedByQuaternion)
{
    SMath::Quaternion<double> q1(2.0, 3.0, 4.0, 1.0);
    SMath::Quaternion<double> q2(3.0, 4.0, 5.0, 2.0);
    q1 *= q2;

    EXPECT_DOUBLE_EQ(q1.w, -36.0);
    EXPECT_DOUBLE_EQ(q1.x, 6.0);
    EXPECT_DOUBLE_EQ(q1.y, 12.0);
    EXPECT_DOUBLE_EQ(q1.z, 12.0);
}

TEST(QuaternionTest, CanBeDividedByScalar)
{
    SMath::Quaternion<double> a(2.0, 4.0, 6.0, 8.0);
    SMath::Quaternion<double> b = a / 2.0;

    EXPECT_DOUBLE_EQ(b.x, 1.0);
    EXPECT_DOUBLE_EQ(b.y, 2.0);
    EXPECT_DOUBLE_EQ(b.z, 3.0);
    EXPECT_DOUBLE_EQ(b.w, 4.0);
}

TEST(QuaternionTest, CanBeDivideAssignedByScalar)
{
    SMath::Quaternion<double> a(2.0, 4.0, 6.0, 8.0);
    a /= 2.0;

    EXPECT_DOUBLE_EQ(a.x, 1.0);
    EXPECT_DOUBLE_EQ(a.y, 2.0);
    EXPECT_DOUBLE_EQ(a.z, 3.0);
    EXPECT_DOUBLE_EQ(a.w, 4.0);
}

TEST(QuaternionTest, CanBeNegated)
{
    SMath::Quaternion<double> a(1.0, 2.0, 3.0, 4.0);
    SMath::Quaternion<double> b = -a;

    EXPECT_DOUBLE_EQ(b.x, -1.0);
    EXPECT_DOUBLE_EQ(b.y, -2.0);
    EXPECT_DOUBLE_EQ(b.z, -3.0);
    EXPECT_DOUBLE_EQ(b.w, -4.0);
}

TEST(QuaternionTest, DoesNotChangeWithPveSign)
{
    SMath::Quaternion<double> a(1.0, 2.0, 3.0, 4.0);
    SMath::Quaternion<double> b = +a;

    EXPECT_DOUBLE_EQ(b.x, 1.0);
    EXPECT_DOUBLE_EQ(b.y, 2.0);
    EXPECT_DOUBLE_EQ(b.z, 3.0);
    EXPECT_DOUBLE_EQ(b.w, 4.0);
}

TEST(QuaternionTest, CanComputeMagnitude)
{
    SMath::Quaternion<double> a(0.0, 0.0, 0.0, 1.0);
    SMath::Quaternion<double> b(1.0, 2.0, 3.0, 4.0);
    SMath::Quaternion<double> c(0.5, 0.5, 0.5, 0.5);

    EXPECT_DOUBLE_EQ(a.Magnitude(), 1.0);
    EXPECT_DOUBLE_EQ(b.Magnitude(), std::sqrt(30.0));
    EXPECT_DOUBLE_EQ(c.Magnitude(), 1.0);
}

TEST(QuaternionTest, CanComputeSquareMagnitude)
{
    SMath::Quaternion<double> a(0.0, 0.0, 0.0, 1.0);
    SMath::Quaternion<double> b(1.0, 2.0, 3.0, 4.0);
    SMath::Quaternion<double> c(0.5, 0.5, 0.5, 0.5);

    EXPECT_DOUBLE_EQ(a.SquareMagnitude(), 1.0);
    EXPECT_DOUBLE_EQ(b.SquareMagnitude(), 30.0);
    EXPECT_DOUBLE_EQ(c.SquareMagnitude(), 1.0);
}

TEST(QuaternionTest, CanBeNormalized)
{
    SMath::Quaternion<double> a(0.0, 0.0, 0.0, 2.0);
    SMath::Quaternion<double> b = a.Normalized();

    EXPECT_DOUBLE_EQ(b.x, 0.0);
    EXPECT_DOUBLE_EQ(b.y, 0.0);
    EXPECT_DOUBLE_EQ(b.z, 0.0);
    EXPECT_DOUBLE_EQ(b.w, 1.0);
    EXPECT_DOUBLE_EQ(a.w, 2.0); // Original unchanged

    a.Normalize();
    EXPECT_DOUBLE_EQ(a.x, 0.0);
    EXPECT_DOUBLE_EQ(a.y, 0.0);
    EXPECT_DOUBLE_EQ(a.z, 0.0);
    EXPECT_DOUBLE_EQ(a.w, 1.0);

    SMath::Quaternion<double> c(1.0, 2.0, 3.0, 4.0);
    c.Normalize();
    double mag = std::sqrt(30.0);
    EXPECT_DOUBLE_EQ(c.x, 1.0 / mag);
    EXPECT_DOUBLE_EQ(c.y, 2.0 / mag);
    EXPECT_DOUBLE_EQ(c.z, 3.0 / mag);
    EXPECT_DOUBLE_EQ(c.w, 4.0 / mag);
}

TEST(QuaternionTest, CanComputeConjugate)
{
    SMath::Quaternion<double> a(1.0, 2.0, 3.0, 4.0);
    SMath::Quaternion<double> b = a.Conjugate();

    EXPECT_DOUBLE_EQ(b.x, -1.0);
    EXPECT_DOUBLE_EQ(b.y, -2.0);
    EXPECT_DOUBLE_EQ(b.z, -3.0);
    EXPECT_DOUBLE_EQ(b.w, 4.0);
}

TEST(QuaternionTest, CanComputeInverse)
{
    SMath::Quaternion<double> a(1.0, 2.0, 3.0, 4.0);
    SMath::Quaternion<double> b = a.Inverse();
    SMath::Quaternion<double> identity = a * b;

    // a * a^-1 should equal identity (accounting for floating point error)
    EXPECT_NEAR(identity.x, 0.0, 1e-10);
    EXPECT_NEAR(identity.y, 0.0, 1e-10);
    EXPECT_NEAR(identity.z, 0.0, 1e-10);
    EXPECT_NEAR(identity.w, 1.0, 1e-10);
}

TEST(QuaternionTest, CanComputeDotProduct)
{
    SMath::Quaternion<double> a(0.0, 0.0, 0.0, 1.0);
    SMath::Quaternion<double> b(0.0, 0.0, 0.0, 1.0);
    SMath::Quaternion<double> c(1.0, 2.0, 3.0, 4.0);
    SMath::Quaternion<double> d(2.0, 3.0, 4.0, 5.0);

    EXPECT_DOUBLE_EQ(SMath::Quaternion<double>::Dot(a, b), 1.0);
    EXPECT_DOUBLE_EQ(SMath::Quaternion<double>::Dot(c, d), 40.0); // 1*2 + 2*3 + 3*4 + 4*5
}

TEST(QuaternionTest, CanCreateFromAxisAngle)
{
    // Rotation of 90 degrees around Z-axis
    SMath::Vector3 axis(0.0, 0.0, 1.0);
    double angle = SMath::Pi / 2.0;
    SMath::Quaternion<double> q = SMath::Quaternion<double>::FromAxisAngle(axis, angle);

    EXPECT_NEAR(q.x, 0.0, 1e-10);
    EXPECT_NEAR(q.y, 0.0, 1e-10);
    EXPECT_NEAR(q.z, std::sin(angle / 2.0), 1e-10);
    EXPECT_NEAR(q.w, std::cos(angle / 2.0), 1e-10);

    // Identity rotation (angle = 0)
    SMath::Quaternion<double> identity = SMath::Quaternion<double>::FromAxisAngle(axis, 0.0);
    EXPECT_DOUBLE_EQ(identity.x, 0.0);
    EXPECT_DOUBLE_EQ(identity.y, 0.0);
    EXPECT_DOUBLE_EQ(identity.z, 0.0);
    EXPECT_DOUBLE_EQ(identity.w, 1.0);
}

TEST(QuaternionTest, CanConvertToAxisAngle)
{
    SMath::Quaternion<double> q(0.0, 0.0, std::sin(SMath::Pi / 4.0), std::cos(SMath::Pi / 4.0));
    SMath::Vector3 axis;
    double angle;
    q.ToAxisAngle(axis, angle);

    EXPECT_NEAR(angle, SMath::Pi / 2.0, 1e-10);
    EXPECT_NEAR(axis.x, 0.0, 1e-10);
    EXPECT_NEAR(axis.y, 0.0, 1e-10);
    EXPECT_NEAR(axis.z, 1.0, 1e-10);
}

TEST(QuaternionTest, CanRotateVector)
{
    // 90 degree rotation around Z-axis
    SMath::Quaternion<double> q = SMath::Quaternion<double>::FromAxisAngle(SMath::Vector3(0.0, 0.0, 1.0), SMath::Pi / 2.0);
    SMath::Vector3 v(1.0, 0.0, 0.0);
    SMath::Vector3 rotated = q.Rotate(v);

    EXPECT_NEAR(rotated.x, 0.0, 1e-10);
    EXPECT_NEAR(rotated.y, 1.0, 1e-10);
    EXPECT_NEAR(rotated.z, 0.0, 1e-10);
}

TEST(QuaternionTest, CanLerp)
{
    SMath::Quaternion a(0.0, 0.0, 0.0, 1.0); // Identity
    SMath::Quaternion b = SMath::Quaternion<double>::FromAxisAngle(SMath::Vector3(0.0, 0.0, 1.0), SMath::Pi / 2.0);

    // At t=0, should equal a
    SMath::Quaternion<double> result0 = SMath::Quaternion<double>::Lerp(a, b, 0.0);
    EXPECT_NEAR(result0.x, a.x, 1e-10);
    EXPECT_NEAR(result0.y, a.y, 1e-10);
    EXPECT_NEAR(result0.z, a.z, 1e-10);
    EXPECT_NEAR(result0.w, a.w, 1e-10);

    // At t=1, should equal b
    SMath::Quaternion<double> result1 = SMath::Quaternion<double>::Lerp(a, b, 1.0);
    EXPECT_NEAR(result1.x, b.x, 1e-10);
    EXPECT_NEAR(result1.y, b.y, 1e-10);
    EXPECT_NEAR(result1.z, b.z, 1e-10);
    EXPECT_NEAR(result1.w, b.w, 1e-10);

    // At t=0.5, should be halfway interpolation
    SMath::Quaternion<double> result_half = SMath::Quaternion<double>::Lerp(a, b, 0.5);

    // Result should be normalized
    EXPECT_NEAR(result_half.Magnitude(), 1.0, 1e-10);

    // Should be between a and b
    EXPECT_GT(SMath::Quaternion<double>::Dot(result_half, a), 0.0);
    EXPECT_GT(SMath::Quaternion<double>::Dot(result_half, b), 0.0);

    // Test with arbitrary quaternions
    SMath::Quaternion<double> q1(1.0, 2.0, 3.0, 4.0);
    q1.Normalize();
    SMath::Quaternion<double> q2(2.0, 1.0, 4.0, 3.0);
    q2.Normalize();

    SMath::Quaternion<double> lerp_result = SMath::Quaternion<double>::Lerp(q1, q2, 0.3);

    // Result must be normalized
    EXPECT_NEAR(lerp_result.Magnitude(), 1.0, 1e-10);
}

TEST(QuaternionTest, CanSlerp)
{
    SMath::Quaternion<double> a(0.0, 0.0, 0.0, 1.0); // Identity
    SMath::Quaternion<double> b = SMath::Quaternion<double>::FromAxisAngle(SMath::Vector3(0.0, 0.0, 1.0), SMath::Pi / 2.0);

    // At t=0, should equal a
    SMath::Quaternion<double> result0 = SMath::Quaternion<double>::Slerp(a, b, 0.0);
    EXPECT_NEAR(result0.x, a.x, 1e-10);
    EXPECT_NEAR(result0.y, a.y, 1e-10);
    EXPECT_NEAR(result0.z, a.z, 1e-10);
    EXPECT_NEAR(result0.w, a.w, 1e-10);

    // At t=1, should equal b
    SMath::Quaternion<double> result1 = SMath::Quaternion<double>::Slerp(a, b, 1.0);
    EXPECT_NEAR(result1.x, b.x, 1e-10);
    EXPECT_NEAR(result1.y, b.y, 1e-10);
    EXPECT_NEAR(result1.z, b.z, 1e-10);
    EXPECT_NEAR(result1.w, b.w, 1e-10);

    // At t=0.5, should be halfway rotation
    SMath::Quaternion<double> result_half = SMath::Quaternion<double>::Slerp(a, b, 0.5);
    SMath::Quaternion<double> expected_half = SMath::Quaternion<double>::FromAxisAngle(SMath::Vector3(0.0, 0.0, 1.0), SMath::Pi / 4.0);
    EXPECT_NEAR(result_half.x, expected_half.x, 1e-10);
    EXPECT_NEAR(result_half.y, expected_half.y, 1e-10);
    EXPECT_NEAR(result_half.z, expected_half.z, 1e-10);
    EXPECT_NEAR(result_half.w, expected_half.w, 1e-10);
}

TEST(QuaternionTest, SlerpUsesLerpForSmallAngles)
{
    // Test that Slerp falls back to Lerp for very close quaternions (dot > 0.9995)
    // Use an extremely small angle that would cause division by near-zero sin(theta)
    SMath::Quaternion<double> a(0.0, 0.0, 0.0, 1.0); // Identity
    SMath::Quaternion<double> b = SMath::Quaternion<double>::FromAxisAngle(SMath::Vector3(0.0, 0.0, 1.0), 0.00001); // Extremely small rotation

    // Verify quaternions are very close (dot should be > 0.9995)
    double dot = SMath::Quaternion<double>::Dot(a, b);
    EXPECT_GT(dot, 0.9995);

    // Slerp should work without numerical issues (no NaN/Inf)
    SMath::Quaternion<double> result = SMath::Quaternion<double>::Slerp(a, b, 0.5);

    // Check all components are finite (not NaN or Inf)
    EXPECT_TRUE(std::isfinite(result.x));
    EXPECT_TRUE(std::isfinite(result.y));
    EXPECT_TRUE(std::isfinite(result.z));
    EXPECT_TRUE(std::isfinite(result.w));

    // Result should be normalized
    EXPECT_NEAR(result.Magnitude(), 1.0, 1e-6);

    // Test with identity quaternions (most extreme case: dot = 1.0)
    SMath::Quaternion<double> identity1(0.0, 0.0, 0.0, 1.0);
    SMath::Quaternion<double> identity2(0.0, 0.0, 0.0, 1.0);
    SMath::Quaternion<double> result_identity = SMath::Quaternion<double>::Slerp(identity1, identity2, 0.5);

    // Should not produce NaN
    EXPECT_TRUE(std::isfinite(result_identity.x));
    EXPECT_TRUE(std::isfinite(result_identity.y));
    EXPECT_TRUE(std::isfinite(result_identity.z));
    EXPECT_TRUE(std::isfinite(result_identity.w));

    // Should return a valid quaternion close to identity
    EXPECT_NEAR(result_identity.x, 0.0, 1e-6);
    EXPECT_NEAR(result_identity.y, 0.0, 1e-6);
    EXPECT_NEAR(result_identity.z, 0.0, 1e-6);
    EXPECT_NEAR(result_identity.w, 1.0, 1e-6);
}

TEST(QuaternionTest, CanCreateFromEulerAngles)
{
    // Test identity (0, 0, 0)
    SMath::Quaternion<double> q1 = SMath::Quaternion<double>::FromEuler(0.0, 0.0, 0.0);
    EXPECT_NEAR(q1.x, 0.0, 1e-10);
    EXPECT_NEAR(q1.y, 0.0, 1e-10);
    EXPECT_NEAR(q1.z, 0.0, 1e-10);
    EXPECT_NEAR(q1.w, 1.0, 1e-10);

    // Test 90 degree rotation around Z
    SMath::Quaternion<double> q2 = SMath::Quaternion<double>::FromEuler(0.0, 0.0, SMath::Pi / 2.0);
    SMath::Vector3 v(1.0, 0.0, 0.0);
    SMath::Vector3 rotated = q2.Rotate(v);
    EXPECT_NEAR(rotated.x, 0.0, 1e-10);
    EXPECT_NEAR(rotated.y, 1.0, 1e-10);
    EXPECT_NEAR(rotated.z, 0.0, 1e-10);
}

TEST(QuaternionTest, CanConvertToEulerAngles)
{
    SMath::Quaternion<double> q = SMath::Quaternion<double>::FromEuler(0.1, 0.2, 0.3);
    SMath::Vector3 euler = q.ToEuler();

    EXPECT_NEAR(euler.x, 0.1, 1e-10);
    EXPECT_NEAR(euler.y, 0.2, 1e-10);
    EXPECT_NEAR(euler.z, 0.3, 1e-10);
}