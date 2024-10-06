#include <algorithm>

// Of course, you do not need to use this struct, this is purely for the sake of demonstration.
// You should probably replace this with an existing Vector2 type in your dev environment.
struct vec2 {
    float x;
    float y;
};

vec2 JoystickToTankWheels(const vec2 input) {
	const float turningReduction = 0.6f;
	const float turnRate = 0.4f;

	const float x = input.x;
	const float y = input.y;

	const float negY = -y;
	const float oneMinusY = 1.0f+negY;
	const float yPlus1 = 1.0f+y;
	const float turnRateTimesX = turnRate*x;
	const float turnReduTimesY = turningReduction*y;

	const float a = turnRateTimesX*oneMinusY;
	const float b = turnRateTimesX*yPlus1;

	const float c = y - turnReduTimesY*std::max(0.0f,-x);
	const float d = y - turnReduTimesY*std::max(0.0f,x);

	const float xForward = c + a;
	const float yForward = d - a;

	const float xBackward = c - b;
	const float yBackward = d + b;

	const float maskForward = std::min(yPlus1,1.0f);
	const float maskBackward = std::max(0.0f,negY);

	const float leftWheelDirection = xForward*maskForward + xBackward*maskBackward;
	const float rightWheelDirection = yForward*maskForward + yBackward*maskBackward;

	return {leftWheelDirection,rightWheelDirection};
}
