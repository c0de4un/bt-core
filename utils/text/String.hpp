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

#ifndef BT_CORE_STRING_HPP
#define BT_CORE_STRING_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include bt::core::IString
#ifndef BT_CORE_I_STRING_HXX
#include "IString.hxx"
#endif // !BT_CORE_I_STRING_HXX

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
		 * String - universal symbols container.
		 * Designed to support char, wchar_t, int32.
		 * Depending on the platform, can switch between implementations.
		 * 
		 * @version 0.1
		 * @authors Denis Z. (code4un@yandex.ru)
		**/
		class BT_API String final : public btIString
		{

			// -----------------------------------------------------------

			// ===========================================================
			// META
			// ===========================================================

			BT_CLASS

			// -----------------------------------------------------------

		private:

			// -----------------------------------------------------------

			// ===========================================================
			// DELETED
			// ===========================================================

			String(const String&) = delete;
			String& operator=(const String&) = delete;
			String(String&&) = delete;
			String& operator=(String&&);

			// ===========================================================
			// FIELDS
			// ===========================================================

			/** Current Encoding. **/
			btEncoding mEncoding;

			/** Native container. **/
			void* mBuffer;

			// -----------------------------------------------------------

		public:

			// -----------------------------------------------------------

			// ===========================================================
			// FIELDS
			// ===========================================================

			// ===========================================================
			// CONSTRUCTORS & DESTRUCTOR
			// ===========================================================

			/**
			 * @brief
			 * String constructor for multi-bytes.
			 * 
			 * @param pChars - multi-byte chars c-string (usuall utf-8 2 chars per symbols).
			 * @param pEncoding - encoding (default is utf-8).
			**/
			explicit String( const char* const pChars, const btEncoding pEncoding = btEncoding::UTF8 );

			/**
			 * @brief
			 * String constructor for unicode.
			 *
			 * @param pChars - multi-byte chars c-string (usuall utf-8 2 chars per symbols).
			 * @param pEncoding - encoding (default is utf-8).
			**/
			explicit String(const wchar_t* const pChars);

			/**
			 * @brief
			 * String destructor.
			 * 
			 * @throws - no exceptions.
			**/
			virtual ~String();

			// ===========================================================
			// GETTERS & SETTERS
			// ===========================================================

			// ===========================================================
			// IString
			// ===========================================================

			// ===========================================================
			// METHODS
			// ===========================================================

			// -----------------------------------------------------------

		}; /// bt::core::String

	} /// bt::core

} /// bt
using btString = bt::core::String;
#define BT_CORE_STRING_DECL

// -----------------------------------------------------------

#endif // !BT_CORE_STRING_HPP