#if !defined( _SOUL_CORE_H )
	#include "core.h"
#endif     /* _SOUL_CORE_H */

#if !defined( _SOUL_H )
#define       _SOUL_H

PUBLIC void SoulLoadModules( lua_State *_s );
PUBLIC void CleanUpSoulStuff( void );

PUBLIC bool Running( void ); 
PUBLIC void StartDraw( void );
PUBLIC void EndDraw( void );

#if defined( _SOUL_IMPLEMENTATION )

#endif    /* _SOUL_IMPLEMENTATION */

#endif     /* _SOUL_H */
