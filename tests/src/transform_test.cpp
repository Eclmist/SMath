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
#include "transform.h"

TEST(TransformTest, CanBeCreated)
{
    ASSERT_NO_THROW(SMath::Transform());
}

TEST(TransformTest, DefaultsToIdentity)
{
    EXPECT_TRUE(SMath::Transform().GetMatrix().IsIdentity());
    EXPECT_TRUE(SMath::Transform().GetMatrixInverse().IsIdentity());
}

TEST(TransformTest, CanSetTranlation)
{
    SMath::Transform t;
    ASSERT_NO_THROW(t.SetTranslation({ 1, 2, 3 }));
    EXPECT_EQ(t.GetMatrix(), SMath::Matrix4x4(1, 0, 0, 1, 0, 1, 0, 2, 0, 0, 1, 3, 0, 0, 0, 1));
    ASSERT_NO_THROW(t.SetTranslation({ 1, 2, 4 }));
    EXPECT_EQ(t.GetMatrix(), SMath::Matrix4x4(1, 0, 0, 1, 0, 1, 0, 2, 0, 0, 1, 4, 0, 0, 0, 1));
}

TEST(TransformTest, CanSetRotation)
{
    SMath::Transform t;
    ASSERT_NO_THROW(t.SetRotation({ SMath::Pi / 2, 0, 0 }));
    EXPECT_EQ(t.GetMatrix(), SMath::Matrix4x4(1, 0, 0, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, 0, 0, 1));
}

TEST(TransformTest, CanSetScale)
{
    SMath::Transform t;
    ASSERT_NO_THROW(t.SetScale({ 1, 2, 4}));
    EXPECT_EQ(t.GetMatrix(), SMath::Matrix4x4(1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 4, 0, 0, 0, 0, 1));
}

TEST(TransformTest, MatrixHasCorrectValues)
{
    SMath::Transform t, t2;

    ASSERT_NO_THROW(t.SetTranslation({ 1, 2, 3 }));
    EXPECT_EQ(t.GetMatrix(), SMath::Matrix4x4(1, 0, 0, 1, 0, 1, 0, 2, 0, 0, 1, 3, 0, 0, 0, 1));
    EXPECT_EQ(t.GetMatrixInverse(), SMath::Matrix4x4(1, 0, 0, 1, 0, 1, 0, 2, 0, 0, 1, 3, 0, 0, 0, 1).Inversed());

    ASSERT_NO_THROW(t.SetScale({ 1, 1, 4 }));
    EXPECT_EQ(t.GetMatrix(), SMath::Matrix4x4(1, 0, 0, 1, 0, 1, 0, 2, 0, 0, 4, 3, 0, 0, 0, 1));
    EXPECT_EQ(t.GetMatrixInverse(), SMath::Matrix4x4(1, 0, 0, 1, 0, 1, 0, 2, 0, 0, 4, 3, 0, 0, 0, 1).Inversed());

    ASSERT_NO_THROW(t2.SetRotation({ SMath::Pi / 2, 0, 0 }));
    EXPECT_EQ(t2.GetMatrix(), SMath::Matrix4x4(1, 0, 0, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, 0, 0, 1));
    EXPECT_EQ(t2.GetMatrixInverse(), SMath::Matrix4x4(1, 0, 0, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, 0, 0, 1).Inversed());

    ASSERT_NO_THROW(t2.SetRotation({ SMath::Pi / 2, SMath::Pi / 2, SMath::Pi / 2 }));
    EXPECT_EQ(t2.GetMatrix(), SMath::Matrix4x4(0, 0, 1, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 1));
    EXPECT_EQ(t2.GetMatrixInverse(), SMath::Matrix4x4(0, 0, 1, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 1).Inversed());

    ASSERT_NO_THROW(t.SetRotation({ SMath::Pi / 2, SMath::Pi / 2, SMath::Pi / 2 }));
    EXPECT_EQ(t.GetMatrix(), SMath::Matrix4x4(0, 0, 4, 1, 0, 1, 0, 2, -1, 0, 0, 3, 0, 0, 0, 1));
    EXPECT_EQ(t.GetMatrixInverse(), SMath::Matrix4x4(0, 0, 4, 1, 0, 1, 0, 2, -1, 0, 0, 3, 0, 0, 0, 1).Inversed());
}

TEST(TransformTest, CanTransformVectorsIdentity)
{
    SMath::Transform t;
    SMath::Vector3 forward = { 0, 0, 1 };
    SMath::Vector3 up = { 0, 1, 0 };
    SMath::Vector3 right = { 1, 0, 0 };

    // Indentity transform should not change vector
    EXPECT_EQ(t(forward), forward);
    EXPECT_EQ(t(up), up);
    EXPECT_EQ(t(right), right);
}

