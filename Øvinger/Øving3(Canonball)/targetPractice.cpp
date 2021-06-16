
#include "targetPractice.h"

//Opg. 3b
void testDeviation(double compareOperand, double toOperand, double maxError, string name){
	if (abs(toOperand-compareOperand) <= maxError){
		cout << name << " er lik " << toOperand << "\n";
	} else{
		cout << name << " er ikke lik " << toOperand << "\n";
	}
}

// 4b) - her er velocityX og velocityY er starthastigheten
double getDistanceTraveled(double velocityX, double velocityY){
	double time = flightTime(velocityY);
	double distance = posX(0.0, velocityX, time);
	return distance;
}

// 4c)
double targetPractice(double distanceToTarget, double velocityX, double velocityY){
	return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
}

void playTargetPractice(){
	cout << "The target is between 100 and 1000 meters away\n";
	double initVelocity = 0;
	double angle = 0;
	double velocityY = 0;
	double velocityX = 0;
	double distanceToTarget = randomWithLimits(100,1000);
	int count = 0;
	double flight_Time = 0;
	double difference = 0;
	while (count < 11){
		angle = getUserInputTheta();
		initVelocity = getUserInputAbsVelocity();
		velocityX = getVelocityX(angle, initVelocity);
		velocityY = getVelocityY(angle, initVelocity);
		difference = targetPractice(distanceToTarget, velocityX, velocityY);
		count += 1;
		flight_Time = flightTime(velocityY);
		cannonBallViz(distanceToTarget, 1000, velocityX, velocityY, 10);
		cout << "The flighttime was ";
		printTime(flight_Time);
		
		if ( (-5 < difference) && (difference<5)){
			break;
		}else if (difference <= -5){
			cout << "The cannon went too far! " << -difference << " too long. Try again.\n";
		}else{
			cout << "The cannon went too short! " << difference << " too short. Try again.\n";
		}	
	}
	if (count <=10){
		cout << "You won! You used " << count << " attempts.\n"; 
	}else{
		cout << "You lost.\n";
	}
}