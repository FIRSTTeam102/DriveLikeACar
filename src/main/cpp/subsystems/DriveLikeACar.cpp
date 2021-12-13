// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveLikeACar.h"
#include "RobotContainer.h"
#include "Constants.h"

DriveLikeACar::DriveLikeACar():
	mDriveTopLeft{DriveConstants::kTopLeftMotor},
	mDriveBottomLeft{DriveConstants::kBottomLeftMotor},
	mDriveTopRight{DriveConstants::kTopRightMotor},
	mDriveBottomRight{DriveConstants::kBottomRightMotor}
{
	setNeutralMode(DriveConstants::kDriveLikeACarMode);
	mDriveTopLeft.SetInverted(true);
	mDriveBottomLeft.SetInverted(true);
	mDriveTopRight.SetInverted(true);
	mDriveBottomRight.SetInverted(true);
}

// This method will be called once per scheduler run
void DriveLikeACar::Periodic() {}

void DriveLikeACar::drive() {
	if (isBraking) {
		stop();
		return;
	}
	double accelerator = 0.85 * mpDriverController->GetRawAxis((int)frc::XboxController::Axis::kRightTrigger);
	if (-0.1 < accelerator && accelerator < 0.1) accelerator = 0;
	accelerator = accelerator*accelerator;
	double wheel = -1.00 * mpDriverController->GetRawAxis((int)frc::XboxController::Axis::kLeftX);
	if (-0.1 < wheel && wheel < 0.1) wheel = 0;

	switch (mGear) {
		case Gear::Forward: break;
		case Gear::Reverse: accelerator = -1.0 * accelerator; wheel = -1.0 * wheel; break;
		case Gear::Neutral: accelerator = 0; break;
	}

	printf("Gear %d\n", mGear);

	mDrive.CurvatureDrive(accelerator, wheel, false);
	printf("Driving %F    %F\n", accelerator, wheel);
}

void DriveLikeACar::move(double left, double right) {
	mDrive.TankDrive(left, right, false);
}

void DriveLikeACar::carMove(double accelerator, double wheel) {
	mDrive.CurvatureDrive(accelerator, wheel, false);
}

void DriveLikeACar::stop() {
	mDrive.TankDrive(0, 0, false);
}

void DriveLikeACar::setNeutralMode(ctre::phoenix::motorcontrol::NeutralMode mode) {
	mDriveTopLeft.SetNeutralMode(mode);
	mDriveBottomLeft.SetNeutralMode(mode);
	mDriveTopRight.SetNeutralMode(mode);
	mDriveBottomRight.SetNeutralMode(mode);
}