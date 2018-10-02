grammar IFD;

file: line*;

line: version | declare | setenv | start | end | detail | property | image | geomerty | time | raytrace | quit | COMMENT;

setenv
   : 'setenv' VAR_NAME '=' VALUE
   ;

version
   : 'ray_version' VERSION
   ;

declare
   : 'ray_declare' OBJECT TYPE VAR_NAME VALUE
   ;

start
   : 'ray_start' OBJECT
   ;

end
   : 'ray_end'
   ;

detail
   : 'ray_detail' ('-T' | ('-v' VALUE) | ('-V' VALUE VALUE))? (VAR_NAME | STRING | VALUE) (STREAM | VALUE)
   ;

property
   : 'ray_property' OBJECT VAR_NAME (STREAM | VALUE)
   ;

image
   : 'ray_image' VALUE VALUE?
   ;

geomerty
   : 'ray_geometry' VALUE
   ;

time
   : 'ray_time' VALUE
   ;

raytrace
   : 'ray_raytrace'
   ;

quit
   : 'ray_quit'
   ;

COMMENT
   : '#' ~( '\r' | '\n' )*
   ;

STREAM
   : 'stdin' .*? 'ray_end'
   ;

TYPE
   : 'float' | 'bool' | 'int' | 'vector2' | 'vector3' | 'vector4' | 'matrix3' | 'matrix4' | 'string'
   ;

OBJECT
   : 'global' | 'material' | 'geo' | 'geomerty' | 'segment' | 'camera' | 'light' | 'fog' | 'object' | 'instance' | 'plane' | 'image' | 'renderer'
   ;

VERSION
   : 'VEX' INT '.' INT '.' INT '.' INT
   ;

VAR_NAME
   : VALID_ID_START VALID_ID_CHAR*
   ;

VALUE
   : INTEGER | NUMBER | STRING
   ;

INTEGER
   : INT
   ;

NUMBER
   : '-'? INT '.' [0-9] + EXP? | '-'? INT EXP | '-'? INT
   ;

STRING
   : QUOTED | NO_QUOTED
   ;
   
NO_QUOTED
   : ~(' ' | '\'' | '"' | '\t' | '\r' | '\n')+
   ;

QUOTED
   : '"' (NO_QUOTED | ' ')* '"'
   ;

CHARS
   : LETTER+
   ;

fragment VALID_ID_START
   : LETTER | '_'
   ;


fragment VALID_ID_CHAR
   : VALID_ID_START | ('0' .. '9') | '-' | '+' | ':' | '.'
   ;


fragment LETTER
   : [a-zA-Z]
   ;

fragment INT
   : '0' | [1-9] [0-9]*
   ;

fragment EXP
   : [Ee] [+\-]? INT
   ;

WS: [ \n\t\r]+
   -> skip;