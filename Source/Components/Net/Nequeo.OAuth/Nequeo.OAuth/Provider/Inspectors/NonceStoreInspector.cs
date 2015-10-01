﻿/*  Company :       Nequeo Pty Ltd, http://www.nequeo.com.au/
 *  Copyright :     Copyright © Nequeo Pty Ltd 2012 http://www.nequeo.com.au/
 * 
 *  File :          
 *  Purpose :       
 * 
 */

#region Nequeo Pty Ltd License
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
#endregion

using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Web;
using System.IO;

using Nequeo.Cryptography.Signing;
using Nequeo.Net.OAuth.Storage;
using Nequeo.Net.OAuth.Framework;
using Nequeo.Net.OAuth.Framework.Signing;
using Nequeo.Net.OAuth.Framework.Utility;

namespace Nequeo.Net.OAuth.Provider.Inspectors
{
    /// <summary>
    /// Nonce store inspector
    /// </summary>
    public class NonceStoreInspector : IContextInspector
    {
        readonly INonceStore _nonceStore;

        /// <summary>
        /// Nonce store inspector
        /// </summary>
        /// <param name="nonceStore">The nonce store.</param>
        public NonceStoreInspector(INonceStore nonceStore)
        {
            if (nonceStore == null) throw new ArgumentNullException("nonceStore");
            _nonceStore = nonceStore;
        }

        /// <summary>
        /// Inspect the current context.
        /// </summary>
        /// <param name="phase">The current provider phase.</param>
        /// <param name="context">OAuth context</param>
        public void InspectContext(ProviderPhase phase, IOAuthContext context)
        {
            if (!_nonceStore.RecordNonceAndCheckIsUnique(context, context.Nonce))
            {
                throw Error.NonceHasAlreadyBeenUsed(context);
            }
        }
    }
}