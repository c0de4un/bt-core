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

#ifndef BT_CORE_ENGINE_HPP
#define BT_CORE_ENGINE_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ecs::System
#ifndef ECS_SYSTEM_HPP
#include "../../ecs/systems/System.hpp"
#endif // !ECS_SYSTEM_HPP

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
		 * Engine - base engine class.
		 *
		 * @version 0.1
		**/
		class BT_API Engine : public ecs_System
		{

			// -----------------------------------------------------------

			// ===========================================================
			// META
			// ===========================================================

			BT_CLASS

			// -----------------------------------------------------------

		protected:

			// -----------------------------------------------------------

			// ===========================================================
			// FIELDS
			// ===========================================================

			// ===========================================================
			// DELETED
			// ===========================================================

			Engine(const Engine&) = delete;
			Engine& operator=(const Engine&) = delete;
			Engine(Engine&&) = delete;
			Engine& operator=(Engine&&) = delete;

			// -----------------------------------------------------------

		public:

			// -----------------------------------------------------------

			// ===========================================================
			// CONSTRUCTOR & DESTRUCTOR
			// ===========================================================

			/**
			 * @brief
			 * Engine constructor.
			 * 
			 * @param typeID - Engine Type-ID, defautl is Engine-Type..
			 * @throws - can throw exception.
			**/
			explicit Engine( const ECSTypeID typeID = 1 );

			/**
			 * @brief
			 * Engine destructor.
			 * 
			 * @throws - can throw exception.
			**/
			virtual ~Engine();

			// ===========================================================
			// GETTERS & SETTERS
			// ===========================================================

			// ===========================================================
			// bt::ecs::System
			// ===========================================================

			/**
			 * @brief
			 * Called when System starting.
			 *
			 * @thread_safety - thread-lock used.
			 * @throws - can throw exception.
			**/
			virtual bool onStart() override;

			/**
			 * @brief
			 * Called whe System resuming from pause.
			 *
			 * @thread_safety - thread-lock used.
			 * @throws - can throw exception.
			**/
			virtual bool onResume() override;

			/**
			 * @brief
			 * Called whe System pausing.
			 *
			 * @thread_safety - thread-lock used.
			 * @throws - can throw exception.
			**/
			virtual void onPause() override;

			/**
			 * @brief
			 * Called whe System stopping.
			 *
			 * @thread_safety - thread-lock used.
			 * @throws - can throw exception.
			**/
			virtual void onStop() override;

			// ===========================================================
			// METHODS
			// ===========================================================



			// -----------------------------------------------------------

		}; /// bt::core::Engine

		// -----------------------------------------------------------

	} /// bt::core

} /// bt

using bt_Engine = bt::core::Engine;
#define BT_CORE_ENGINE_DECL

// -----------------------------------------------------------

#endif // !BT_CORE_ENGINE_HPP