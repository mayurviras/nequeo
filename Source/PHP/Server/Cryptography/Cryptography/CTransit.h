/*  Company :       Nequeo Pty Ltd, http://www.nequeo.com.au/
 *  Copyright :     Copyright � Nequeo Pty Ltd 2012 http://www.nequeo.com.au/
 * 
 *  File :          CTransit.h
 *  Purpose :       
 * 
 */

/*
    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use,
    copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following
    conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#ifndef _CTRANSIT_
#define _CTRANSIT_

#include "stdafx.h"

#include "HashcodeType.h"

///	<summary>
///	Transit class.
///	</summary>
public class CTransit
{
	public:
		// Constructors
		CTransit();
		virtual ~CTransit();

		char* Encrypt(const char* value);
		char* Decrypt(const char* value);

		char* GetHashcode(const char* value, long hashcodeType);
		char* GetHashcodeMD5(const char* value);
		char* GetHashcodeSHA1(const char* value);
			
	private:
				
		bool m_disposed;
};

#endif