/***
* ==++==
*
* Copyright (c) 2016 by Hyunuk Kim <nnhope@hotmail.com>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* ==--==
* =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
*
* Network.cpp
*
* A number of network-utility functions implementation.
*
* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
****/

#include <elabo\Network.h>

#include <Windows.h>

namespace elabo
{
namespace network
{

bool GetLocalAddress( std::vector<std::string>& vecAddr )
{
	vecAddr.reserve( 4 );

	WSADATA data;
	if ( WSAStartup( 0x0202, &data ) != 0 )
	{
		return false;
	}

	char name[ MAX_PATH ] = { 0, };
	if ( gethostname( name, sizeof( name ) ) == SOCKET_ERROR )
	{
		return false;
	}

	hostent *entry = gethostbyname( name );
	if ( entry == nullptr )
	{
		return false;
	}

	for ( int i = 0; nullptr != entry->h_addr_list[ i ]; i++ )
	{
		in_addr addr;
		memcpy( &addr, entry->h_addr_list[ i ], sizeof( in_addr ) );
		std::string address = inet_ntoa( addr );
		vecAddr.emplace_back( std::string( inet_ntoa( addr ) ) );
	}

	return true;
}

} // namespace network

} // namespace elabo
