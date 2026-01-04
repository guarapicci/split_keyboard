/*
    SPDX-FileCopyrightText: 2025 Devin Lin <devin@kde.org>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2

import org.kde.kirigami as Kirigami
import org.kde.kcmutils as KCM

KCM.ScrollViewKCM {
    id: root

    view: LocaleSelectorListView {
        id: list

        Kirigami.Separator {
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
        }
    }

    footer: Kirigami.FormLayout {
        id: formLayout

        QQC2.CheckBox {
            id: soundsEnabled
            Kirigami.FormData.label: i18n("Key press feedback:")
            text: i18n("Sound")

            checked: kcm.soundEnabled
            onCheckedChanged: {
                kcm.soundEnabled = checked;
                checked = Qt.binding(() => kcm.soundEnabled)
            }
        }

        QQC2.CheckBox {
            id: vibrationEnabled
            text: i18n("Vibration")

            checked: kcm.vibrationEnabled
            onCheckedChanged: {
                kcm.vibrationEnabled = checked;
                checked = Qt.binding(() => kcm.vibrationEnabled)
            }
        }

        QQC2.CheckBox {
            id: keyboardNavigationEnabled
            Kirigami.FormData.label: i18n("General:")
            text: i18n("Keyboard navigation")

            checked: kcm.keyboardNavigationEnabled
            onCheckedChanged: {
                kcm.keyboardNavigationEnabled = checked;
                checked = Qt.binding(() => kcm.keyboardNavigationEnabled)
            }
        }
        QQC2.Switch {
            id: splitKeyboardEnabled
            text: i18n("Split keyboard")

            checked: kcm.splitKeyboardEnabled
            onCheckedChanged: {
                kcm.splitKeyboardEnabled = checked;
                checked = Qt.binding(() => kcm.splitKeyboardEnabled)
            }
        }
        QQC2.Switch {
            id: automaticHeightEnabled
            text: i18n("Automatic Height")

            checked: kcm.automaticHeightEnabled
            onCheckedChanged: {
                kcm.automaticHeightEnabled = checked;
                checked = Qt.binding(() => kcm.automaticHeightEnabled)
            }
        }
        QQC2.Slider {
            id: manualHeight
            visible: !(automaticHeightEnabled.checked)

            Kirigami.FormData.label: i18n("Height")

            // upper and lower limits are set to avoid obviously unusable values
            // (e.g. no space left for GUI, not enough height for a keyboard)
            // eventually the style and QML UI should figure out these boundaries automatically
            from: 0.06
            to: 0.8

            value: kcm.manualRelativeHeight
            onValueChanged: {
                kcm.manualRelativeHeight = value;
                value = Qt.binding(() => kcm.manualRelativeHeight)
            }

        }
    }
}
