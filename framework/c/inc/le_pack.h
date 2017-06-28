/**
 * @page c_pack Low-level Pack/Unpack API
 *
 * @ref le_pack.h "API Reference"
 *
 * <HR>
 *
 * This low-level pack/unpack API is intended to support the higher level
 * IPC messaging system, specifically code generated by ifgen.  But it
 * can also be used to hand-pack messages if using the @ref c_messaging
 * API directly.
 *
 * This low-level pack/unpack API supports:
 *   - Packing basic types supported by the IPC system.
 *   - Packing reference types
 *   - Packing arrays of the above types
 *   - Packing strings.
 * It also supports unpacking any of the above.
 */

#ifndef LE_PACK_H_INCLUDE_GUARD
#define LE_PACK_H_INCLUDE_GUARD

//--------------------------------------------------------------------------------------------------
// Pack functions
//--------------------------------------------------------------------------------------------------

// Packing a simple value is basically the same regardless of type.  But don't use this macro
// directly to get better verification that we're only packing the types we expect
#define LE_PACK_PACK_SIMPLE_VALUE(value)               \
    if (*sizePtr < sizeof(value))                      \
    {                                                  \
        return false;                                  \
    }                                                  \
                                                       \
    memcpy(*bufferPtr, &(value), sizeof(value));                \
                                                                \
    *bufferPtr = *bufferPtr + sizeof(value);                    \
    *sizePtr -= sizeof(value);                                  \
                                                                \
    return true


