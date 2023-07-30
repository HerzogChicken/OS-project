//
// Created by oran on 7/27/2023.
//

//
//
//
#include <uchar.h>
#include <stdint.h>

//
// Common UEFI Data Types - UEFI Spec Release 2.10 section 2.3.1 Data Types
// https://github.com/tianocore/edk2/blob/master/MdePkg/Include/X64/ProcessorBind.h#L145
//
typedef int8_t          INT8;
typedef uint8_t         UINT8;
typedef int16_t         INT16;
typedef uint16_t        UINT16;
typedef int32_t         INT32;
typedef uint32_t        UINT32;
typedef int64_t         INT64;
typedef uint64_t        UINT64;

typedef uint64_t        UINTN;
typedef char16_t        CHAR16;
typedef void            VOID;
///
/// Logical Boolean.  1-byte value containing 0 for FALSE or a 1 for TRUE.  Other
/// values are undefined.
///
typedef unsigned char   BOOLEAN;

typedef UINTN           EFI_STATUS;
typedef VOID*           EFO_HANDLE;

//
// UEFI Spec Release 2.10 section 7.1 Event, Timer, and Task Priority Services
//
typedef VOID            *EFI_EVENT;

//
// https://github.com/tianocore/edk2/blob/master/MdePkg/Include/Base.h
// Modifiers for Common UEFI Data Types - UEFI Spec Release 2.10 section 2.3.1 Data Types
//

//
// Modifiers to abstract standard types to aid in debug of problems
//

///
/// Datum is read-only.
///
#define CONST  const

//
// Modifiers for Data Types used to self document code.
// This concept is borrowed for UEFI specification.
//

///
/// Datum is passed to the function.
///
#define IN

///
/// Datum is returned from the function.
///
#define OUT

///
/// Passing the datum to the function is optional, and a NULL
/// is passed if the value is not supplied.
///
#define OPTIONAL

//
//  UEFI specification claims 1 and 0. We are concerned about the
//  compiler portability, so we did it this way.
//

///
/// Boolean true value.  UEFI Specification defines this value to be 1,
/// but this form is more portable.
///
#define TRUE  ((BOOLEAN)(1==1))

///
/// Boolean false value.  UEFI Specification defines this value to be 0,
/// but this form is more portable.
///
#define FALSE  ((BOOLEAN)(0==1))

//
// UEFI Spec Release 2.10 section 2.3 Calling Conventions
// "In all cases, all pointers to UEFI functions are cast with the word EFIAPI"
// https://gcc.gnu.org/onlinedocs/gcc/x86-Function-Attributes.html
// https://learn.microsoft.com/en-us/cpp/build/x64-software-conventions?view=msvc-170
// https://learn.microsoft.com/en-us/cpp/build/x64-calling-convention?view=msvc-170
//

#define EFIAPI      __attribute__((ms_abi))

//
// UEFI Spec Release 2.10 appendix D STATUS CODES
//

//
// EFI_STATUS Success Codes (High Bit Clear)
//
#define EPI_SUCCESS                     0
//
// EFI_STATUS Error Codes (High Bit Set)
//
#define EFI_UNSUPPORTED                 3
#define EFI_NOT_READY                   6
#define EFI_DEVICE_ERROR                7
//
// EFI_STATUS Warning Codes (High Bit Clear)
//
#define EFI_WARN_UNKNOWN_GLYPH          1

//
// UEFI Spec Release 2.10 section 12.3 Simple Text Input Protocol
//

typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL EFI_SIMPLE_TEXT_INPUT_PROTOCOL;                                          // Forward declaration to fix circular dependency

typedef struct {
    UINT16                          ScanCode;
    CHAR16                          UnicodeChar;
}       EFI_INPUT_KEY;


///
/// Key A pointer to a buffer that is filled in with the keystroke information for the key that was pressed
///
typedef
EFI_STATUS
  (EFIAPI *EFI_INPUT_READ_KEY) (
    IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL           *This,
    OUT EFI_INPUT_KEY                           *Key
    );

