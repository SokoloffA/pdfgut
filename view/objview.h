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


#ifndef OBJVIEW_H
#define OBJVIEW_H

#include <QWidget>
#include "pdfparser/pdfobject.h"

namespace Ui {
class ObjView;
}

namespace PDF {
    class Object;
}

class Document;

class ObjView : public QWidget
{
    Q_OBJECT

public:
    explicit ObjView(QWidget *parent = 0);
    ~ObjView();

signals:
    void objectClicked(PDF::ObjNum, PDF::GenNum);

public slots:
    void refresh(const Document &document, const PDF::Object &object);

private:
    Ui::ObjView *ui;
};



#endif // OBJVIEW_H
