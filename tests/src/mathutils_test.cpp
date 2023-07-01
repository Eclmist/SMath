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

TEST(MathUtilsTest, CanConvertDegToRad)
{
    EXPECT_DOUBLE_EQ(SMath::DegToRad(1.0), 0.017453292519943295);
    EXPECT_DOUBLE_EQ(SMath::DegToRad(0.0), 0);
    EXPECT_DOUBLE_EQ(SMath::DegToRad(-1.0), -0.017453292519943295);
    EXPECT_DOUBLE_EQ(SMath::DegToRad(30.0), 0.52359877559829882);
    EXPECT_DOUBLE_EQ(SMath::DegToRad(45.0), 0.78539816339744828);
    EXPECT_DOUBLE_EQ(SMath::DegToRad(45.0), SMath::PiOver4);
    EXPECT_DOUBLE_EQ(SMath::DegToRad(60.0), 1.0471975511965976);
    EXPECT_DOUBLE_EQ(SMath::DegToRad(90.0), 1.5707963267948966);
    EXPECT_DOUBLE_EQ(SMath::DegToRad(90.0), SMath::PiOver2);
    EXPECT_DOUBLE_EQ(SMath::DegToRad(180.0), 3.1415926535897931);
    EXPECT_DOUBLE_EQ(SMath::DegToRad(180.0), SMath::Pi);
    EXPECT_DOUBLE_EQ(SMath::DegToRad(270.0), 4.7123889803846897);
    EXPECT_DOUBLE_EQ(SMath::DegToRad(360.0), 6.2831853071795862);
}

TEST(MathUtilsTest, CanConvertRadToDeg)
{
    EXPECT_DOUBLE_EQ(SMath::RadToDeg(1.0), 57.295779513082323);
    EXPECT_DOUBLE_EQ(SMath::RadToDeg(0.0), 0);
    EXPECT_DOUBLE_EQ(SMath::RadToDeg(-1.0), -57.295779513082323);
    EXPECT_DOUBLE_EQ(SMath::RadToDeg(SMath::Pi), 180);
    EXPECT_DOUBLE_EQ(SMath::RadToDeg(SMath::Pi * 2), 360);
    EXPECT_DOUBLE_EQ(SMath::RadToDeg(SMath::PiOver2), 90);
    EXPECT_DOUBLE_EQ(SMath::RadToDeg(SMath::PiOver4), 45);
}

