// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() {
	// Initialize all of your commands and subsystems here

	// mDriveLikeACar.SetDefaultCommand(std::move(mRunDriveLikeACar));
	mDriveLikeACar.setDriverController(&mDriverController);

	// Configure the button bindings
	ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
	// Configure your button bindings here
	mDriverLT.WhenHeld(&mHitBrakes, true);
	mDriverButtonY.WhenPressed(&mForwardGear, false);
	mDriverButtonA.WhenPressed(&mReverseGear, false);
	mDriverButtonB.WhenPressed(&mParkGear, false);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
	// An example command will be run in autonomous
	return nullptr;
}