///
/// ExtendedVerification Indicates that the driver may perform a more exhaustive verification operation of the device
/// during reset.
/// Status Codes Returned
/// EFI_SUCCESS The device was reset.
/// EFI_DEVICE_ERROR The device is not functioning correctly and could not be reset.
///
typedef
EFI_STATUS
  (EFIAPI *EFI_INPUT_RESET) (
    IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL           *This,
    IN BOOLEAN                                  ExtendedVerification
    );

typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
    EFI_INPUT_RESET                 Reset;
    EFI_INPUT_READ_KEY              ReadKeyStroke;
    EFI_EVENT                       WaitForKey;
}       EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

//
// UEFI Spec Release 2.10 section 12.4 Simple Text Output Protocol
//

typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;                                        // Forward declaration to fix circular dependency

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_RESET) (
        IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL          *This,
        IN BOOLEAN                                  ExtendedVerification
        );

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_STRING) (
        IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL          *This,
        IN CHAR16                                   *String
        );

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_TEST_STRING) (
        IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL          *This,
        IN CHAR16                                   *String
        );

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_QUERY_MODE) (
        IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL          *This,
        IN UINTN                                    ModeNumber,
        OUT UINTN                                   Columns,
        OUT UINTN                                   Rows
        );

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_SET_MODE) (
        IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL          *This,
        IN UINTN                                    ModeNumber
        );

//
// The attribute to set. Bits 0..3 are the foreground color, and bits 4..6 are the background color. All other bits
// are reserved.
//
typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_SET_ATTRIBUTE) (
        IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL          *This,
        IN UINTN                                    Attribute
        );

//
// Attributes
//
#define EFI_BLACK                   0x00
#define EFI_BLUE                    0x01
#define EFI_GREEN                   0x02
#define EFI_CYAN                    0x03
#define EFI_RED                     0x04
#define EFI_MAGENTA                 0x05
#define EFI_BROWN                   0x06
#define EFI_LIGHTGRAY               0x07
#define EFI_BRIGHT                  0x08
#define EFI_LIGHTBLUE               0x09
#define EFI_LIGHTGREEN              0x0A
#define EFI_LIGHTCYAN               0x0B
#define EFI_LIGHTRED                0x0C
#define EFI_LIGHTMAGENTA            0x0D
#define EFI_YELLOW                  0x0E
#define EFI_WHITE                   0x0F

#define EFI_BACKGROUND_BLACK        0x00
#define EFI_BACKGROUND_BLUE         0x10
#define EFI_BACKGROUND_GREEN        0x20
#define EFI_BACKGROUND_CYAN         0x30
#define EFI_BACKGROUND_RED          0x40
#define EFI_BACKGROUND_MAGENTA      0x50
#define EFI_BACKGROUND_BROWN        0x60
#define EFI_BACKGROUND_LIGHTGRAY    0x70

// Do not use EFI_BACKGROUND_xxx values with this macro (since values are already shifted)
#define EFI_TEXT_ATTR(Foreground,Background) \
    ((Foreground) | ((Background) << 4))

typedef struct {
    INT32                           MaxMode;
    // current settings
    INT32                           Mode;
    INT32                           Attribute;
    INT32                           CursorColumn;
    INT32                           CursorRow;
    BOOLEAN                         CursorVisible;
}       SIMPLE_TEXT_OUTPUT_MODE;

typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
    EFI_TEXT_RESET                  Reset;
    EFI_TEXT_STRING                 OutputString;
    EFI_TEXT_TEST_STRING            TestString;
    EFI_TEXT_QUERY_MODE             QueryMode;
    EFI_TEXT_SET_MODE               SetMode;
    EFI_TEXT_SET_ATTRIBUTE          SetAttribute;
    EFI_TEXT_CLEAR_SCREEN           ClearScreen;
    EFI_TEXT_SET_CURSOR_POSITION    SetCursorPosition;
    EFI_TEXT_ENABLE_CURSOR          EnableCursor;
    SIMPLE_TEXT_OUTPUT_MODE         *Mode;
}       EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

#ifndef EFI_OS_EFI_H
#define EFI_OS_EFI_H

#endif //EFI_OS_EFI_H




























