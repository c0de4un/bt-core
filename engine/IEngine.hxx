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

#ifndef BT_CORE_I_ENGINE_HXX
#define BT_CORE_I_ENGINE_HXX

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include btEngine API
#ifndef BT_CFG_API_HPP
#include "../../config/bt_api.hpp"
#endif // !BT_CFG_API_HPP

// Include bt::ecs::ISystem
#ifndef BT_ECS_I_SYSTEM_HXX
#include "../../ecs/systems/ISystem.hxx"
#endif // !BT_ECS_I_SYSTEM_HXX

// ===========================================================
// TYPES
// ===========================================================

namespace bt
{

	namespace core
	{

		// -----------------------------------------------------------

		/**
		 * @brief
		 * IEngine - engine interface.
		 * Allows to separate implementation & data from behavior requirements.
		 *
		 * @version 0.1
		 * @authors Denis Z. (code4un@yandex.ru)
		**/
		class BT_API IEngine : public ecs_ISystem
		{

			// -----------------------------------------------------------

			// ===========================================================
			// META
			// ===========================================================

			BT_INTERFACE

			// -----------------------------------------------------------

		public:

			// -----------------------------------------------------------

			// ===========================================================
			// DESTRUCTOR
			// ===========================================================

			/**
			 * @brief
			 * IEngine destructor.
			 * 
			 * @throws - no exceptions.
			**/
			virtual ~IEngine()
			{
			}

			// ===========================================================
			// GETTERS & SETTERS
			// ===========================================================

			// ===========================================================
			// METHODS
			// ===========================================================

			/**
			 * @brief
			 * Start/Resume Engine.
			 *
			 * @thread_safety - thread-safe.
			 * @return - 'true' if started/resumed, 'false' if error.
			 * @throws - can throw exception.
			**/
			bool StartEngine()
			{ return this->StartSystem(); }

			/**
			 * @brief
			 * Pause Engine.
			 *
			 * @thread_safety - thread-locks used.
			 * @throws - can throw exception.
			**/
			void PauseEngine()
			{ this->PauseSystem(); }

			/**
			 * @brief
			 * Stop Engine.
			 * Unlikely #Pause, release (unload) all related resources.
			 *
			 * @thread_safety - thread-locks used.
			 * @throws - no exceptions.
			**/
			void StopEngine()
			{ this->StopSystem(); }

			// -----------------------------------------------------------

		}; /// bt::core::IEngine

		// -----------------------------------------------------------

	} /// bt::core

} /// bt
using btIEngine = bt::core::IEngine;
#define BT_CORE_I_ENGINE_DECL

// -----------------------------------------------------------

#endif // !BT_CORE_I_ENGINE_HXX