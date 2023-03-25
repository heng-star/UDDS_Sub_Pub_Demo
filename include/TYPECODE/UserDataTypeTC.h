// Don't modify this file as it will be overwritten.
//


#ifndef UserDataTypeTC_hh
#define UserDataTypeTC_hh

#include "DDS/TypeCode.h"
//	This file can only be used on current platform

#define ORBUS_LITTLE_ENDIAN

#if     defined (ORBUS_BIG_ENDIAN)
#       define  MAKE_BIG_LONG(a,b,c,d) \
            ((((a) & 0xff) << 24) | (((b) & 0xff) << 16) \
             | (((c) & 0xff) <<  8) | ((d) & 0xff))
#       define  BIG_ENDIAN_LONG(x)      (x)
#else   // ORBUS_LITTLE_ENDIAN
#       define  MAKE_BIG_LONG(a,b,c,d) \
            ((((d) & 0xff) << 24) | (((c) & 0xff) << 16) \
             | (((b) & 0xff) <<  8) | ((a) & 0xff))
#       define BYTE_FROM(n,integer)    (((integer)>>(8*(n)))&0xff)
#       define BIG_ENDIAN_LONG(integer) \
            MAKE_BIG_LONG (BYTE_FROM(3,integer), BYTE_FROM(2,integer),\
                BYTE_FROM(1,integer), BYTE_FROM(0,integer))
#endif

static long oc_SHE [] = {
  0,
  BIG_ENDIAN_LONG (12),
  MAKE_BIG_LONG ('I', 'D', 'L', ':'),
  MAKE_BIG_LONG ('S', 'H', 'E', ':'),
  MAKE_BIG_LONG ('1', '.', '0',  0 ),
  BIG_ENDIAN_LONG (4),
  MAKE_BIG_LONG ('S', 'H', 'E',  0 ),
  BIG_ENDIAN_LONG (tk_short),
};

static long oc_SH [] = {
  0,
  BIG_ENDIAN_LONG (11),
  MAKE_BIG_LONG ('I', 'D', 'L', ':'),
  MAKE_BIG_LONG ('S', 'H', ':', '1'),
  MAKE_BIG_LONG ('.', '0',  0 ,  0 ),
  BIG_ENDIAN_LONG (3),
  MAKE_BIG_LONG ('S', 'H',  0 ,  0 ),
  BIG_ENDIAN_LONG (tk_alias),
  BIG_ENDIAN_LONG (32),
  BIG_ENDIAN_LONG (0),
  BIG_ENDIAN_LONG (12),
  MAKE_BIG_LONG ('I', 'D', 'L', ':'),
  MAKE_BIG_LONG ('S', 'H', 'E', ':'),
  MAKE_BIG_LONG ('1', '.', '0',  0 ),
  BIG_ENDIAN_LONG (4),
  MAKE_BIG_LONG ('S', 'H', 'E',  0 ),
  BIG_ENDIAN_LONG (tk_short),
};

static long oc_TestEnum [] = {
  0,
  BIG_ENDIAN_LONG (17),
  MAKE_BIG_LONG ('I', 'D', 'L', ':'),
  MAKE_BIG_LONG ('T', 'e', 's', 't'),
  MAKE_BIG_LONG ('E', 'n', 'u', 'm'),
  MAKE_BIG_LONG (':', '1', '.', '0'),
  0,
  BIG_ENDIAN_LONG (9),
  MAKE_BIG_LONG ('T', 'e', 's', 't'),
  MAKE_BIG_LONG ('E', 'n', 'u', 'm'),
  0,
  BIG_ENDIAN_LONG (3),
  BIG_ENDIAN_LONG (2),
  MAKE_BIG_LONG ('A',  0 ,  0 ,  0 ),
  BIG_ENDIAN_LONG (2),
  MAKE_BIG_LONG ('B',  0 ,  0 ,  0 ),
  BIG_ENDIAN_LONG (2),
  MAKE_BIG_LONG ('C',  0 ,  0 ,  0 ),
};

static TypeCode tc_TestEnum = TypeCode(tk_enum, sizeof(oc_TestEnum), (unsigned char *)&oc_TestEnum);


static long oc_number [] = {
  0,
  BIG_ENDIAN_LONG (15),
  MAKE_BIG_LONG ('I', 'D', 'L', ':'),
  MAKE_BIG_LONG ('n', 'u', 'm', 'b'),
  MAKE_BIG_LONG ('e', 'r', ':', '1'),
  MAKE_BIG_LONG ('.', '0',  0 ,  0 ),
  BIG_ENDIAN_LONG (7),
  MAKE_BIG_LONG ('n', 'u', 'm', 'b'),
  MAKE_BIG_LONG ('e', 'r',  0 ,  0 ),
  BIG_ENDIAN_LONG (2),
  BIG_ENDIAN_LONG (2),
  MAKE_BIG_LONG ('x',  0 ,  0 ,  0 ),
  BIG_ENDIAN_LONG (tk_short),
  BIG_ENDIAN_LONG (2),
  MAKE_BIG_LONG ('y',  0 ,  0 ,  0 ),
  BIG_ENDIAN_LONG (tk_short),
};

