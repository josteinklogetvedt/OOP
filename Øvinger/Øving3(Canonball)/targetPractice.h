#pragma once
#include "canonball.h"
#include "utilities.h"
#include "canonball_viz.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name);

double getDistanceTraveled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget, double velocityX, double velocityY);

void playTargetPractice();
