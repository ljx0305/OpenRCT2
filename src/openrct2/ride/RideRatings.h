/*****************************************************************************
 * Copyright (c) 2014-2018 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../common.h"

using ride_rating = fixed16_2dp;

// Convenience function for writing ride ratings. The result is a 16 bit signed
// integer. To create the ride rating 3.65 type RIDE_RATING(3,65)
#define RIDE_RATING(whole, fraction)    FIXED_2DP(whole, fraction)
#define RIDE_RATING_UNDEFINED           (ride_rating)(uint16)0xFFFF

#pragma pack(push, 1)

// Used for return values, for functions that modify all three.
struct rating_tuple {
    ride_rating excitement;
    ride_rating intensity;
    ride_rating nausea;
};
assert_struct_size(rating_tuple, 6);

#pragma pack(pop)

enum {
    RIDE_RATING_STATION_FLAG_NO_ENTRANCE = 1 << 0
};

struct rct_ride_rating_calc_data {
    uint16  proximity_x;
    uint16  proximity_y;
    uint16  proximity_z;
    uint16  proximity_start_x;
    uint16  proximity_start_y;
    uint16  proximity_start_z;
    uint8   current_ride;
    uint8   state;
    uint8   proximity_track_type;
    uint8   proximity_base_height;
    uint16  proximity_total;
    uint16  proximity_scores[26];
    uint16  num_brakes;
    uint16  num_reversers;
    uint16  station_flags;
};

extern rct_ride_rating_calc_data gRideRatingsCalcData;

void ride_ratings_update_ride(int rideIndex);
void ride_ratings_update_all();

