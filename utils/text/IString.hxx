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

#ifndef BT_CORE_I_STRING_HXX
#define BT_CORE_I_STRING_HXX

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// API
#ifndef BT_CFG_API_HPP
#include "../../../config/bt_api.hpp"
#endif // !BT_CFG_API_HPP

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
		 * Encodings enum.
		**/
		enum BT_API Encoding : unsigned char
		{

			// -----------------------------------------------------------

			BT_ENUM

			ASCII = 0,
			ANSI = 1,
			UTF8 = 2,
			UTF8LE = 3,
			UTF8BE = 4,
			UTF16 = 5,
			UTF16LE = 6,
			UTF16BE = 7,
			UNICODE = 8,
			MAX = 99,

			// -----------------------------------------------------------

		}; /// bt::core::Encoding

		// -----------------------------------------------------------

		/**
		 * @brief
		 * IString - string interface to define base behavior.
		 * 
		 * @version 0.1
		 * @authors Denis Z. (code4un@yandex.ru)
		**/
		class BT_API IString
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

			// ===========================================================
			// GETTERS & SETTERS
			// ===========================================================

			// ===========================================================
			// METHODS
			// ===========================================================

			// -----------------------------------------------------------

		}; /// bt::core::IString

		// -----------------------------------------------------------

	} /// bt::core

} /// bt
using btIString = bt::core::IString;
using btEncoding = bt::core::Encoding;
#define BT_CORE_I_STRING_DECL

// -----------------------------------------------------------

#endif // !BT_CORE_I_STRING_HXX