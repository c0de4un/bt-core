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

#ifndef BT_ENGINE_HPP
#define BT_ENGINE_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include bt::api
#ifndef BT_CFG_API_HPP
#include "../config/bt_api.hpp"
#endif // !BT_CFG_API_HPP

// Include bt::lock
#ifndef BT_CFG_LOCK_HPP
#include "../config/bt_lock.hpp"
#endif // !BT_CFG_LOCK_HPP

// Include bt::memory
#ifndef BT_CFG_MEMORY_HPP
#include "../config/bt_memory.hpp"
#endif // !BT_CFG_MEMORY_HPP

// ===========================================================
// FORWARD-DECLARATIONS
// ===========================================================

// Forward-declare bt::core::IEngine
#ifndef BT_CORE_I_ENGINE_DECL
#define BT_CORE_I_ENGINE_DECL
namespace bt { namespace core { class IEngine; } }
using btIEngine = bt::core::IEngine;
#endif // !BT_CORE_I_ENGINE_DECL

// ===========================================================
// TYPES
// ===========================================================

namespace bt
{

	/**
	 * @brief
	 * API - common access provieder to btEngine API.
	 * Allows to avoid manual caching & managing API-objects, like Engine, Renderer, etc.,
	 * providing thread-safe handlerswithout knowing specific implementations.
	 * 
	 * @version 0.1
	**/
	class BT_API API final
	{

		// -----------------------------------------------------------

		// ===========================================================
		// META
		// ===========================================================

		// -----------------------------------------------------------

	private:

		// -----------------------------------------------------------

		// ===========================================================
		// FIELDS
		// ===========================================================

		/** bt::core::IEngine instance. **/
		static bt_sptr<btIEngine> mEngine;
		
		// ===========================================================
		// CONSTRUCTOR
		// ===========================================================

		/**
		 * @brief
		 * API constructor.
		 * 
		 * @throws - can throw exception.
		**/
		explicit API();

		// ===========================================================
		// DELETED
		// ===========================================================

		// -----------------------------------------------------------

	public:

		// -----------------------------------------------------------

		// ===========================================================
		// DESTRUCTOR
		// ===========================================================

		/**
		 * @brief
		 * API destructor.
		 * 
		 * @throws - no exceptions.
		**/
		~API();

		// ===========================================================
		// GETTERS & SETTERS
		// ===========================================================

		/**
		 * @brief
		 * Returns current IEngine instance.
		 * 
		 * @thread_safety - weak-pointer used (thread-lock).
		 * @return - weak-pointer to the IEngine, or null.
		 * @throws - no exceptions.
		**/
		static BT_API bt_wptr<btIEngine> getEngine() BT_NOEXCEPT;

		// ===========================================================
		// METHODS
		// ===========================================================

		/**
		 * @brief
		 * Initialize Engine.
		 * 
		 * @thread_safety - main (system/ui) thread-only.
		 * @param engineInstance - IEngine implementation.
		 * @throws - can throw exception.
		**/
		static BT_API void Initialize( bt_sptr<btIEngine>& engineInstance );

		/**
		 * @brief
		 * Terminate Engine.
		 * 
		 * @thread_safety - thread-safe.
		 * @throws - can throw exception.
		**/
		static BT_API void Terminate( );

		// -----------------------------------------------------------

	}; /// bt::API

} /// bt
using btAPI = bt::API;
#define BT_ENGINE_DECL

// -----------------------------------------------------------

#endif // !BT_ENGINE_HPP