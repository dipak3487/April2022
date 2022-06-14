
#ifndef JSON_FORWARD_AMALGAMATED_H_INCLUDED
# define JSON_FORWARD_AMALGAMATED_H_INCLUDED
/// If defined, indicates that the source file is amalgamated
/// to prevent private header inclusion.
#define JSON_IS_AMALGAMATION

// //////////////////////////////////////////////////////////////////////
// Beginning of content of file: include/json/version.h
// //////////////////////////////////////////////////////////////////////

#ifndef JSON_VERSION_H_INCLUDED
#define JSON_VERSION_H_INCLUDED


#define JSONCPP_VERSION_STRING "1.9.4"
#define JSONCPP_VERSION_MAJOR 1
#define JSONCPP_VERSION_MINOR 9
#define JSONCPP_VERSION_PATCH 3
#define JSONCPP_VERSION_QUALIFIER
#define JSONCPP_VERSION_HEXA                                                   \
  ((JSONCPP_VERSION_MAJOR << 24) | (JSONCPP_VERSION_MINOR << 16) |             \
   (JSONCPP_VERSION_PATCH << 8))

#ifdef JSONCPP_USING_SECURE_MEMORY
#undef JSONCPP_USING_SECURE_MEMORY
#endif
#define JSONCPP_USING_SECURE_MEMORY 0
// If non-zero, the library zeroes any memory that it has allocated before
// it frees its memory.

#endif // JSON_VERSION_H_INCLUDED

// //////////////////////////////////////////////////////////////////////
// End of content of file: include/json/version.h
// //////////////////////////////////////////////////////////////////////






// //////////////////////////////////////////////////////////////////////
// Beginning of content of file: include/json/allocator.h
// //////////////////////////////////////////////////////////////////////
#ifndef JSON_ALLOCATOR_H_INCLUDED
#define JSON_ALLOCATOR_H_INCLUDED

#include <cstring>
#include <memory>

#pragma pack(push, 8)

namespace Json {
template <typename T> class SecureAllocator {
public:
  // Type definitions
  using value_type = T;
  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;

  /**
   * Allocate memory for N items using the standard allocator.
   */
  pointer allocate(size_type n) {
    // allocate using "global operator new"
    return static_cast<pointer>(::operator new(n * sizeof(T)));
  }

  /**
   * Release memory which was allocated for N items at pointer P.
   *
   * The memory block is filled with zeroes before being released.
   * The pointer argument is tagged as "volatile" to prevent the
   * compiler optimizing out this critical step.
   */
  void deallocate(volatile pointer p, size_type n) {
    std::memset(p, 0, n * sizeof(T));
    // free using "global operator delete"
    ::operator delete(p);
  }

  /**
   * Construct an item in-place at pointer P.
   */
  template <typename... Args> void construct(pointer p, Args&&... args) {
    // construct using "placement new" and "perfect forwarding"
    ::new (static_cast<void*>(p)) T(std::forward<Args>(args)...);
  }

  size_type max_size() const { return size_t(-1) / sizeof(T); }

  pointer address(reference x) const { return std::addressof(x); }

  const_pointer address(const_reference x) const { return std::addressof(x); }

  /**
   * Destroy an item in-place at pointer P.
   */
  void destroy(pointer p) {
    // destroy using "explicit destructor"
    p->~T();
  }

  // Boilerplate
  SecureAllocator() {}
  template <typename U> SecureAllocator(const SecureAllocator<U>&) {}
  template <typename U> struct rebind { using other = SecureAllocator<U>; };
};

template <typename T, typename U>
bool operator==(const SecureAllocator<T>&, const SecureAllocator<U>&) {
  return true;
}

template <typename T, typename U>
bool operator!=(const SecureAllocator<T>&, const SecureAllocator<U>&) {
  return false;
}

} // namespace Json

#pragma pack(pop)

#endif // JSON_ALLOCATOR_H_INCLUDED

// //////////////////////////////////////////////////////////////////////
// End of content of file: include/json/allocator.h
// //////////////////////////////////////////////////////////////////////






// //////////////////////////////////////////////////////////////////////
// Beginning of content of file: include/json/config.h
// //////////////////////////////////////////////////////////////////////


#ifndef JSON_CONFIG_H_INCLUDED
#define JSON_CONFIG_H_INCLUDED
#include <cstddef>
#include <cstdint>
#include <istream>
#include <memory>
#include <ostream>
#include <sstream>
#include <string>
#include <type_traits>

// If non-zero, the library uses exceptions to report bad input instead of C
// assertion macros. The default is to use exceptions.
#ifndef JSON_USE_EXCEPTION
#define JSON_USE_EXCEPTION 1
#endif

// Temporary, tracked for removal with issue #982.
#ifndef JSON_USE_NULLREF
#define JSON_USE_NULLREF 1
#endif

/// If defined, indicates that the source file is amalgamated
/// to prevent private header inclusion.
/// Remarks: it is automatically defined in the generated amalgamated header.
// #define JSON_IS_AMALGAMATION

// Export macros for DLL visibility
#if defined(JSON_DLL_BUILD)
#if defined(_MSC_VER) || defined(__MINGW32__)
#define JSON_API __declspec(dllexport)
#define JSONCPP_DISABLE_DLL_INTERFACE_WARNING
#elif defined(__GNUC__) || defined(__clang__)
#define JSON_API __attribute__((visibility("default")))
#endif // if defined(_MSC_VER)

#elif defined(JSON_DLL)
#if defined(_MSC_VER) || defined(__MINGW32__)
#define JSON_API __declspec(dllimport)
#define JSONCPP_DISABLE_DLL_INTERFACE_WARNING
#endif // if defined(_MSC_VER)
#endif // ifdef JSON_DLL_BUILD

