#pragma once

#include <cstdint>
#include "proDefines.h"

namespace proE {
  using std::uint8_t;
  using std::uint16_t;
  using std::uint32_t;
  using std::uint64_t;
  using std::int8_t;
  using std::int16_t;
  using std::int32_t;
  using std::int64_t;

  // Basic unsigned types

  using uint8 = uint8_t;
  using uint16 = uint16_t;
  using uint32 = uint32_t;
  using uint64 = uint64_t;

  // Basic Signed types

  using int8  = int8_t;
  using int16 = int16_t;
  using int32 = int32_t;
  using int64 = int64_t;

  // @class QWord

#if PRO_COMPILER == PRO_COMPILER_MSVC
<<<<<<< HEAD
    using WCHAR = wchar_t;
#else 
    using WCHAR = unsigned short;
=======
  using WCHAR = wchar_t;
#else  
  using WCHAR = unsigned short;
>>>>>>> edcc2e013d18047535ffeb7599dc357a47993e19
#endif
  using ANSICHAR = char;
  using UNICHAR = WCHAR;
  // Memory Byte Type
  using BYTE_T = uint8;
  //SIZE_T is an architecture dependant data type
  using SIZE_T = size_t;

}