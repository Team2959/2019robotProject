/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/PrepForHatchCommand.h"
#include "Robot.h"

PrepForHatchCommand::PrepForHatchCommand() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::m_hatchSubsystem);
}

// Called just before this Command runs the first time
void PrepForHatchCommand::Initialize() {
  Robot::m_hatchSubsystem.PrepForHatch();
}

// Called repeatedly when this Command is scheduled to run
void PrepForHatchCommand::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool PrepForHatchCommand::IsFinished() { return true; }

// Called once after isFinished returns true
void PrepForHatchCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PrepForHatchCommand::Interrupted() {}
