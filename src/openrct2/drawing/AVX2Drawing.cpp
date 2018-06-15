/*****************************************************************************
 * Copyright (c) 2014-2018 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "../common.h"
#include "../core/Guard.hpp"
#include "Drawing.h"

#ifdef __AVX2__

#include <immintrin.h>

void mask_avx2(sint32 width, sint32 height, const uint8 * RESTRICT maskSrc, const uint8 * RESTRICT colourSrc,
               uint8 * RESTRICT dst, sint32 maskWrap, sint32 colourWrap, sint32 dstWrap)
{
    if (width == 32)
    {
        const sint32 maskWrapSIMD = maskWrap + 32;
        const sint32 colourWrapSIMD = colourWrap + 32;
        const sint32 dstWrapSIMD = dstWrap + 32;
        const __m256i zero = {};
        for (sint32 yy = 0; yy < height; yy++) {
            const __m256i colour   = _mm256_lddqu_si256((const __m256i *)(colourSrc + yy * colourWrapSIMD));
            const __m256i mask     = _mm256_lddqu_si256((const __m256i *)(maskSrc   + yy * maskWrapSIMD));
            const __m256i dest     = _mm256_lddqu_si256((const __m256i *)(dst       + yy * dstWrapSIMD));
            const __m256i mc       = _mm256_and_si256 (colour, mask);
            const __m256i saturate = _mm256_cmpeq_epi8(mc, zero);
            const __m256i blended  = _mm256_blendv_epi8(mc, dest, saturate);
            _mm256_storeu_si256 ((__m256i *)(dst + yy * dstWrapSIMD), blended);
        }
    }
    else
    {
        mask_scalar(width, height, maskSrc, colourSrc, dst, maskWrap, colourWrap, dstWrap);
    }
}

#else

#ifdef OPENRCT2_X86
#error You have to compile this file with AVX2 enabled, when targeting x86!
#endif

void mask_avx2(sint32 width, sint32 height, const uint8 * RESTRICT maskSrc, const uint8 * RESTRICT colourSrc,
               uint8 * RESTRICT dst, sint32 maskWrap, sint32 colourWrap, sint32 dstWrap)
{
    openrct2_assert(false, "AVX2 function called on a CPU that doesn't support AVX2");
}

#endif // __AVX2__
