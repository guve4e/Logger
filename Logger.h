/**
 * Defines macros to Logger member functions
 */

#ifndef LOGGER_LOGGERI_H
#define LOGGER_LOGGERI_H

#include "LoggerImpl.h"

static Logger::C_Logger<Logger::C_Stream> Log("log.txt");

#define LOG Log.write<Logger::Type::Debug>
#define LOG_ERR Log.write< Logger::Type::Error >
#define LOG_ERR Log.write< Logger::Type::Warning >

#endif
