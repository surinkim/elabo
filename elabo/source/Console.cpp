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
* Console.cpp
*
* Windows console specific functions.
*
* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
****/

#include <elabo\Console.h>

#include <stdio.h> 

namespace elabo
{
namespace console
{

void SetConsoleEcho( Turn turn )
{
	HANDLE handle = GetStdHandle( STD_INPUT_HANDLE );
	if ( ( handle == INVALID_HANDLE_VALUE ) || ( handle == NULL ) )
		return;

	DWORD mode;
	if ( !GetConsoleMode( handle, &mode ) )
		return;

	mode = ( turn == Turn::ON ) ? mode | ENABLE_ECHO_INPUT : mode & ~ENABLE_ECHO_INPUT;

	SetConsoleMode( handle, mode );
}

void ColoredPrintf( TextColor color, const char* fmt, ... )
{
	va_list args;
	va_start( args, fmt );

	const HANDLE handle = GetStdHandle( STD_OUTPUT_HANDLE );

	//Store current color
	CONSOLE_SCREEN_BUFFER_INFO buffer_info;
	GetConsoleScreenBufferInfo( handle, &buffer_info );
	const WORD prevColor = buffer_info.wAttributes;

	fflush( stdout );

	auto GetColorAttr = [ & ] ( const TextColor color ) -> WORD
	{
		switch ( color )
		{
		case TextColor::DEFAULT:
			return 0;
		case TextColor::RED:
			return FOREGROUND_RED;
		case TextColor::GREEN:
			return FOREGROUND_GREEN;
		case TextColor::YELLOW:
			return FOREGROUND_RED | FOREGROUND_GREEN;
		default:
			return prevColor;
		}

	};

	SetConsoleTextAttribute( handle,
							 GetColorAttr( color ) | FOREGROUND_INTENSITY );
	vprintf( fmt, args );

	fflush( stdout );

	//Restore previous text color.
	SetConsoleTextAttribute( handle, prevColor );

	va_end( args );
}

} // namespace console

} // namespace elabo

