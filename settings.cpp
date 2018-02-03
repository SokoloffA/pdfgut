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


#include "settings.h"
#include <QDir>
#include <QDebug>

QString Settings::mFileName;

/************************************************

 ************************************************/
Settings::Settings(const QString &organization, const QString &application):
    QSettings(organization, application)
{
    setIniCodec("UTF-8");
    defaultValues();
}


/************************************************

 ************************************************/
Settings::Settings(const QString &fileName):
    QSettings(fileName, QSettings::IniFormat)
{
    setIniCodec("UTF-8");
    defaultValues();
}


/************************************************

 ************************************************/
Settings::~Settings()
{

}

/************************************************

 ************************************************/
void Settings::defaultValues()
{
    setDefaultValue(LastDir, QDir::homePath());
}


/************************************************

 ************************************************/
Settings &Settings::instance()
{
    static Settings *inst = 0;

    if (!inst)
    {
        if (mFileName.isEmpty())
            inst = new Settings("pdfgut", "pdfgut");
        else
            inst = new Settings(mFileName);
    }

    return *inst;
}


/************************************************

 ************************************************/
void Settings::setFileName(const QString &fileName)
{
    mFileName = fileName;
}



/************************************************

 ************************************************/
QString Settings::keyToString(Settings::Key key) const
{
    QMetaObject meta = this->staticMetaObject;
    QMetaEnum me = meta.enumerator(0);
    return QString(me.valueToKey(key)).replace('_', '/');
}




/************************************************

 ************************************************/
void Settings::setDefaultValue(const QString &key, const QVariant &defaultValue)
{
    setValue(key, value(key, defaultValue));
}


/************************************************

 ************************************************/
void Settings::setDefaultValue(Settings::Key key, const QVariant &defaultValue)
{
    setValue(key, value(key, defaultValue));
}


/************************************************

 ************************************************/
QVariant Settings::value(Settings::Key key, const QVariant &defaultValue) const
{
    return value(keyToString(key), defaultValue);
}


/************************************************

 ************************************************/
QVariant Settings::value(const QString &key, const QVariant &defaultValue) const
{
    return QSettings::value(key, defaultValue);
}


/************************************************

 ************************************************/
void Settings::setValue(Settings::Key key, const QVariant &value)
{
    setValue(keyToString(key), value);
}


/************************************************

 ************************************************/
void Settings::setValue(const QString &key, const QVariant &value)
{
    QSettings::setValue(key, value);
}



