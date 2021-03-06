/*
 * NOTE: I have made a lot of changes to this file (including renaming
 * all the macros), but no substantive changes. The library still
 * functions exactly the same. Although I've slapped the name of my
 * project onto it, full credit still goes to the developers of Hedley below.
 */

/* Changes:
 * 1. Replaced all instances of HEDLEY_ with __DAI_.
 *    This is to avoid introducing any identifiers not
 *    starting with __DAI_.
 * 2. Changed HEDLEY_MALLOC to __DAI_MALLOC_ATTR to
 *    avoid name clash with existing macro elsewhere.
 * 3. Renamed HEDLEY_VERSION to __DAI_HEDLEY_VERSION.
 */


 /* Hedley - https://nemequ.github.io/hedley
 * Created by Evan Nemerson <evan@nemerson.com>
 *
 * To the extent possible under law, the author(s) have dedicated all
 * copyright and related and neighboring rights to this software to
 * the public domain worldwide. This software is distributed without
 * any warranty.
 *
 * For details, see <http://creativecommons.org/publicdomain/zero/1.0/>.
 * SPDX-License-Identifier: CC0-1.0
 */

#if !defined(__DAI_HEDLEY_VERSION) || (__DAI_HEDLEY_VERSION < 15)
#if defined(__DAI_HEDLEY_VERSION)
#  undef __DAI_HEDLEY_VERSION
#endif
#define __DAI_HEDLEY_VERSION 15

#if defined(__DAI_STRINGIFY_EX)
#  undef __DAI_STRINGIFY_EX
#endif
#define __DAI_STRINGIFY_EX(x) #x

#if defined(__DAI_STRINGIFY)
#  undef __DAI_STRINGIFY
#endif
#define __DAI_STRINGIFY(x) __DAI_STRINGIFY_EX(x)

#if defined(__DAI_CONCAT_EX)
#  undef __DAI_CONCAT_EX
#endif
#define __DAI_CONCAT_EX(a,b) a##b

#if defined(__DAI_CONCAT)
#  undef __DAI_CONCAT
#endif
#define __DAI_CONCAT(a,b) __DAI_CONCAT_EX(a,b)

#if defined(__DAI_CONCAT3_EX)
#  undef __DAI_CONCAT3_EX
#endif
#define __DAI_CONCAT3_EX(a,b,c) a##b##c

#if defined(__DAI_CONCAT3)
#  undef __DAI_CONCAT3
#endif
#define __DAI_CONCAT3(a,b,c) __DAI_CONCAT3_EX(a,b,c)

#if defined(__DAI_HEDLEY_VERSION_ENCODE)
#  undef __DAI_HEDLEY_VERSION_ENCODE
#endif
#define __DAI_HEDLEY_VERSION_ENCODE(major,minor,revision) (((major) * 1000000) + ((minor) * 1000) + (revision))

#if defined(__DAI_HEDLEY_VERSION_DECODE_MAJOR)
#  undef __DAI_HEDLEY_VERSION_DECODE_MAJOR
#endif
#define __DAI_HEDLEY_VERSION_DECODE_MAJOR(version) ((version) / 1000000)

#if defined(__DAI_HEDLEY_VERSION_DECODE_MINOR)
#  undef __DAI_HEDLEY_VERSION_DECODE_MINOR
#endif
#define __DAI_HEDLEY_VERSION_DECODE_MINOR(version) (((version) % 1000000) / 1000)

#if defined(__DAI_HEDLEY_VERSION_DECODE_REVISION)
#  undef __DAI_HEDLEY_VERSION_DECODE_REVISION
#endif
#define __DAI_HEDLEY_VERSION_DECODE_REVISION(version) ((version) % 1000)

#if defined(__DAI_GNUC_VERSION)
#  undef __DAI_GNUC_VERSION
#endif
#if defined(__GNUC__) && defined(__GNUC_PATCHLEVEL__)
#  define __DAI_GNUC_VERSION __DAI_HEDLEY_VERSION_ENCODE(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#elif defined(__GNUC__)
#  define __DAI_GNUC_VERSION __DAI_HEDLEY_VERSION_ENCODE(__GNUC__, __GNUC_MINOR__, 0)
#endif

#if defined(__DAI_GNUC_VERSION_CHECK)
#  undef __DAI_GNUC_VERSION_CHECK
#endif
#if defined(__DAI_GNUC_VERSION)
#  define __DAI_GNUC_VERSION_CHECK(major,minor,patch) (__DAI_GNUC_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_GNUC_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_MSVC_VERSION)
#  undef __DAI_MSVC_VERSION
#endif
#if defined(_MSC_FULL_VER) && (_MSC_FULL_VER >= 140000000) && !defined(__ICL)
#  define __DAI_MSVC_VERSION __DAI_HEDLEY_VERSION_ENCODE(_MSC_FULL_VER / 10000000, (_MSC_FULL_VER % 10000000) / 100000, (_MSC_FULL_VER % 100000) / 100)
#elif defined(_MSC_FULL_VER) && !defined(__ICL)
#  define __DAI_MSVC_VERSION __DAI_HEDLEY_VERSION_ENCODE(_MSC_FULL_VER / 1000000, (_MSC_FULL_VER % 1000000) / 10000, (_MSC_FULL_VER % 10000) / 10)
#elif defined(_MSC_VER) && !defined(__ICL)
#  define __DAI_MSVC_VERSION __DAI_HEDLEY_VERSION_ENCODE(_MSC_VER / 100, _MSC_VER % 100, 0)
#endif

#if defined(__DAI_MSVC_VERSION_CHECK)
#  undef __DAI_MSVC_VERSION_CHECK
#endif
#if !defined(__DAI_MSVC_VERSION)
#  define __DAI_MSVC_VERSION_CHECK(major,minor,patch) (0)
#elif defined(_MSC_VER) && (_MSC_VER >= 1400)
#  define __DAI_MSVC_VERSION_CHECK(major,minor,patch) (_MSC_FULL_VER >= ((major * 10000000) + (minor * 100000) + (patch)))
#elif defined(_MSC_VER) && (_MSC_VER >= 1200)
#  define __DAI_MSVC_VERSION_CHECK(major,minor,patch) (_MSC_FULL_VER >= ((major * 1000000) + (minor * 10000) + (patch)))
#else
#  define __DAI_MSVC_VERSION_CHECK(major,minor,patch) (_MSC_VER >= ((major * 100) + (minor)))
#endif

#if defined(__DAI_INTEL_VERSION)
#  undef __DAI_INTEL_VERSION
#endif
#if defined(__INTEL_COMPILER) && defined(__INTEL_COMPILER_UPDATE) && !defined(__ICL)
#  define __DAI_INTEL_VERSION __DAI_HEDLEY_VERSION_ENCODE(__INTEL_COMPILER / 100, __INTEL_COMPILER % 100, __INTEL_COMPILER_UPDATE)
#elif defined(__INTEL_COMPILER) && !defined(__ICL)
#  define __DAI_INTEL_VERSION __DAI_HEDLEY_VERSION_ENCODE(__INTEL_COMPILER / 100, __INTEL_COMPILER % 100, 0)
#endif

#if defined(__DAI_INTEL_VERSION_CHECK)
#  undef __DAI_INTEL_VERSION_CHECK
#endif
#if defined(__DAI_INTEL_VERSION)
#  define __DAI_INTEL_VERSION_CHECK(major,minor,patch) (__DAI_INTEL_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_INTEL_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_INTEL_CL_VERSION)
#  undef __DAI_INTEL_CL_VERSION
#endif
#if defined(__INTEL_COMPILER) && defined(__INTEL_COMPILER_UPDATE) && defined(__ICL)
#  define __DAI_INTEL_CL_VERSION __DAI_HEDLEY_VERSION_ENCODE(__INTEL_COMPILER, __INTEL_COMPILER_UPDATE, 0)
#endif

#if defined(__DAI_INTEL_CL_VERSION_CHECK)
#  undef __DAI_INTEL_CL_VERSION_CHECK
#endif
#if defined(__DAI_INTEL_CL_VERSION)
#  define __DAI_INTEL_CL_VERSION_CHECK(major,minor,patch) (__DAI_INTEL_CL_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_INTEL_CL_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_PGI_VERSION)
#  undef __DAI_PGI_VERSION
#endif
#if defined(__PGI) && defined(__PGIC__) && defined(__PGIC_MINOR__) && defined(__PGIC_PATCHLEVEL__)
#  define __DAI_PGI_VERSION __DAI_HEDLEY_VERSION_ENCODE(__PGIC__, __PGIC_MINOR__, __PGIC_PATCHLEVEL__)
#endif

#if defined(__DAI_PGI_VERSION_CHECK)
#  undef __DAI_PGI_VERSION_CHECK
#endif
#if defined(__DAI_PGI_VERSION)
#  define __DAI_PGI_VERSION_CHECK(major,minor,patch) (__DAI_PGI_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_PGI_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_SUNPRO_VERSION)
#  undef __DAI_SUNPRO_VERSION
#endif
#if defined(__SUNPRO_C) && (__SUNPRO_C > 0x1000)
#  define __DAI_SUNPRO_VERSION __DAI_HEDLEY_VERSION_ENCODE((((__SUNPRO_C >> 16) & 0xf) * 10) + ((__SUNPRO_C >> 12) & 0xf), (((__SUNPRO_C >> 8) & 0xf) * 10) + ((__SUNPRO_C >> 4) & 0xf), (__SUNPRO_C & 0xf) * 10)
#elif defined(__SUNPRO_C)
#  define __DAI_SUNPRO_VERSION __DAI_HEDLEY_VERSION_ENCODE((__SUNPRO_C >> 8) & 0xf, (__SUNPRO_C >> 4) & 0xf, (__SUNPRO_C) & 0xf)
#elif defined(__SUNPRO_CC) && (__SUNPRO_CC > 0x1000)
#  define __DAI_SUNPRO_VERSION __DAI_HEDLEY_VERSION_ENCODE((((__SUNPRO_CC >> 16) & 0xf) * 10) + ((__SUNPRO_CC >> 12) & 0xf), (((__SUNPRO_CC >> 8) & 0xf) * 10) + ((__SUNPRO_CC >> 4) & 0xf), (__SUNPRO_CC & 0xf) * 10)
#elif defined(__SUNPRO_CC)
#  define __DAI_SUNPRO_VERSION __DAI_HEDLEY_VERSION_ENCODE((__SUNPRO_CC >> 8) & 0xf, (__SUNPRO_CC >> 4) & 0xf, (__SUNPRO_CC) & 0xf)
#endif

#if defined(__DAI_SUNPRO_VERSION_CHECK)
#  undef __DAI_SUNPRO_VERSION_CHECK
#endif
#if defined(__DAI_SUNPRO_VERSION)
#  define __DAI_SUNPRO_VERSION_CHECK(major,minor,patch) (__DAI_SUNPRO_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_SUNPRO_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_EMSCRIPTEN_VERSION)
#  undef __DAI_EMSCRIPTEN_VERSION
#endif
#if defined(__EMSCRIPTEN__)
#  define __DAI_EMSCRIPTEN_VERSION __DAI_HEDLEY_VERSION_ENCODE(__EMSCRIPTEN_major__, __EMSCRIPTEN_minor__, __EMSCRIPTEN_tiny__)
#endif

#if defined(__DAI_EMSCRIPTEN_VERSION_CHECK)
#  undef __DAI_EMSCRIPTEN_VERSION_CHECK
#endif
#if defined(__DAI_EMSCRIPTEN_VERSION)
#  define __DAI_EMSCRIPTEN_VERSION_CHECK(major,minor,patch) (__DAI_EMSCRIPTEN_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_EMSCRIPTEN_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_ARM_VERSION)
#  undef __DAI_ARM_VERSION
#endif
#if defined(__CC_ARM) && defined(__ARMCOMPILER_VERSION)
#  define __DAI_ARM_VERSION __DAI_HEDLEY_VERSION_ENCODE(__ARMCOMPILER_VERSION / 1000000, (__ARMCOMPILER_VERSION % 1000000) / 10000, (__ARMCOMPILER_VERSION % 10000) / 100)
#elif defined(__CC_ARM) && defined(__ARMCC_VERSION)
#  define __DAI_ARM_VERSION __DAI_HEDLEY_VERSION_ENCODE(__ARMCC_VERSION / 1000000, (__ARMCC_VERSION % 1000000) / 10000, (__ARMCC_VERSION % 10000) / 100)
#endif

