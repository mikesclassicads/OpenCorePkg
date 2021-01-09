/** @file
  Copyright (C) 2018, vit9696. All rights reserved.
  Copyright (C) 2020, PMheart. All rights reserved.

  All rights reserved.

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
**/

#ifndef OC_USER_UTILITIES_OCVALIDATE_NVRAM_KEY_INFO_H
#define OC_USER_UTILITIES_OCVALIDATE_NVRAM_KEY_INFO_H

#include <Library/OcConfigurationLib.h>

typedef
BOOLEAN
(*NVRAM_KEY_CHECK) (
  IN  CONST VOID    *Value,
  IN  UINT32        ValueSize
  );

typedef struct NVRAM_KEY_CONTEXT_ {
  CONST CHAR8       *KeyName;
  NVRAM_KEY_CHECK   KeyChecker;
} NVRAM_KEY_CONTEXT;

typedef
BOOLEAN
(*NVRAM_GUID_CHECK) (
  IN  CONST CHAR8  *KeyName,
  IN  CONST VOID   *KeyValue,
  IN  UINT32       ValueSize
  );

typedef struct NVRAM_GUID_CONTEXT_ {
  CONST EFI_GUID    *Guid;
  NVRAM_GUID_CHECK  GuidChecker;
} NVRAM_GUID_CONTEXT;

extern NVRAM_GUID_CONTEXT mGUIDCheckers[];
extern UINTN              mGUIDCheckersSize;

#endif // OC_USER_UTILITIES_OCVALIDATE_NVRAM_KEY_INFO_H