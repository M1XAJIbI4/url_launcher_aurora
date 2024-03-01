// SPDX-FileCopyrightText: 2023 Open Mobile Platform LLC <community@omp.ru>
// SPDX-License-Identifier: BSD-3-Clause

#include "intent_default.h"

#include <QDebug>
#include <QtQml>

#include "../utils/utils.h"

#include "../invoke_manager/invoke_manager.h"

using namespace RuntimeManager;

using namespace Invoker;

namespace {
    const QString intentsHintPreferredHandler = QStringLiteral("preferredHandler");
    const QString intentsIntentNameStart = QStringLiteral("Start");
    const QString intentsIntentNameOpenURI = QStringLiteral("OpenURI");
}

namespace Intent {
    IntentDefault::IntentDefault(QObject* parent)
        : QObject(parent) 
    {
        
        connect(
            &InvokeManager::instance(), 
            &Invoker::InvokeManager::errorInfo,
            this, 
            &IntentDefault::errorInfo,
            Qt::QueuedConnection
        );
    }

    void IntentDefault::registerQmlType() 
    {
        qmlRegisterType<IntentDefault>("ru.auroraos.IntentDefault", 1, 0, "IntentDefault");
    }

    void IntentDefault::invokeStart(const QString& binName) 
    {
        QJsonObject hints = {
            {intentsHintPreferredHandler, binName},
        };
        QJsonObject params = {};
        InvokeManager::instance().invoke(intentsIntentNameStart, hints, params);
    }

    void IntentDefault::invokeOpenURI(QString url) 
    {
        QJsonObject hints = {};
        QJsonObject params = {
            {"uri", url}
        };
        InvokeManager::instance().invoke(intentsIntentNameOpenURI, hints, params);
    }
}
