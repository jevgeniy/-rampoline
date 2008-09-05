/**
 * @file tpl_os_rez_kernel.h
 *
 * @section desc File description
 *
 * This header file provides internal function
 * for resource management.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_OS_REZ_KERNEL_H
#define TPL_OS_REZ_KERNEL_H

#include "tpl_os_internal_types.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * Getting a resource.
 */
extern FUNC(void, OS_CODE) tpl_get_resource(
    P2VAR(tpl_resource, AUTOMATIC, OS_APPL_DATA) res);


/*
 * Releasing a resource
 */
extern FUNC(void, OS_CODE) tpl_release_resource(
    P2VAR(tpl_resource, AUTOMATIC, OS_APPL_DATA) res);


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* tpl_os_rez_kernel.h */

/* End of file tpl_os_rez_kernel.h */
