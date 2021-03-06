/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveWithControllerCommand.h"
#include "Robot.h"
#include <chrono>
#include <iostream>

DriveWithControllerCommand::DriveWithControllerCommand()
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    Requires(&Robot::m_driveTrainSubsystem);

    jsc.SetDeadband(0.1);
    jsc.SetExponent(4.0);
    jsc.SetRange(0, Robot::m_driveTrainSubsystem.GetMaxSpeed());
}

// Called just before this Command runs the first time
void DriveWithControllerCommand::Initialize() 
{
}

// Called repeatedly when this Command is scheduled to run
void DriveWithControllerCommand::Execute()
{
    Robot::m_driveTrainSubsystem.TankDrive(
        jsc.Condition(-1.0 * Robot::m_oi.m_leftDriverJoystick.GetY()),
        jsc.Condition(-1.0 * Robot::m_oi.m_rightDriverJoystick.GetY())
    );
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithControllerCommand::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveWithControllerCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithControllerCommand::Interrupted() {}
