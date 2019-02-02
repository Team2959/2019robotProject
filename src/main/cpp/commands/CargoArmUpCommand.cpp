/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/CargoArmUpCommand.h"
#include "Robot.h"
#include "commands/StopCargoControlWheelsCommand.h"

CargoArmUpCommand::CargoArmUpCommand() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::m_cargoArmSubsystem);
}

// Called just before this Command runs the first time
void CargoArmUpCommand::Initialize()
{
  Robot::m_cargoArmSubsystem.ArmUp();
  
  auto ptr = new StopCargoControlWheelsCommand();
  ptr->Start();
}

// Called repeatedly when this Command is scheduled to run
void CargoArmUpCommand::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool CargoArmUpCommand::IsFinished()
{
  return Robot::m_cargoArmSubsystem.ArmAtPosition();
}

// Called once after isFinished returns true
void CargoArmUpCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CargoArmUpCommand::Interrupted() {}