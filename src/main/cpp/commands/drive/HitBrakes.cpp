// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/drive/HitBrakes.h"

HitBrakes::HitBrakes(DriveLikeACar* pDriveLikeACar): mpDriveLikeACar(pDriveLikeACar) {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pDriveLikeACar);
}

// Called when the command is initially scheduled.
void HitBrakes::Initialize() {
	if (DriveConstants::kDriveLikeACarMode == Coast) {
		// Apply the brakes when pressed
		mpDriveLikeACar->setNeutralMode(Brake);
		// Take control of the throttle
		mpDriveLikeACar->isBraking = true;
	} else {
		End(true);
	}
}

// Called repeatedly when this Command is scheduled to run
void HitBrakes::Execute() {
	// Maybe ramp down speed?
	mpDriveLikeACar->stop();
}

// Called once the command ends or is interrupted.
void HitBrakes::End(bool interrupted) {
	if (!interrupted) {
		mpDriveLikeACar->setNeutralMode(Coast);
	}
}

// Returns true when the command should end.
bool HitBrakes::IsFinished() {
	return false;
}
