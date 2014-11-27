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
#define DEBUG_RESOLVE
#define DEBUG_LOAD

#include "%name%_api.h"
#include "capi.h"

namespace %Name% {
static const char* names[] = {
    "%Name%",
    NULL
};

#if CAPI_HAS_%NAME%_VERSION
static const int versions[] = {
    capi::NoVersion,
// the following line will be replaced by the content of config/%NAME%/version if exists
    %VERSIONS%
    , capi::EndVersion
};
CAPI_BEGIN_DLL_VER(names, versions)
#else
CAPI_BEGIN_DLL(names)
#endif
#ifndef CAPI_LINK_%NAME%
// CAPI_DEFINE_RESOLVER(argc, return_type, name, argv_no_name)
%DEFINE_RESOLVER%
#endif //CAPI_LINK_%NAME%
CAPI_END_DLL()

api::api() : dll(new api_dll()) {
    qDebug("capi::version: %s build %s", capi::version::name, capi::version::build());
}
api::~api() { delete dll;}
bool api::loaded() const {
#ifdef CAPI_LINK_%NAME%
    return true;
#else
    return dll->isLoaded();
#endif //CAPI_LINK_%NAME%
}

#ifndef CAPI_LINK_%NAME%
// CAPI_DEFINE(argc, return_type, name, argv_no_name)
%DEFINE%
#endif //CAPI_LINK_%NAME%
} //namespace %Name%
