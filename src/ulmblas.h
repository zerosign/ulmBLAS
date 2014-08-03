#ifndef ULMBLAS_H
#define ULMBLAS_H 1

#include <ctype.h>

#ifdef FAKE_ATLAS
#   define ULMBLAS(x) ATL_##x
#   define F77BLAS(x) x##_intern
#else
#   define ULMBLAS(x) ULM_##x
#   define F77BLAS(x) x##_
#endif

//
//  Constants for buffer sizes
//

//#define MC  384
#define KC  384
#define NC  4096


#define MR  4
#define NR  4


//
//  Constants for Trans, Side, UpLo and Diag are compatible with CBLAS and ATLAS
//
enum Trans {
    NoTrans   = 111,
    Trans     = 112,
    ConjTrans = 113,
    Conj      = 114
};

enum Side {
    Left    = 141,
    Right   = 142
};

enum UpLo {
    Upper   = 121,
    Lower   = 122
};

enum Diag {
    NonUnit = 131,
    Unit    = 132
};

enum Order {
    RowMajor = 101,
    ColMajor = 102
};

//
//  Convert trans chars 'n', 'N', 't', 'T', 'c', 'C', 'r', 'R' to corresponding
//  enum Trans constants.  Illegal chars result in 0.
//
#define charToTranspose(x)  (toupper(x) == 'N' ? NoTrans :   \
                             toupper(x) == 'T' ? Trans :     \
                             toupper(x) == 'C' ? ConjTrans : \
                             toupper(x) == 'R' ? Conj: 0)

//
//  Convert side chars 'l', 'L', 'r', 'R' to corresponding enum Side constants.
//  Illegal chars result in 0.
//
#define charToSide(x)  (toupper(x) == 'L' ? Left :     \
                        toupper(x) == 'R' ? Right : 0)

//
//  Convert uplo chars 'u', 'U', 'l', 'L' to corresponding enum UpLo constants.
//  Illegal chars result in 0.
//
#define charToUpLo(x)  (toupper(x) == 'U' ? Upper :     \
                        toupper(x) == 'L' ? Lower : 0)

//
//  Convert diag chars 'u', 'U', 'n', 'N' to corresponding enum Diag constants.
//  Illegal chars result in 0.
//
#define charToDiag(x)  (toupper(x) == 'N' ? NonUnit :     \
                        toupper(x) == 'U' ? Unit : 0)


//
//  macro for max function
//
#define max(x,y)  (((x)<(y)) ? (y) : (x))

//
//  macro for min function
//
#define min(x,y)  (((x)>(y)) ? (y) : (x))


#endif // ULM_BLAS_H
