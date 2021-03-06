/* Company :       Nequeo Pty Ltd, http://www.nequeo.com.au/
*  Copyright :     Copyright � Nequeo Pty Ltd 2014 http://www.nequeo.com.au/
*
*  File :          Latin9Encoding.h
*  Purpose :       Latin9Encoding header.
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

#ifndef _LATIN9ENCODING_H
#define _LATIN9ENCODING_H

#include "GlobalText.h"
#include "TextEncoding.h"

namespace Nequeo{
	namespace IO{
		namespace Text
		{
			class Latin9Encoding : public TextEncoding
				/// ISO Latin-9 (8859-15) text encoding.
				///
				/// Latin-9 is basically Latin-1 with the EURO sign plus
				/// some other minor changes.
			{
			public:
				Latin9Encoding();
				~Latin9Encoding();
				const char* canonicalName() const;
				bool isA(const std::string& encodingName) const;
				const CharacterMap& characterMap() const;
				int convert(const unsigned char* bytes) const;
				int convert(int ch, unsigned char* bytes, int length) const;
				int queryConvert(const unsigned char* bytes, int length) const;
				int sequenceLength(const unsigned char* bytes, int length) const;

			private:
				static const char* _names[];
				static const CharacterMap _charMap;
			};
		}
	}
}
#endif
