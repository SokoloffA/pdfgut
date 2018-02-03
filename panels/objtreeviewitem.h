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


#ifndef OBJTREEVIEWITEM_H
#define OBJTREEVIEWITEM_H

#include <QStandardItem>

#include "pdfparser/pdfobject.h"


class ObjTreeViewItem: public QStandardItem
{
public:
    enum Roles {

        ObjRole = Qt::UserRole + 1,
        GenRole,
        TypeRole,
        SubTypeRole
    };

    explicit ObjTreeViewItem(const PDF::Object &obj);
    virtual ~ObjTreeViewItem();

    PDF::ObjNum objNum() const;
    PDF::GenNum genNum() const;

    static ObjTreeViewItem *fromQStandardItem(QStandardItem *item);

};

#endif // OBJTREEVIEWITEM_H
