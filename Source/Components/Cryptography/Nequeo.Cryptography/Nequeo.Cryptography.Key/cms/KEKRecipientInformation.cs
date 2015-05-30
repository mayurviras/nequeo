using System;
using System.IO;

using Nequeo.Cryptography.Key.Asn1.Cms;
using Nequeo.Cryptography.Key.Asn1.X509;
using Nequeo.Cryptography.Key.Crypto;
using Nequeo.Cryptography.Key.Crypto.Parameters;
using Nequeo.Cryptography.Key.Security;

namespace Nequeo.Cryptography.Key.Cms
{
    /**
    * the RecipientInfo class for a recipient who has been sent a message
    * encrypted using a secret key known to the other side.
    */
    public class KekRecipientInformation
        : RecipientInformation
    {
        private KekRecipientInfo info;

		internal KekRecipientInformation(
			KekRecipientInfo	info,
			CmsSecureReadable	secureReadable)
			: base(info.KeyEncryptionAlgorithm, secureReadable)
		{
            this.info = info;
            this.rid = new RecipientID();

			KekIdentifier kekId = info.KekID;

			rid.KeyIdentifier = kekId.KeyIdentifier.GetOctets();
        }

		/**
        * decrypt the content and return an input stream.
        */
        public override CmsTypedStream GetContentStream(
            ICipherParameters key)
        {
			try
			{
				byte[] encryptedKey = info.EncryptedKey.GetOctets();
				IWrapper keyWrapper = WrapperUtilities.GetWrapper(keyEncAlg.ObjectID.Id);

				keyWrapper.Init(false, key);

				KeyParameter sKey = ParameterUtilities.CreateKeyParameter(
					GetContentAlgorithmName(), keyWrapper.Unwrap(encryptedKey, 0, encryptedKey.Length));

				return GetContentFromSessionKey(sKey);
			}
			catch (SecurityUtilityException e)
			{
				throw new CmsException("couldn't create cipher.", e);
			}
			catch (InvalidKeyException e)
			{
				throw new CmsException("key invalid in message.", e);
			}
        }
    }
}
