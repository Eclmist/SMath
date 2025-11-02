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
#include "rect.h"

TEST(RectTest, CanBeCreated)
{
    ASSERT_NO_THROW(SMath::Rect rect(0, 0, 0, 0));
    ASSERT_NO_THROW(SMath::Rect rect(-1, 0, 0, 0));
    ASSERT_NO_THROW(SMath::Rect rect(0, -1, 0, 0));
    ASSERT_NO_THROW(SMath::Rect rect(0, 0, 100, 100));
    ASSERT_NO_THROW(SMath::Rect rect(0, 0, 10000, 10000));
}

TEST(RectTest, CanCheckIfInBounds)
{
    SMath::Rect rect(100, 200, 200, 400);
    EXPECT_FALSE(rect.Contains(99, 199));
    EXPECT_FALSE(rect.Contains(100, 199));
    EXPECT_TRUE(rect.Contains(100, 200));

    EXPECT_FALSE(rect.Contains(300, 600));
    EXPECT_FALSE(rect.Contains(299, 600));
    EXPECT_FALSE(rect.Contains(300, 599));
    EXPECT_TRUE(rect.Contains(299, 599));
}