/* Company :       Nequeo Pty Ltd, http://www.nequeo.com.au/
*  Copyright :     Copyright � Nequeo Pty Ltd 2016 http://www.nequeo.com.au/
*
*  File :          Global.h
*  Purpose :       Global.
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

#include "stdafx.h"

#ifdef NEQUEOAWSMANAGEMENT_EXPORTS
#define EXPORT_NEQUEO_AWS_MANAGEMENT_API __declspec(dllexport) 
#else
#define EXPORT_NEQUEO_AWS_MANAGEMENT_API __declspec(dllimport) 
#endif

// Global Aws definitions.
#include <aws\core\Aws.h>
#include <aws\core\Region.h>
#include <aws\core\SDKConfig.h>
#include <aws\core\Core_EXPORTS.h>
#include <aws\core\auth\AWSCredentialsProvider.h>
#include <aws\core\utils\Outcome.h>
#include <aws\core\utils\StringUtils.h>
#include <aws\core\utils\threading\Executor.h>
#include <aws\core\utils\threading\ThreadTask.h>
#include <aws\core\utils\memory\AWSMemory.h>
#include <aws\core\utils\memory\stl\AWSAllocator.h>
#include <aws\core\utils\memory\stl\AWSString.h>
#include <aws\core\utils\ratelimiter\DefaultRateLimiter.h>
#include <aws\core\client\RetryStrategy.h>
#include <aws\core\client\ClientConfiguration.h>
#include <aws\core\client\AWSError.h>
