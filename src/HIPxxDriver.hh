/**
 * @file HIPxxDriver.hh
 * @author Paulius Velesko (pvelesko@gmail.com)
 * @brief Header defining global HIPxx classes and functions such as
 * HIPxxBackend type pointer Backend which gets initialized at the start of
 * execution.
 * @version 0.1
 * @date 2021-08-19
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef HIPXX_DRIVER_H
#define HIPXX_DRIVER_H
#include <iostream>
#include <mutex>

#include "HIPxxBackend.hh"

/**
 * @brief
 * Global Backend pointer through which backend-specific operations are
 * performed
 */
extern HIPxxBackend* Backend;

/**
 * @brief
 * Singleton backend initialization flag
 */
extern std::once_flag initialized;
extern std::once_flag uninitialized;

/**
 * @brief
 * Singleton backend initialization function outer wrapper
 */
extern void HIPxxInitialize(std::string BE = "");

/**
 * @brief
 * Singleton backend initialization function outer wrapper
 */
extern void HIPxxUninitialize();

/**
 * @brief
 * Singleton backend initialization function called via std::call_once
 */
void HIPxxInitializeCallOnce(std::string BE = "");

/**
 * @brief
 * Singleton backend uninitialization function called via std::call_once
 */
void HIPxxUninitializeCallOnce();

std::string read_env_var(std::string ENV_VAR);
std::string read_backend_selection();

#endif