//--------------------------------------------------------------------------------------------------
/**
 * Pack a uint8_t into a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_PackUint8
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    uint8_t value
)
{
    LE_PACK_PACK_SIMPLE_VALUE(value);
}

//--------------------------------------------------------------------------------------------------
/**
 * Pack a uint16_t into a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_PackUint16
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    uint16_t value
)
{
    LE_PACK_PACK_SIMPLE_VALUE(value);
}

//--------------------------------------------------------------------------------------------------
/**
 * Pack a uint32_t into a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_PackUint32
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    uint32_t value
)
{
    LE_PACK_PACK_SIMPLE_VALUE(value);
}

//--------------------------------------------------------------------------------------------------
/**
 * Pack a uint64_t into a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_PackUint64
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    uint64_t value
)
{
    LE_PACK_PACK_SIMPLE_VALUE(value);
}

//--------------------------------------------------------------------------------------------------
/**
 * Pack a int8_t into a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_PackInt8
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    int8_t value
)
{
    LE_PACK_PACK_SIMPLE_VALUE(value);
}

//--------------------------------------------------------------------------------------------------
/**
 * Pack a int16_t into a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_PackInt16
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    int16_t value
)
{
    LE_PACK_PACK_SIMPLE_VALUE(value);
}

//--------------------------------------------------------------------------------------------------
/**
 * Pack a int32_t into a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_PackInt32
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    int32_t value
)
{
    LE_PACK_PACK_SIMPLE_VALUE(value);
}

//--------------------------------------------------------------------------------------------------
/**
 * Pack a int64_t into a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_PackInt64
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    int64_t value
)
{
    LE_PACK_PACK_SIMPLE_VALUE(value);
}

//--------------------------------------------------------------------------------------------------
/**
 * Pack a size_t into a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note Packed sizes are limited to 2^32-1, regardless of platform
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_PackSize
(
    uint8_t **bufferPtr,
    size_t *sizePtr,
    size_t value
)
{
    if (value > UINT32_MAX)
    {
        return false;
    }

    return le_pack_PackUint32(bufferPtr, sizePtr, value);
}

//--------------------------------------------------------------------------------------------------
/**
 * Pack a bool into a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_PackBool
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    bool value
)
{
    // Force boolean to uint8_t 0 or 1 for packing, regarldess of underlying OS type.
    // Underlying type has been int on some platforms in the past.
    uint8_t simpleValue = ((value)?1:0);
    LE_PACK_PACK_SIMPLE_VALUE(simpleValue);
}

//--------------------------------------------------------------------------------------------------
/**
 * Pack a char into a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_PackChar
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    char value
)
{
    LE_PACK_PACK_SIMPLE_VALUE(value);
}

//--------------------------------------------------------------------------------------------------
/**
 * Pack a double into a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_PackDouble
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    double value
)
{
    LE_PACK_PACK_SIMPLE_VALUE(value);
}

//--------------------------------------------------------------------------------------------------
/**
 * Pack a le_result_t into a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_PackResult
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    le_result_t value
)
{
    LE_PACK_PACK_SIMPLE_VALUE(value);
}

//--------------------------------------------------------------------------------------------------
/**
 * Pack le_onoff_t into a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_PackOnOff
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    le_onoff_t value
)
{
    LE_PACK_PACK_SIMPLE_VALUE(value);
}

#undef LE_PACK_PACK_SIMPLE_VALUE

//--------------------------------------------------------------------------------------------------
/**
 * Pack a reference into a buffer, incrementing the buffer pointer and decrementing the available
 * size.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_PackReference
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    const void* ref
)
{
    size_t refAsInt = (size_t)ref;

    //  All references passed through an API must be safe references (or NULL), so
    // 0-bit will be set and reference will be <= UINT32_MAX.  Size check
    // is performed in pack function.
    if ((refAsInt <= UINT32_MAX) &&
        ((refAsInt & 0x01) ||
         !refAsInt))
    {
        return le_pack_PackUint32(bufferPtr, sizePtr, (uint32_t)refAsInt);
    }
    else
    {
        return false;
    }
}

//--------------------------------------------------------------------------------------------------
/**
 * Pack a string into a buffer, incrementing the buffer pointer and decrementing the available
 * size.
 *
 * @note Always decrements available size according to the max possible size used, not actual size
 * used.  Will assert if provided string is larger than maximum allowable string.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_PackString
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    const char *stringPtr,
    uint32_t maxStringCount
)
{
    size_t bytesCopied;

    if (*sizePtr < (maxStringCount + sizeof(uint32_t)))
    {
        return false;
    }

    if (!stringPtr)
    {
        return false;
    }

    // First copy in the string -- up to maxStringCount bytes, allowing enough
    // space at the begining for a uint32.
    for (bytesCopied = 0;
         bytesCopied < maxStringCount && stringPtr[bytesCopied];
         ++bytesCopied)
    {
        (*bufferPtr)[bytesCopied + sizeof(uint32_t)] = stringPtr[bytesCopied];
    }

    // String was too long to fit in the buffer -- return false.
    if (stringPtr[bytesCopied] != '\0')
    {
        return false;
    }

    // Then go back and copy string size.  No loss of precision packing into a uint32
    // because maxStringCount is a uint32 or less.
    bool packResult = le_pack_PackUint32(bufferPtr, sizePtr, bytesCopied);
    LE_ASSERT(packResult); // Should not fail -- have checked there's enough space above.

    // Now increment buffer by size of string actually copied, and decrement available
    // space by max which could have been copied.  This ensures out of space errors will
    // be caught as soon as possible.
    *bufferPtr = *bufferPtr + bytesCopied;
    *sizePtr -= maxStringCount;

    return true;
}

//--------------------------------------------------------------------------------------------------
/**
 * Pack the size information for an array into a buffer, incrementing the buffer pointer and
 * decrementing the available size.
 *
 * @note Users of this API should generally use LE_PACK_PACKARRAY macro instead which also
 * packs the array data.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_PackArrayHeader
(
    uint8_t **bufferPtr,
    size_t *sizePtr,
    const void *arrayPtr,
    size_t elementSize,
    size_t arrayCount,
    size_t arrayMaxCount
)
{
    if ((*sizePtr < arrayMaxCount*elementSize + sizeof(uint32_t)) ||
        (arrayCount > arrayMaxCount))
    {
        return false;
    }

    LE_ASSERT(le_pack_PackSize(bufferPtr, sizePtr, arrayCount));

    return true;
}

//--------------------------------------------------------------------------------------------------
/**
 * Pack an array into a buffer, incrementing the buffer pointer and decrementing the available
 * size.
 *
 * @note Always decrements available size according to the max possible size used, not actual size
 * used.  Will assert if provided string is larger than maximum allowable string.
 */
//--------------------------------------------------------------------------------------------------
#define LE_PACK_PACKARRAY(bufferPtr,                                    \
                          sizePtr,                                      \
                          arrayPtr,                                     \
                          arrayCount,                                   \
                          arrayMaxCount,                                \
                          packFunc,                                     \
                          resultPtr)                                    \
    do {                                                                \
        *(resultPtr) = le_pack_PackArrayHeader((bufferPtr), (sizePtr), \
                                               (arrayPtr), sizeof((arrayPtr)[0]), \
                                               (arrayCount), (arrayMaxCount)); \
        if (*(resultPtr))                                               \
        {                                                               \
            uint32_t i;                                                 \
            size_t newSizePtr = *(sizePtr) - sizeof((arrayPtr)[0])*(arrayMaxCount); \
            for (i = 0; i < (arrayCount); ++i)                          \
            {                                                           \
                LE_ASSERT(packFunc((bufferPtr), (sizePtr), (arrayPtr)[i])); \
            }                                                           \
            LE_ASSERT(*(sizePtr) >= newSizePtr);                        \
            *(sizePtr) = newSizePtr;                                    \
            *(resultPtr) = true;                                        \
        }                                                               \
    } while (0)

//--------------------------------------------------------------------------------------------------
// Unpack functions
//--------------------------------------------------------------------------------------------------

