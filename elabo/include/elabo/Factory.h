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
* Factory.h
*
* A Factory class implementations by using template, some c++ 11 keywords.
*
* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
****/

#ifndef ELABO_PATTERN_FACTORY_H_
#define ELABO_PATTERN_FACTORY_H_

#include <map>
#include <functional>

namespace elabo
{
namespace pattern
{

template< class Abstract, typename Identifier, typename Creator = std::function<std::unique_ptr<Abstract>(std::string)> >
class Factory
{
public:
    bool Add( const Identifier& id, Creator creator )
    {
        return _objectMap.insert( ObjectMap::value_type(id, creator ) ).second;
    }

    bool Remove( const Identifier& id )
    {
        return ( _objectMap.erase(id) == 1);
    }

    std::unique_ptr<Abstract> Create( const Identifier& id, std::string name )
    {
        auto it = _objectMap.find( id );
        if ( it == _objectMap.end() )
            return nullptr;

        return (*it).second(name);
    }

private:
    using ObjectMap = std::map<Identifier, Creator>;
    ObjectMap _objectMap;
};

} // namespace pattern

} // namespace elabo

#endif // ELABO_PATTERN_FACTORY_H_