TEST(TransformTest, CanTransformVectorsTranslated)
{
    SMath::Transform t;
    t.SetTranslation({ 1.0, -1.0, 2.5 });

    SMath::Vector3 forward = { 0, 0, 1 };
    SMath::Vector3 up = { 0, 1, 0 };
    SMath::Vector3 right = { 1, 0, 0 };

    // Translation should not change vector
    EXPECT_EQ(t(forward), forward);
    EXPECT_EQ(t(up), up);
    EXPECT_EQ(t(right), right);
}

TEST(TransformTest, CanTransformVectorsScaled)
{
    SMath::Transform t;
    t.SetScale({ 2.0, 2.0, -2.0 });

    SMath::Vector3 forward = { 0, 0, 1 };
    SMath::Vector3 up = { 0, 1, 0 };
    SMath::Vector3 right = { 1, 0, 0 };

    // Scale should change vector
    EXPECT_EQ(t(forward), SMath::Vector3(0, 0, -2));
    EXPECT_EQ(t(up), SMath::Vector3(0, 2, 0));
    EXPECT_EQ(t(right), SMath::Vector3(2, 0, 0));
}

TEST(TransformTest, CanTransformVectorsRotated)
{
    SMath::Transform t;
    t.SetRotation({ 0, SMath::DegToRad(90), 0 });

    SMath::Vector3 forward = { 0, 0, 1 };
    SMath::Vector3 up = { 0, 1, 0 };
    SMath::Vector3 right = { 1, 0, 0 };

    // Rotation should change vector
    EXPECT_EQ(t(forward), right);
    EXPECT_EQ(t(up), up);
    EXPECT_EQ(t(right), -forward);

    t.SetRotation({ SMath::DegToRad(90), 0, 0});
    EXPECT_EQ(t(forward), -up);
    EXPECT_EQ(t(up), forward);
    EXPECT_EQ(t(right), right);
}

TEST(TransformTest, CanTransformPointsIdentity)
{
    SMath::Transform t;
    SMath::Point3 forward = { 0, 0, 1 };
    SMath::Point3 up = { 0, 1, 0 };
    SMath::Point3 right = { 1, 0, 0 };


    // Indentity transform should not change point
    EXPECT_EQ(t(forward), forward);
    EXPECT_EQ(t(up), up);
    EXPECT_EQ(t(right), right);
}

TEST(TransformTest, CanTransformPointsTranslated)
{
    SMath::Transform t;
    SMath::Vector3 translation(1.0, 2.5, -1.0);
    t.SetTranslation(translation);

    SMath::Point3 forward = { 0, 0, 1 };
    SMath::Point3 up = { 0, 1, 0 };
    SMath::Point3 right = { 1, 0, 0 };

    // Translation should change point
    EXPECT_EQ(t(forward), forward + translation);
    EXPECT_EQ(t(up), up + translation);
    EXPECT_EQ(t(right), right + translation);
}

TEST(TransformTest, CanTransformPointsScaled)
{
    SMath::Transform t;
    t.SetScale({ 2.0, 2.0, -2.0 });

    SMath::Point3 forward = { 0, 0, 1 };
    SMath::Point3 up = { 0, 1, 0 };
    SMath::Point3 right = { 1, 0, 0 };

    // Scale should change point
    EXPECT_EQ(t(forward), SMath::Point3(0, 0, -2));
    EXPECT_EQ(t(up), SMath::Point3(0, 2, 0));
    EXPECT_EQ(t(right), SMath::Point3(2, 0, 0));
}

TEST(TransformTest, CanTransformPointsRotated)
{
    SMath::Transform t;
    t.SetRotation({ 0, SMath::DegToRad(90), 0 });

    SMath::Point3 forward = { 0, 0, 1 };
    SMath::Point3 up = { 0, 1, 0 };
    SMath::Point3 right = { 1, 0, 0 };

    // Rotation should change point
    EXPECT_EQ(t(forward), right);
    EXPECT_EQ(t(up), up);
    EXPECT_EQ(t(right), -forward);

    t.SetRotation({ SMath::DegToRad(90), 0, 0 });
    EXPECT_EQ(t(forward), -up);
    EXPECT_EQ(t(up), forward);
    EXPECT_EQ(t(right), right);
}

TEST(TransformTest, CanTransformNormalsIdentity)
{
    SMath::Transform t;
    SMath::Normal3 forward = { 0, 0, 1 };
    SMath::Normal3 up = { 0, 1, 0 };
    SMath::Normal3 right = { 1, 0, 0 };

    // Indentity transform should not change normal
    EXPECT_EQ(t(forward), forward);
    EXPECT_EQ(t(up), up);
    EXPECT_EQ(t(right), right);
}