#define LE_PACK_UNPACK_SIMPLE_VALUE(valuePtr)                   \
    if (*sizePtr < sizeof(*(valuePtr)))                         \
    {                                                           \
        return false;                                           \
    }                                                           \
                                                                \
    memcpy((valuePtr), *bufferPtr, sizeof(*(valuePtr)));        \
                                                                \
    *bufferPtr = (*bufferPtr) + sizeof(*(valuePtr));            \
    *sizePtr -= sizeof(*(valuePtr));                            \
                                                                \
    return true

//--------------------------------------------------------------------------------------------------
/**
 * Unpack a uint8_t from a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_UnpackUint8
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    uint8_t* valuePtr
)
{
    LE_PACK_UNPACK_SIMPLE_VALUE(valuePtr);
}

//--------------------------------------------------------------------------------------------------
/**
 * Unpack a uint16_t from a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_UnpackUint16
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    uint16_t* valuePtr
)
{
    LE_PACK_UNPACK_SIMPLE_VALUE(valuePtr);
}

//--------------------------------------------------------------------------------------------------
/**
 * Unpack a uint32_t from a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_UnpackUint32
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    uint32_t* valuePtr
)
{
    LE_PACK_UNPACK_SIMPLE_VALUE(valuePtr);
}

//--------------------------------------------------------------------------------------------------
/**
 * Unpack a uint64_t from a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_UnpackUint64
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    uint64_t* valuePtr
)
{
    LE_PACK_UNPACK_SIMPLE_VALUE(valuePtr);
}

//--------------------------------------------------------------------------------------------------
/**
 * Unpack a int8_t from a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_UnpackInt8
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    int8_t* valuePtr
)
{
    LE_PACK_UNPACK_SIMPLE_VALUE(valuePtr);
}

//--------------------------------------------------------------------------------------------------
/**
 * Unpack a int16_t from a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_UnpackInt16
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    int16_t* valuePtr
)
{
    LE_PACK_UNPACK_SIMPLE_VALUE(valuePtr);
}

//--------------------------------------------------------------------------------------------------
/**
 * Unpack a int32_t from a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_UnpackInt32
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    int32_t* valuePtr
)
{
    LE_PACK_UNPACK_SIMPLE_VALUE(valuePtr);
}

//--------------------------------------------------------------------------------------------------
/**
 * Unpack a int64_t from a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_UnpackInt64
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    int64_t* valuePtr
)
{
    LE_PACK_UNPACK_SIMPLE_VALUE(valuePtr);
}

/**
 * Pack a size_t into a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note Packed sizes are limited to 2^32-1, regardless of platform
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_UnpackSize
(
    uint8_t **bufferPtr,
    size_t *sizePtr,
    size_t *valuePtr
)
{
    uint32_t rawValue;

    if (!le_pack_UnpackUint32(bufferPtr, sizePtr, &rawValue))
    {
        return false;
    }

    *valuePtr = rawValue;

    return true;
}

//--------------------------------------------------------------------------------------------------
/**
 * Unpack a bool from a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_UnpackBool
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    bool* valuePtr
)
{
    // Treat boolean as uint8_t for packing, regarldess of underlying OS type.
    // Underlying type has been int on some platforms in the past.
    uint8_t simpleValue;
    if (*sizePtr < sizeof(simpleValue))
    {
        return false;
    }

    memcpy(&simpleValue, *bufferPtr, sizeof(simpleValue));

    *bufferPtr = ((uint8_t* )*bufferPtr) + sizeof(simpleValue);
    *sizePtr -= sizeof(simpleValue);

    // force to true or false
    *valuePtr = !!simpleValue;

    return true;
}

//--------------------------------------------------------------------------------------------------
/**
 * Unpack a char from a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_UnpackChar
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    char* valuePtr
)
{
    LE_PACK_UNPACK_SIMPLE_VALUE(valuePtr);
}

//--------------------------------------------------------------------------------------------------
/**
 * Unpack a double from a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_UnpackDouble
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    double* valuePtr
)
{
    LE_PACK_UNPACK_SIMPLE_VALUE(valuePtr);
}

//--------------------------------------------------------------------------------------------------
/**
 * Unpack a le_result_t from a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_UnpackResult
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    le_result_t* valuePtr
)
{
    LE_PACK_UNPACK_SIMPLE_VALUE(valuePtr);
}

//--------------------------------------------------------------------------------------------------
/**
 * Pack le_onoff_t into a buffer, incrementing the buffer pointer and decrementing the
 * available size, as appropriate.
 *
 * @note By making this an inline function, gcc can often optimize out the size check if the buffer
 * size is known at compile time.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_UnpackOnOff
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    le_onoff_t* valuePtr
)
{
    LE_PACK_UNPACK_SIMPLE_VALUE(valuePtr);
}

#undef LE_PACK_UNPACK_SIMPLE_VALUE

//--------------------------------------------------------------------------------------------------
/**
 * Unpack a reference from a buffer, incrementing the buffer pointer and decrementing the available
 * size.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_UnpackReference
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    void* refPtr                ///< Pointer to the reference.  Declared as void * to allow implicit
                                ///< conversion from pointer to reference types.
)
{
    uint32_t refAsInt;

    if (!le_pack_UnpackUint32(bufferPtr, sizePtr, &refAsInt))
    {
        return false;
    }

    //  All references passed through an API must be safe references, so
    // 0-bit will be set.  Check that here to be safe.
    if ((refAsInt & 0x01) ||
        (!refAsInt))
    {
        // Double cast to avoid warnings.
        *(void **)refPtr = (void *)(size_t)refAsInt;
        return true;
    }
    else
    {
        return false;
    }
}

//--------------------------------------------------------------------------------------------------
/**
 * Unpack a string from a buffer, incrementing the buffer pointer and decrementing the available
 * size.
 *
 * @note Always decrements available size according to the max possible size used, not actual size
 * used.  Will assert if provided string is larger than maximum allowable string.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_UnpackString
(
    uint8_t** bufferPtr,
    size_t* sizePtr,
    char *stringPtr,
    uint32_t bufferSize,
    uint32_t maxStringCount
)
{
    uint32_t stringSize;

    if (*sizePtr < (maxStringCount + sizeof(uint32_t)))
    {
        return false;
    }

    // First get string size
    if (!le_pack_UnpackUint32(bufferPtr, sizePtr, &stringSize))
    {
        return false;
    }

    if ((stringSize > maxStringCount) ||
        (stringSize > bufferSize))
    {
        return false;
    }

    if (!stringPtr)
    {
        // Only allow unpacking into no output buffer if the string is zero sized.
        // Otherwise an output buffer is required.
        if (stringSize)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    memcpy(stringPtr, *bufferPtr, stringSize);
    stringPtr[stringSize] = '\0';

    *bufferPtr = *bufferPtr + stringSize;
    *sizePtr -= maxStringCount;

    return true;
}

//--------------------------------------------------------------------------------------------------
/**
 * Pack the size information for an array into a buffer, incrementing the buffer pointer and
 * decrementing the available size.
 *
 * @note Users of this API should generally use LE_PACK_PACKARRAY macro instead which also
 * packs the array data.
 */
