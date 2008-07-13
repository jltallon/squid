/*
 * $Id: ACLASN.h,v 1.10 2008/02/26 21:49:34 amosjeffries Exp $
 *
 *
 * SQUID Web Proxy Cache          http://www.squid-cache.org/
 * ----------------------------------------------------------
 *
 *  Squid is the result of efforts by numerous individuals from
 *  the Internet community; see the CONTRIBUTORS file for full
 *  details.   Many organizations have provided support for Squid's
 *  development; see the SPONSORS file for full details.  Squid is
 *  Copyrighted (C) 2001 by the Regents of the University of
 *  California; see the COPYRIGHT file for full details.  Squid
 *  incorporates software developed and/or copyrighted by other
 *  sources; see the CREDITS file for full details.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
 *
 *
 * Copyright (c) 2003, Robert Collins <robertc@squid-cache.org>
 */

#ifndef SQUID_ACLASN_H
#define SQUID_ACLASN_H

#include "ACLData.h"
#include "CbDataList.h"
#include "ACLStrategised.h"
#include "ACLChecklist.h"
#include "IPAddress.h"

SQUIDCEXTERN int asnMatchIp(CbDataList<int> *, IPAddress &);

/// \ingroup ACLAPI
SQUIDCEXTERN void asnInit(void);

/// \ingroup ACLAPI
SQUIDCEXTERN void asnFreeMemory(void);

/// \ingroup ACLAPI
class ACLASN : public ACLData<IPAddress>
{

public:
    MEMPROXY_CLASS(ACLASN);

    virtual ~ACLASN();

    virtual bool match(IPAddress);
    virtual wordlist *dump();
    virtual void parse();
    bool empty() const;
    virtual ACLData<IPAddress> *clone() const;
    virtual void prepareForUse();

private:
    static ACL::Prototype SourceRegistryProtoype;
    static ACLStrategised<IPAddress> SourceRegistryEntry_;
    static ACL::Prototype DestinationRegistryProtoype;
    static ACLStrategised<IPAddress> DestinationRegistryEntry_;
    CbDataList<int> *data;
};

MEMPROXY_CLASS_INLINE(ACLASN)          /**DOCS_NOSEMI*/

#endif /* SQUID_ACLASN_H */
