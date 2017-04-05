/*
 * Copyright (C) 2017 iCub Facility, Istituto Italiano di Tecnologia (IIT)
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */

#ifndef YARP_OS_IMPL_PLATFORMSTDLIB_H
#define YARP_OS_IMPL_PLATFORMSTDLIB_H

#include <yarp/conf/system.h>
#ifdef YARP_HAS_ACE
# include <ace/OS_NS_stdlib.h>
#else
# include <stdlib.h>
#endif

namespace yarp {
namespace os {
namespace impl {


#if defined(YARP_HAS_ACE)
    using std::getenv;
# if defined(_MSC_VER)
    // ACE bindings for setenv and unsetenv do not work
    // on Visual Studio (last tested ACE 6.4.2, VS 2015).
    inline int setenv(const char *name, const char *value, int overwrite) {
        YARP_UNUSED(overwrite);
        return _putenv_s(name, value);
    }
    inline int unsetenv(const char *name) {
        return _putenv_s(name, "");
    }
# else
    using ACE_OS::setenv;
    using ACE_OS::unsetenv;
# endif
# if defined(_MSC_VER)
    // FIXME FIXME FIXME
    YARP_COMPILER_WARNING("Check if ACE_OS::putenv works")
#endif
    using ACE_OS::putenv;
#else
    using std::getenv;
    using ::setenv;
    using ::unsetenv;
    using ::putenv;
#endif


} // namespace impl
} // namespace os
} // namespace yarp


#endif // YARP_OS_IMPL_PLATFORMSTDLIB_H
