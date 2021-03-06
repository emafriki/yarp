/*
 * Copyright (C) 2006-2020 Istituto Italiano di Tecnologia (IIT)
 * Copyright (C) 2006-2010 RobotCub Consortium
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#ifndef YARP_SERVERSQL_IMPL_NAMESERVERCONTAINER_H
#define YARP_SERVERSQL_IMPL_NAMESERVERCONTAINER_H

#include <yarp/os/Contact.h>
#include <yarp/os/NameSpace.h>
#include <yarp/os/Searchable.h>

#include <yarp/serversql/impl/AllocatorOnTriples.h>
#include <yarp/serversql/impl/ComposedNameService.h>
#include <yarp/serversql/impl/NameServiceOnTriples.h>
#include <yarp/serversql/impl/StyleNameService.h>
#include <yarp/serversql/impl/SubscriberOnSql.h>
#include <yarp/serversql/impl/TripleSourceCreator.h>

namespace yarp {
namespace serversql {
namespace impl {

class NameServerContainer : public ComposedNameService
{
private:
    yarp::os::Contact contact;
    TripleSourceCreator db;
    SubscriberOnSql subscriber;
    AllocatorConfig config;
    AllocatorOnTriples alloc;
    NameServiceOnTriples ns;
    StyleNameService style;
    ComposedNameService combo1;
    bool silent{false};
    yarp::os::NameSpace *space{nullptr};
public:
    using ComposedNameService::open;

    ~NameServerContainer() override;

    void setSilent(bool silent);
    const yarp::os::Contact& where();
    yarp::os::Contact whereDelegate();
    void preregister(const yarp::os::Contact& c);
    bool open(yarp::os::Searchable& options);
};

} // namespace impl
} // namespace serversql
} // namespace yarp


#endif // YARP_SERVERSQL_IMPL_NAMESERVERCONTAINER_H