#if !defined(JSON_API)
#define JSON_API
#endif

#if defined(_MSC_VER) && _MSC_VER < 1800
#error                                                                         \
    "ERROR:  Visual Studio 12 (2013) with _MSC_VER=1800 is the oldest supported compiler with sufficient C++11 capabilities"
#endif

#if defined(_MSC_VER) && _MSC_VER < 1900
// As recommended at
// https://stackoverflow.com/questions/2915672/snprintf-and-visual-studio-2010
extern JSON_API int msvc_pre1900_c99_snprintf(char* outBuf, size_t size,
                                              const char* format, ...);
#define jsoncpp_snprintf msvc_pre1900_c99_snprintf
#else
#define jsoncpp_snprintf std::snprintf
#endif

// If JSON_NO_INT64 is defined, then Json only support C++ "int" type for
// integer
// Storages, and 64 bits integer support is disabled.
// #define JSON_NO_INT64 1

// JSONCPP_OVERRIDE is maintained for backwards compatibility of external tools.
// C++11 should be used directly in JSONCPP.
#define JSONCPP_OVERRIDE override

#ifdef __clang__
#if __has_extension(attribute_deprecated_with_message)
#define JSONCPP_DEPRECATED(message) __attribute__((deprecated(message)))
#endif
#elif defined(__GNUC__) // not clang (gcc comes later since clang emulates gcc)
#if (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 5))
#define JSONCPP_DEPRECATED(message) __attribute__((deprecated(message)))
#elif (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 1))
#define JSONCPP_DEPRECATED(message) __attribute__((__deprecated__))
#endif                  // GNUC version
#elif defined(_MSC_VER) // MSVC (after clang because clang on Windows emulates
                        // MSVC)
#define JSONCPP_DEPRECATED(message) __declspec(deprecated(message))
#endif // __clang__ || __GNUC__ || _MSC_VER

#if !defined(JSONCPP_DEPRECATED)
#define JSONCPP_DEPRECATED(message)
#endif // if !defined(JSONCPP_DEPRECATED)

#if defined(__clang__) || (defined(__GNUC__) && (__GNUC__ >= 6))
#define JSON_USE_INT64_DOUBLE_CONVERSION 1
#endif

#if !defined(JSON_IS_AMALGAMATION)

#include "allocator.h"
#include "version.h"

#endif // if !defined(JSON_IS_AMALGAMATION)

namespace Json {
using Int = int;
using UInt = unsigned int;
#if defined(JSON_NO_INT64)
using LargestInt = int;
using LargestUInt = unsigned int;
#undef JSON_HAS_INT64
#else                 // if defined(JSON_NO_INT64)
// For Microsoft Visual use specific types as long long is not supported
#if defined(_MSC_VER) // Microsoft Visual Studio
using Int64 = __int64;
using UInt64 = unsigned __int64;
#else                 // if defined(_MSC_VER) // Other platforms, use long long
using Int64 = int64_t;
using UInt64 = uint64_t;
#endif                // if defined(_MSC_VER)
using LargestInt = Int64;
using LargestUInt = UInt64;
#define JSON_HAS_INT64
#endif // if defined(JSON_NO_INT64)

template <typename T>
using Allocator =
    typename std::conditional<JSONCPP_USING_SECURE_MEMORY, SecureAllocator<T>,
                              std::allocator<T>>::type;
using String = std::basic_string<char, std::char_traits<char>, Allocator<char>>;
using IStringStream =
    std::basic_istringstream<String::value_type, String::traits_type,
                             String::allocator_type>;
using OStringStream =
    std::basic_ostringstream<String::value_type, String::traits_type,
                             String::allocator_type>;
using IStream = std::istream;
using OStream = std::ostream;
} // namespace Json

// Legacy names (formerly macros).
using JSONCPP_STRING = Json::String;
using JSONCPP_ISTRINGSTREAM = Json::IStringStream;
using JSONCPP_OSTRINGSTREAM = Json::OStringStream;
using JSONCPP_ISTREAM = Json::IStream;
using JSONCPP_OSTREAM = Json::OStream;

#endif // JSON_CONFIG_H_INCLUDED

// //////////////////////////////////////////////////////////////////////
// End of content of file: include/json/config.h
// //////////////////////////////////////////////////////////////////////






// //////////////////////////////////////////////////////////////////////
// Beginning of content of file: include/json/forwards.h
// //////////////////////////////////////////////////////////////////////


#ifndef JSON_FORWARDS_H_INCLUDED
#define JSON_FORWARDS_H_INCLUDED

#if !defined(JSON_IS_AMALGAMATION)
#include "config.h"
#endif // if !defined(JSON_IS_AMALGAMATION)

namespace Json {

// writer.h
class StreamWriter;
class StreamWriterBuilder;
class Writer;
class FastWriter;
class StyledWriter;
class StyledStreamWriter;

// reader.h
class Reader;
class CharReader;
class CharReaderBuilder;

// json_features.h
class Features;

// value.h
using ArrayIndex = unsigned int;
class StaticString;
class Path;
class PathArgument;
class Value;
class ValueIteratorBase;
class ValueIterator;
class ValueConstIterator;

} // namespace Json

#endif // JSON_FORWARDS_H_INCLUDED

// //////////////////////////////////////////////////////////////////////
// End of content of file: include/json/forwards.h
// //////////////////////////////////////////////////////////////////////





#endif //ifndef JSON_FORWARD_AMALGAMATED_H_INCLUDED