#include "Graphics_Susu.h"
typedef double mapObstacle[256][192*2];

void initMapObstacle(mapObstacle myMapObstacle);
void BounceUpdate(pSusu mySusu, mapObstacle myMapObstacle);
void BounceSusu(pSusu mySusu, double bounce_angle);
