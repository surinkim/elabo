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
* String.cpp
*
* A number of string utility functions implementation.
*
* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
****/

#include <string>
#include <codecvt>

namespace elabo
{
namespace string
{
std::string ConvertToString( const wchar_t* text )
{
	std::wstring_convert<std::codecvt_utf8_utf16 <wchar_t >> converter;
	return converter.to_bytes( text );
}

std::wstring ConvertToWString( const char* text )
{
	std::wstring_convert<std::codecvt_utf8_utf16 <wchar_t>> converter;
	return converter.from_bytes( text );
}

} // namespace console

} // namespace elabo
