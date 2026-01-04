/*
    SPDX-FileCopyrightText: 2025 Devin Lin <devin@kde.org>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

#pragma once

#include <KQuickManagedConfigModule>

#include "plasmakeyboardsettings.h"

class PlasmaKeyboardKcm : public KQuickManagedConfigModule
{
    Q_OBJECT
    Q_PROPERTY(bool soundEnabled READ soundEnabled WRITE setSoundEnabled NOTIFY soundEnabledChanged)
    Q_PROPERTY(bool vibrationEnabled READ vibrationEnabled WRITE setVibrationEnabled NOTIFY vibrationEnabledChanged)
    Q_PROPERTY(QStringList enabledLocales READ enabledLocales NOTIFY enabledLocalesChanged)
    Q_PROPERTY(bool keyboardNavigationEnabled READ keyboardNavigationEnabled WRITE setKeyboardNavigationEnabled NOTIFY keyboardNavigationEnabledChanged)
    Q_PROPERTY(bool splitKeyboardEnabled READ splitKeyboardEnabled WRITE setSplitKeyboardEnabled NOTIFY splitKeyboardEnabledChanged)
    Q_PROPERTY(bool automaticHeightEnabled READ automaticHeightEnabled WRITE setAutomaticHeightEnabled NOTIFY automaticHeightEnabledChanged)
    Q_PROPERTY(double manualRelativeHeight READ manualRelativeHeight WRITE setManualRelativeHeight NOTIFY manualRelativeHeightChanged)

public:
    PlasmaKeyboardKcm(QObject *parent, const KPluginMetaData &metaData);

    bool soundEnabled() const;
    void setSoundEnabled(bool soundEnabled);

    bool vibrationEnabled() const;
    void setVibrationEnabled(bool vibrationEnabled);

    QStringList enabledLocales() const;

    Q_INVOKABLE void enableLocale(const QString &locale);
    Q_INVOKABLE void disableLocale(const QString &locale);

    bool keyboardNavigationEnabled() const;
    void setKeyboardNavigationEnabled(bool keyboardNavigationEnabled);

    bool splitKeyboardEnabled() const;
    void setSplitKeyboardEnabled(bool splitKeyboardEnabled);

    bool automaticHeightEnabled() const;
    void setAutomaticHeightEnabled(bool automaticHeightEnabled);

    double manualRelativeHeight() const;
    void setManualRelativeHeight(double manualRelativeHeight);

    bool isSaveNeeded() const override;

public Q_SLOTS:
    void load() override;
    void save() override;

Q_SIGNALS:
    void soundEnabledChanged();
    void vibrationEnabledChanged();
    void enabledLocalesChanged();
    void keyboardNavigationEnabledChanged();
    void splitKeyboardEnabledChanged();
    void automaticHeightEnabledChanged();
    void manualRelativeHeightChanged();

private:
    bool m_soundEnabled = false;
    bool m_vibrationEnabled = true;
    bool m_keyboardNavigationEnabled = false;
    bool m_splitKeyboardEnabled = true;
    bool m_automaticHeightEnabled = true;
    double m_manualRelativeHeight = 0.3;


    bool m_saveNeeded = false;

    QStringList m_enabledLocales;

    PlasmaKeyboardSettings *m_settings = nullptr;

};
