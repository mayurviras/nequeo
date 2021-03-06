using System;

using Nequeo.Cryptography.Key.Crypto;
using Nequeo.Cryptography.Key.Utilities.IO;

namespace Nequeo.Cryptography.Key.Cms
{
	internal class MacOutputStream
		: BaseOutputStream
	{
		private readonly IMac mac;

		internal MacOutputStream(IMac mac)
		{
			this.mac = mac;
		}

		public override void Write(byte[] b, int off, int len)
		{
			mac.BlockUpdate(b, off, len);
		}

		public override void WriteByte(byte b)
		{
			mac.Update(b);
		}
	}
}
