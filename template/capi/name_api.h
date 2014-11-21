/******************************************************************************
    mkapi dynamic load code generation for %TEMPLATE% template
    Copyright (C) 2014 Wang Bin <wbsecg1@gmail.com>
    https://github.com/wang-bin/mkapi
    https://github.com/wang-bin/capi

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
******************************************************************************/

#ifndef %NAME%_API_H
#define %NAME%_API_H

// no need to include the C header if only functions declared there
extern "C" {
#include "%Name%.h"
}

namespace %Name% {
class api_dll;
class api
{
public:
    api();
    ~api();
    bool loaded() const;
    %Declare%
private:
    api_dll *dll;
};
} //namespace %Name%


#endif // %NAME%_API_H