#if defined(__DAI_ARM_VERSION_CHECK)
#  undef __DAI_ARM_VERSION_CHECK
#endif
#if defined(__DAI_ARM_VERSION)
#  define __DAI_ARM_VERSION_CHECK(major,minor,patch) (__DAI_ARM_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_ARM_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_IBM_VERSION)
#  undef __DAI_IBM_VERSION
#endif
#if defined(__ibmxl__)
#  define __DAI_IBM_VERSION __DAI_HEDLEY_VERSION_ENCODE(__ibmxl_version__, __ibmxl_release__, __ibmxl_modification__)
#elif defined(__xlC__) && defined(__xlC_ver__)
#  define __DAI_IBM_VERSION __DAI_HEDLEY_VERSION_ENCODE(__xlC__ >> 8, __xlC__ & 0xff, (__xlC_ver__ >> 8) & 0xff)
#elif defined(__xlC__)
#  define __DAI_IBM_VERSION __DAI_HEDLEY_VERSION_ENCODE(__xlC__ >> 8, __xlC__ & 0xff, 0)
#endif

#if defined(__DAI_IBM_VERSION_CHECK)
#  undef __DAI_IBM_VERSION_CHECK
#endif
#if defined(__DAI_IBM_VERSION)
#  define __DAI_IBM_VERSION_CHECK(major,minor,patch) (__DAI_IBM_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_IBM_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_TI_VERSION)
#  undef __DAI_TI_VERSION
#endif
#if \
    defined(__TI_COMPILER_VERSION__) && \
    ( \
      defined(__TMS470__) || defined(__TI_ARM__) || \
      defined(__MSP430__) || \
      defined(__TMS320C2000__) \
    )
#  if (__TI_COMPILER_VERSION__ >= 16000000)
#    define __DAI_TI_VERSION __DAI_HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#  endif
#endif

#if defined(__DAI_TI_VERSION_CHECK)
#  undef __DAI_TI_VERSION_CHECK
#endif
#if defined(__DAI_TI_VERSION)
#  define __DAI_TI_VERSION_CHECK(major,minor,patch) (__DAI_TI_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_TI_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_TI_CL2000_VERSION)
#  undef __DAI_TI_CL2000_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__) && defined(__TMS320C2000__)
#  define __DAI_TI_CL2000_VERSION __DAI_HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif

#if defined(__DAI_TI_CL2000_VERSION_CHECK)
#  undef __DAI_TI_CL2000_VERSION_CHECK
#endif
#if defined(__DAI_TI_CL2000_VERSION)
#  define __DAI_TI_CL2000_VERSION_CHECK(major,minor,patch) (__DAI_TI_CL2000_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_TI_CL2000_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_TI_CL430_VERSION)
#  undef __DAI_TI_CL430_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__) && defined(__MSP430__)
#  define __DAI_TI_CL430_VERSION __DAI_HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif

#if defined(__DAI_TI_CL430_VERSION_CHECK)
#  undef __DAI_TI_CL430_VERSION_CHECK
#endif
#if defined(__DAI_TI_CL430_VERSION)
#  define __DAI_TI_CL430_VERSION_CHECK(major,minor,patch) (__DAI_TI_CL430_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_TI_CL430_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_TI_ARMCL_VERSION)
#  undef __DAI_TI_ARMCL_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__) && (defined(__TMS470__) || defined(__TI_ARM__))
#  define __DAI_TI_ARMCL_VERSION __DAI_HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif

#if defined(__DAI_TI_ARMCL_VERSION_CHECK)
#  undef __DAI_TI_ARMCL_VERSION_CHECK
#endif
#if defined(__DAI_TI_ARMCL_VERSION)
#  define __DAI_TI_ARMCL_VERSION_CHECK(major,minor,patch) (__DAI_TI_ARMCL_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_TI_ARMCL_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_TI_CL6X_VERSION)
#  undef __DAI_TI_CL6X_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__) && defined(__TMS320C6X__)
#  define __DAI_TI_CL6X_VERSION __DAI_HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif

#if defined(__DAI_TI_CL6X_VERSION_CHECK)
#  undef __DAI_TI_CL6X_VERSION_CHECK
#endif
#if defined(__DAI_TI_CL6X_VERSION)
#  define __DAI_TI_CL6X_VERSION_CHECK(major,minor,patch) (__DAI_TI_CL6X_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_TI_CL6X_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_TI_CL7X_VERSION)
#  undef __DAI_TI_CL7X_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__) && defined(__C7000__)
#  define __DAI_TI_CL7X_VERSION __DAI_HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif

#if defined(__DAI_TI_CL7X_VERSION_CHECK)
#  undef __DAI_TI_CL7X_VERSION_CHECK
#endif
#if defined(__DAI_TI_CL7X_VERSION)
#  define __DAI_TI_CL7X_VERSION_CHECK(major,minor,patch) (__DAI_TI_CL7X_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_TI_CL7X_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_TI_CLPRU_VERSION)
#  undef __DAI_TI_CLPRU_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__) && defined(__PRU__)
#  define __DAI_TI_CLPRU_VERSION __DAI_HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif

#if defined(__DAI_TI_CLPRU_VERSION_CHECK)
#  undef __DAI_TI_CLPRU_VERSION_CHECK
#endif
#if defined(__DAI_TI_CLPRU_VERSION)
#  define __DAI_TI_CLPRU_VERSION_CHECK(major,minor,patch) (__DAI_TI_CLPRU_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_TI_CLPRU_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_CRAY_VERSION)
#  undef __DAI_CRAY_VERSION
#endif
#if defined(_CRAYC)
#  if defined(_RELEASE_PATCHLEVEL)
#    define __DAI_CRAY_VERSION __DAI_HEDLEY_VERSION_ENCODE(_RELEASE_MAJOR, _RELEASE_MINOR, _RELEASE_PATCHLEVEL)
#  else
#    define __DAI_CRAY_VERSION __DAI_HEDLEY_VERSION_ENCODE(_RELEASE_MAJOR, _RELEASE_MINOR, 0)
#  endif
#endif

#if defined(__DAI_CRAY_VERSION_CHECK)
#  undef __DAI_CRAY_VERSION_CHECK
#endif
#if defined(__DAI_CRAY_VERSION)
#  define __DAI_CRAY_VERSION_CHECK(major,minor,patch) (__DAI_CRAY_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_CRAY_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_IAR_VERSION)
#  undef __DAI_IAR_VERSION
#endif
#if defined(__IAR_SYSTEMS_ICC__)
#  if __VER__ > 1000
#    define __DAI_IAR_VERSION __DAI_HEDLEY_VERSION_ENCODE((__VER__ / 1000000), ((__VER__ / 1000) % 1000), (__VER__ % 1000))
#  else
#    define __DAI_IAR_VERSION __DAI_HEDLEY_VERSION_ENCODE(__VER__ / 100, __VER__ % 100, 0)
#  endif
#endif

#if defined(__DAI_IAR_VERSION_CHECK)
#  undef __DAI_IAR_VERSION_CHECK
#endif
#if defined(__DAI_IAR_VERSION)
#  define __DAI_IAR_VERSION_CHECK(major,minor,patch) (__DAI_IAR_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_IAR_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_TINYC_VERSION)
#  undef __DAI_TINYC_VERSION
#endif
#if defined(__TINYC__)
#  define __DAI_TINYC_VERSION __DAI_HEDLEY_VERSION_ENCODE(__TINYC__ / 1000, (__TINYC__ / 100) % 10, __TINYC__ % 100)
#endif

#if defined(__DAI_TINYC_VERSION_CHECK)
#  undef __DAI_TINYC_VERSION_CHECK
#endif
#if defined(__DAI_TINYC_VERSION)
#  define __DAI_TINYC_VERSION_CHECK(major,minor,patch) (__DAI_TINYC_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_TINYC_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_DMC_VERSION)
#  undef __DAI_DMC_VERSION
#endif
#if defined(__DMC__)
#  define __DAI_DMC_VERSION __DAI_HEDLEY_VERSION_ENCODE(__DMC__ >> 8, (__DMC__ >> 4) & 0xf, __DMC__ & 0xf)
#endif

#if defined(__DAI_DMC_VERSION_CHECK)
#  undef __DAI_DMC_VERSION_CHECK
#endif
#if defined(__DAI_DMC_VERSION)
#  define __DAI_DMC_VERSION_CHECK(major,minor,patch) (__DAI_DMC_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_DMC_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_COMPCERT_VERSION)
#  undef __DAI_COMPCERT_VERSION
#endif
#if defined(__COMPCERT_VERSION__)
#  define __DAI_COMPCERT_VERSION __DAI_HEDLEY_VERSION_ENCODE(__COMPCERT_VERSION__ / 10000, (__COMPCERT_VERSION__ / 100) % 100, __COMPCERT_VERSION__ % 100)
#endif

#if defined(__DAI_COMPCERT_VERSION_CHECK)
#  undef __DAI_COMPCERT_VERSION_CHECK
#endif
#if defined(__DAI_COMPCERT_VERSION)
#  define __DAI_COMPCERT_VERSION_CHECK(major,minor,patch) (__DAI_COMPCERT_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_COMPCERT_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_PELLES_VERSION)
#  undef __DAI_PELLES_VERSION
#endif
#if defined(__POCC__)
#  define __DAI_PELLES_VERSION __DAI_HEDLEY_VERSION_ENCODE(__POCC__ / 100, __POCC__ % 100, 0)
#endif

#if defined(__DAI_PELLES_VERSION_CHECK)
#  undef __DAI_PELLES_VERSION_CHECK
#endif
#if defined(__DAI_PELLES_VERSION)
#  define __DAI_PELLES_VERSION_CHECK(major,minor,patch) (__DAI_PELLES_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_PELLES_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_MCST_LCC_VERSION)
#  undef __DAI_MCST_LCC_VERSION
#endif
#if defined(__LCC__) && defined(__LCC_MINOR__)
#  define __DAI_MCST_LCC_VERSION __DAI_HEDLEY_VERSION_ENCODE(__LCC__ / 100, __LCC__ % 100, __LCC_MINOR__)
#endif

#if defined(__DAI_MCST_LCC_VERSION_CHECK)
#  undef __DAI_MCST_LCC_VERSION_CHECK
#endif
#if defined(__DAI_MCST_LCC_VERSION)
#  define __DAI_MCST_LCC_VERSION_CHECK(major,minor,patch) (__DAI_MCST_LCC_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_MCST_LCC_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_GCC_VERSION)
#  undef __DAI_GCC_VERSION
#endif
#if \
  defined(__DAI_GNUC_VERSION) && \
  !defined(__clang__) && \
  !defined(__DAI_INTEL_VERSION) && \
  !defined(__DAI_PGI_VERSION) && \
  !defined(__DAI_ARM_VERSION) && \
  !defined(__DAI_CRAY_VERSION) && \
  !defined(__DAI_TI_VERSION) && \
  !defined(__DAI_TI_ARMCL_VERSION) && \
  !defined(__DAI_TI_CL430_VERSION) && \
  !defined(__DAI_TI_CL2000_VERSION) && \
  !defined(__DAI_TI_CL6X_VERSION) && \
  !defined(__DAI_TI_CL7X_VERSION) && \
  !defined(__DAI_TI_CLPRU_VERSION) && \
  !defined(__COMPCERT__) && \
  !defined(__DAI_MCST_LCC_VERSION)
#  define __DAI_GCC_VERSION __DAI_GNUC_VERSION
#endif

#if defined(__DAI_GCC_VERSION_CHECK)
#  undef __DAI_GCC_VERSION_CHECK
#endif
#if defined(__DAI_GCC_VERSION)
#  define __DAI_GCC_VERSION_CHECK(major,minor,patch) (__DAI_GCC_VERSION >= __DAI_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define __DAI_GCC_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(__DAI_HAS_ATTRIBUTE)
#  undef __DAI_HAS_ATTRIBUTE
#endif
#if \
  defined(__has_attribute) && \
  ( \
    (!defined(__DAI_IAR_VERSION) || __DAI_IAR_VERSION_CHECK(8,5,9)) \
  )
