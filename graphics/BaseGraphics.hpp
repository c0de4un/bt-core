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

#ifndef BT_CORE_BASE_GRAPHICS_HPP
#define BT_CORE_BASE_GRAPHICS_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include bt::core::IGraphics
#ifndef BT_CORE_I_GRAPHICS_HXX
#include "IGraphics.hxx"
#endif // !BT_CORE_I_GRAPHICS_HXX

// Include bt::ecs::ISystem
#ifndef BT_ECS_I_SYSTEM_HXX
#endif // !BT_ECS_I_SYSTEM_HXX

// Include bt::ecs::IEventsListener
#ifndef BT_ECS_I_EVENTS_LISTENER_HXX

#endif // !BT_ECS_I_EVENTS_LISTENER_HXX

// ===========================================================
// FORWARD-DECLARATIONS
// ===========================================================

// Forward-Declare bt::core::IRender

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
		 * BaseGraphics - base graphics manager implementation.
		 * 
		 * @version 0.1
		**/
		class BT_API BaseGraphics : public bt_IGraphics
		{// @TODO BaseGraphics

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
			// CONSTRUCTOR
			// ===========================================================

			// ===========================================================
			// DELETED
			// ===========================================================

			BaseGraphics(const BaseGraphics&) = delete;
			BaseGraphics& operator=(const BaseGraphics&) = delete;
			BaseGraphics(BaseGraphics&&) = delete;
			BaseGraphics& operator=(BaseGraphics&&) = delete;

			// -----------------------------------------------------------

		public:

			// -----------------------------------------------------------

			// ===========================================================
			// DESTRUCTOR
			// ===========================================================

			/**
			 * @brief
			 * BaseGraphics destructor.
			 * 
			 * @throws - can throw exception.
			**/
			virtual ~BaseGraphics();

			// ===========================================================
			// GETTERS & SETTERS
			// ===========================================================

			// ===========================================================
			// bt::core::IGraphics
			// ===========================================================

			// ===========================================================
			// bt::ecs::ISystem
			// ===========================================================

			// ===========================================================
			// METHODS
			// ===========================================================

			// -----------------------------------------------------------

		}; /// bt::core::BaseGraphics

		// -----------------------------------------------------------

	} /// bt::core

} /// bt
using bt_BaseGraphics = bt::core::BaseGraphics;
#define BT_CORE_BASE_GRAPHICS_DECL

// -----------------------------------------------------------

#endif // !BT_CORE_BASE_GRAPHICS_HPP