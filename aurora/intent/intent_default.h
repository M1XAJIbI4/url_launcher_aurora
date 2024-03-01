// SPDX-FileCopyrightText: 2023 Open Mobile Platform LLC <community@omp.ru>
// SPDX-License-Identifier: BSD-3-Clause

#ifndef INTENT_DEFAULT_H
#define INTENT_DEFAULT_H

#include <QObject>

namespace Intent {
    class IntentDefault : public QObject
    {
        Q_OBJECT
    public:
        explicit IntentDefault(QObject* parent = nullptr);
        ~IntentDefault() override = default;

        static void registerQmlType();

    signals:
        void errorInfo(const QString&, const QString&);

    public slots:
        void invokeStart(const QString& binName);
        void invokeOpenURI(QString url);
    };
}

#endif // INTENT_DEFAULT_H
