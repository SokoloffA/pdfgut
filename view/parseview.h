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


#ifndef PARSEVIEW_H
#define PARSEVIEW_H

#include <QTextBrowser>
#include "pdfparser/pdfobject.h"

namespace PDF {
    class Object;
}

class ParseView : public QTextBrowser
{
    Q_OBJECT
public:
    explicit ParseView(QWidget *parent = 0);

signals:
    void objectSelected(PDF::ObjNum, PDF::GenNum);

public slots:
    void selectObject(const PDF::Object &object);


private slots:
    void linkClicked(const QUrl &url);
};

#endif // PARSEVIEW_H
