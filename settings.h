/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * PDFGut - show the Internal Structure of a PDF
 * https://github.com/SokoloffA/pdfgut
 *
 * Copyright: 2018
 *   Alexander Sokoloff <sokoloff.a@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * END_COMMON_COPYRIGHT_HEADER */


#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QMetaEnum>

class Settings : public QSettings
{
    Q_OBJECT
public:
    enum Key{
        LastDir,

        // MainWindow ***************************
        MainWindow_Geometry,
        MainWindow_State,
        MainWindow_SplitterPos
    };

    Q_ENUMS(Key)
    static Settings &instance();
    static void setFileName(const QString &fileName);

    QVariant value(Key key, const QVariant &defaultValue = QVariant()) const;
    QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const;

    void setValue(Key key, const QVariant &value);
    void setValue(const QString &key, const QVariant &value);

private:
    explicit Settings(const QString &organization, const QString &application);
    explicit Settings(const QString &fileName);
    virtual ~Settings();

    void defaultValues();
    void setDefaultValue(const QString &key, const QVariant &defaultValue);
    void setDefaultValue(Key key, const QVariant &defaultValue);

    QString keyToString(Key key) const;
    static QString mFileName;
};

#define settings Settings::instance()


#endif // SETTINGS_H
