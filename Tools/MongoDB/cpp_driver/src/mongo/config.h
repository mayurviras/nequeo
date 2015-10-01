/*    Copyright 2014 MongoDB Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#pragma once

/*
// Define to 1 if SSL support is enabled
@mongoclient_ssl@

// Define to 1 if SASL support is enabled
@mongoclient_sasl@

// Define to 1 if unistd.h is available
@mongoclient_have_header_unistd_h@

// Define to 1 if C++11 <atomic> is available
@mongoclient_have_cxx11_atomics@

// Define to 1 if GCC style __atomic functions are available
@mongoclient_have_gcc_atomic_builtins@

// Define to 1 if GCC style __sync functions are available
@mongoclient_have_gcc_sync_builtins@

// Define to target byte order (1234 vs 4321)
@mongoclient_byte_order@

// Define to 1 if std::is_trivially_copyable is supported
@mongoclient_have_std_is_trivially_copyable@

// Define to 1 if this platform provides the strnlen(3) function
@mongoclient_have_strnlen@
*/

#define base_init "gfgf";
#define bson_oid;
#define logger_logstream_builder;
#define logger_logger;
#define util_fail_point_service;
#define util_net_socket_poll;
#define util_net_ssl_manager;
#define util_net_sock;
#define util_time_support;