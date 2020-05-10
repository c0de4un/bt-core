/**
* Copyright © 2020 Denis Z. (code4un@yandex.ru) All rights reserved.
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
#ifndef BT_CORE_ENGINE_HPP
#include "Engine.hpp"
#endif // !BT_CORE_ENGINE_HPP

// DEBUG
#ifdef BT_DEBUG

// Include bt::assert
#ifndef BT_CFG_ASSERTIONS_HPP
#include "../../config/bt_assertions.hpp"
#endif // !BT_CFG_ASSERTIONS_HPP

// Include bt::Log
#ifndef BT_CORE_LOG_HPP
#include "../utils/metrics/Log.hpp"
#endif // !BT_CORE_LOG_HPP

#endif
// DEBUG

// ===========================================================
// bt::core::Engine
// ===========================================================

namespace bt
{

	namespace core
	{

		// -----------------------------------------------------------

		// ===========================================================
		// CONSTRUCTOR & DESTRUCTOR
		// ===========================================================

		Engine::Engine(const ECSTypeID typeID)
			: System(typeID)
		{
		}

		Engine::~Engine()
		{
			System::Stop();
		}

		// ===========================================================
		// bt::ecs::System
		// ===========================================================

		bool Engine::onStart()
		{// @TODO Engine::onStart
#ifdef BT_DEBUG // DEBUG
			bt_Log::Print(u8"Engine::onStart", bt_LogLevel::Info);
#endif // DEBUG

			return false;
		}

		bool Engine::onResume()
		{// @TODO Engine::onResume
#ifdef BT_DEBUG // DEBUG
			bt_Log::Print(u8"Engine::onResume", bt_LogLevel::Info);
#endif // DEBUG

			return false;
		}

		void Engine::onPause()
		{// @TODO Engine::onPause
#ifdef BT_DEBUG // DEBUG
			bt_Log::Print(u8"Engine::onPause", bt_LogLevel::Info);
#endif // DEBUG
		}

		void Engine::onStop()
		{// @TODO Engine::onStop
#ifdef BT_DEBUG // DEBUG
			bt_Log::Print(u8"Engine::onStop", bt_LogLevel::Info);
#endif // DEBUG
		}

		// ===========================================================
		// METHODS
		// ===========================================================



		// -----------------------------------------------------------

	} /// bt::core

} /// bt

// -----------------------------------------------------------