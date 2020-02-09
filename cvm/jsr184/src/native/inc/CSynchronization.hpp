/*
* Copyright (c) 2005-2006 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  M3GCore function call serialization and synchronization
*
*/

#ifndef CSYNCHRONIZATION_H
#define CSYNCHRONIZATION_H

// INCLUDE FILES
//#include <e32std.h>
//#include <e32base.h>
#include <pthread.h>

#ifdef __cplusplus
// CLASS DECLARATION
/**
 * @class CSynchronization
 */
class CSynchronization
{
public:
    /**
     * Two-phased constructor.
         */
    static CSynchronization* InstanceL();

    /**
         * Dtor
         */
    ~CSynchronization();

    /**
       * Locks the semaphore
       */
    void Lock();

    /**
       * Unlocks the semaphore
       */
    void Unlock();

    /**
    * Sets error code for error occured during lock period
    */
    void SetErrorCode(int aCode);

    /**
    * Returns error string set with SetErrorString
    */
    int GetErrorCode();

private: // METHODS
    /**
      * Constructor
      */
    CSynchronization();

    /**
    * Two-phased constructor.
    * @return New object
    */
    static CSynchronization* NewL();

    /**
     * Constructor
     */
    void ConstructL();

private: // MEMBER VARIABLES
    static CSynchronization* iSelf;
    pthread_mutex_t iGuard;
    int iErrorCode;
};
#else
typedef struct CSynchronization_s CSynchronization;
struct CSynchronization_s
{
    /**
     * Two-phased constructor.
         */
    //void (*InstanceL)(void); // static

    /**
         * Dtor
         */
    void (*CSynchronization_destructor)(CSynchronization *);

    /**
       * Locks the semaphore
       */
    void (*Lock)(CSynchronization *);

    /**
       * Unlocks the semaphore
       */
    void (*Unlock)(CSynchronization *);

    /**
    * Sets error code for error occured during lock period
    */
    void (*SetErrorCode)(CSynchronization *obj, int aCode);

    /**
    * Returns error string set with SetErrorString
    */
    int (*GetErrorCode)(CSynchronization *);

    /**
      * Constructor
      */
    //CSynchronization();

    /**
    * Two-phased constructor.
    * @return New object
    */
    //void CSynchronization* (*NewL)(CSynchronization *); // static

    /**
     * Constructor
     */
    void (*ConstructL)(CSynchronization *);

	// MEMBER VARIABLES
	pthread_mutex_t iGuard;
	int iErrorCode;
};
CSynchronization* CSynchronization__InstanceL();
#endif

#endif // CSYNCHRONIZATION_H