TEST(TransformTest, CanTransformNormalsTranslated)
{
    SMath::Transform t;
    SMath::Vector3 translation(1.0, 2.5, -1.0);
    t.SetTranslation(translation);

    SMath::Normal3 forward = { 0, 0, 1 };
    SMath::Normal3 up = { 0, 1, 0 };
    SMath::Normal3 right = { 1, 0, 0 };

    // Translation should not change normal
    EXPECT_EQ(t(forward), forward);
    EXPECT_EQ(t(up), up);
    EXPECT_EQ(t(right), right);
}

TEST(TransformTest, CanTransformNormalsScaled)
{
    SMath::Transform t;
    t.SetScale({ 0.5, 0.5, 0.5 });

    SMath::Normal3 forward = { 0, 0, 1 };
    SMath::Normal3 up = { 0, 1, 0 };

    SMath::Normal3 right = { 1, 0, 0 };

    // Scale should change normal
    EXPECT_EQ(t(forward).Normalized(), SMath::Normal3(0, 0, 1.0));
    EXPECT_EQ(t(up).Normalized(), SMath::Normal3(0, 1.0, 0));
    EXPECT_EQ(t(right).Normalized(), SMath::Normal3(1.0, 0, 0));

    // Scaling non-axis aligned normal must be done with inv transposed mat
    t.SetScale({ 1.0, 0.5, 1.0 });
    SMath::Normal3 rightDiag = SMath::Normal3(1.0, 1.0, 0.0).Normalized();
    SMath::Vector3 rightDiagVec = SMath::Vector3(1.0, 1.0, 0.0).Normalized();

    EXPECT_FALSE(t(rightDiag) == t(rightDiagVec));
    EXPECT_EQ(t(rightDiag).Normalized(), SMath::Normal3(2, 4, 0).Normalized());
}

TEST(TransformTest, CanTransformNormalsRotated)
{
    SMath::Transform t;
    t.SetRotation({ 0, SMath::DegToRad(90), 0 });

    SMath::Normal3 forward = { 0, 0, 1 };
    SMath::Normal3 up = { 0, 1, 0 };
    SMath::Normal3 right = { 1, 0, 0 };

    // Rotation should change normal
    EXPECT_EQ(t(forward), right);
    EXPECT_EQ(t(up), up);
    EXPECT_EQ(t(right), -forward);

    t.SetRotation({ SMath::DegToRad(90), 0, 0 });
    EXPECT_EQ(t(forward), -up);
    EXPECT_EQ(t(up), forward);
    EXPECT_EQ(t(right), right);
}

TEST(TransformTest, CanTransformRaysIdentity)
{
    SMath::Transform t;
    SMath::Ray r1({ 0,0,1 }, { 0,0,1 });
    SMath::Ray r2({ 0,1,0 }, { 0,1,0 });
    SMath::Ray r3({ 1,0,0 }, { 1,0,0 });

    EXPECT_EQ(t(r1), r1);
    EXPECT_EQ(t(r2), r2);
    EXPECT_EQ(t(r3), r3);
}

TEST(TransformTest, CanTransformRaysTranslated)
{
    SMath::Transform t;
    t.SetTranslation({ 1.0, -1.0, 2.5 });

    SMath::Ray r1({ 0,0,1 }, { 0,0,1 });
    SMath::Ray r2({ 0,1,0 }, { 0,1,0 });
    SMath::Ray r3({ 1,0,0 }, { 1,0,0 });

    EXPECT_EQ(t(r1).GetDirection(), r1.GetDirection());
    EXPECT_EQ(t(r2).GetDirection(), r2.GetDirection());
    EXPECT_EQ(t(r3).GetDirection(), r3.GetDirection());
    EXPECT_EQ(t(r1).GetOrigin(), r1.GetOrigin() + SMath::Vector3(1.0, -1.0, 2.5));
    EXPECT_EQ(t(r2).GetOrigin(), r2.GetOrigin() + SMath::Vector3(1.0, -1.0, 2.5));
    EXPECT_EQ(t(r3).GetOrigin(), r3.GetOrigin() + SMath::Vector3(1.0, -1.0, 2.5));
}

