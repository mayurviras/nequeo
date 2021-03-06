﻿/*  Company :       Nequeo Pty Ltd, http://www.nequeo.com.au/
 *  Copyright :     Copyright © Nequeo Pty Ltd 2010 http://www.nequeo.com.au/
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
using System.Text;

namespace Nequeo.Data.Custom
{
    /// <summary>
    /// Database rountine type.
    /// </summary>
    public enum FunctionRoutineType
    {
        #region Function Routine
        /// <summary>
        /// no rountine.
        /// </summary>
        None = 0,
        /// <summary>
        /// Stored procedure rountine.
        /// </summary>
        StoredProcedure = 1,
        /// <summary>
        /// Table function rountine.
        /// </summary>
        TableFunction = 2,
        /// <summary>
        /// Scalar function rountine.
        /// </summary>
        ScalarFunction = 3,

        #endregion
    }

    /// <summary>
    /// Custom data column attribute.
    /// </summary>
    [Serializable]
    [AttributeUsage(AttributeTargets.Property | AttributeTargets.Field)]
    public sealed class DataColumnAttribute : System.Attribute
    {
        #region Constructors
        /// <summary>
        /// Default constructor.
        /// </summary>
        /// <param name="columnName">The name of the column.</param>
        public DataColumnAttribute(string columnName)
        {
            _columnName = columnName;
        }
        #endregion

        #region Private Fields
        private string _columnName = string.Empty;
        private bool _isPrimaryKey = false;
        private bool _isAutoGenerated = false;
        private bool _isRowVersion = false;
        private bool _isNullable = false;
        private string _dbType = "VarChar";
        private long _length = -1;
        #endregion

        #region Public Properties
        /// <summary>
        /// Gets sets, the data column name.
        /// </summary>
        public string ColumnName
        {
            get { return _columnName; }
            set { _columnName = value; }
        }

        /// <summary>
        /// Gets sets, is the column a primary key.
        /// </summary>
        public bool IsPrimaryKey
        {
            get { return _isPrimaryKey; }
            set { _isPrimaryKey = value; }
        }

        /// <summary>
        /// Gets sets, is the column auto generated.
        /// </summary>
        public bool IsAutoGenerated
        {
            get { return _isAutoGenerated; }
            set { _isAutoGenerated = value; }
        }

        /// <summary>
        /// Gets sets, is the column a row versioning column.
        /// </summary>
        public bool IsRowVersion
        {
            get { return _isRowVersion; }
            set { _isRowVersion = value; }
        }

        /// <summary>
        /// Gets sets, is the column a nullable column.
        /// </summary>
        public bool IsNullable
        {
            get { return _isNullable; }
            set { _isNullable = value; }
        }

        /// <summary>
        /// Gets sets, the database type of the column.
        /// </summary>
        public string DbType
        {
            get { return _dbType; }
            set { _dbType = value; }
        }

        /// <summary>
        /// Gets sets, the length of the column type.
        /// </summary>
        public long Length
        {
            get { return _length; }
            set { _length = value; }
        }
        #endregion
    }

    /// <summary>
    /// Custom data column foreign key attribute.
    /// </summary>
    [Serializable]
    [AttributeUsage(AttributeTargets.Property | AttributeTargets.Field)]
    public sealed class DataColumnForeignKeyAttribute : System.Attribute
    {
        #region Constructors
        /// <summary>
        /// Default constructor.
        /// </summary>
        /// <param name="foreignKeyTable">The name of the foreign key table.</param>
        public DataColumnForeignKeyAttribute(string foreignKeyTable)
        {
            _foreignKeyTable = foreignKeyTable;
        }
        #endregion

        #region Private Fields
        private string _columnName = string.Empty;
        private string _columnType = "varchar";
        private string _foreignKeyTable = string.Empty;
        private string _foreignKeyColumnName = string.Empty;
        private bool _isNullable = false;
        private bool _isReference = false;
        private long _length = -1;
        #endregion

        #region Public Properties
        /// <summary>
        /// Gets sets, the data column name.
        /// </summary>
        public string ColumnName
        {
            get { return _columnName; }
            set { _columnName = value; }
        }

        /// <summary>
        /// Gets sets, the data column database type.
        /// </summary>
        public string ColumnType
        {
            get { return _columnType; }
            set { _columnType = value; }
        }

        /// <summary>
        /// Gets sets, the name of the reference table.
        /// </summary>
        public string Name
        {
            get { return _foreignKeyTable; }
            set { _foreignKeyTable = value; }
        }

        /// <summary>
        /// Gets sets, the name of the reference column name.
        /// </summary>
        public string ReferenceColumnName
        {
            get { return _foreignKeyColumnName; }
            set { _foreignKeyColumnName = value; }
        }

        /// <summary>
        /// Gets sets, is the column a nullable column.
        /// </summary>
        public bool IsNullable
        {
            get { return _isNullable; }
            set { _isNullable = value; }
        }

        /// <summary>
        /// Gets sets, is the column a reference.
        /// </summary>
        public bool IsReference
        {
            get { return _isReference; }
            set { _isReference = value; }
        }

        /// <summary>
        /// Gets sets, the length of the column type.
        /// </summary>
        public long Length
        {
            get { return _length; }
            set { _length = value; }
        }
        #endregion
    }

    /// <summary>
    /// Custom data column attribute.
    /// </summary>
    [Serializable]
    [AttributeUsage(AttributeTargets.Class | AttributeTargets.Struct)]
    public sealed class DataTableAttribute : System.Attribute
    {
        #region Constructors
        /// <summary>
        /// Default constructor.
        /// </summary>
        /// <param name="tableName">The name of the table.</param>
        public DataTableAttribute(string tableName)
        {
            _tableName = tableName;
        }
        #endregion

        #region Private Fields
        private string _tableName = string.Empty;
        #endregion

        #region Public Properties
        /// <summary>
        /// Gets sets, the data table name.
        /// </summary>
        public string TableName
        {
            get { return _tableName; }
            set { _tableName = value; }
        }
        #endregion
    }

    /// <summary>
    /// Database attribute.
    /// </summary>
    [Serializable]
    [AttributeUsage(AttributeTargets.Class | AttributeTargets.Struct)]
    public sealed class DatabaseAttribute : System.Attribute
    {
        #region Constructors
        /// <summary>
        /// Default constructor.
        /// </summary>
        /// <param name="databaseName">The name of the database.</param>
        public DatabaseAttribute(string databaseName)
        {
            _databaseName = databaseName;
        }
        #endregion

        #region Private Fields
        private string _databaseName = string.Empty;
        #endregion

        #region Public Properties
        /// <summary>
        /// Gets sets, the database name.
        /// </summary>
        public string Name
        {
            get { return _databaseName; }
            set { _databaseName = value; }
        }
        #endregion
    }

    /// <summary>
    /// Function attribute.
    /// </summary>
    [Serializable]
    [AttributeUsage(AttributeTargets.Method)]
    public sealed class FunctionRoutineAttribute : System.Attribute
    {
        #region Constructors
        /// <summary>
        /// Default constructor.
        /// </summary>
        /// <param name="functionName">The name of the function.</param>
        /// <param name="functionRoutineType">The function routine type.</param>
        public FunctionRoutineAttribute(string functionName, FunctionRoutineType functionRoutineType)
        {
            _functionName = functionName;
            _functionRoutineType = functionRoutineType;
        }
        #endregion

        #region Private Fields
        private bool _isMultiRecordSet = false;
        private string _functionName = string.Empty;
        private FunctionRoutineType _functionRoutineType = FunctionRoutineType.None;
        #endregion

        #region Public Properties
        /// <summary>
        /// Gets sets, the function name.
        /// </summary>
        public string Name
        {
            get { return _functionName; }
            set { _functionName = value; }
        }

        /// <summary>
        /// Gets sets, the function routine type.
        /// </summary>
        public FunctionRoutineType FunctionRoutineType
        {
            get { return _functionRoutineType; }
            set { _functionRoutineType = value; }
        }

        /// <summary>
        /// Gets sets, the multiple result set indicator.
        /// </summary>
        public bool IsMultiResultSet
        {
            get { return _isMultiRecordSet; }
            set { _isMultiRecordSet = value; }
        }
        #endregion
    }

    /// <summary>
    /// Function multi return type attribute.
    /// </summary>
    [Serializable]
    [AttributeUsage(AttributeTargets.Method, AllowMultiple = true)]
    public sealed class FunctionMultiReturnTypeAttribute : System.Attribute
    {
        #region Constructors
        /// <summary>
        /// Default constructor.
        /// </summary>
        /// <param name="returnType">The return type.</param>
        /// <param name="order">The order in which the type is loaded.</param>
        public FunctionMultiReturnTypeAttribute(Type returnType, int order)
        {
            _order = order;
            _returnType = returnType;
        }
        #endregion

        #region Private Fields
        private int _order = 0;
        private Type _returnType;
        #endregion

        #region Public Properties
        /// <summary>
        /// Gets sets, the return type.
        /// </summary>
        public int Order
        {
            get { return _order; }
            set { _order = value; }
        }

        /// <summary>
        /// Gets sets, the return type.
        /// </summary>
        public Type ReturnType
        {
            get { return _returnType; }
            set { _returnType = value; }
        }
        #endregion
    }

    /// <summary>
    /// Function attribute.
    /// </summary>
    [Serializable]
    [AttributeUsage(AttributeTargets.Parameter | AttributeTargets.GenericParameter)]
    public sealed class FunctionParameterAttribute : System.Attribute
    {
        #region Constructors
        /// <summary>
        /// Default constructor.
        /// </summary>
        /// <param name="parameterName">The name of the parameter.</param>
        /// <param name="dbType">The database type.</param>
        /// <param name="length">The parameter length.</param>
        /// <param name="parameterDirection">The parameter direction.</param>
        /// <param name="isNullable">Is the paramter nullable.</param>
        public FunctionParameterAttribute(string parameterName, string dbType, long length,
            System.Data.ParameterDirection parameterDirection, bool isNullable)
        {
            _parameterName = parameterName;
            _dbType = dbType;
            _length = length;
            _parameterDirection = parameterDirection;
            _isNullable = isNullable;
        }
        #endregion

        #region Private Fields
        private string _parameterName = string.Empty;
        private string _dbType = "VarChar";
        private long _length = -1;
        private bool _isNullable = true;
        private System.Data.ParameterDirection _parameterDirection = System.Data.ParameterDirection.Input;
        #endregion

        #region Public Properties
        /// <summary>
        /// Gets sets, the parameter name.
        /// </summary>
        public string Name
        {
            get { return _parameterName; }
            set { _parameterName = value; }
        }

        /// <summary>
        /// Gets sets, the database type of the column.
        /// </summary>
        public string DbType
        {
            get { return _dbType; }
            set { _dbType = value; }
        }

        /// <summary>
        /// Gets sets, the length of the column type.
        /// </summary>
        public long Length
        {
            get { return _length; }
            set { _length = value; }
        }

        /// <summary>
        /// Gets sets, the function routine type.
        /// </summary>
        public System.Data.ParameterDirection ParameterDirection
        {
            get { return _parameterDirection; }
            set { _parameterDirection = value; }
        }

        /// <summary>
        /// Gets sets, is the column a nullable column.
        /// </summary>
        public bool IsNullable
        {
            get { return _isNullable; }
            set { _isNullable = value; }
        }
        #endregion
    }

    /// <summary>
    /// Custom type property mapping attribute.
    /// </summary>
    [Serializable]
    [AttributeUsage(AttributeTargets.Property | AttributeTargets.Field, AllowMultiple = true)]
    public sealed class PropertyMappingAttribute : System.Attribute
    {
        #region Constructors
        /// <summary>
        /// Default constructor.
        /// </summary>
        /// <param name="mappingName">the property mapping name.</param>
        /// <param name="mappingSource">The mapping source type.</param>
        public PropertyMappingAttribute(string mappingName, Type mappingSource)
        {
            _mappingName = mappingName;
            _mappingSource = mappingSource;
        }
        #endregion

        #region Private Fields
        private string _mappingName = string.Empty;
        private Type _mappingSource = null;
        #endregion

        #region Public Properties
        /// <summary>
        /// Gets sets, the property mapping name.
        /// </summary>
        public string Name
        {
            get { return _mappingName; }
            set { _mappingName = value; }
        }

        /// <summary>
        /// Gets sets, the mapping source type.
        /// </summary>
        public Type MappingSource
        {
            get { return _mappingSource; }
            set { _mappingSource = value; }
        }
        #endregion
    }
}
