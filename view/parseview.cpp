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


#include "parseview.h"
#include "pdfparser/pdfobject.h"
#include "pdfparser/pdfvalue.h"
#include "../thememanager.h"

QString asHTML(const PDF::Value value, bool topLevel);


/************************************************
 *
 ************************************************/
ParseView::ParseView(QWidget *parent) :
    QTextBrowser(parent)
{
    this->setOpenLinks(false);

    connect(this, SIGNAL(anchorClicked(QUrl)),
            this, SLOT(linkClicked(QUrl)));

    this->setStyleSheet(ThemeManager::instance().parseViewQSS());
}


/************************************************
 *
 ************************************************/
QString dictAsHTML(const PDF::Dict dict, bool topLevel)
{
    QString res = "<ul>";
    QString cls =  topLevel ? "class=topLevel" : "";
    foreach (QString key, dict.keys())
    {
        res += QString("<li %2><span class=dName>%1:</span>&nbsp;&nbsp;").arg(key).arg(cls);
        res += asHTML(dict.value(key), false);
        res += "</li>";
    }
    res += "</ul>";
    return res;
}


/************************************************
 *
 ************************************************/
QString arrayAsHTML(const PDF::Array arr)
{
    QString res = "<span class=array>[&nbsp; ";

    for(int i=0; i<arr.size(); ++i)
    {
        res += asHTML(arr.at(i), false) + "&nbsp; ";
    }

    return res + "]</span>";
}


/************************************************
 *
 ************************************************/
QString asHTML(const PDF::Value value, bool topLevel)
{
    switch (value.type())
    {
    case PDF::Value::Type::Dict:
        return dictAsHTML(value.asDict(), topLevel);

    case PDF::Value::Type::Array:
        return arrayAsHTML(value.asArray());

    case PDF::Value::Type::Name:
        return QString("<span class=name> /%1</span>").arg(value.asName().value());

    case PDF::Value::Type::Bool:
        return QString("<span class=bool>%1</span>").arg(value.asBool().value() ? "true" : "false");

    case PDF::Value::Type::Number:
        return QString("<span class=num>%1</span>").arg(value.asNumber().value());

    case PDF::Value::Type::Link:
    {
        return QString("<a href='%1_%2' class=link>%1 %2 R</a>")
                .arg(value.asLink().objNum())
                .arg(value.asLink().genNum());
    }
        break;

    case PDF::Value::Type::String:
        return QString("<span class=string>%1</span>").arg(value.asString().value());
        break;

    case PDF::Value::Type::Null:
        return "<span class=null>null</span>";
        break;

    default:
        return QString("<span class=unknown>Unknown type</span>");
        break;

    }
}


/************************************************
 *
 ************************************************/
void ParseView::selectObject(const PDF::Object &object)
{
    if (!object.isValid())
    {
        this->setHtml("");
        return;
    }

    QString type = object.subType().isEmpty() ? object.type() : QString("%1:%2").arg(object.type(), object.subType());

    QString res = "<html><body>";
    res += ThemeManager::instance().parseViewCSS();
    res += "<div class=header><br>";
    res += QString("&nbsp;<b>Object&nbsp;&nbsp; %1 %2</b><br>").arg(object.objNum()).arg(object.genNum());
    res += QString("&nbsp;<i>Type: %1</i><br>").arg(type);
    res += "</div>";
    res += "<br>";

    res += "<div class=objectView>";
    res += asHTML(object.value(), true);

    res += "</div>";
    res += "</body></html>";

    this->setHtml(res);
}


/************************************************
 *
 ************************************************/
void ParseView::linkClicked(const QUrl &url)
{

    bool ok;
    int objNum = url.path().section("_", 0, 0).toInt(&ok);
    if (!ok)
        return;

    int genNum = url.path().section("_", 1).toInt(&ok);
    if (!ok)
        return;

    emit objectSelected(objNum, genNum);
}
