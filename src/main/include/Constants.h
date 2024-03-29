// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <ctre/Phoenix/motorcontrol/NeutralMode.h>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace DriveConstants {
	ctre::phoenix::motorcontrol::NeutralMode constexpr kDriveLikeACarMode = ctre::phoenix::motorcontrol::NeutralMode::Coast;
	bool constexpr useSteeringWheel = true; // @todo detect from device name
	bool constexpr turnInPlace = true;

	// Motor controllers (TalonSRX)
	int constexpr kTopLeftMotor = 1;
	int constexpr kTopRightMotor = 3;
	int constexpr kBottomLeftMotor = 2;
	int constexpr kBottomRightMotor = 4;
}