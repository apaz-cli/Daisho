#ifndef __DAI_STDLIB_COMPUTEDCONFIG
#define __DAI_STDLIB_COMPUTEDCONFIG


#if defined(__DAI_TESTING_BACKTRACES)
#define __DAI_USING_BACKTRACES 1
#else
#if __DAI_HAS_BACKTRACES && __DAI_BACKTRACES_ENABLED
#define __DAI_USING_BACKTRACES 1
#else
#define __DAI_USING_BACKTRACES 0
#endif
#endif

#define __DAI_INSANE (__DAI_SANITY_CHECK == 0)
#define __DAI_SANE (__DAI_SANITY_CHECK > 0)
#define __DAI_PEDANTIC (__DAI_SANITY_CHECK > 1)

#endif /* __DAI_STDLIB_COMPUTEDCONFIG */
