//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
// Developed by Minigraph
//
// Author:  James Stanard 
//

#pragma once

#include "pch.h"
#include "../../ExportHeader.h"

namespace GameCore
{
    extern D3D12PLAYGROUNDGRAPHICS_API bool gIsSupending;

    class D3D12PLAYGROUNDGRAPHICS_API IGameApp
    {
    public:
        // This function can be used to initialize application state and will run after essential
        // hardware resources are allocated.  Some state that does not depend on these resources
        // should still be initialized in the constructor such as pointers and flags.
        virtual void Startup( void ) = 0;
        virtual void Cleanup( void ) = 0;

        // Decide if you want the app to exit.  By default, app continues until the 'ESC' key is pressed.
        virtual bool IsDone( void );

        // The update method will be invoked once per frame.  Both state updating and scene
        // rendering should be handled by this method.
        virtual void Update( float deltaT ) = 0;

        // Official rendering pass
        virtual void RenderScene( void ) = 0;

        // Optional UI (overlay) rendering pass.  This is LDR.  The buffer is already cleared.
        virtual void RenderUI();
    };

    int D3D12PLAYGROUNDGRAPHICS_API RunApplication(IGameApp& app, const wchar_t* className, HINSTANCE hInst, int nCmdShow);
}