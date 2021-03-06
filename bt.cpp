/**
* Copyright � 2020 Denis Z. (code4un@yandex.ru) All rights reserved.
* Authors: Denis Z. (code4un@yandex.ru)
* All rights reserved.
* Language: C++
* License: see LICENSE.txt
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* 1. Redistributions of source code must retain the above copyright notice,
* this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must display the names 'Denis Zyamaev' and
* in the credits of the application, if such credits exist.
* The authors of this work must be notified via email (code4un@yandex.ru) in
* this case of redistribution.
* 3. Neither the name of copyright holders nor the names of its contributors
* may be used to endorse or promote products derived from this software
* without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
* IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
**/

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// HEADER
#ifndef BT_ENGINE_HPP
#include "bt.hpp"
#endif // !BT_ENGINE_HPP

// Include bt::ecs
#ifndef BT_ECS_HPP
#include "../ecs/ecs.hpp"
#endif // !BT_ECS_HPP

// Include bt::core::Engine
#ifndef BT_CORE_ENGINE_HPP
#include "engine/Engine.hpp"
#endif // !BT_CORE_ENGINE_HPP

// DEBUG
#ifdef BT_DEBUG

// Include bt::core::Log
#ifndef BT_CORE_LOG_HPP
#include "core/utils/metrics/Log.hpp"
#endif // !BT_CORE_LOG_HPP

// Include bt::assert
#ifndef BT_CFG_ASSERTIONS_HPP
#include "../config/bt_assertions.hpp"
#endif // !BT_CFG_ASSERTIONS_HPP

#endif
// DEBUG

// ===========================================================
// bt::API
// ===========================================================

namespace bt
{

	// -----------------------------------------------------------

	// ===========================================================
	// CONSTANTS & FIELDS
	// ===========================================================

	bt_sptr<bt_Engine> API::mEngine( nullptr );

	// ===========================================================
	// CONSTRUCTOR & DESTRUCTOR
	// ===========================================================

	API::API()
	{
	}

	API::~API()
	{
	}

	// ===========================================================
	// GETTERS & SETTERS
	// ===========================================================

	bt_sptr<bt_Engine> API::getEngine() BT_NOEXCEPT
	{ return mEngine; }

	// ===========================================================
	// METHODS
	// ===========================================================

	void API::Initialize(bt_sptr<bt_Engine>& engineInstance)
	{

#ifdef BT_DEBUG // DEBUG
		bt_assert( !mEngine && "API::Initialize - Engine already set !" );
#endif // DEBUG

		// Copy Engine pointer-value.
		mEngine = engineInstance;

		// Initialize ECS
		if ( !ECS::Initialize() ) {

#ifdef BT_DEBUG // DEBUG
			bt_Log::Print( u8"API::Initialize - failed to initialize ECS !", bt_LogLevel::Error );
#endif // DEBUG

			Terminate();
			return;
		}

	}

	void API::Terminate()
	{

		// Release instance.
		mEngine.reset();

		// Terminate ECS
		ECS::Terminate();

	}

	// -----------------------------------------------------------

} /// bt

// -----------------------------------------------------------