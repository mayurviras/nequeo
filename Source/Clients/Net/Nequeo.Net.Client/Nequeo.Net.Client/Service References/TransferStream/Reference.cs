﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.544
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace Nequeo.Net.ServiceModel.TransferStream
{
    
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ServiceModel.ServiceContractAttribute(ConfigurationName="TransferStream.IStream")]
    public interface IStream {
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IStream/UploadStructuredFile", ReplyAction="http://tempuri.org/IStream/UploadStructuredFileResponse")]
        bool UploadStructuredFile(System.IO.Stream stream);
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IStream/UploadFile", ReplyAction="http://tempuri.org/IStream/UploadFileResponse")]
        bool UploadFile(System.IO.Stream stream);
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IStream/DownloadFile", ReplyAction="http://tempuri.org/IStream/DownloadFileResponse")]
        System.IO.Stream DownloadFile(string fileName);
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IStream/GetFileSize", ReplyAction="http://tempuri.org/IStream/GetFileSizeResponse")]
        long GetFileSize(string fileName);
    }
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public interface IStreamChannel : Nequeo.Net.ServiceModel.TransferStream.IStream, System.ServiceModel.IClientChannel
    {
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public partial class StreamClient : System.ServiceModel.ClientBase<Nequeo.Net.ServiceModel.TransferStream.IStream>, Nequeo.Net.ServiceModel.TransferStream.IStream
    {
        
        public StreamClient() {
        }
        
        public StreamClient(string endpointConfigurationName) : 
                base(endpointConfigurationName) {
        }
        
        public StreamClient(string endpointConfigurationName, string remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public StreamClient(string endpointConfigurationName, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public StreamClient(System.ServiceModel.Channels.Binding binding, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(binding, remoteAddress) {
        }
        
        public bool UploadStructuredFile(System.IO.Stream stream) {
            return base.Channel.UploadStructuredFile(stream);
        }
        
        public bool UploadFile(System.IO.Stream stream) {
            return base.Channel.UploadFile(stream);
        }
        
        public System.IO.Stream DownloadFile(string fileName) {
            return base.Channel.DownloadFile(fileName);
        }
        
        public long GetFileSize(string fileName) {
            return base.Channel.GetFileSize(fileName);
        }
    }
}