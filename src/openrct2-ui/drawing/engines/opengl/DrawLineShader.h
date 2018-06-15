/*****************************************************************************
 * Copyright (c) 2014-2018 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "GLSLTypes.h"
#include "OpenGLShaderProgram.h"
#include "DrawCommands.h"

class DrawLineShader final : public OpenGLShaderProgram
{
private:
    GLuint uScreenSize;

    GLuint vClip;
    GLuint vBounds;
    GLuint vColour;
    GLuint vDepth;

    GLuint vVertMat;

    GLuint _vbo;
    GLuint _vboInstances;
    GLuint _vao;

public:
    DrawLineShader();
    ~DrawLineShader() override;

    void SetScreenSize(sint32 width, sint32 height);
    void DrawInstances(const LineCommandBatch& instances);

private:
    void GetLocations();
};
