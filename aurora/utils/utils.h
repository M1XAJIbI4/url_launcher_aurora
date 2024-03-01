// SPDX-FileCopyrightText: 2023 Open Mobile Platform LLC <community@omp.ru>
// SPDX-License-Identifier: BSD-3-Clause

#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include "RuntimeManager/error.h"

namespace Utils {

    QString errorCodeToString(const RuntimeManager::Error::Code &code); 

} // namespace Utils

#endif // SIMPLELOGGER_H