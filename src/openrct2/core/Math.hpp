/*****************************************************************************
 * Copyright (c) 2014-2018 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include <algorithm>

/**
 * Common mathematical functions.
 */
namespace Math
{
    template<typename T>
    static T Min(T a, T b)
    {
        return (std::min)(a, b);
    }

    template<typename T>
    static T Max(T a, T b)
    {
        return (std::max)(a, b);
    }

    template<typename T>
    static T Clamp(T low, T x, T high)
    {
        return (std::min)((std::max)(low, x), high);
    }

    template<typename T>
    static T Sign(T x)
    {
        if (x < 0) return -1;
        if (x > 0) return 1;
        return 0;
    }
} // namespace Math
