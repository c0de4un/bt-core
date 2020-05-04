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

#ifndef BT_CORE_I_LOG_HXX
#define BT_CORE_I_LOG_HXX

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// bt::core::Log
#ifndef BT_CORE_LOG_HPP
#include "Log.hpp"
#endif // !BT_CORE_LOG_HPP

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
		 * ILog - base logging interface (behavior).
		 * 
		 * @version 0.1
		**/
		class BT_API ILog
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
			 * ILog destructor.
			 * 
			**/
			virtual ~ILog()
			{
			}

			// ===========================================================
			// METHODS
			// ===========================================================

			/**
			 * @brief
			 * Print Log-message.
			 * 
			 * @thread_safety - thread-safe.
			 * @param pMsg - Log-Message to print.
			 * @param logLvl - Log-Level (Info, Debug, etc).
			 * @throws - can throw exception.
			**/
			virtual void Print( const char* const pMsg, const ELogLevel logLvl ) = 0;

			/**
			 * @brief
			 * Print Log-message, using wchar_t.
			 * 
			 * (?) Event if this method does exists, still, avoid using it.
			 * Some platforms (Android) doesn't use wchar_t at all, instead
			 * multi-byte char (2 chars per symbol) used by default.
			 * 
			 * @thread_safety - thread-safe.
			 * @param pMsg - Log-Message to print.
			 * @param logLvl - Log-Level (Info, Debug, etc).
			 * @throws - can throw exception.
			**/
			virtual void Print_W( const wchar_t* const pMsg, const ELogLevel logLvl ) = 0;

			// -----------------------------------------------------------

		}; /// bt::core::ILog

		// -----------------------------------------------------------

	} /// bt::core

} /// bt
using btILog = bt::core::ILog;
#define BT_CORE_I_LOG_DECL

// -----------------------------------------------------------

#endif // !BT_CORE_I_LOG_HXX