#pragma once

#include "RobotAdditions.h"

class RobotJoint //Class of joints and motors of Robot 
{
private:
	
public:
	
	double curCoord;
	MoveType jointType;
	
	RobotJoint() = default;
	RobotJoint(MoveType j);
};