#  define __DAI_HAS_ATTRIBUTE(attribute) __has_attribute(attribute)
#else
#  define __DAI_HAS_ATTRIBUTE(attribute) (0)
#endif

#if defined(__DAI_GNUC_HAS_ATTRIBUTE)
#  undef __DAI_GNUC_HAS_ATTRIBUTE
#endif
#if defined(__has_attribute)
#  define __DAI_GNUC_HAS_ATTRIBUTE(attribute,major,minor,patch) __DAI_HAS_ATTRIBUTE(attribute)
#else
#  define __DAI_GNUC_HAS_ATTRIBUTE(attribute,major,minor,patch) __DAI_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(__DAI_GCC_HAS_ATTRIBUTE)
#  undef __DAI_GCC_HAS_ATTRIBUTE
#endif
#if defined(__has_attribute)
#  define __DAI_GCC_HAS_ATTRIBUTE(attribute,major,minor,patch) __DAI_HAS_ATTRIBUTE(attribute)
#else
#  define __DAI_GCC_HAS_ATTRIBUTE(attribute,major,minor,patch) __DAI_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(__DAI_HAS_CPP_ATTRIBUTE)
#  undef __DAI_HAS_CPP_ATTRIBUTE
#endif
#if \
  defined(__has_cpp_attribute) && \
  defined(__cplusplus) && \
  (!defined(__DAI_SUNPRO_VERSION) || __DAI_SUNPRO_VERSION_CHECK(5,15,0))
#  define __DAI_HAS_CPP_ATTRIBUTE(attribute) __has_cpp_attribute(attribute)
#else
#  define __DAI_HAS_CPP_ATTRIBUTE(attribute) (0)
#endif

#if defined(__DAI_HAS_CPP_ATTRIBUTE_NS)
#  undef __DAI_HAS_CPP_ATTRIBUTE_NS
#endif
#if !defined(__cplusplus) || !defined(__has_cpp_attribute)
#  define __DAI_HAS_CPP_ATTRIBUTE_NS(ns,attribute) (0)
#elif \
  !defined(__DAI_PGI_VERSION) && \
  !defined(__DAI_IAR_VERSION) && \
  (!defined(__DAI_SUNPRO_VERSION) || __DAI_SUNPRO_VERSION_CHECK(5,15,0)) && \
  (!defined(__DAI_MSVC_VERSION) || __DAI_MSVC_VERSION_CHECK(19,20,0))
#  define __DAI_HAS_CPP_ATTRIBUTE_NS(ns,attribute) __DAI_HAS_CPP_ATTRIBUTE(ns::attribute)
#else
#  define __DAI_HAS_CPP_ATTRIBUTE_NS(ns,attribute) (0)
#endif

#if defined(__DAI_GNUC_HAS_CPP_ATTRIBUTE)
#  undef __DAI_GNUC_HAS_CPP_ATTRIBUTE
#endif
#if defined(__has_cpp_attribute) && defined(__cplusplus)
#  define __DAI_GNUC_HAS_CPP_ATTRIBUTE(attribute,major,minor,patch) __has_cpp_attribute(attribute)
#else
#  define __DAI_GNUC_HAS_CPP_ATTRIBUTE(attribute,major,minor,patch) __DAI_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(__DAI_GCC_HAS_CPP_ATTRIBUTE)
#  undef __DAI_GCC_HAS_CPP_ATTRIBUTE
#endif
#if defined(__has_cpp_attribute) && defined(__cplusplus)
#  define __DAI_GCC_HAS_CPP_ATTRIBUTE(attribute,major,minor,patch) __has_cpp_attribute(attribute)
#else
#  define __DAI_GCC_HAS_CPP_ATTRIBUTE(attribute,major,minor,patch) __DAI_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(__DAI_HAS_BUILTIN)
#  undef __DAI_HAS_BUILTIN
#endif
#if defined(__has_builtin)
#  define __DAI_HAS_BUILTIN(builtin) __has_builtin(builtin)
#else
#  define __DAI_HAS_BUILTIN(builtin) (0)
#endif

#if defined(__DAI_GNUC_HAS_BUILTIN)
#  undef __DAI_GNUC_HAS_BUILTIN
#endif
#if defined(__has_builtin)
#  define __DAI_GNUC_HAS_BUILTIN(builtin,major,minor,patch) __has_builtin(builtin)
#else
#  define __DAI_GNUC_HAS_BUILTIN(builtin,major,minor,patch) __DAI_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(__DAI_GCC_HAS_BUILTIN)
#  undef __DAI_GCC_HAS_BUILTIN
#endif
#if defined(__has_builtin)
#  define __DAI_GCC_HAS_BUILTIN(builtin,major,minor,patch) __has_builtin(builtin)
#else
#  define __DAI_GCC_HAS_BUILTIN(builtin,major,minor,patch) __DAI_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(__DAI_HAS_FEATURE)
#  undef __DAI_HAS_FEATURE
#endif
#if defined(__has_feature)
#  define __DAI_HAS_FEATURE(feature) __has_feature(feature)
#else
#  define __DAI_HAS_FEATURE(feature) (0)
#endif

#if defined(__DAI_GNUC_HAS_FEATURE)
#  undef __DAI_GNUC_HAS_FEATURE
#endif
#if defined(__has_feature)
#  define __DAI_GNUC_HAS_FEATURE(feature,major,minor,patch) __has_feature(feature)
#else
#  define __DAI_GNUC_HAS_FEATURE(feature,major,minor,patch) __DAI_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(__DAI_GCC_HAS_FEATURE)
#  undef __DAI_GCC_HAS_FEATURE
#endif
#if defined(__has_feature)
#  define __DAI_GCC_HAS_FEATURE(feature,major,minor,patch) __has_feature(feature)
#else
#  define __DAI_GCC_HAS_FEATURE(feature,major,minor,patch) __DAI_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(__DAI_HAS_EXTENSION)
#  undef __DAI_HAS_EXTENSION
#endif
#if defined(__has_extension)
#  define __DAI_HAS_EXTENSION(extension) __has_extension(extension)
#else
#  define __DAI_HAS_EXTENSION(extension) (0)
#endif

#if defined(__DAI_GNUC_HAS_EXTENSION)
#  undef __DAI_GNUC_HAS_EXTENSION
#endif
#if defined(__has_extension)
#  define __DAI_GNUC_HAS_EXTENSION(extension,major,minor,patch) __has_extension(extension)
#else
#  define __DAI_GNUC_HAS_EXTENSION(extension,major,minor,patch) __DAI_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(__DAI_GCC_HAS_EXTENSION)
#  undef __DAI_GCC_HAS_EXTENSION
#endif
#if defined(__has_extension)
#  define __DAI_GCC_HAS_EXTENSION(extension,major,minor,patch) __has_extension(extension)
#else
#  define __DAI_GCC_HAS_EXTENSION(extension,major,minor,patch) __DAI_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(__DAI_HAS_DECLSPEC_ATTRIBUTE)
#  undef __DAI_HAS_DECLSPEC_ATTRIBUTE
#endif
#if defined(__has_declspec_attribute)
#  define __DAI_HAS_DECLSPEC_ATTRIBUTE(attribute) __has_declspec_attribute(attribute)
#else
#  define __DAI_HAS_DECLSPEC_ATTRIBUTE(attribute) (0)
#endif

#if defined(__DAI_GNUC_HAS_DECLSPEC_ATTRIBUTE)
#  undef __DAI_GNUC_HAS_DECLSPEC_ATTRIBUTE
#endif
#if defined(__has_declspec_attribute)
#  define __DAI_GNUC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) __has_declspec_attribute(attribute)
#else
#  define __DAI_GNUC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) __DAI_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(__DAI_GCC_HAS_DECLSPEC_ATTRIBUTE)
#  undef __DAI_GCC_HAS_DECLSPEC_ATTRIBUTE
#endif
#if defined(__has_declspec_attribute)
#  define __DAI_GCC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) __has_declspec_attribute(attribute)
#else
#  define __DAI_GCC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) __DAI_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(__DAI_HAS_WARNING)
#  undef __DAI_HAS_WARNING
#endif
#if defined(__has_warning)
#  define __DAI_HAS_WARNING(warning) __has_warning(warning)
#else
#  define __DAI_HAS_WARNING(warning) (0)
#endif

#if defined(__DAI_GNUC_HAS_WARNING)
#  undef __DAI_GNUC_HAS_WARNING
#endif
#if defined(__has_warning)
#  define __DAI_GNUC_HAS_WARNING(warning,major,minor,patch) __has_warning(warning)
#else
#  define __DAI_GNUC_HAS_WARNING(warning,major,minor,patch) __DAI_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(__DAI_GCC_HAS_WARNING)
#  undef __DAI_GCC_HAS_WARNING
#endif
#if defined(__has_warning)
#  define __DAI_GCC_HAS_WARNING(warning,major,minor,patch) __has_warning(warning)
#else
#  define __DAI_GCC_HAS_WARNING(warning,major,minor,patch) __DAI_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if \
  (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) || \
  defined(__clang__) || \
  __DAI_GCC_VERSION_CHECK(3,0,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  __DAI_IAR_VERSION_CHECK(8,0,0) || \
  __DAI_PGI_VERSION_CHECK(18,4,0) || \
  __DAI_ARM_VERSION_CHECK(4,1,0) || \
  __DAI_TI_VERSION_CHECK(15,12,0) || \
  __DAI_TI_ARMCL_VERSION_CHECK(4,7,0) || \
  __DAI_TI_CL430_VERSION_CHECK(2,0,1) || \
  __DAI_TI_CL2000_VERSION_CHECK(6,1,0) || \
  __DAI_TI_CL6X_VERSION_CHECK(7,0,0) || \
  __DAI_TI_CL7X_VERSION_CHECK(1,2,0) || \
  __DAI_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  __DAI_CRAY_VERSION_CHECK(5,0,0) || \
  __DAI_TINYC_VERSION_CHECK(0,9,17) || \
  __DAI_SUNPRO_VERSION_CHECK(8,0,0) || \
  (__DAI_IBM_VERSION_CHECK(10,1,0) && defined(__C99_PRAGMA_OPERATOR))
#  define __DAI_PRAGMA(value) _Pragma(#value)
#elif __DAI_MSVC_VERSION_CHECK(15,0,0)
#  define __DAI_PRAGMA(value) __pragma(value)
#else
#  define __DAI_PRAGMA(value)
#endif

#if defined(__DAI_DIAGNOSTIC_PUSH)
#  undef __DAI_DIAGNOSTIC_PUSH
#endif
#if defined(__DAI_DIAGNOSTIC_POP)
#  undef __DAI_DIAGNOSTIC_POP
#endif
#if defined(__clang__)
#  define __DAI_DIAGNOSTIC_PUSH _Pragma("clang diagnostic push")
#  define __DAI_DIAGNOSTIC_POP _Pragma("clang diagnostic pop")
#elif __DAI_INTEL_VERSION_CHECK(13,0,0)
#  define __DAI_DIAGNOSTIC_PUSH _Pragma("warning(push)")
#  define __DAI_DIAGNOSTIC_POP _Pragma("warning(pop)")
#elif __DAI_GCC_VERSION_CHECK(4,6,0)
#  define __DAI_DIAGNOSTIC_PUSH _Pragma("GCC diagnostic push")
#  define __DAI_DIAGNOSTIC_POP _Pragma("GCC diagnostic pop")
#elif \
  __DAI_MSVC_VERSION_CHECK(15,0,0) || \
  __DAI_INTEL_CL_VERSION_CHECK(2021,1,0)
#  define __DAI_DIAGNOSTIC_PUSH __pragma(warning(push))
#  define __DAI_DIAGNOSTIC_POP __pragma(warning(pop))
#elif __DAI_ARM_VERSION_CHECK(5,6,0)
#  define __DAI_DIAGNOSTIC_PUSH _Pragma("push")
#  define __DAI_DIAGNOSTIC_POP _Pragma("pop")
#elif \
    __DAI_TI_VERSION_CHECK(15,12,0) || \
    __DAI_TI_ARMCL_VERSION_CHECK(5,2,0) || \
    __DAI_TI_CL430_VERSION_CHECK(4,4,0) || \
    __DAI_TI_CL6X_VERSION_CHECK(8,1,0) || \
    __DAI_TI_CL7X_VERSION_CHECK(1,2,0) || \
    __DAI_TI_CLPRU_VERSION_CHECK(2,1,0)
#  define __DAI_DIAGNOSTIC_PUSH _Pragma("diag_push")
#  define __DAI_DIAGNOSTIC_POP _Pragma("diag_pop")
#elif __DAI_PELLES_VERSION_CHECK(2,90,0)
#  define __DAI_DIAGNOSTIC_PUSH _Pragma("warning(push)")
#  define __DAI_DIAGNOSTIC_POP _Pragma("warning(pop)")
#else
#  define __DAI_DIAGNOSTIC_PUSH
#  define __DAI_DIAGNOSTIC_POP
#endif

/* __DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_ is for
   HEDLEY INTERNAL USE ONLY.  API subject to change without notice. */
#if defined(__DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_)
#  undef __DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_
#endif
#if defined(__cplusplus)
#  if __DAI_HAS_WARNING("-Wc++98-compat")
#    if __DAI_HAS_WARNING("-Wc++17-extensions")
#      if __DAI_HAS_WARNING("-Wc++1z-extensions")
#        define __DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(xpr) \
           __DAI_DIAGNOSTIC_PUSH \
           _Pragma("clang diagnostic ignored \"-Wc++98-compat\"") \
           _Pragma("clang diagnostic ignored \"-Wc++17-extensions\"") \
           _Pragma("clang diagnostic ignored \"-Wc++1z-extensions\"") \
           xpr \
           __DAI_DIAGNOSTIC_POP
#      else
#        define __DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(xpr) \
           __DAI_DIAGNOSTIC_PUSH \
           _Pragma("clang diagnostic ignored \"-Wc++98-compat\"") \
           _Pragma("clang diagnostic ignored \"-Wc++17-extensions\"") \
           xpr \
           __DAI_DIAGNOSTIC_POP
#      endif
#    else
#      define __DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(xpr) \
         __DAI_DIAGNOSTIC_PUSH \
         _Pragma("clang diagnostic ignored \"-Wc++98-compat\"") \
         xpr \
         __DAI_DIAGNOSTIC_POP
#    endif
#  endif
#endif
#if !defined(__DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_)
#  define __DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(x) x
#endif

#if defined(__DAI_CONST_CAST)
#  undef __DAI_CONST_CAST
#endif
#if defined(__cplusplus)
#  define __DAI_CONST_CAST(T, expr) (const_cast<T>(expr))
#elif \
  __DAI_HAS_WARNING("-Wcast-qual") || \
  __DAI_GCC_VERSION_CHECK(4,6,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0)
#  define __DAI_CONST_CAST(T, expr) (__extension__ ({ \
      __DAI_DIAGNOSTIC_PUSH \
      __DAI_DIAGNOSTIC_DISABLE_CAST_QUAL \
      ((T) (expr)); \
      __DAI_DIAGNOSTIC_POP \
    }))
