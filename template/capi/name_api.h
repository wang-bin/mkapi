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
#ifndef CAPI_LINK_%NAME%
namespace capi { // avoid ambiguity if call function directly
#endif
// the following line will be replaced by the content of config/%NAME%/include if exists
#include "%Name%.h"
#ifndef CAPI_LINK_%NAME%
}
#endif

namespace %Name% {
#ifdef %NAME%_CAPI_NS
namespace capi {
#else
class api_dll;
class api
{
    api_dll *dll;
public:
    api();
    virtual ~api();
    virtual bool loaded() const; // user may inherits multiple api classes: final::loaded() { return base1::loaded() && base2::loaded();}
#endif %NAME%_CAPI_NS
#ifndef CAPI_LINK_%NAME%
    %Declare%
#endif //CAPI_LINK_%NAME%
}
#ifndef %NAME%_CAPI_NS
;
#endif
} //namespace %Name%


#endif // %NAME%_API_H
