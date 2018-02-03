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


#include "objnumtreeview.h"
#include "objtreeviewitem.h"
#include "pdfparser/pdfxref.h"
#include <QHeaderView>


/************************************************
 *
 ************************************************/
ObjNumTreeView::ObjNumTreeView(QWidget *parent) :
    QTreeView(parent)
{
    mModel = new QStandardItemModel(this);


    mModel->setHorizontalHeaderLabels(QStringList() << "Object");

    connect(this, &ObjNumTreeView::activated,
            this, &ObjNumTreeView::itemActivated);

    connect(this, &ObjNumTreeView::clicked,
            this, &ObjNumTreeView::itemActivated);

    setModel(mModel);
}


/************************************************
 *
 ************************************************/
void ObjNumTreeView::refresh(const Document &document)
{
    mModel->removeRows(0, mModel->rowCount());
    int row = 0;
    foreach (const PDF::XRefEntry &entry, document.xRefTable())
    {
        if (entry.type() == PDF::XRefEntry::Free)
            continue;

        PDF::Object obj = document.reader().getObject(entry);
        QStandardItem *item = new ObjTreeViewItem(obj);
        mModel->setItem(row, item);
        row++;
    }
}


/************************************************
 *
 ************************************************/
void ObjNumTreeView::selectObject(const PDF::Object &object)
{
    for (int i=0; i<mModel->rowCount(); ++i)
    {
        ObjTreeViewItem *item = ObjTreeViewItem::fromQStandardItem(mModel->item(i, 0));
        if (item && item->objNum() == object.objNum() && item->genNum() == object.genNum())
        {
            this->setCurrentIndex(item->index());
        }
    }
}


/************************************************
 *
 ************************************************/
void ObjNumTreeView::itemActivated(const QModelIndex &index)
{
    ObjTreeViewItem *item = ObjTreeViewItem::fromQStandardItem(mModel->itemFromIndex(index));
    if (item)
    {
        emit objectSelected(item->objNum(), item->genNum());
    }
}
