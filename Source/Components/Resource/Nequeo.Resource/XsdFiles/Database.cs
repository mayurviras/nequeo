﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:2.0.50727.5446
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// 
// This source code was auto-generated by xsd, Version=2.0.50727.3038.
// 
namespace Resources {
    using System.Xml.Serialization;
    
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.3038")]
    [System.SerializableAttribute()]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true)]
    [System.Xml.Serialization.XmlRootAttribute(Namespace="", IsNullable=false)]
    public partial class Context {
        
        private string databaseConnectionField;
        
        private string databaseField;
        
        private string namespaceCompanyNameField;
        
        private string namespaceExtendedNameField;
        
        private string dataBaseConnectField;
        
        private string dataBaseOwnerField;
        
        private byte connectionTypeField;
        
        private byte connectionDataTypeField;
        
        private string dataAccessProviderField;
        
        private bool tableListExclusionField;
        
        private string[] tableListField;
        
        /// <remarks/>
        public string DatabaseConnection {
            get {
                return this.databaseConnectionField;
            }
            set {
                this.databaseConnectionField = value;
            }
        }
        
        /// <remarks/>
        public string Database {
            get {
                return this.databaseField;
            }
            set {
                this.databaseField = value;
            }
        }
        
        /// <remarks/>
        public string NamespaceCompanyName {
            get {
                return this.namespaceCompanyNameField;
            }
            set {
                this.namespaceCompanyNameField = value;
            }
        }
        
        /// <remarks/>
        public string NamespaceExtendedName {
            get {
                return this.namespaceExtendedNameField;
            }
            set {
                this.namespaceExtendedNameField = value;
            }
        }
        
        /// <remarks/>
        public string DataBaseConnect {
            get {
                return this.dataBaseConnectField;
            }
            set {
                this.dataBaseConnectField = value;
            }
        }
        
        /// <remarks/>
        public string DataBaseOwner {
            get {
                return this.dataBaseOwnerField;
            }
            set {
                this.dataBaseOwnerField = value;
            }
        }
        
        /// <remarks/>
        public byte ConnectionType {
            get {
                return this.connectionTypeField;
            }
            set {
                this.connectionTypeField = value;
            }
        }
        
        /// <remarks/>
        public byte ConnectionDataType {
            get {
                return this.connectionDataTypeField;
            }
            set {
                this.connectionDataTypeField = value;
            }
        }
        
        /// <remarks/>
        public string DataAccessProvider {
            get {
                return this.dataAccessProviderField;
            }
            set {
                this.dataAccessProviderField = value;
            }
        }
        
        /// <remarks/>
        public bool TableListExclusion {
            get {
                return this.tableListExclusionField;
            }
            set {
                this.tableListExclusionField = value;
            }
        }
        
        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItemAttribute(IsNullable=false)]
        public string[] TableList {
            get {
                return this.tableListField;
            }
            set {
                this.tableListField = value;
            }
        }
    }
}
