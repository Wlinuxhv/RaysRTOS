#ifndef _VALIST 
#define _VALIST 
typedef char *va_list; 
typedef s16 acpi_native_int; 

/* 
* Storage alignment properties 
*/ 
#define  _AUPBND                (sizeof (acpi_native_int) - 1) 
#define  _ADNBND                (sizeof (acpi_native_int) - 1)
/* 
* Variable argument list macro definitions 
*/ 
#define _bnd(X, bnd)            (((sizeof (X)) + (bnd)) & (~(bnd))) 
#define va_arg(ap, T)           (*(T *)(((ap) += (_bnd (T, _AUPBND))) - (_bnd (T,_ADNBND)))) 
#define va_end(ap)              (void) 0 
#define va_start(ap, A)         (void) ((ap) = (((char *) &(A)) + (_bnd (A,_AUPBND))))
//#endif                /* va_arg */
#endif                /* _VALIST */

