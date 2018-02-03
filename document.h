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


#ifndef DOCUMENT_H
#define DOCUMENT_H


#include "pdfparser/pdfobject.h"
#include "pdfparser/pdfreader.h"
#include "pdfparser/pdfxref.h"

namespace PDF {
    class Reader;
}

class Document : public QObject
{
    Q_OBJECT
public:
    explicit Document(QObject *parent = 0);

    bool load(const QString &fileName);

    QString fileName() const { return mFileName; }

    const PDF::Object &currentObject() const;

    const PDF::XRefTable &xRefTable() const;

    const PDF::Reader &reader() const { return mReader; }
    PDF::Reader &reader() { return mReader; }

signals:
    void loaded(const Document &document);
    void currentObjectChanged(const PDF::Object &obj);

public slots:
    void setCurrentObject(PDF::ObjNum objNum, PDF::GenNum genNum);

private:
    PDF::Reader mReader;
    QString mFileName;
    PDF::Object mCurrentObject;
};



#endif // DOCUMENT_H
