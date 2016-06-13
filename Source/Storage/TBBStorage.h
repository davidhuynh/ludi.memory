/*!
 *  \file 	TbbStorage.h
 *  \brief 	<description> 
 *  \date	2011-11-3 14:29
 *
 *  Created by David Huynh on 2011/11/03.
 *  Copyright (C) 2011 David Huynh, Inc. All Rights Reserved.
 *  
 */

#ifndef LUDI_MEMORY_TBB_STORAGE_H_
#define LUDI_MEMORY_TBB_STORAGE_H_

#include "Memory.h"

namespace ludi { 
namespace memory {
    /*! Standard allocation using std::malloc(). */
    class TBBStorage { 
    protected:
        // Nothing

    public:
        /*! */
        TBBStorage();
        /*! */
        virtual ~TBBStorage();

    private:
        DISALLOW_COPY_AND_ASSIGN(TBBStorage);

    public:
        /*! */
        void* Create(size_t size, size_t alignment) {
            
        }

        /*! */
        void Destroy() {

        }
    };

} // memory	
} // ludi

#endif	// LUDI_MEMORY_TBB_STORAGE_H_
