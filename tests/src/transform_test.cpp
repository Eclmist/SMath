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
#include "transform.h"

TEST(TransformTest, CanGetTranslationMatrix)
{
    auto mt1 = SMath::Transform<double>::GetTranslationMatrix({});
    ASSERT_EQ(mt1, SMath::Matrix4x4(
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1));

    auto mt2 = SMath::Transform<double>::GetTranslationMatrix({ 5, 6, 7 });
    ASSERT_EQ(mt2, SMath::Matrix4x4(
        1, 0, 0, 5,
        0, 1, 0, 6,
        0, 0, 1, 7,
        0, 0, 0, 1));
}

TEST(TransformTest, CanGetRotationMatrix)
{
    auto mt1 = SMath::Transform<double>::GetRotationMatrix({});
    ASSERT_EQ(mt1, SMath::Matrix4x4(
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1));


    auto mt2 = SMath::Transform<double>::GetRotationMatrix({ SMath::Pi, SMath::Pi * 2, -SMath::Pi });

    ASSERT_EQ(mt2, SMath::Matrix4x4(
        -1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, -1, 0,
        0, 0, 0, 1));
}

TEST(TransformTest, CanGetScaleMatrix)
{
    auto mt1 = SMath::Transform<double>::GetScaleMatrix({ 5, 6, 7 });
    ASSERT_EQ(mt1, SMath::Matrix4x4(
        5, 0, 0, 0,
        0, 6, 0, 0,
        0, 0, 7, 0,
        0, 0, 0, 1));
}

