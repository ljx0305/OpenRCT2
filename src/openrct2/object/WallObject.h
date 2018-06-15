/*****************************************************************************
 * Copyright (c) 2014-2018 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "SceneryObject.h"

#include "../world/Scenery.h"

class WallObject final : public SceneryObject
{
private:
    rct_scenery_entry   _legacyType = {};

public:
    explicit WallObject(const rct_object_entry &entry) : SceneryObject(entry) { }

    void * GetLegacyData()  override { return &_legacyType; }

    void ReadLegacy(IReadObjectContext * context, IStream * stream) override;
    void ReadJson(IReadObjectContext * context, const json_t * root) override;
    void Load() override;
    void Unload() override;

    void DrawPreview(rct_drawpixelinfo * dpi, sint32 width, sint32 height) const override;
};
