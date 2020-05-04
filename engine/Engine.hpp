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

#ifndef BT_CORE_ENGINE_HPP
#define BT_CORE_ENGINE_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include bt::core::IEngine
#ifndef BT_CORE_I_ENGINE_HXX
#include "IEngine.hxx"
#endif // !BT_CORE_I_ENGINE_HXX

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
		class BT_API Engine : public btIEngine
		{

			// -----------------------------------------------------------

			// ===========================================================
			// META
			// ===========================================================

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
			 * @throws - can throw exception.
			**/
			explicit Engine();

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
			// bt::core::ISystem
			// ===========================================================

			/**
			 * @brief
			 * Start/Resume System.
			 *
			 * @thread_safety - thread-locks used.
			 * @return - 'true' if OK, 'false' if error.
			 * @throws - can throw exception.
			**/
			virtual bool StartSystem() final;

			/**
			 * @brief
			 * Pause System.
			 *
			 * @thread_safety - thread-locks used.
			 * @throws - can throw exception.
			**/
			virtual void PauseSystem() final;

			/**
			 * @brief
			 * Stop System.
			 * Unlikely #Pause, release (unload) all related resources.
			 *
			 * @thread_safety - thread-locks used.
			 * @throws - no exceptions.
			**/
			virtual void StopSystem() final;

			// ===========================================================
			// METHODS
			// ===========================================================

			/**
			 * @brief
			 * Called on Start.
			 * 
			 * @thread_safety - thread-safe.
			 * @return - 'true' if OK, 'false' if error.
			 * @throws - can throw exception.
			**/
			virtual bool onStart();

			/**
			 * @brief
			 * Called on Resume (unpause).
			 * 
			 * @thread_safety - thread-safe.
			 * @return - 'true' if OK, 'false' if error.
			 * @throws - can throw exception.
			**/
			virtual bool Resume();

			/**
			 * @brief
			 * Called upon Pause.
			 * 
			 * @thread_safety - thread-safe.
			 * @throws - can throw exception.
			**/
			virtual void onPause();

			/**
			 * @brief
			 * Called on Stop.
			 * 
			 * @thread_safety - thread-safe.
			 * @throws - can throw exception.
			**/
			virtual void onStop();

			// -----------------------------------------------------------

		}; /// bt::core::Engine

		// -----------------------------------------------------------

	} /// bt::core

} /// bt
using btEngine = bt::core::Engine;
#define BT_CORE_ENGINE_DECL

// -----------------------------------------------------------

#endif // !BT_CORE_ENGINE_HPP