static TypeCode tc_number = TypeCode(tk_struct, sizeof(oc_number), (unsigned char *)&oc_number);


static long oc_news [] = {
  0,
  BIG_ENDIAN_LONG (13),
  MAKE_BIG_LONG ('I', 'D', 'L', ':'),
  MAKE_BIG_LONG ('n', 'e', 'w', 's'),
  MAKE_BIG_LONG (':', '1', '.', '0'),
  0,
  BIG_ENDIAN_LONG (5),
  MAKE_BIG_LONG ('n', 'e', 'w', 's'),
  0,
  BIG_ENDIAN_LONG (2),
  BIG_ENDIAN_LONG (5),
  MAKE_BIG_LONG ('d', 'a', 't', 'e'),
  0,
  BIG_ENDIAN_LONG (tk_long),
  BIG_ENDIAN_LONG (4),
  MAKE_BIG_LONG ('n', 'u', 'm',  0 ),
  BIG_ENDIAN_LONG (tk_struct),
  BIG_ENDIAN_LONG (64),
  BIG_ENDIAN_LONG (0),
  BIG_ENDIAN_LONG (15),
  MAKE_BIG_LONG ('I', 'D', 'L', ':'),
  MAKE_BIG_LONG ('n', 'u', 'm', 'b'),
  MAKE_BIG_LONG ('e', 'r', ':', '1'),
  MAKE_BIG_LONG ('.', '0',  0 ,  0 ),
  BIG_ENDIAN_LONG (7),
  MAKE_BIG_LONG ('n', 'u', 'm', 'b'),
  MAKE_BIG_LONG ('e', 'r',  0 ,  0 ),
  BIG_ENDIAN_LONG (2),
  BIG_ENDIAN_LONG (2),
  MAKE_BIG_LONG ('x',  0 ,  0 ,  0 ),
  BIG_ENDIAN_LONG (tk_short),
  BIG_ENDIAN_LONG (2),
  MAKE_BIG_LONG ('y',  0 ,  0 ,  0 ),
  BIG_ENDIAN_LONG (tk_short),
};

static TypeCode tc_news = TypeCode(tk_struct, sizeof(oc_news), (unsigned char *)&oc_news);


