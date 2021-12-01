// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/drive/RunDriveLikeACar.h"

RunDriveLikeACar::RunDriveLikeACar(DriveLikeACar* pDriveLikeACar): mpDriveLikeACar(pDriveLikeACar) {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pDriveLikeACar);
}

// Called when the command is initially scheduled.
void RunDriveLikeACar::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void RunDriveLikeACar::Execute() {
	mpDriveLikeACar->drive();
}

// Called once the command ends or is interrupted.
void RunDriveLikeACar::End(bool interrupted) {}

// Returns true when the command should end.
bool RunDriveLikeACar::IsFinished() {
	return false;
}
