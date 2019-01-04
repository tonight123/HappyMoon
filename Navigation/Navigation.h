#ifndef _NAVIGATION_H_
#define _NAVIGATION_H_
#include "mathTool.h"
#include "Visiondata_deal.h"
#include "Task.h"

typedef struct {
    Vector3f_t accel;
    Vector3f_t accel_bias;
    
    Vector3f_t velocity;
    float      velMeasure[6];
    
    Vector3f_t position;
    Vector3f_t posMeasure;
} NAVGATION_t;

typedef struct {
	float PosCurrentTime;
	uint64_t PosLastTime;
	float VelCurrentTime;
	uint64_t VelLastTime;
} FPS_Navigation;


void NavigationInit(void);
void VelocityEstimate(void);
void PositionEstimate(void);
Vector3f_t GetCopterPosition(void);
Vector3f_t GetCopterVelocity(void);
float GetFPSNavigationPos(void);
float GetFPSNavigationVel(void);
#endif
