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


#include "objtreeviewitem.h"

#define ITEM_MAGIC_VALUE 20171205
#define ITEM_MAGIC_ROLE  Qt::UserRole + 10


/************************************************
 *
 ************************************************/
ObjTreeViewItem::ObjTreeViewItem(const PDF::Object &obj):
    QStandardItem()
{
    setData(ITEM_MAGIC_VALUE, ITEM_MAGIC_ROLE);
    setData(obj.objNum(),   ObjRole);
    setData(obj.genNum(),   GenRole);
    setData(obj.type(),     TypeRole);
    setData(obj.subType(),  SubTypeRole);


    QString text = QString("%1 %2").arg(obj.objNum()).arg(obj.genNum());
    QString type = obj.type();
    QString subType = obj.subType();

    if (!type.isEmpty())
        text += QString(" (%1%2)")
                .arg(type)
                .arg(subType.isEmpty() ? "" : ":" + subType);

    this->setText(text);


}


/************************************************
 *
 ************************************************/
ObjTreeViewItem::~ObjTreeViewItem()
{

}


/************************************************
 *
 ************************************************/
PDF::ObjNum ObjTreeViewItem::objNum() const
{
    return data(ObjRole).toInt();
}


/************************************************
 *
 ************************************************/
PDF::GenNum ObjTreeViewItem::genNum() const
{
    return data(GenRole).toInt();
}


/************************************************
 *
 ************************************************/
ObjTreeViewItem *ObjTreeViewItem::fromQStandardItem(QStandardItem *item)
{
    if (!item)
        return nullptr;

    if (item->data(ITEM_MAGIC_ROLE).toInt() == ITEM_MAGIC_VALUE)
        return static_cast<ObjTreeViewItem*>(item);

    return nullptr;
}

