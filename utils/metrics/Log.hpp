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

#ifndef BT_CORE_LOG_HPP
#define BT_CORE_LOG_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// API
#ifndef BT_CFG_API_HPP
#include "../../../config/bt_api.hpp"
#endif // !BT_CFG_API_HPP

// ===========================================================
// FORWARD-DECLARATIONS
// ===========================================================

// Forward-Declare bt::core::ILog
#ifndef BT_CORE_I_LOG_DECL
#define BT_CORE_I_LOG_DECL
namespace bt { namespace core { class ILog; } }
using btILog = bt::core::ILog;
#endif // !BT_CORE_I_LOG_DECL

// ===========================================================
// TYPES
// ===========================================================

namespace bt
{

	namespace core
	{

		// -----------------------------------------------------------

		enum ELogLevel : unsigned char
		{

			// -----------------------------------------------------------

			BT_ENUM

			Info = 0,
			Debug = 1,
			Warning = 2,
			Error = 3

			// -----------------------------------------------------------

		}; /// bt::core::ELogLevel

		// -----------------------------------------------------------

		/**
		 * @brief
		 * Log - base log class. Also used as common static-logger util.
		 * 
		 * @version 0.1
		 * @authors Denis Z. (code4un@yandex.ru)
		**/
		class Log final
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
			// FIELDS
			// ===========================================================

			/** ILog instance (handler). **/
			static btILog* mInstance;

			// ===========================================================
			// DELETED
			// ===========================================================

			Log(const Log&) = delete;
			Log& operator=(const Log&) = delete;
			Log(Log&&) = delete;
			Log& operator=(Log&&) = delete;

			// ===========================================================
			// CONSTRUCTOR
			// ===========================================================

			explicit Log();

			// -----------------------------------------------------------

		public:

			// -----------------------------------------------------------

			// ===========================================================
			// DESTRUCTOR
			// ===========================================================

			~Log();

			// ===========================================================
			// GETTERS & SETTERS
			// ===========================================================

			/**
			 * @brief
			 * Returns current ILog instance.
			 * 
			 * @thread_safety - not thread-safe.
			 * @throws - no exceptions.
			**/
			static btILog* getInstance() noexcept;

			// ===========================================================
			// METHODS
			// ===========================================================

			/**
			 * @brief
			 * Initialize Logging.
			 * 
			 * @thread_safety - call only from main (ui/system) thread.
			 * @param pInstance - Log-instance to use.
			 * @throws - no exceptions.
			**/
			static void Initialize( btILog* const pInstance ) noexcept;

			/**
			 * @brief
			 * Terminate (release) Log-instance.
			 * 
			 * @thread_safety - main thread only.
			 * @throws - no exception.
			**/
			static void Terminate( ) noexcept;

			/**
			 * @brief
			 * Print chars (1 or multi-byte) to Log.
			 *
			 * @thread_safety - thread-safe.
			 * @param pMsg - chars to print.
			 * @param logLvl - Log-Level.
			 * @throws - can throw exception.
			**/
			static void Print( const char* const pMsg, const ELogLevel logLvl );

			/**
			 * @brief
			 * Print wchars (wstring) to Log.
			 * 
			 * @thread_safety - thread-safe.
			 * @param pMsg - wchars to print.
			 * @param logLvl - Log-Level.
			 * @throws - can throw exception.
			**/
			static void Print_W(const wchar_t* const pMsg, const ELogLevel logLvl);

			// -----------------------------------------------------------

		}; /// bt::core::Log

		// -----------------------------------------------------------

	} /// bt::core

} /// bt
#define BT_CORE_LOG_DECL

// -----------------------------------------------------------

// ===========================================================
// POST-CONFIG
// ===========================================================

#ifndef BT_CFG_LOG_HPP
#include "../../../config/bt_log.hpp"
#endif // !BT_CFG_LOG_HPP

// -----------------------------------------------------------

#endif // !BT_CORE_LOG_HPP