//--------------------------------------------------------------------------------------------------
static inline bool le_pack_UnpackArrayHeader
(
    uint8_t **bufferPtr,
    size_t *sizePtr,
    const void *arrayPtr,
    size_t elementSize,
    size_t *arrayCountPtr,
    size_t arrayMaxCount
)
{
    if (*sizePtr < (arrayMaxCount*elementSize + sizeof(uint32_t)))
    {
        return false;
    }

    LE_ASSERT(le_pack_UnpackSize(bufferPtr, sizePtr, arrayCountPtr));
    if (*arrayCountPtr > arrayMaxCount)
    {
        return false;
    }
    else if (!arrayPtr)
    {
        // Missing array pointer must match zero sized array.
        return (*arrayCountPtr == 0);
    }

    return true;
}

//--------------------------------------------------------------------------------------------------
/**
 * Unpack an array into from buffer, incrementing the buffer pointer and decrementing the available
 * size.
 *
 * @note Always decrements available size according to the max possible size used, not actual size
 * used.  Will assert if provided string is larger than maximum allowable string.
 */
//--------------------------------------------------------------------------------------------------
#define LE_PACK_UNPACKARRAY(bufferPtr,                                  \
                            sizePtr,                                    \
                            arrayPtr,                                   \
                            arrayCountPtr,                              \
                            arrayMaxCount,                              \
                            unpackFunc,                                 \
                            resultPtr)                                  \
    do {                                                                \
        if (!le_pack_UnpackArrayHeader((bufferPtr), (sizePtr),           \
                                       (arrayPtr), sizeof((arrayPtr)[0]), \
                                       (arrayCountPtr), (arrayMaxCount))) \
        {                                                               \
            *(resultPtr) = false;                                       \
        }                                                               \
        else                                                            \
        {                                                               \
            uint32_t i;                                                 \
            size_t newSizePtr = *(sizePtr) - sizeof((arrayPtr)[0])*(arrayMaxCount); \
            for (i = 0; i < *(arrayCountPtr); ++i)                      \
            {                                                           \
                LE_ASSERT(unpackFunc((bufferPtr), (sizePtr), &(arrayPtr)[i])); \
            }                                                           \
            LE_ASSERT(*(sizePtr) >= newSizePtr);                        \
            *(sizePtr) = newSizePtr;                                    \
            *(resultPtr) = true;                                        \
        }                                                               \
    } while (0)

#endif /* LE_PACK_H_INCLUDE_GUARD */
