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

#include "gtest.h"
#include "ray.h"

TEST(RayTest, CanBeCreated)
{
    ASSERT_NO_THROW(SMath::Ray<double>({ 0.0 }, { 1.0, 2.0, 3.0 }));
}

TEST(RayTest, DirectionIsNormalized)
{
    EXPECT_EQ(SMath::Ray<double>({ 0.0 }, { 6.0, 0.0, 0.0 }).GetDirection(), SMath::Vector3(1.0, 0.0, 0.0));
    EXPECT_EQ(SMath::Ray<double>({ 0.0 }, { 1.0, 2.0, 3.0 }).GetDirection(), SMath::Vector3(1.0, 2.0, 3.0).Normalized());

    SMath::Ray<double> r({ 0.0 }, { 0.0 });
    r.SetDirection({ 1.0, 0.0, 0.0 });
    EXPECT_EQ(r.GetDirection().Magnitude(), 1.0);
    r.SetDirection({ 1.0, 2.0, 3.0 });
    EXPECT_EQ(r.GetDirection().Magnitude(), 1.0);
}

TEST(RayTest, CanBeCopied)
{
    SMath::Ray<double> r({ 0.0 }, { 1.0, 2.0, 3.0 });
    SMath::Ray<double> copy(r);
    EXPECT_EQ(r.GetDirection(), copy.GetDirection());
    EXPECT_EQ(r.GetOrigin(), copy.GetOrigin());
}

TEST(RayTest, CanBeEvaluated)
{
    SMath::Ray<double> r({ 0.0 }, { 1.0, 0.0, 0.0 });
    EXPECT_EQ(r(1), SMath::Point3(1.0, 0.0, 0.0));
    EXPECT_EQ(r(2), SMath::Point3(2.0, 0.0, 0.0));
    EXPECT_EQ(r(-1), SMath::Point3(-1.0, 0.0, 0.0));

    SMath::Ray<double> r2({ 2.0, 1.0, 0.0 }, { 0.0, 1.0, 0.0 });
    EXPECT_EQ(r2(0), SMath::Point3(2.0, 1.0, 0.0));
    EXPECT_EQ(r2(1), SMath::Point3(2.0, 2.0, 0.0));
    EXPECT_EQ(r2(-1), SMath::Point3(2.0, 0.0, 0.0));
}

TEST(RayTest, CanTestForEquality)
{
    SMath::Ray<double> r({ 0.0 }, { 1.0, 0.0, 0.0 });
    SMath::Ray<double> r2({ 2.0, 1.0, 0.0 }, { 0.0, 1.0, 0.0 });
    SMath::Ray<double> r3({ 0.0 }, { 1.0, 2.0, 3.0 });

    EXPECT_EQ(r, r);
    EXPECT_EQ(r2, r2);
    EXPECT_EQ(r3, r3);

    EXPECT_NE(r, r2);
    EXPECT_NE(r, r3);
    EXPECT_NE(r2, r3);
}

