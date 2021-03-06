/* -*- mode: C++; c-basic-offset: 4; tab-width: 4 -*-
 *
 * Copyright (c) 2004-2007 Apple Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#include <pthread.h>

#include "dyldLock.h"



static pthread_mutex_t	sGlobalMutex;


//
// This initializer can go away once the following is available:
//     <rdar://problem/4927311> implement PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
//
void dyldGlobalLockInitialize()
{
	pthread_mutexattr_t recursiveMutexAttr;
	pthread_mutexattr_init(&recursiveMutexAttr);
	pthread_mutexattr_settype(&recursiveMutexAttr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&sGlobalMutex, &recursiveMutexAttr);
}


LockHelper::LockHelper() 
{ 
	pthread_mutex_lock(&sGlobalMutex);
}

LockHelper::~LockHelper() 
{ 
	pthread_mutex_unlock(&sGlobalMutex);
}

void dyldGlobalLockAcquire() 
{
	pthread_mutex_lock(&sGlobalMutex);
}

void dyldGlobalLockRelease() 
{
	pthread_mutex_unlock(&sGlobalMutex);
}