#else
#  define __DAI_CONST_CAST(T, expr) ((T) (expr))
#endif

#if defined(__DAI_REINTERPRET_CAST)
#  undef __DAI_REINTERPRET_CAST
#endif
#if defined(__cplusplus)
#  define __DAI_REINTERPRET_CAST(T, expr) (reinterpret_cast<T>(expr))
#else
#  define __DAI_REINTERPRET_CAST(T, expr) ((T) (expr))
#endif

#if defined(__DAI_STATIC_CAST)
#  undef __DAI_STATIC_CAST
#endif
#if defined(__cplusplus)
#  define __DAI_STATIC_CAST(T, expr) (static_cast<T>(expr))
#else
#  define __DAI_STATIC_CAST(T, expr) ((T) (expr))
#endif

#if defined(__DAI_CPP_CAST)
#  undef __DAI_CPP_CAST
#endif
#if defined(__cplusplus)
#  if __DAI_HAS_WARNING("-Wold-style-cast")
#    define __DAI_CPP_CAST(T, expr) \
       __DAI_DIAGNOSTIC_PUSH \
       _Pragma("clang diagnostic ignored \"-Wold-style-cast\"") \
       ((T) (expr)) \
       __DAI_DIAGNOSTIC_POP
#  elif __DAI_IAR_VERSION_CHECK(8,3,0)
#    define __DAI_CPP_CAST(T, expr) \
       __DAI_DIAGNOSTIC_PUSH \
       _Pragma("diag_suppress=Pe137") \
       __DAI_DIAGNOSTIC_POP
#  else
#    define __DAI_CPP_CAST(T, expr) ((T) (expr))
#  endif
#else
#  define __DAI_CPP_CAST(T, expr) (expr)
#endif

