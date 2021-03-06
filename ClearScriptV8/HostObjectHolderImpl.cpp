// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT license.

#include "ClearScriptV8Native.h"

//-----------------------------------------------------------------------------
// HostObjectHolderImpl implementation
//-----------------------------------------------------------------------------

HostObjectHolderImpl::HostObjectHolderImpl(void* pvObject):
    m_pvObject(pvObject)
{
}

//-----------------------------------------------------------------------------

HostObjectHolderImpl* HostObjectHolderImpl::Clone() const
{
    return new HostObjectHolderImpl(HostObjectUtil::GetInstance().AddRef(m_pvObject));
}

//-----------------------------------------------------------------------------

void* HostObjectHolderImpl::GetObject() const
{
    return m_pvObject;
}

//-----------------------------------------------------------------------------

HostObjectHolderImpl::~HostObjectHolderImpl()
{
    HostObjectUtil::GetInstance().Release(m_pvObject);
}