static long oc_user [] = {
  0,
  BIG_ENDIAN_LONG (13),
  MAKE_BIG_LONG ('I', 'D', 'L', ':'),
  MAKE_BIG_LONG ('u', 's', 'e', 'r'),
  MAKE_BIG_LONG (':', '1', '.', '0'),
  0,
  BIG_ENDIAN_LONG (5),
  MAKE_BIG_LONG ('u', 's', 'e', 'r'),
  0,
  BIG_ENDIAN_LONG (5),
  BIG_ENDIAN_LONG (2),
  MAKE_BIG_LONG ('a',  0 ,  0 ,  0 ),
  BIG_ENDIAN_LONG (tk_array),
  BIG_ENDIAN_LONG (184),
  BIG_ENDIAN_LONG (0),
  BIG_ENDIAN_LONG (tk_array),
  BIG_ENDIAN_LONG (168),
  BIG_ENDIAN_LONG (0),
  BIG_ENDIAN_LONG (tk_array),
  BIG_ENDIAN_LONG (152),
  BIG_ENDIAN_LONG (0),
  BIG_ENDIAN_LONG (tk_struct),
  BIG_ENDIAN_LONG (136),
  BIG_ENDIAN_LONG (0),
  BIG_ENDIAN_LONG (13),
  MAKE_BIG_LONG ('I', 'D', 'L', ':'),
  MAKE_BIG_LONG ('n', 'e', 'w', 's'),
  MAKE_BIG_LONG (':', '1', '.', '0'),
  0,
  BIG_ENDIAN_LONG (5),
  MAKE_BIG_LONG ('n', 'e', 'w', 's'),
  0,
  BIG_ENDIAN_LONG (2),
  BIG_ENDIAN_LONG (5),
  MAKE_BIG_LONG ('d', 'a', 't', 'e'),
  0,
  BIG_ENDIAN_LONG (tk_long),
  BIG_ENDIAN_LONG (4),
  MAKE_BIG_LONG ('n', 'u', 'm',  0 ),
  BIG_ENDIAN_LONG (tk_struct),
  BIG_ENDIAN_LONG (64),
  BIG_ENDIAN_LONG (0),
  BIG_ENDIAN_LONG (15),
  MAKE_BIG_LONG ('I', 'D', 'L', ':'),
  MAKE_BIG_LONG ('n', 'u', 'm', 'b'),
  MAKE_BIG_LONG ('e', 'r', ':', '1'),
  MAKE_BIG_LONG ('.', '0',  0 ,  0 ),
  BIG_ENDIAN_LONG (7),
  MAKE_BIG_LONG ('n', 'u', 'm', 'b'),
  MAKE_BIG_LONG ('e', 'r',  0 ,  0 ),
  BIG_ENDIAN_LONG (2),
  BIG_ENDIAN_LONG (2),
  MAKE_BIG_LONG ('x',  0 ,  0 ,  0 ),
  BIG_ENDIAN_LONG (tk_short),
  BIG_ENDIAN_LONG (2),
  MAKE_BIG_LONG ('y',  0 ,  0 ,  0 ),
  BIG_ENDIAN_LONG (tk_short),
  BIG_ENDIAN_LONG (2),
  BIG_ENDIAN_LONG (2),
  BIG_ENDIAN_LONG (2),
  BIG_ENDIAN_LONG (4),
  MAKE_BIG_LONG ('n', 'u', 'm',  0 ),
  BIG_ENDIAN_LONG (tk_alias),
  BIG_ENDIAN_LONG (68),
  BIG_ENDIAN_LONG (0),
  BIG_ENDIAN_LONG (11),
  MAKE_BIG_LONG ('I', 'D', 'L', ':'),
  MAKE_BIG_LONG ('S', 'H', ':', '1'),
  MAKE_BIG_LONG ('.', '0',  0 ,  0 ),
  BIG_ENDIAN_LONG (3),
  MAKE_BIG_LONG ('S', 'H',  0 ,  0 ),
  BIG_ENDIAN_LONG (tk_alias),
  BIG_ENDIAN_LONG (32),
  BIG_ENDIAN_LONG (0),
  BIG_ENDIAN_LONG (12),
  MAKE_BIG_LONG ('I', 'D', 'L', ':'),
  MAKE_BIG_LONG ('S', 'H', 'E', ':'),
  MAKE_BIG_LONG ('1', '.', '0',  0 ),
  BIG_ENDIAN_LONG (4),
  MAKE_BIG_LONG ('S', 'H', 'E',  0 ),
  BIG_ENDIAN_LONG (tk_short),
  BIG_ENDIAN_LONG (3),
  MAKE_BIG_LONG ('t', 'e',  0 ,  0 ),
  BIG_ENDIAN_LONG (tk_enum),
  BIG_ENDIAN_LONG (72),
  BIG_ENDIAN_LONG (0),
  BIG_ENDIAN_LONG (17),
  MAKE_BIG_LONG ('I', 'D', 'L', ':'),
  MAKE_BIG_LONG ('T', 'e', 's', 't'),
  MAKE_BIG_LONG ('E', 'n', 'u', 'm'),
  MAKE_BIG_LONG (':', '1', '.', '0'),
  0,
  BIG_ENDIAN_LONG (9),
  MAKE_BIG_LONG ('T', 'e', 's', 't'),
  MAKE_BIG_LONG ('E', 'n', 'u', 'm'),
  0,
  BIG_ENDIAN_LONG (3),
  BIG_ENDIAN_LONG (2),
  MAKE_BIG_LONG ('A',  0 ,  0 ,  0 ),
  BIG_ENDIAN_LONG (2),
  MAKE_BIG_LONG ('B',  0 ,  0 ,  0 ),
  BIG_ENDIAN_LONG (2),
  MAKE_BIG_LONG ('C',  0 ,  0 ,  0 ),
  BIG_ENDIAN_LONG (2),
  MAKE_BIG_LONG ('b',  0 ,  0 ,  0 ),
  BIG_ENDIAN_LONG (tk_array),
  BIG_ENDIAN_LONG (28),
  BIG_ENDIAN_LONG (0),
  BIG_ENDIAN_LONG (tk_array),
  BIG_ENDIAN_LONG (12),
  BIG_ENDIAN_LONG (0),
  BIG_ENDIAN_LONG (tk_long),
  BIG_ENDIAN_LONG (2),
  BIG_ENDIAN_LONG (2),
  BIG_ENDIAN_LONG (9),
  MAKE_BIG_LONG ('s', 't', 'r', 'v'),
  MAKE_BIG_LONG ('a', 'l', 'u', 'e'),
  0,
  BIG_ENDIAN_LONG (tk_string),
  BIG_ENDIAN_LONG (0),
};

static TypeCode tc_user = TypeCode(tk_struct, sizeof(oc_user), (unsigned char *)&oc_user);





#endif /*UserDataTypeTC_hh */