#if defined(__DAI_DIAGNOSTIC_DISABLE_DEPRECATED)
#  undef __DAI_DIAGNOSTIC_DISABLE_DEPRECATED
#endif
#if __DAI_HAS_WARNING("-Wdeprecated-declarations")
#  define __DAI_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"")
#elif __DAI_INTEL_VERSION_CHECK(13,0,0)
#  define __DAI_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("warning(disable:1478 1786)")
#elif __DAI_INTEL_CL_VERSION_CHECK(2021,1,0)
#  define __DAI_DIAGNOSTIC_DISABLE_DEPRECATED __pragma(warning(disable:1478 1786))
#elif __DAI_PGI_VERSION_CHECK(20,7,0)
#  define __DAI_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("diag_suppress 1215,1216,1444,1445")
#elif __DAI_PGI_VERSION_CHECK(17,10,0)
#  define __DAI_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("diag_suppress 1215,1444")
#elif __DAI_GCC_VERSION_CHECK(4,3,0)
#  define __DAI_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")
#elif __DAI_MSVC_VERSION_CHECK(15,0,0)
#  define __DAI_DIAGNOSTIC_DISABLE_DEPRECATED __pragma(warning(disable:4996))
#elif __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("diag_suppress 1215,1444")
#elif \
    __DAI_TI_VERSION_CHECK(15,12,0) || \
    (__DAI_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    __DAI_TI_ARMCL_VERSION_CHECK(5,2,0) || \
    (__DAI_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    __DAI_TI_CL2000_VERSION_CHECK(6,4,0) || \
    (__DAI_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    __DAI_TI_CL430_VERSION_CHECK(4,3,0) || \
    (__DAI_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    __DAI_TI_CL6X_VERSION_CHECK(7,5,0) || \
    __DAI_TI_CL7X_VERSION_CHECK(1,2,0) || \
    __DAI_TI_CLPRU_VERSION_CHECK(2,1,0)
#  define __DAI_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("diag_suppress 1291,1718")
#elif __DAI_SUNPRO_VERSION_CHECK(5,13,0) && !defined(__cplusplus)
#  define __DAI_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("error_messages(off,E_DEPRECATED_ATT,E_DEPRECATED_ATT_MESS)")
#elif __DAI_SUNPRO_VERSION_CHECK(5,13,0) && defined(__cplusplus)
#  define __DAI_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("error_messages(off,symdeprecated,symdeprecated2)")
#elif __DAI_IAR_VERSION_CHECK(8,0,0)
#  define __DAI_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("diag_suppress=Pe1444,Pe1215")
#elif __DAI_PELLES_VERSION_CHECK(2,90,0)
#  define __DAI_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("warn(disable:2241)")
#else
#  define __DAI_DIAGNOSTIC_DISABLE_DEPRECATED
#endif

#if defined(__DAI_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS)
#  undef __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS
#endif
#if __DAI_HAS_WARNING("-Wunknown-pragmas")
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("clang diagnostic ignored \"-Wunknown-pragmas\"")
#elif __DAI_INTEL_VERSION_CHECK(13,0,0)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("warning(disable:161)")
#elif __DAI_INTEL_CL_VERSION_CHECK(2021,1,0)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS __pragma(warning(disable:161))
#elif __DAI_PGI_VERSION_CHECK(17,10,0)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("diag_suppress 1675")
#elif __DAI_GCC_VERSION_CHECK(4,3,0)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("GCC diagnostic ignored \"-Wunknown-pragmas\"")
#elif __DAI_MSVC_VERSION_CHECK(15,0,0)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS __pragma(warning(disable:4068))
#elif \
    __DAI_TI_VERSION_CHECK(16,9,0) || \
    __DAI_TI_CL6X_VERSION_CHECK(8,0,0) || \
    __DAI_TI_CL7X_VERSION_CHECK(1,2,0) || \
    __DAI_TI_CLPRU_VERSION_CHECK(2,3,0)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("diag_suppress 163")
#elif __DAI_TI_CL6X_VERSION_CHECK(8,0,0)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("diag_suppress 163")
#elif __DAI_IAR_VERSION_CHECK(8,0,0)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("diag_suppress=Pe161")
#elif __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("diag_suppress 161")
#else
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS
#endif

#if defined(__DAI_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES)
#  undef __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES
#endif
#if __DAI_HAS_WARNING("-Wunknown-attributes")
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("clang diagnostic ignored \"-Wunknown-attributes\"")
#elif __DAI_GCC_VERSION_CHECK(4,6,0)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")
#elif __DAI_INTEL_VERSION_CHECK(17,0,0)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("warning(disable:1292)")
#elif __DAI_INTEL_CL_VERSION_CHECK(2021,1,0)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES __pragma(warning(disable:1292))
#elif __DAI_MSVC_VERSION_CHECK(19,0,0)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES __pragma(warning(disable:5030))
#elif __DAI_PGI_VERSION_CHECK(20,7,0)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("diag_suppress 1097,1098")
#elif __DAI_PGI_VERSION_CHECK(17,10,0)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("diag_suppress 1097")
#elif __DAI_SUNPRO_VERSION_CHECK(5,14,0) && defined(__cplusplus)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("error_messages(off,attrskipunsup)")
#elif \
    __DAI_TI_VERSION_CHECK(18,1,0) || \
    __DAI_TI_CL6X_VERSION_CHECK(8,3,0) || \
    __DAI_TI_CL7X_VERSION_CHECK(1,2,0)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("diag_suppress 1173")
#elif __DAI_IAR_VERSION_CHECK(8,0,0)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("diag_suppress=Pe1097")
#elif __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("diag_suppress 1097")
#else
#  define __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES
#endif

#if defined(__DAI_DIAGNOSTIC_DISABLE_CAST_QUAL)
#  undef __DAI_DIAGNOSTIC_DISABLE_CAST_QUAL
#endif
#if __DAI_HAS_WARNING("-Wcast-qual")
#  define __DAI_DIAGNOSTIC_DISABLE_CAST_QUAL _Pragma("clang diagnostic ignored \"-Wcast-qual\"")
#elif __DAI_INTEL_VERSION_CHECK(13,0,0)
#  define __DAI_DIAGNOSTIC_DISABLE_CAST_QUAL _Pragma("warning(disable:2203 2331)")
#elif __DAI_GCC_VERSION_CHECK(3,0,0)
#  define __DAI_DIAGNOSTIC_DISABLE_CAST_QUAL _Pragma("GCC diagnostic ignored \"-Wcast-qual\"")
#else
#  define __DAI_DIAGNOSTIC_DISABLE_CAST_QUAL
#endif

#if defined(__DAI_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION)
#  undef __DAI_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION
#endif
#if __DAI_HAS_WARNING("-Wunused-function")
#  define __DAI_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION _Pragma("clang diagnostic ignored \"-Wunused-function\"")
#elif __DAI_GCC_VERSION_CHECK(3,4,0)
#  define __DAI_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION _Pragma("GCC diagnostic ignored \"-Wunused-function\"")
#elif __DAI_MSVC_VERSION_CHECK(1,0,0)
#  define __DAI_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION __pragma(warning(disable:4505))
#elif __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION _Pragma("diag_suppress 3142")
#else
#  define __DAI_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION
#endif

#if defined(__DAI_DEPRECATED)
#  undef __DAI_DEPRECATED
#endif
#if defined(__DAI_DEPRECATED_FOR)
#  undef __DAI_DEPRECATED_FOR
#endif
#if \
  __DAI_MSVC_VERSION_CHECK(14,0,0) || \
  __DAI_INTEL_CL_VERSION_CHECK(2021,1,0)
#  define __DAI_DEPRECATED(since) __declspec(deprecated("Since " # since))
#  define __DAI_DEPRECATED_FOR(since, replacement) __declspec(deprecated("Since " #since "; use " #replacement))
#elif \
  (__DAI_HAS_EXTENSION(attribute_deprecated_with_message) && !defined(__DAI_IAR_VERSION)) || \
  __DAI_GCC_VERSION_CHECK(4,5,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  __DAI_ARM_VERSION_CHECK(5,6,0) || \
  __DAI_SUNPRO_VERSION_CHECK(5,13,0) || \
  __DAI_PGI_VERSION_CHECK(17,10,0) || \
  __DAI_TI_VERSION_CHECK(18,1,0) || \
  __DAI_TI_ARMCL_VERSION_CHECK(18,1,0) || \
  __DAI_TI_CL6X_VERSION_CHECK(8,3,0) || \
  __DAI_TI_CL7X_VERSION_CHECK(1,2,0) || \
  __DAI_TI_CLPRU_VERSION_CHECK(2,3,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_DEPRECATED(since) __attribute__((__deprecated__("Since " #since)))
#  define __DAI_DEPRECATED_FOR(since, replacement) __attribute__((__deprecated__("Since " #since "; use " #replacement)))
#elif defined(__cplusplus) && (__cplusplus >= 201402L)
#  define __DAI_DEPRECATED(since) __DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[deprecated("Since " #since)]])
#  define __DAI_DEPRECATED_FOR(since, replacement) __DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[deprecated("Since " #since "; use " #replacement)]])
#elif \
  __DAI_HAS_ATTRIBUTE(deprecated) || \
  __DAI_GCC_VERSION_CHECK(3,1,0) || \
  __DAI_ARM_VERSION_CHECK(4,1,0) || \
  __DAI_TI_VERSION_CHECK(15,12,0) || \
  (__DAI_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (__DAI_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (__DAI_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL430_VERSION_CHECK(4,3,0) || \
  (__DAI_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL6X_VERSION_CHECK(7,5,0) || \
  __DAI_TI_CL7X_VERSION_CHECK(1,2,0) || \
  __DAI_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10) || \
  __DAI_IAR_VERSION_CHECK(8,10,0)
#  define __DAI_DEPRECATED(since) __attribute__((__deprecated__))
#  define __DAI_DEPRECATED_FOR(since, replacement) __attribute__((__deprecated__))
#elif \
  __DAI_MSVC_VERSION_CHECK(13,10,0) || \
  __DAI_PELLES_VERSION_CHECK(6,50,0) || \
  __DAI_INTEL_CL_VERSION_CHECK(2021,1,0)
#  define __DAI_DEPRECATED(since) __declspec(deprecated)
#  define __DAI_DEPRECATED_FOR(since, replacement) __declspec(deprecated)
#elif __DAI_IAR_VERSION_CHECK(8,0,0)
#  define __DAI_DEPRECATED(since) _Pragma("deprecated")
#  define __DAI_DEPRECATED_FOR(since, replacement) _Pragma("deprecated")
#else
#  define __DAI_DEPRECATED(since)
#  define __DAI_DEPRECATED_FOR(since, replacement)
#endif

#if defined(__DAI_UNAVAILABLE)
#  undef __DAI_UNAVAILABLE
#endif
#if \
  __DAI_HAS_ATTRIBUTE(warning) || \
  __DAI_GCC_VERSION_CHECK(4,3,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_UNAVAILABLE(available_since) __attribute__((__warning__("Not available until " #available_since)))
#else
#  define __DAI_UNAVAILABLE(available_since)
#endif

#if defined(__DAI_WARN_UNUSED_RESULT)
#  undef __DAI_WARN_UNUSED_RESULT
#endif
#if defined(__DAI_WARN_UNUSED_RESULT_MSG)
#  undef __DAI_WARN_UNUSED_RESULT_MSG
#endif
#if \
  __DAI_HAS_ATTRIBUTE(warn_unused_result) || \
  __DAI_GCC_VERSION_CHECK(3,4,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  __DAI_TI_VERSION_CHECK(15,12,0) || \
  (__DAI_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (__DAI_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (__DAI_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL430_VERSION_CHECK(4,3,0) || \
  (__DAI_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL6X_VERSION_CHECK(7,5,0) || \
  __DAI_TI_CL7X_VERSION_CHECK(1,2,0) || \
  __DAI_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  (__DAI_SUNPRO_VERSION_CHECK(5,15,0) && defined(__cplusplus)) || \
  __DAI_PGI_VERSION_CHECK(17,10,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_WARN_UNUSED_RESULT __attribute__((__warn_unused_result__))
#  define __DAI_WARN_UNUSED_RESULT_MSG(msg) __attribute__((__warn_unused_result__))
#elif (__DAI_HAS_CPP_ATTRIBUTE(nodiscard) >= 201907L)
#  define __DAI_WARN_UNUSED_RESULT __DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[nodiscard]])
#  define __DAI_WARN_UNUSED_RESULT_MSG(msg) __DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[nodiscard(msg)]])
#elif __DAI_HAS_CPP_ATTRIBUTE(nodiscard)
#  define __DAI_WARN_UNUSED_RESULT __DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[nodiscard]])
#  define __DAI_WARN_UNUSED_RESULT_MSG(msg) __DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[nodiscard]])
#elif defined(_Check_return_) /* SAL */
#  define __DAI_WARN_UNUSED_RESULT _Check_return_
#  define __DAI_WARN_UNUSED_RESULT_MSG(msg) _Check_return_
#else
#  define __DAI_WARN_UNUSED_RESULT
#  define __DAI_WARN_UNUSED_RESULT_MSG(msg)
#endif

#if defined(__DAI_SENTINEL)
#  undef __DAI_SENTINEL
#endif
#if \
  __DAI_HAS_ATTRIBUTE(sentinel) || \
  __DAI_GCC_VERSION_CHECK(4,0,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  __DAI_ARM_VERSION_CHECK(5,4,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_SENTINEL(position) __attribute__((__sentinel__(position)))
#else
#  define __DAI_SENTINEL(position)
#endif

#if defined(__DAI_NO_RETURN)
#  undef __DAI_NO_RETURN
#endif
#if __DAI_IAR_VERSION_CHECK(8,0,0)
#  define __DAI_NO_RETURN __noreturn
#elif \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_NO_RETURN __attribute__((__noreturn__))
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#  define __DAI_NO_RETURN _Noreturn
#elif defined(__cplusplus) && (__cplusplus >= 201103L)
#  define __DAI_NO_RETURN __DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[noreturn]])
#elif \
  __DAI_HAS_ATTRIBUTE(noreturn) || \
  __DAI_GCC_VERSION_CHECK(3,2,0) || \
  __DAI_SUNPRO_VERSION_CHECK(5,11,0) || \
  __DAI_ARM_VERSION_CHECK(4,1,0) || \
  __DAI_IBM_VERSION_CHECK(10,1,0) || \
  __DAI_TI_VERSION_CHECK(15,12,0) || \
  (__DAI_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (__DAI_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (__DAI_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL430_VERSION_CHECK(4,3,0) || \
  (__DAI_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL6X_VERSION_CHECK(7,5,0) || \
  __DAI_TI_CL7X_VERSION_CHECK(1,2,0) || \
  __DAI_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  __DAI_IAR_VERSION_CHECK(8,10,0)
#  define __DAI_NO_RETURN __attribute__((__noreturn__))
#elif __DAI_SUNPRO_VERSION_CHECK(5,10,0)
#  define __DAI_NO_RETURN _Pragma("does_not_return")
#elif \
  __DAI_MSVC_VERSION_CHECK(13,10,0) || \
  __DAI_INTEL_CL_VERSION_CHECK(2021,1,0)
#  define __DAI_NO_RETURN __declspec(noreturn)
#elif __DAI_TI_CL6X_VERSION_CHECK(6,0,0) && defined(__cplusplus)
#  define __DAI_NO_RETURN _Pragma("FUNC_NEVER_RETURNS;")
#elif __DAI_COMPCERT_VERSION_CHECK(3,2,0)
#  define __DAI_NO_RETURN __attribute((noreturn))
#elif __DAI_PELLES_VERSION_CHECK(9,0,0)
#  define __DAI_NO_RETURN __declspec(noreturn)
#else
#  define __DAI_NO_RETURN
#endif

#if defined(__DAI_NO_ESCAPE)
#  undef __DAI_NO_ESCAPE
#endif
#if __DAI_HAS_ATTRIBUTE(noescape)
#  define __DAI_NO_ESCAPE __attribute__((__noescape__))
#else
#  define __DAI_NO_ESCAPE
#endif

#if defined(__DAI_UNREACHABLE)
#  undef __DAI_UNREACHABLE
#endif
#if defined(__DAI_UNREACHABLE_RETURN)
#  undef __DAI_UNREACHABLE_RETURN
#endif
#if defined(__DAI_ASSUME)
#  undef __DAI_ASSUME
#endif
#if \
  __DAI_MSVC_VERSION_CHECK(13,10,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  __DAI_INTEL_CL_VERSION_CHECK(2021,1,0)
#  define __DAI_ASSUME(expr) __assume(expr)
#elif __DAI_HAS_BUILTIN(__builtin_assume)
#  define __DAI_ASSUME(expr) __builtin_assume(expr)
#elif \
    __DAI_TI_CL2000_VERSION_CHECK(6,2,0) || \
    __DAI_TI_CL6X_VERSION_CHECK(4,0,0)
#  if defined(__cplusplus)
#    define __DAI_ASSUME(expr) std::_nassert(expr)
#  else
#    define __DAI_ASSUME(expr) _nassert(expr)
#  endif
#endif
#if \
  (__DAI_HAS_BUILTIN(__builtin_unreachable) && (!defined(__DAI_ARM_VERSION))) || \
  __DAI_GCC_VERSION_CHECK(4,5,0) || \
  __DAI_PGI_VERSION_CHECK(18,10,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  __DAI_IBM_VERSION_CHECK(13,1,5) || \
  __DAI_CRAY_VERSION_CHECK(10,0,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_UNREACHABLE() __builtin_unreachable()
#elif defined(__DAI_ASSUME)
#  define __DAI_UNREACHABLE() __DAI_ASSUME(0)
#endif
#if !defined(__DAI_ASSUME)
#  if defined(__DAI_UNREACHABLE)
#    define __DAI_ASSUME(expr) __DAI_STATIC_CAST(void, ((expr) ? 1 : (__DAI_UNREACHABLE(), 1)))
#  else
#    define __DAI_ASSUME(expr) __DAI_STATIC_CAST(void, expr)
#  endif
#endif
#if defined(__DAI_UNREACHABLE)
#  if  \
      __DAI_TI_CL2000_VERSION_CHECK(6,2,0) || \
      __DAI_TI_CL6X_VERSION_CHECK(4,0,0)
#    define __DAI_UNREACHABLE_RETURN(value) return (__DAI_STATIC_CAST(void, __DAI_ASSUME(0)), (value))
#  else
#    define __DAI_UNREACHABLE_RETURN(value) __DAI_UNREACHABLE()
#  endif
#else
#  define __DAI_UNREACHABLE_RETURN(value) return (value)
#endif
#if !defined(__DAI_UNREACHABLE)
#  define __DAI_UNREACHABLE() __DAI_ASSUME(0)
#endif

__DAI_DIAGNOSTIC_PUSH
#if __DAI_HAS_WARNING("-Wpedantic")
#  pragma clang diagnostic ignored "-Wpedantic"
#endif
#if __DAI_HAS_WARNING("-Wc++98-compat-pedantic") && defined(__cplusplus)
#  pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#if __DAI_GCC_HAS_WARNING("-Wvariadic-macros",4,0,0)
#  if defined(__clang__)
#    pragma clang diagnostic ignored "-Wvariadic-macros"
#  elif defined(__DAI_GCC_VERSION)
#    pragma GCC diagnostic ignored "-Wvariadic-macros"
#  endif
#endif
#if defined(__DAI_NON_NULL)
#  undef __DAI_NON_NULL
#endif
#if \
  __DAI_HAS_ATTRIBUTE(nonnull) || \
  __DAI_GCC_VERSION_CHECK(3,3,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  __DAI_ARM_VERSION_CHECK(4,1,0)
#  define __DAI_NON_NULL(...) __attribute__((__nonnull__(__VA_ARGS__)))
#else
#  define __DAI_NON_NULL(...)
#endif
__DAI_DIAGNOSTIC_POP

#if defined(__DAI_PRINTF_FORMAT)
#  undef __DAI_PRINTF_FORMAT
#endif
#if defined(__MINGW32__) && __DAI_GCC_HAS_ATTRIBUTE(format,4,4,0) && !defined(__USE_MINGW_ANSI_STDIO)
#  define __DAI_PRINTF_FORMAT(string_idx,first_to_check) __attribute__((__format__(ms_printf, string_idx, first_to_check)))
#elif defined(__MINGW32__) && __DAI_GCC_HAS_ATTRIBUTE(format,4,4,0) && defined(__USE_MINGW_ANSI_STDIO)
#  define __DAI_PRINTF_FORMAT(string_idx,first_to_check) __attribute__((__format__(gnu_printf, string_idx, first_to_check)))
#elif \
  __DAI_HAS_ATTRIBUTE(format) || \
  __DAI_GCC_VERSION_CHECK(3,1,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  __DAI_ARM_VERSION_CHECK(5,6,0) || \
  __DAI_IBM_VERSION_CHECK(10,1,0) || \
  __DAI_TI_VERSION_CHECK(15,12,0) || \
  (__DAI_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (__DAI_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (__DAI_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL430_VERSION_CHECK(4,3,0) || \
  (__DAI_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL6X_VERSION_CHECK(7,5,0) || \
  __DAI_TI_CL7X_VERSION_CHECK(1,2,0) || \
  __DAI_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_PRINTF_FORMAT(string_idx,first_to_check) __attribute__((__format__(__printf__, string_idx, first_to_check)))
#elif __DAI_PELLES_VERSION_CHECK(6,0,0)
#  define __DAI_PRINTF_FORMAT(string_idx,first_to_check) __declspec(vaformat(printf,string_idx,first_to_check))
#else
#  define __DAI_PRINTF_FORMAT(string_idx,first_to_check)
#endif

#if defined(__DAI_CONSTEXPR)
#  undef __DAI_CONSTEXPR
#endif
#if defined(__cplusplus)
#  if __cplusplus >= 201103L
#    define __DAI_CONSTEXPR __DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(constexpr)
#  endif
#endif
#if !defined(__DAI_CONSTEXPR)
#  define __DAI_CONSTEXPR
#endif

#if defined(__DAI_PREDICT)
#  undef __DAI_PREDICT
#endif
#if defined(__DAI_LIKELY)
#  undef __DAI_LIKELY
#endif
#if defined(__DAI_UNLIKELY)
#  undef __DAI_UNLIKELY
#endif
#if defined(__DAI_UNPREDICTABLE)
#  undef __DAI_UNPREDICTABLE
#endif
#if __DAI_HAS_BUILTIN(__builtin_unpredictable)
#  define __DAI_UNPREDICTABLE(expr) __builtin_unpredictable((expr))
#endif
#if \
  (__DAI_HAS_BUILTIN(__builtin_expect_with_probability) && !defined(__DAI_PGI_VERSION)) || \
  __DAI_GCC_VERSION_CHECK(9,0,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_PREDICT(expr, value, probability) __builtin_expect_with_probability(  (expr), (value), (probability))
#  define __DAI_PREDICT_TRUE(expr, probability)   __builtin_expect_with_probability(!!(expr),    1   , (probability))
#  define __DAI_PREDICT_FALSE(expr, probability)  __builtin_expect_with_probability(!!(expr),    0   , (probability))
#  define __DAI_LIKELY(expr)                      __builtin_expect                 (!!(expr),    1                  )
#  define __DAI_UNLIKELY(expr)                    __builtin_expect                 (!!(expr),    0                  )
#elif \
  (__DAI_HAS_BUILTIN(__builtin_expect) && !defined(__DAI_INTEL_CL_VERSION)) || \
  __DAI_GCC_VERSION_CHECK(3,0,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  (__DAI_SUNPRO_VERSION_CHECK(5,15,0) && defined(__cplusplus)) || \
  __DAI_ARM_VERSION_CHECK(4,1,0) || \
  __DAI_IBM_VERSION_CHECK(10,1,0) || \
  __DAI_TI_VERSION_CHECK(15,12,0) || \
  __DAI_TI_ARMCL_VERSION_CHECK(4,7,0) || \
  __DAI_TI_CL430_VERSION_CHECK(3,1,0) || \
  __DAI_TI_CL2000_VERSION_CHECK(6,1,0) || \
  __DAI_TI_CL6X_VERSION_CHECK(6,1,0) || \
  __DAI_TI_CL7X_VERSION_CHECK(1,2,0) || \
  __DAI_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  __DAI_TINYC_VERSION_CHECK(0,9,27) || \
  __DAI_CRAY_VERSION_CHECK(8,1,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_PREDICT(expr, expected, probability) \
     (((probability) >= 0.9) ? __builtin_expect((expr), (expected)) : (__DAI_STATIC_CAST(void, expected), (expr)))
#  define __DAI_PREDICT_TRUE(expr, probability) \
     (__extension__ ({ \
       double __DAI_probability_ = (probability); \
       ((__DAI_probability_ >= 0.9) ? __builtin_expect(!!(expr), 1) : ((__DAI_probability_ <= 0.1) ? __builtin_expect(!!(expr), 0) : !!(expr))); \
     }))
#  define __DAI_PREDICT_FALSE(expr, probability) \
     (__extension__ ({ \
       double __DAI_probability_ = (probability); \
       ((__DAI_probability_ >= 0.9) ? __builtin_expect(!!(expr), 0) : ((__DAI_probability_ <= 0.1) ? __builtin_expect(!!(expr), 1) : !!(expr))); \
     }))
#  define __DAI_LIKELY(expr)   __builtin_expect(!!(expr), 1)
#  define __DAI_UNLIKELY(expr) __builtin_expect(!!(expr), 0)
#else
#  define __DAI_PREDICT(expr, expected, probability) (__DAI_STATIC_CAST(void, expected), (expr))
#  define __DAI_PREDICT_TRUE(expr, probability) (!!(expr))
#  define __DAI_PREDICT_FALSE(expr, probability) (!!(expr))
#  define __DAI_LIKELY(expr) (!!(expr))
#  define __DAI_UNLIKELY(expr) (!!(expr))
#endif
#if !defined(__DAI_UNPREDICTABLE)
#  define __DAI_UNPREDICTABLE(expr) __DAI_PREDICT(expr, 1, 0.5)
#endif

#if defined(__DAI_MALLOC_ATTR)
#  undef __DAI_MALLOC_ATTR
#endif
#if \
  __DAI_HAS_ATTRIBUTE(malloc) || \
  __DAI_GCC_VERSION_CHECK(3,1,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  __DAI_SUNPRO_VERSION_CHECK(5,11,0) || \
  __DAI_ARM_VERSION_CHECK(4,1,0) || \
  __DAI_IBM_VERSION_CHECK(12,1,0) || \
  __DAI_TI_VERSION_CHECK(15,12,0) || \
  (__DAI_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (__DAI_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (__DAI_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL430_VERSION_CHECK(4,3,0) || \
  (__DAI_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL6X_VERSION_CHECK(7,5,0) || \
  __DAI_TI_CL7X_VERSION_CHECK(1,2,0) || \
  __DAI_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_MALLOC_ATTR __attribute__((__malloc__))
#elif __DAI_SUNPRO_VERSION_CHECK(5,10,0)
#  define __DAI_MALLOC_ATTR _Pragma("returns_new_memory")
#elif \
  __DAI_MSVC_VERSION_CHECK(14,0,0) || \
  __DAI_INTEL_CL_VERSION_CHECK(2021,1,0)
#  define __DAI_MALLOC_ATTR __declspec(restrict)
#else
#  define __DAI_MALLOC_ATTR
#endif

#if defined(__DAI_PURE)
#  undef __DAI_PURE
#endif
#if \
  __DAI_HAS_ATTRIBUTE(pure) || \
  __DAI_GCC_VERSION_CHECK(2,96,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  __DAI_SUNPRO_VERSION_CHECK(5,11,0) || \
  __DAI_ARM_VERSION_CHECK(4,1,0) || \
  __DAI_IBM_VERSION_CHECK(10,1,0) || \
  __DAI_TI_VERSION_CHECK(15,12,0) || \
  (__DAI_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (__DAI_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (__DAI_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL430_VERSION_CHECK(4,3,0) || \
  (__DAI_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL6X_VERSION_CHECK(7,5,0) || \
  __DAI_TI_CL7X_VERSION_CHECK(1,2,0) || \
  __DAI_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  __DAI_PGI_VERSION_CHECK(17,10,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_PURE __attribute__((__pure__))
#elif __DAI_SUNPRO_VERSION_CHECK(5,10,0)
#  define __DAI_PURE _Pragma("does_not_write_global_data")
#elif defined(__cplusplus) && \
    ( \
      __DAI_TI_CL430_VERSION_CHECK(2,0,1) || \
      __DAI_TI_CL6X_VERSION_CHECK(4,0,0) || \
      __DAI_TI_CL7X_VERSION_CHECK(1,2,0) \
    )
#  define __DAI_PURE _Pragma("FUNC_IS_PURE;")
#else
#  define __DAI_PURE
#endif

#if defined(__DAI_CONST)
#  undef __DAI_CONST
#endif
#if \
  __DAI_HAS_ATTRIBUTE(const) || \
  __DAI_GCC_VERSION_CHECK(2,5,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  __DAI_SUNPRO_VERSION_CHECK(5,11,0) || \
  __DAI_ARM_VERSION_CHECK(4,1,0) || \
  __DAI_IBM_VERSION_CHECK(10,1,0) || \
  __DAI_TI_VERSION_CHECK(15,12,0) || \
  (__DAI_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (__DAI_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (__DAI_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL430_VERSION_CHECK(4,3,0) || \
  (__DAI_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL6X_VERSION_CHECK(7,5,0) || \
  __DAI_TI_CL7X_VERSION_CHECK(1,2,0) || \
  __DAI_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  __DAI_PGI_VERSION_CHECK(17,10,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_CONST __attribute__((__const__))
#elif \
  __DAI_SUNPRO_VERSION_CHECK(5,10,0)
#  define __DAI_CONST _Pragma("no_side_effect")
#else
#  define __DAI_CONST __DAI_PURE
#endif

#if defined(__DAI_RESTRICT)
#  undef __DAI_RESTRICT
#endif
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) && !defined(__cplusplus)
#  define __DAI_RESTRICT restrict
#elif \
  __DAI_GCC_VERSION_CHECK(3,1,0) || \
  __DAI_MSVC_VERSION_CHECK(14,0,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  __DAI_INTEL_CL_VERSION_CHECK(2021,1,0) || \
  __DAI_ARM_VERSION_CHECK(4,1,0) || \
  __DAI_IBM_VERSION_CHECK(10,1,0) || \
  __DAI_PGI_VERSION_CHECK(17,10,0) || \
  __DAI_TI_CL430_VERSION_CHECK(4,3,0) || \
  __DAI_TI_CL2000_VERSION_CHECK(6,2,4) || \
  __DAI_TI_CL6X_VERSION_CHECK(8,1,0) || \
  __DAI_TI_CL7X_VERSION_CHECK(1,2,0) || \
  (__DAI_SUNPRO_VERSION_CHECK(5,14,0) && defined(__cplusplus)) || \
  __DAI_IAR_VERSION_CHECK(8,0,0) || \
  defined(__clang__) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_RESTRICT __restrict
#elif __DAI_SUNPRO_VERSION_CHECK(5,3,0) && !defined(__cplusplus)
#  define __DAI_RESTRICT _Restrict
#else
#  define __DAI_RESTRICT
#endif

#if defined(__DAI_INLINE)
#  undef __DAI_INLINE
#endif
#if \
  (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) || \
  (defined(__cplusplus) && (__cplusplus >= 199711L))
#  define __DAI_INLINE inline
#elif \
  defined(__DAI_GCC_VERSION) || \
  __DAI_ARM_VERSION_CHECK(6,2,0)
#  define __DAI_INLINE __inline__
#elif \
  __DAI_MSVC_VERSION_CHECK(12,0,0) || \
  __DAI_INTEL_CL_VERSION_CHECK(2021,1,0) || \
  __DAI_ARM_VERSION_CHECK(4,1,0) || \
  __DAI_TI_ARMCL_VERSION_CHECK(5,1,0) || \
  __DAI_TI_CL430_VERSION_CHECK(3,1,0) || \
  __DAI_TI_CL2000_VERSION_CHECK(6,2,0) || \
  __DAI_TI_CL6X_VERSION_CHECK(8,0,0) || \
  __DAI_TI_CL7X_VERSION_CHECK(1,2,0) || \
  __DAI_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_INLINE __inline
#else
#  define __DAI_INLINE
#endif

#if defined(__DAI_ALWAYS_INLINE)
#  undef __DAI_ALWAYS_INLINE
#endif
#if \
  __DAI_HAS_ATTRIBUTE(always_inline) || \
  __DAI_GCC_VERSION_CHECK(4,0,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  __DAI_SUNPRO_VERSION_CHECK(5,11,0) || \
  __DAI_ARM_VERSION_CHECK(4,1,0) || \
  __DAI_IBM_VERSION_CHECK(10,1,0) || \
  __DAI_TI_VERSION_CHECK(15,12,0) || \
  (__DAI_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (__DAI_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (__DAI_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL430_VERSION_CHECK(4,3,0) || \
  (__DAI_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL6X_VERSION_CHECK(7,5,0) || \
  __DAI_TI_CL7X_VERSION_CHECK(1,2,0) || \
  __DAI_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10) || \
  __DAI_IAR_VERSION_CHECK(8,10,0)
#  define __DAI_ALWAYS_INLINE __attribute__((__always_inline__)) __DAI_INLINE
#elif \
  __DAI_MSVC_VERSION_CHECK(12,0,0) || \
  __DAI_INTEL_CL_VERSION_CHECK(2021,1,0)
#  define __DAI_ALWAYS_INLINE __forceinline
#elif defined(__cplusplus) && \
    ( \
      __DAI_TI_ARMCL_VERSION_CHECK(5,2,0) || \
      __DAI_TI_CL430_VERSION_CHECK(4,3,0) || \
      __DAI_TI_CL2000_VERSION_CHECK(6,4,0) || \
      __DAI_TI_CL6X_VERSION_CHECK(6,1,0) || \
      __DAI_TI_CL7X_VERSION_CHECK(1,2,0) || \
      __DAI_TI_CLPRU_VERSION_CHECK(2,1,0) \
    )
#  define __DAI_ALWAYS_INLINE _Pragma("FUNC_ALWAYS_INLINE;")
#elif __DAI_IAR_VERSION_CHECK(8,0,0)
#  define __DAI_ALWAYS_INLINE _Pragma("inline=forced")
#else
#  define __DAI_ALWAYS_INLINE __DAI_INLINE
#endif

#if defined(__DAI_NEVER_INLINE)
#  undef __DAI_NEVER_INLINE
#endif
#if \
  __DAI_HAS_ATTRIBUTE(noinline) || \
  __DAI_GCC_VERSION_CHECK(4,0,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  __DAI_SUNPRO_VERSION_CHECK(5,11,0) || \
  __DAI_ARM_VERSION_CHECK(4,1,0) || \
  __DAI_IBM_VERSION_CHECK(10,1,0) || \
  __DAI_TI_VERSION_CHECK(15,12,0) || \
  (__DAI_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (__DAI_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (__DAI_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL430_VERSION_CHECK(4,3,0) || \
  (__DAI_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  __DAI_TI_CL6X_VERSION_CHECK(7,5,0) || \
  __DAI_TI_CL7X_VERSION_CHECK(1,2,0) || \
  __DAI_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10) || \
  __DAI_IAR_VERSION_CHECK(8,10,0)
#  define __DAI_NEVER_INLINE __attribute__((__noinline__))
#elif \
  __DAI_MSVC_VERSION_CHECK(13,10,0) || \
  __DAI_INTEL_CL_VERSION_CHECK(2021,1,0)
#  define __DAI_NEVER_INLINE __declspec(noinline)
#elif __DAI_PGI_VERSION_CHECK(10,2,0)
#  define __DAI_NEVER_INLINE _Pragma("noinline")
#elif __DAI_TI_CL6X_VERSION_CHECK(6,0,0) && defined(__cplusplus)
#  define __DAI_NEVER_INLINE _Pragma("FUNC_CANNOT_INLINE;")
#elif __DAI_IAR_VERSION_CHECK(8,0,0)
#  define __DAI_NEVER_INLINE _Pragma("inline=never")
#elif __DAI_COMPCERT_VERSION_CHECK(3,2,0)
#  define __DAI_NEVER_INLINE __attribute((noinline))
#elif __DAI_PELLES_VERSION_CHECK(9,0,0)
#  define __DAI_NEVER_INLINE __declspec(noinline)
#else
#  define __DAI_NEVER_INLINE
#endif

#if defined(__DAI_PRIVATE)
#  undef __DAI_PRIVATE
#endif
#if defined(__DAI_PUBLIC)
#  undef __DAI_PUBLIC
#endif
#if defined(__DAI_IMPORT)
#  undef __DAI_IMPORT
#endif
#if defined(_WIN32) || defined(__CYGWIN__)
#  define __DAI_PRIVATE
#  define __DAI_PUBLIC   __declspec(dllexport)
#  define __DAI_IMPORT   __declspec(dllimport)
#else
#  if \
    __DAI_HAS_ATTRIBUTE(visibility) || \
    __DAI_GCC_VERSION_CHECK(3,3,0) || \
    __DAI_SUNPRO_VERSION_CHECK(5,11,0) || \
    __DAI_INTEL_VERSION_CHECK(13,0,0) || \
    __DAI_ARM_VERSION_CHECK(4,1,0) || \
    __DAI_IBM_VERSION_CHECK(13,1,0) || \
    ( \
      defined(__TI_EABI__) && \
      ( \
        (__DAI_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
        __DAI_TI_CL6X_VERSION_CHECK(7,5,0) \
      ) \
    ) || \
    __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#    define __DAI_PRIVATE __attribute__((__visibility__("hidden")))
#    define __DAI_PUBLIC  __attribute__((__visibility__("default")))
#  else
#    define __DAI_PRIVATE
#    define __DAI_PUBLIC
#  endif
#  define __DAI_IMPORT    extern
#endif

#if defined(__DAI_NO_THROW)
#  undef __DAI_NO_THROW
#endif
#if \
  __DAI_HAS_ATTRIBUTE(nothrow) || \
  __DAI_GCC_VERSION_CHECK(3,3,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_NO_THROW __attribute__((__nothrow__))
#elif \
  __DAI_MSVC_VERSION_CHECK(13,1,0) || \
  __DAI_INTEL_CL_VERSION_CHECK(2021,1,0) || \
  __DAI_ARM_VERSION_CHECK(4,1,0)
#  define __DAI_NO_THROW __declspec(nothrow)
#else
#  define __DAI_NO_THROW
#endif

#if defined(__DAI_FALL_THROUGH)
# undef __DAI_FALL_THROUGH
#endif
#if \
  __DAI_HAS_ATTRIBUTE(fallthrough) || \
  __DAI_GCC_VERSION_CHECK(7,0,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_FALL_THROUGH __attribute__((__fallthrough__))
#elif __DAI_HAS_CPP_ATTRIBUTE_NS(clang,fallthrough)
#  define __DAI_FALL_THROUGH __DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[clang::fallthrough]])
#elif __DAI_HAS_CPP_ATTRIBUTE(fallthrough)
#  define __DAI_FALL_THROUGH __DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[fallthrough]])
#elif defined(__fallthrough) /* SAL */
#  define __DAI_FALL_THROUGH __fallthrough
#else
#  define __DAI_FALL_THROUGH
#endif

#if defined(__DAI_RETURNS_NON_NULL)
#  undef __DAI_RETURNS_NON_NULL
#endif
#if \
  __DAI_HAS_ATTRIBUTE(returns_nonnull) || \
  __DAI_GCC_VERSION_CHECK(4,9,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_RETURNS_NON_NULL __attribute__((__returns_nonnull__))
#elif defined(_Ret_notnull_) /* SAL */
#  define __DAI_RETURNS_NON_NULL _Ret_notnull_
#else
#  define __DAI_RETURNS_NON_NULL
#endif

#if defined(__DAI_ARRAY_PARAM)
#  undef __DAI_ARRAY_PARAM
#endif
#if \
  defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) && \
  !defined(__STDC_NO_VLA__) && \
  !defined(__cplusplus) && \
  !defined(__DAI_PGI_VERSION) && \
  !defined(__DAI_TINYC_VERSION)
#  define __DAI_ARRAY_PARAM(name) (name)
#else
#  define __DAI_ARRAY_PARAM(name)
#endif

#if defined(__DAI_IS_CONSTANT)
#  undef __DAI_IS_CONSTANT
#endif
#if defined(__DAI_REQUIRE_CONSTEXPR)
#  undef __DAI_REQUIRE_CONSTEXPR
#endif
/* __DAI_IS_CONSTEXPR_ is for
   HEDLEY INTERNAL USE ONLY.  API subject to change without notice. */
#if defined(__DAI_IS_CONSTEXPR_)
#  undef __DAI_IS_CONSTEXPR_
#endif
#if \
  __DAI_HAS_BUILTIN(__builtin_constant_p) || \
  __DAI_GCC_VERSION_CHECK(3,4,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0) || \
  __DAI_TINYC_VERSION_CHECK(0,9,19) || \
  __DAI_ARM_VERSION_CHECK(4,1,0) || \
  __DAI_IBM_VERSION_CHECK(13,1,0) || \
  __DAI_TI_CL6X_VERSION_CHECK(6,1,0) || \
  (__DAI_SUNPRO_VERSION_CHECK(5,10,0) && !defined(__cplusplus)) || \
  __DAI_CRAY_VERSION_CHECK(8,1,0) || \
  __DAI_MCST_LCC_VERSION_CHECK(1,25,10)
#  define __DAI_IS_CONSTANT(expr) __builtin_constant_p(expr)
#endif
#if !defined(__cplusplus)
#  if \
       __DAI_HAS_BUILTIN(__builtin_types_compatible_p) || \
       __DAI_GCC_VERSION_CHECK(3,4,0) || \
       __DAI_INTEL_VERSION_CHECK(13,0,0) || \
       __DAI_IBM_VERSION_CHECK(13,1,0) || \
       __DAI_CRAY_VERSION_CHECK(8,1,0) || \
       __DAI_ARM_VERSION_CHECK(5,4,0) || \
       __DAI_TINYC_VERSION_CHECK(0,9,24)
#    if defined(__INTPTR_TYPE__)
#      define __DAI_IS_CONSTEXPR_(expr) __builtin_types_compatible_p(__typeof__((1 ? (void*) ((__INTPTR_TYPE__) ((expr) * 0)) : (int*) 0)), int*)
#    else
#      include <stdint.h>
#      define __DAI_IS_CONSTEXPR_(expr) __builtin_types_compatible_p(__typeof__((1 ? (void*) ((intptr_t) ((expr) * 0)) : (int*) 0)), int*)
#    endif
#  elif \
       ( \
          defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L) && \
          !defined(__DAI_SUNPRO_VERSION) && \
          !defined(__DAI_PGI_VERSION) && \
          !defined(__DAI_IAR_VERSION)) || \
       (__DAI_HAS_EXTENSION(c_generic_selections) && !defined(__DAI_IAR_VERSION)) || \
       __DAI_GCC_VERSION_CHECK(4,9,0) || \
       __DAI_INTEL_VERSION_CHECK(17,0,0) || \
       __DAI_IBM_VERSION_CHECK(12,1,0) || \
       __DAI_ARM_VERSION_CHECK(5,3,0)
#    if defined(__INTPTR_TYPE__)
#      define __DAI_IS_CONSTEXPR_(expr) _Generic((1 ? (void*) ((__INTPTR_TYPE__) ((expr) * 0)) : (int*) 0), int*: 1, void*: 0)
#    else
#      include <stdint.h>
#      define __DAI_IS_CONSTEXPR_(expr) _Generic((1 ? (void*) ((intptr_t) * 0) : (int*) 0), int*: 1, void*: 0)
#    endif
#  elif \
       defined(__DAI_GCC_VERSION) || \
       defined(__DAI_INTEL_VERSION) || \
       defined(__DAI_TINYC_VERSION) || \
       defined(__DAI_TI_ARMCL_VERSION) || \
       __DAI_TI_CL430_VERSION_CHECK(18,12,0) || \
       defined(__DAI_TI_CL2000_VERSION) || \
       defined(__DAI_TI_CL6X_VERSION) || \
       defined(__DAI_TI_CL7X_VERSION) || \
       defined(__DAI_TI_CLPRU_VERSION) || \
       defined(__clang__)
#    define __DAI_IS_CONSTEXPR_(expr) ( \
         sizeof(void) != \
         sizeof(*( \
           1 ? \
             ((void*) ((expr) * 0L) ) : \
             ((struct { char v[sizeof(void) * 2]; } *) 1) \
           ) \
         ) \
       )
#  endif
#endif
#if defined(__DAI_IS_CONSTEXPR_)
#  if !defined(__DAI_IS_CONSTANT)
#    define __DAI_IS_CONSTANT(expr) __DAI_IS_CONSTEXPR_(expr)
#  endif
#  define __DAI_REQUIRE_CONSTEXPR(expr) (__DAI_IS_CONSTEXPR_(expr) ? (expr) : (-1))
#else
#  if !defined(__DAI_IS_CONSTANT)
#    define __DAI_IS_CONSTANT(expr) (0)
#  endif
#  define __DAI_REQUIRE_CONSTEXPR(expr) (expr)
#endif

#if defined(__DAI_BEGIN_C_DECLS)
#  undef __DAI_BEGIN_C_DECLS
#endif
#if defined(__DAI_END_C_DECLS)
#  undef __DAI_END_C_DECLS
#endif
#if defined(__DAI_C_DECL)
#  undef __DAI_C_DECL
#endif
#if defined(__cplusplus)
#  define __DAI_BEGIN_C_DECLS extern "C" {
#  define __DAI_END_C_DECLS }
#  define __DAI_C_DECL extern "C"
#else
#  define __DAI_BEGIN_C_DECLS
#  define __DAI_END_C_DECLS
#  define __DAI_C_DECL
#endif

#if defined(__DAI_STATIC_ASSERT)
#  undef __DAI_STATIC_ASSERT
#endif
#if \
  !defined(__cplusplus) && ( \
      (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)) || \
      (__DAI_HAS_FEATURE(c_static_assert) && !defined(__DAI_INTEL_CL_VERSION)) || \
      __DAI_GCC_VERSION_CHECK(6,0,0) || \
      __DAI_INTEL_VERSION_CHECK(13,0,0) || \
      defined(_Static_assert) \
    )
#  define __DAI_STATIC_ASSERT(expr, message) _Static_assert(expr, message)
#elif \
  (defined(__cplusplus) && (__cplusplus >= 201103L)) || \
  __DAI_MSVC_VERSION_CHECK(16,0,0) || \
  __DAI_INTEL_CL_VERSION_CHECK(2021,1,0)
#  define __DAI_STATIC_ASSERT(expr, message) __DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(static_assert(expr, message))
#else
#  define __DAI_STATIC_ASSERT(expr, message)
#endif

#if defined(__DAI_NULL)
#  undef __DAI_NULL
#endif
#if defined(__cplusplus)
#  if __cplusplus >= 201103L
#    define __DAI_NULL __DAI_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(nullptr)
#  elif defined(NULL)
#    define __DAI_NULL NULL
#  else
#    define __DAI_NULL __DAI_STATIC_CAST(void*, 0)
#  endif
#elif defined(NULL)
#  define __DAI_NULL NULL
#else
#  define __DAI_NULL ((void*) 0)
#endif

#if defined(__DAI_MESSAGE)
#  undef __DAI_MESSAGE
#endif
#if __DAI_HAS_WARNING("-Wunknown-pragmas")
#  define __DAI_MESSAGE(msg) \
  __DAI_DIAGNOSTIC_PUSH \
  __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS \
  __DAI_PRAGMA(message msg) \
  __DAI_DIAGNOSTIC_POP
#elif \
  __DAI_GCC_VERSION_CHECK(4,4,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0)
#  define __DAI_MESSAGE(msg) __DAI_PRAGMA(message msg)
#elif __DAI_CRAY_VERSION_CHECK(5,0,0)
#  define __DAI_MESSAGE(msg) __DAI_PRAGMA(_CRI message msg)
#elif __DAI_IAR_VERSION_CHECK(8,0,0)
#  define __DAI_MESSAGE(msg) __DAI_PRAGMA(message(msg))
#elif __DAI_PELLES_VERSION_CHECK(2,0,0)
#  define __DAI_MESSAGE(msg) __DAI_PRAGMA(message(msg))
#else
#  define __DAI_MESSAGE(msg)
#endif

#if defined(__DAI_WARNING)
#  undef __DAI_WARNING
#endif
#if __DAI_HAS_WARNING("-Wunknown-pragmas")
#  define __DAI_WARNING(msg) \
  __DAI_DIAGNOSTIC_PUSH \
  __DAI_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS \
  __DAI_PRAGMA(clang warning msg) \
  __DAI_DIAGNOSTIC_POP
#elif \
  __DAI_GCC_VERSION_CHECK(4,8,0) || \
  __DAI_PGI_VERSION_CHECK(18,4,0) || \
  __DAI_INTEL_VERSION_CHECK(13,0,0)
#  define __DAI_WARNING(msg) __DAI_PRAGMA(GCC warning msg)
#elif \
  __DAI_MSVC_VERSION_CHECK(15,0,0) || \
  __DAI_INTEL_CL_VERSION_CHECK(2021,1,0)
#  define __DAI_WARNING(msg) __DAI_PRAGMA(message(msg))
#else
#  define __DAI_WARNING(msg) __DAI_MESSAGE(msg)
#endif

#if defined(__DAI_REQUIRE)
#  undef __DAI_REQUIRE
#endif
#if defined(__DAI_REQUIRE_MSG)
#  undef __DAI_REQUIRE_MSG
#endif
#if __DAI_HAS_ATTRIBUTE(diagnose_if)
#  if __DAI_HAS_WARNING("-Wgcc-compat")
#    define __DAI_REQUIRE(expr) \
       __DAI_DIAGNOSTIC_PUSH \
       _Pragma("clang diagnostic ignored \"-Wgcc-compat\"") \
       __attribute__((diagnose_if(!(expr), #expr, "error"))) \
       __DAI_DIAGNOSTIC_POP
#    define __DAI_REQUIRE_MSG(expr,msg) \
       __DAI_DIAGNOSTIC_PUSH \
       _Pragma("clang diagnostic ignored \"-Wgcc-compat\"") \
       __attribute__((diagnose_if(!(expr), msg, "error"))) \
       __DAI_DIAGNOSTIC_POP
#  else
#    define __DAI_REQUIRE(expr) __attribute__((diagnose_if(!(expr), #expr, "error")))
#    define __DAI_REQUIRE_MSG(expr,msg) __attribute__((diagnose_if(!(expr), msg, "error")))
#  endif
#else
#  define __DAI_REQUIRE(expr)
#  define __DAI_REQUIRE_MSG(expr,msg)
#endif

#if defined(__DAI_FLAGS)
#  undef __DAI_FLAGS
#endif
#if __DAI_HAS_ATTRIBUTE(flag_enum) && (!defined(__cplusplus) || __DAI_HAS_WARNING("-Wbitfield-enum-conversion"))
#  define __DAI_FLAGS __attribute__((__flag_enum__))
#else
#  define __DAI_FLAGS
#endif

#if defined(__DAI_FLAGS_CAST)
#  undef __DAI_FLAGS_CAST
#endif
#if __DAI_INTEL_VERSION_CHECK(19,0,0)
#  define __DAI_FLAGS_CAST(T, expr) (__extension__ ({ \
  __DAI_DIAGNOSTIC_PUSH \
      _Pragma("warning(disable:188)") \
      ((T) (expr)); \
      __DAI_DIAGNOSTIC_POP \
    }))
#else
#  define __DAI_FLAGS_CAST(T, expr) __DAI_STATIC_CAST(T, expr)
#endif

#if defined(__DAI_EMPTY_BASES)
#  undef __DAI_EMPTY_BASES
#endif
#if \
  (__DAI_MSVC_VERSION_CHECK(19,0,23918) && !__DAI_MSVC_VERSION_CHECK(20,0,0)) || \
  __DAI_INTEL_CL_VERSION_CHECK(2021,1,0)
#  define __DAI_EMPTY_BASES __declspec(empty_bases)
#else
#  define __DAI_EMPTY_BASES
#endif

/* Remaining macros are deprecated. */

#if defined(__DAI_GCC_NOT_CLANG_VERSION_CHECK)
#  undef __DAI_GCC_NOT_CLANG_VERSION_CHECK
#endif
#if defined(__clang__)
#  define __DAI_GCC_NOT_CLANG_VERSION_CHECK(major,minor,patch) (0)
#else
#  define __DAI_GCC_NOT_CLANG_VERSION_CHECK(major,minor,patch) __DAI_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(__DAI_CLANG_HAS_ATTRIBUTE)
#  undef __DAI_CLANG_HAS_ATTRIBUTE
#endif
#define __DAI_CLANG_HAS_ATTRIBUTE(attribute) __DAI_HAS_ATTRIBUTE(attribute)

#if defined(__DAI_CLANG_HAS_CPP_ATTRIBUTE)
#  undef __DAI_CLANG_HAS_CPP_ATTRIBUTE
#endif
#define __DAI_CLANG_HAS_CPP_ATTRIBUTE(attribute) __DAI_HAS_CPP_ATTRIBUTE(attribute)

#if defined(__DAI_CLANG_HAS_BUILTIN)
#  undef __DAI_CLANG_HAS_BUILTIN
#endif
#define __DAI_CLANG_HAS_BUILTIN(builtin) __DAI_HAS_BUILTIN(builtin)

#if defined(__DAI_CLANG_HAS_FEATURE)
#  undef __DAI_CLANG_HAS_FEATURE
#endif
#define __DAI_CLANG_HAS_FEATURE(feature) __DAI_HAS_FEATURE(feature)

#if defined(__DAI_CLANG_HAS_EXTENSION)
#  undef __DAI_CLANG_HAS_EXTENSION
#endif
#define __DAI_CLANG_HAS_EXTENSION(extension) __DAI_HAS_EXTENSION(extension)

#if defined(__DAI_CLANG_HAS_DECLSPEC_DECLSPEC_ATTRIBUTE)
#  undef __DAI_CLANG_HAS_DECLSPEC_DECLSPEC_ATTRIBUTE
#endif
#define __DAI_CLANG_HAS_DECLSPEC_ATTRIBUTE(attribute) __DAI_HAS_DECLSPEC_ATTRIBUTE(attribute)

#if defined(__DAI_CLANG_HAS_WARNING)
#  undef __DAI_CLANG_HAS_WARNING
#endif
#define __DAI_CLANG_HAS_WARNING(warning) __DAI_HAS_WARNING(warning)

#endif /* !defined(__DAI_HEDLEY_VERSION) || (__DAI_HEDLEY_VERSION < X) */
