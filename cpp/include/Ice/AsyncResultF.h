// **********************************************************************
//
// Copyright (c) 2003-2016 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

#ifndef ICE_ASYNC_RESULT_F_H
#define ICE_ASYNC_RESULT_F_H

#include <IceUtil/Shared.h>

#include <Ice/Handle.h>

namespace Ice
{

class AsyncResult;

#ifdef ICE_CPP11_MAPPING
typedef ::std::shared_ptr<AsyncResult> AsyncResultPtr;
#else
ICE_API IceUtil::Shared* upCast(::Ice::AsyncResult*);
typedef IceInternal::Handle<AsyncResult> AsyncResultPtr;
#endif

}

#endif