TEST(TransformTest, CanTransformRaysScaled)
{
    SMath::Transform t;
    t.SetScale({ 2.0, 2.0, -2.0 });

    SMath::Ray r1({ 0,0,1 }, { 0,0,1 });
    SMath::Ray r2({ 0,1,0 }, { 0,1,0 });
    SMath::Ray r3({ 1,0,0 }, { 1,0,0 });

    EXPECT_EQ(t(r1).GetDirection(), SMath::Vector3(0, 0, -2).Normalized());
    EXPECT_EQ(t(r2).GetDirection(), SMath::Vector3(0, 2, 0).Normalized());
    EXPECT_EQ(t(r3).GetDirection(), SMath::Vector3(2, 0, 0).Normalized());

    EXPECT_EQ(t(r1).GetOrigin(), SMath::Point3(0, 0, -2));
    EXPECT_EQ(t(r2).GetOrigin(), SMath::Point3(0, 2, 0));
    EXPECT_EQ(t(r3).GetOrigin(), SMath::Point3(2, 0, 0));
}

TEST(TransformTest, CanTransformRaysRotated)
{
    SMath::Transform t;
    t.SetRotation({ 0, SMath::DegToRad(90), 0 });

    SMath::Ray forward({ 0,0,1 }, { 0,0,1 });
    SMath::Ray up({ 0,1,0 }, { 0,1,0 });
    SMath::Ray right({ 1,0,0 }, { 1,0,0 });

    EXPECT_EQ(t(forward).GetDirection(), right.GetDirection());
    EXPECT_EQ(t(up).GetDirection(), up.GetDirection());
    EXPECT_EQ(t(right).GetDirection(), -forward.GetDirection());

    EXPECT_EQ(t(forward).GetOrigin(), right.GetOrigin());
    EXPECT_EQ(t(up).GetOrigin(), up.GetOrigin());
    EXPECT_EQ(t(right).GetOrigin(), -forward.GetOrigin());
}

TEST(TransformTest, CanGetInverse)
{
    SMath::Transform t, t2;

    t.SetTranslation({ 1, 2, 3 });
    t.SetScale({ 1, 1, 4 });
    t.SetRotation({ SMath::Pi / 2, SMath::Pi / 2, SMath::Pi / 2 });
    t2.SetRotation({ SMath::Pi / 2, 0, 0 });
    t2.SetRotation({ SMath::Pi / 2, SMath::Pi / 2, SMath::Pi / 2 });

    SMath::Transform tInv = t.Inversed();
    SMath::Transform tInv2 = t2.Inversed();

    EXPECT_EQ(tInv.GetMatrix(), t.GetMatrixInverse());
    EXPECT_EQ(tInv.GetMatrixInverse(), t.GetMatrix());

    EXPECT_EQ(tInv2.GetMatrix(), t2.GetMatrixInverse());
    EXPECT_EQ(tInv2.GetMatrixInverse(), t2.GetMatrix());
}

TEST(TransformTest, CorrectOrderOfTransformations)
{
    // Should scale at origin, rotate at origin, then translate to position
    SMath::Transform t;

    SMath::Point3 front = { 0, 0, 1 };
    SMath::Point3 up = { 0, 1, 0 };
    SMath::Point3 right = { 1, 0, 0 };

    t.SetScale(2.0);
    EXPECT_EQ(t(front), SMath::Point3(0, 0, 2));
    EXPECT_EQ(t(up), SMath::Point3(0, 2, 0));
    EXPECT_EQ(t(right), SMath::Point3(2, 0, 0));

    t.SetRotation(SMath::Vector3(SMath::DegToRad(90), 0, 0));
    EXPECT_EQ(t(front), SMath::Point3(0, -2, 0));
    EXPECT_EQ(t(up), SMath::Point3(0, 0, 2));
    EXPECT_EQ(t(right), SMath::Point3(2, 0, 0));

    t.SetTranslation(SMath::Vector3(20, 30, 40));
    EXPECT_EQ(t(front), SMath::Point3(20, 28, 40));
    EXPECT_EQ(t(up), SMath::Point3(20, 30, 42));
    EXPECT_EQ(t(right), SMath::Point3(22, 30, 40));

    SMath::Transform t2;
    SMath::Point3 origin = { 0, 0, 0 };
    t2.SetTranslation({ 10, 100, 20 });
    t2.SetRotation({ SMath::DegToRad(90), 0, 0 });
    EXPECT_EQ(t2(origin), SMath::Point3(10, 100, 20));
    SMath::Vector3 forward = { 0, 0, 1 };
    EXPECT_EQ(t2(forward), SMath::Vector3(0, -1, 0));
    SMath::Ray forwardRay({ 0, 0, 0 }, { 0,0,1 });
    EXPECT_EQ(t2(forwardRay), SMath::Ray({10, 100, 20}, {0, -1, 0}));

    SMath::Transform t3;
    t3.SetTranslation({ 0, 0.5, -10 });
    t3.SetScale({ 0.005 });
    t3.SetRotation({ SMath::DegToRad(2), 0, 0 });
    EXPECT_EQ(t3(forwardRay).GetOrigin(), SMath::Point3(0, 0.5, -10));
}

