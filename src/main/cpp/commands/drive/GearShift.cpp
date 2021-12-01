// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/drive/GearShift.h"

GearShift::GearShift(DriveLikeACar* pDriveLikeACar, DriveLikeACar::Gear gear): mpDriveLikeACar(pDriveLikeACar) {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pDriveLikeACar);
    mGear = gear;
}

// Called when the command is initially scheduled.
void GearShift::Initialize() {
	mpDriveLikeACar->mGear = mGear;
}

// Called repeatedly when this Command is scheduled to run
void GearShift::Execute() {}

// Called once the command ends or is interrupted.
void GearShift::End(bool interrupted) {}

// Returns true when the command should end.
bool GearShift::IsFinished() {
	return true;
}