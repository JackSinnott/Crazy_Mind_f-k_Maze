#include "Xbox360Controller.h"
/// <summary>
/// Author: Jack Sinnott
/// Student Number: C00242525
/// Date: 16/09/2019
/// Estimated Time: 3 hrs
/// Actual Time: 6hrs 30 mins 
/// Known Bugs:  Previous state is not getting updated... I've tried a lot of things to make them compatable but nothing concrete has formed that fixese the problem
/// help recieved by: Richard Fleming, Kiernen Irons and Aaron O'Neil
/// </summary>
Xbox360Controller::Xbox360Controller()
{
	sf_Joystick_Index = 0;
}

Xbox360Controller::~Xbox360Controller()
{
}

void Xbox360Controller::update()
{
	// m_previousState = m_currentState; 
	buttonPresses();
	axisCheck();
}

bool Xbox360Controller::isConnect()
{
	return false;
}

bool Xbox360Controller::connect()
{
	return false;
}

void Xbox360Controller::buttonPresses()
{
	updatedCheck(&m_currentState.a, 0);								// A
	updatedCheck(&m_currentState.b, 1);								// B
	updatedCheck(&m_currentState.x, 2);								// X
	updatedCheck(&m_currentState.y, 3);								// Y
	updatedCheck(&m_currentState.leftB, 4);							// LB
	updatedCheck(&m_currentState.rightB, 5);							// RB
	updatedCheck(&m_currentState.back, 6);							// Back
	updatedCheck(&m_currentState.start, 7);							// Start
	updatedCheck(&m_currentState.leftThumbStickClick, 8);			// LeftThumbClick
	updatedCheck(&m_currentState.rightThumbStickClick, 9); // RightThumbClick
}

void Xbox360Controller::axisCheck()
{
	m_currentState.leftThumbStick.x = m_Joystick.getAxisPosition(0, sf::Joystick::Axis::X); // left thumbstick X axis *only display above 15 or less than -15
	m_currentState.leftThumbStick.y = m_Joystick.getAxisPosition(0, sf::Joystick::Axis::Y); // left thumbstick Y axis
	m_currentState.rightThumbStick.x = m_Joystick.getAxisPosition(0, sf::Joystick::Axis::U); // right thumbstick X axis
	m_currentState.rightThumbStick.y = m_Joystick.getAxisPosition(0, sf::Joystick::Axis::V); // right thumbstick Y axis
	m_currentState.rTrigger = m_Joystick.getAxisPosition(0, sf::Joystick::Axis::Z); // right trigger Z axis
	m_currentState.lTrigger = m_Joystick.getAxisPosition(0, sf::Joystick::Axis::Z); // left trigger Z axis

	// right on DPAD
	if (m_Joystick.getAxisPosition(0, sf::Joystick::Axis::PovX) > DPAD_THRESHOLD)
	{
		m_currentState.dPadRight = true;
	}
	else
	{
		m_currentState.dPadRight = false;
	}

	// left on DPAD
	if (m_Joystick.getAxisPosition(0, sf::Joystick::Axis::PovX) < -DPAD_THRESHOLD)
	{
		m_currentState.dPadLeft = true;
	}
	else
	{
		m_currentState.dPadLeft = false;
	}

	// down on DPAD
	if (m_Joystick.getAxisPosition(0, sf::Joystick::Axis::PovY) < -DPAD_THRESHOLD)
	{
		m_currentState.dPadDown = true;
	}
	else
	{
		m_currentState.dPadDown = false;
	}

	// up on DPAD
	if (m_Joystick.getAxisPosition(0, sf::Joystick::Axis::PovY) > DPAD_THRESHOLD)
	{
		m_currentState.dPadUp = true;
	}
	else
	{
		m_currentState.dPadUp = false;
	}
}

void Xbox360Controller::updatedCheck(bool* t_status, short t_button)
{
	if (m_Joystick.isButtonPressed(0, t_button))					// t_button is the index of controller
	{
		*t_status = true;											// Pointer used because it alters the bool
	}
	else
	{
		*t_status = false;											// Set to false if not pressed
	}
}