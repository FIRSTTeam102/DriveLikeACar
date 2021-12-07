// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/SpeedControllerGroup.h>
#include <ctre/Phoenix.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/XboxController.h>

class DriveLikeACar : public frc2::SubsystemBase {
	public:
		DriveLikeACar();
		bool isBraking = false;
		bool isReverse = false;

		void setDriverController(frc::XboxController* pDriverController) {
			mpDriverController = pDriverController;
		};

		void drive();
		void move(double, double);
		void stop();
		void setNeutralMode(ctre::phoenix::motorcontrol::NeutralMode);

		// Will be called periodically whenever the CommandScheduler runs.
		void Periodic() override;

		enum Gear {
			Forward = 0,
			Reverse = 1,
			Neutral = 2,
			Park = 3
		};
		Gear mGear = Gear::Forward;

	private:
		// Components (e.g. motor controllers and sensors) should generally be
		// declared private and exposed only through public methods.

		frc::XboxController* mpDriverController;

		WPI_TalonSRX mDriveTopLeft;
		WPI_TalonSRX mDriveBottomLeft;
		WPI_TalonSRX mDriveTopRight;
		WPI_TalonSRX mDriveBottomRight;

		frc::SpeedControllerGroup mLeft{mDriveTopLeft, mDriveBottomLeft};
		frc::SpeedControllerGroup mRight{mDriveTopRight, mDriveBottomRight};

		frc::DifferentialDrive mDrive{mLeft, mRight};
};
