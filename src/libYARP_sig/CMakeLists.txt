# Copyright (C) 2006-2020 Istituto Italiano di Tecnologia (IIT)
# All rights reserved.
#
# This software may be modified and distributed under the terms of the
# BSD-3-Clause license. See the accompanying LICENSE file for details.

project(YARP_sig)

add_subdirectory(src)

include(YarpInstallBasicPackageFiles)
yarp_install_basic_package_files(YARP_sig
                                 DEPENDENCIES ${YARP_sig_PUBLIC_DEPS}
                                 PRIVATE_DEPENDENCIES ${YARP_sig_PRIVATE_DEPS})
