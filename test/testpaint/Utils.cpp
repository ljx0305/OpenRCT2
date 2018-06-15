/*****************************************************************************
 * Copyright (c) 2014-2018 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "Utils.hpp"

#include <openrct2/ride/Ride.h>
#include <openrct2/ride/Track.h>
#include <openrct2/ride/TrackData.h>

namespace Utils {
    int getTrackSequenceCount(uint8 rideType, uint8 trackType) {
        int sequenceCount = 0;
        const rct_preview_track **trackBlocks;

        if (ride_type_has_flag(rideType, RIDE_TYPE_FLAG_FLAT_RIDE)) {
            trackBlocks = FlatRideTrackBlocks;
        } else {
            trackBlocks = TrackBlocks;
        }

        for (int i = 0; i < 256; i++) {
            if (trackBlocks[trackType][i].index == 0xFF) {
                break;
            }

            sequenceCount++;
        }

        return sequenceCount;
    }

    bool rideSupportsTrackType(uint8 rideType, uint8 trackType) {
        TRACK_PAINT_FUNCTION_GETTER newPaintGetter = RideTypeTrackPaintFunctions[rideType];

        if (newPaintGetter == nullptr) {
            return false;
        }

        if (newPaintGetter(trackType, 0) == nullptr) {
            return false;
        }

        if (RideTypeTrackPaintFunctionsOld[rideType][trackType] == 0) {
            return false;
        }

        return true;
    }

    bool rideIsImplemented(uint8 rideType) {
        TRACK_PAINT_FUNCTION_GETTER newPaintGetter = RideTypeTrackPaintFunctions[rideType];
        return (newPaintGetter != 0);
    }
}
