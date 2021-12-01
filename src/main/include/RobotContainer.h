// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <frc/GenericHID.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/button/Button.h>

#include "subsystems/DriveLikeACar.h"
#include "commands/drive/RunDriveLikeACar.h"
#include "commands/drive/HitBrakes.h"
#include "commands/drive/GearShift.h"

/**
	* This class is where the bulk of the robot should be declared.  Since
	* Command-based is a "declarative" paradigm, very little robot logic should
	* actually be handled in the {@link Robot} periodic methods (other than the
	* scheduler calls).  Instead, the structure of the robot (including subsystems,
	* commands, and button mappings) should be declared here.
	*/
class RobotContainer {
	public:
		RobotContainer();

		frc2::Command* GetAutonomousCommand();

	private:
		// The robot's subsystems and commands are defined here...

		void ConfigureButtonBindings();

		frc::XboxController mDriverController{0};
		frc2::Button mDriverButtonA{[&] { return mDriverController.GetAButton(); }};
		frc2::Button mDriverButtonB{[&] { return mDriverController.GetBButton(); }};
		frc2::Button mDriverButtonX{[&] { return mDriverController.GetXButton(); }};
		frc2::Button mDriverButtonY{[&] { return mDriverController.GetYButton(); }};
		frc2::Button mDriverButtonLB{[&] { return mDriverController.GetBumper(frc::GenericHID::JoystickHand::kLeftHand); }};
		frc2::Button mDriverButtonRB{[&] { return mDriverController.GetBumper(frc::GenericHID::JoystickHand::kRightHand); }};
		frc2::Button mDriverButtonLMenu{[&] { return mDriverController.GetBackButton(); }};
		frc2::Button mDriverButtonRMenu{[&] { return mDriverController.GetStartButton(); }};
		frc2::Button mDriverLT{[&] { return (mDriverController.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand) > 0.5); }};
		frc2::Button mDriverRT{[&] { return (mDriverController.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand) > 0.5); }};
		frc2::Button mDriverUpDPad{[&] { return (mDriverController.GetPOV() == 0); }};
		frc2::Button mDriverLeftDPad{[&] { return (mDriverController.GetPOV() == 90); }};
		frc2::Button mDriverDownDPad{[&] { return (mDriverController.GetPOV() == 180); }};
		frc2::Button mDriverRightDPad{[&] { return (mDriverController.GetPOV() == 270); }};

		DriveLikeACar mDriveLikeACar;
		RunDriveLikeACar mRunDriveLikeACar{&mDriveLikeACar};
		HitBrakes mHitBrakes{&mDriveLikeACar};
		GearShift mForwardGear{&mDriveLikeACar, DriveLikeACar::Gear::Forward};
		GearShift mReverseGear{&mDriveLikeACar, DriveLikeACar::Gear::Reverse};
};