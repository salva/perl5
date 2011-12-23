/* -*- buffer-read-only: t -*-
   !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
   This file is built by regen/feature.pl.
   Any changes made here will be lost!
 */


#if defined(PERL_CORE) || defined (PERL_EXT)

#define HINT_FEATURE_SHIFT	26

#define FEATURE_BUNDLE_DEFAULT	0
#define FEATURE_BUNDLE_510	1
#define FEATURE_BUNDLE_511	2
#define FEATURE_BUNDLE_515	3
#define FEATURE_BUNDLE_CUSTOM	(HINT_FEATURE_MASK >> HINT_FEATURE_SHIFT)

#define CURRENT_HINTS \
    (PL_curcop == &PL_compiling ? PL_hints : PL_curcop->cop_hints)
#define CURRENT_FEATURE_BUNDLE	(CURRENT_HINTS >> HINT_FEATURE_SHIFT)

#define FEATURE_SAY_IS_ENABLED \
    ( \
	(CURRENT_FEATURE_BUNDLE >= FEATURE_BUNDLE_510 && \
	 CURRENT_FEATURE_BUNDLE <= FEATURE_BUNDLE_515) \
     || (CURRENT_FEATURE_BUNDLE == FEATURE_BUNDLE_CUSTOM && \
	 FEATURE_IS_ENABLED("say")) \
    )

#define FEATURE_STATE_IS_ENABLED \
    ( \
	(CURRENT_FEATURE_BUNDLE >= FEATURE_BUNDLE_510 && \
	 CURRENT_FEATURE_BUNDLE <= FEATURE_BUNDLE_515) \
     || (CURRENT_FEATURE_BUNDLE == FEATURE_BUNDLE_CUSTOM && \
	 FEATURE_IS_ENABLED("state")) \
    )

#define FEATURE_SWITCH_IS_ENABLED \
    ( \
	(CURRENT_FEATURE_BUNDLE >= FEATURE_BUNDLE_510 && \
	 CURRENT_FEATURE_BUNDLE <= FEATURE_BUNDLE_515) \
     || (CURRENT_FEATURE_BUNDLE == FEATURE_BUNDLE_CUSTOM && \
	 FEATURE_IS_ENABLED("switch")) \
    )

#define FEATURE_EVALBYTES_IS_ENABLED \
    ( \
	CURRENT_FEATURE_BUNDLE == FEATURE_BUNDLE_515 \
     || (CURRENT_FEATURE_BUNDLE == FEATURE_BUNDLE_CUSTOM && \
	 FEATURE_IS_ENABLED("evalbytes")) \
    )

#define FEATURE_ARYBASE_IS_ENABLED \
    ( \
	(CURRENT_FEATURE_BUNDLE >= FEATURE_BUNDLE_DEFAULT && \
	 CURRENT_FEATURE_BUNDLE <= FEATURE_BUNDLE_511) \
     || (CURRENT_FEATURE_BUNDLE == FEATURE_BUNDLE_CUSTOM && \
	 FEATURE_IS_ENABLED_d("arybase")) \
    )

#define FEATURE___SUB___IS_ENABLED \
    ( \
	CURRENT_FEATURE_BUNDLE == FEATURE_BUNDLE_515 \
     || (CURRENT_FEATURE_BUNDLE == FEATURE_BUNDLE_CUSTOM && \
	 FEATURE_IS_ENABLED("__SUB__")) \
    )

#define FEATURE_UNIEVAL_IS_ENABLED \
    ( \
	CURRENT_FEATURE_BUNDLE == FEATURE_BUNDLE_515 \
     || (CURRENT_FEATURE_BUNDLE == FEATURE_BUNDLE_CUSTOM && \
	 FEATURE_IS_ENABLED("unieval")) \
    )

#define FEATURE_UNICODE_IS_ENABLED \
    ( \
	(CURRENT_FEATURE_BUNDLE >= FEATURE_BUNDLE_511 && \
	 CURRENT_FEATURE_BUNDLE <= FEATURE_BUNDLE_515) \
     || (CURRENT_FEATURE_BUNDLE == FEATURE_BUNDLE_CUSTOM && \
	 FEATURE_IS_ENABLED("unicode")) \
    )


#endif /* PERL_CORE or PERL_EXT */

/* ex: set ro: */
