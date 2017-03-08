
typedef struct point  
 /* DEFNES A STRUCTURE NAMED POINT WHICH CONTAINS TWO VARIABLES X AND Y ---> THIS BASICALLY GIVES THE COORDINATE OF A POINT ON THE LED MATRIX */
{
  int x;
  int y;
};

enum games { gmMenu = 0, gmPong = 1, gmTedshow = 2, gmSpaceInvaders = 3, gmSnake = 4 };   // ENUMERATED DATA TYPE

enum steering { stLeft, stCentre, stRight };   // ENUMERATED DATA TYPE

enum tedShowState { tsLights, tsFalling };   // ENUMERATED DATA TYPE
