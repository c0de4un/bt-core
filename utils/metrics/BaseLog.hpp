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

#ifndef BT_CORE_BASE_LOG_HPP
#define BT_CORE_BASE_LOG_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include bt::core::ILog
#ifndef BT_CORE_I_LOG_HXX
#include "ILog.hxx"
#endif // !BT_CORE_I_LOG_HXX

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
		 * BaseLog - base log class.
		 * 
		 * @version 0.1
		**/
		class BT_API BaseLog : public btILog
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
			// DELETED
			// ===========================================================

			BaseLog(const BaseLog&) = delete;
			BaseLog& operator=(const BaseLog&) = delete;
			BaseLog(BaseLog&&) = delete;
			BaseLog& operator=(BaseLog&&) = delete;

			// ===========================================================
			// CONSTRUCTOR
			// ===========================================================

			/**
			 * @brief
			 * BaseLog constructor.
			 *
			 * @throws - no exceptions.
			**/
			explicit BaseLog();

			// ===========================================================
			// METHODS
			// ===========================================================

			/**
			 * @brief
			 *
			 * Print INFO-Level Log-message.
			 *
			 * @thread_safety - thread-safe.
			 * @param pMsg - Log-Message to print.
			 * @throws - can throw exception.
			**/
			virtual void Info(const char* const pMsg);

			/**
			 * @brief
			 *
			 * Print INFO-Level Log-message.
			 *
			 * @thread_safety - thread-safe.
			 * @param pMsg - Log-Message to print.
			 * @throws - can throw exception.
			**/
			virtual void Info_W(const wchar_t* const pMsg);

			/**
			 * @brief
			 *
			 * Print DEBUG-Level Log-message.
			 *
			 * @thread_safety - thread-safe.
			 * @param pMsg - Log-Message to print.
			 * @throws - can throw exception.
			**/
			virtual void Debug(const char* const pMsg);

			/**
			 * @brief
			 *
			 * Print DEBUG-Level Log-message.
			 *
			 * @thread_safety - thread-safe.
			 * @param pMsg - Log-Message to print.
			 * @throws - can throw exception.
			**/
			virtual void Debug_W(const wchar_t* const pMsg);

			/**
			 * @brief
			 *
			 * Print WARNING-Level Log-message.
			 *
			 * @thread_safety - thread-safe.
			 * @param pMsg - Log-Message to print.
			 * @throws - can throw exception.
			**/
			virtual void Warning(const char* const pMsg);

			/**
			 * @brief
			 *
			 * Print WARNING-Level Log-message.
			 *
			 * @thread_safety - thread-safe.
			 * @param pMsg - Log-Message to print.
			 * @throws - can throw exception.
			**/
			virtual void Warning_W(const wchar_t* const pMsg);

			/**
			 * @brief
			 *
			 * Print ERROR-Level Log-message.
			 *
			 * @thread_safety - thread-safe.
			 * @param pMsg - Log-Message to print.
			 * @throws - can throw exception.
			**/
			virtual void Error(const char* const pMsg);

			/**
			 * @brief
			 *
			 * Print ERROR-Level Log-message.
			 *
			 * @thread_safety - thread-safe.
			 * @param pMsg - Log-Message to print.
			 * @throws - can throw exception.
			**/
			virtual void Error_W(const wchar_t* const pMsg);

			// -----------------------------------------------------------

		public:

			// -----------------------------------------------------------

			// ===========================================================
			// DESTRUCTOR
			// ===========================================================

			/**
			 * @brief
			 * BaseLog destructor.
			 * 
			 * @throws - no exceptions.
			**/
			virtual ~BaseLog();

			// ===========================================================
			// ILog
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
			virtual void Print(const char* const pMsg, const btLogLevel logLvl) final;

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
			virtual void Print_W(const wchar_t* const pMsg, const btLogLevel logLvl) final;

			// -----------------------------------------------------------

		}; /// bt::core::BaseLog

		// -----------------------------------------------------------

	} /// bt::core

} /// bt
using btBaseLog = bt::core::BaseLog;

// -----------------------------------------------------------

#endif // !BT_CORE_BASE_LOG_HPP