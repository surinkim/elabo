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
* Network.h
*
* A number of network-utility functions implementation.
*
* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
****/

#ifndef ELABO_CONSOLE_H_
#define ELABO_CONSOLE_H_

#include <Windows.h>

namespace elabo
{
namespace console
{

enum class Turn{ ON, OFF };
void SetConsoleEcho( Turn turn );

enum class TextColor { DEFAULT, RED, GREEN, YELLOW };
void ColoredPrintf( TextColor color, const char* fmt, ... );

} // namespace console

} // namespace elabo

#endif // ELABO_CONSOLE_H_