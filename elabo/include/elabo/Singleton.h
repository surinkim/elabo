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
* Singleton.h
*
* Singleton class implementations by using template, some c++ 11 keywords.
*
* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
****/

#ifndef ELABO_PATTERN_SINGLETON_H_
#define ELABO_PATTERN_SINGLETON_H_

namespace elabo
{
namespace pattern
{

template <typename T>
class Singleton
{
protected:
	Singleton() noexcept = default;
	Singleton( const Singleton& ) = delete;
	Singleton& operator=( const Singleton& ) = delete;
	virtual ~Singleton() = default;

public:
	static T& GetInstance() noexcept( std::is_nothrow_constructible<T>::value )
	{
		static T instance;
		return instance;
	}
};

} // namespace pattern

} // namespace elabo

#endif // ELABO_PATTERN_SINGLETON_H_