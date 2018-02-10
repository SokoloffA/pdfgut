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


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"
#include "panels/objnumtreeview.h"
#include "view/objview.h"

#include <QFileDialog>
#include <QString>
#include <QBoxLayout>



/************************************************
 *
 ************************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    mObjNumTree = new ObjNumTreeView(this);
    ui->panelsBox->addWidget(mObjNumTree);

    mView = new ObjView(this);
    ui->previewBox->addWidget(mView);


    connect(ui->actionOpen, SIGNAL(triggered()),
            this, SLOT(openFile()));

    connect(&mDocument,  &Document::loaded,
            mObjNumTree, &ObjNumTreeView::refresh);

    connect(&mDocument,  &Document::currentObjectChanged,
            mObjNumTree, &ObjNumTreeView::selectObject);

    connect(mObjNumTree, SIGNAL(objectSelected(PDF::ObjNum,PDF::GenNum)),
            &mDocument,  SLOT(setCurrentObject(PDF::ObjNum,PDF::GenNum)));

    connect(&mDocument,  &Document::currentObjectChanged,
            mView,       &ObjView::refresh);

    connect(mView,       SIGNAL(objectSelected(PDF::ObjNum,PDF::GenNum)),
            &mDocument,  SLOT(setCurrentObject(PDF::ObjNum,PDF::GenNum)));


    loadSettings();
    ui->mainToolBar->hide();
}


/************************************************
 *
 ************************************************/
MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}


/************************************************
 *
 ************************************************/
void MainWindow::openFile()
{
    mDocument.setCurrentObject(4, 0);
    QString fileName = QFileDialog::getOpenFileName(
                this,
                this->windowTitle(),
                settings.value(Settings::LastDir).toString(),
                tr("PDF files (*.pdf);;All files (*.*)"));

    if (fileName.isEmpty())
        return;

    settings.setValue(Settings::LastDir, QFileInfo(fileName).path());

    mDocument.load(fileName);
}


/************************************************
 *
 ************************************************/
void MainWindow::loadSettings()
{
    restoreGeometry(settings.value("MainWindow/Geometry").toByteArray());
    restoreState(settings.value("MainWindow/State").toByteArray());
    ui->splitter->restoreState(settings.value("MainWindow/Splitter").toByteArray());
}


/************************************************
 *
 ************************************************/
void MainWindow::saveSettings()
{
    settings.setValue("MainWindow/Geometry", saveGeometry());
    settings.setValue("MainWindow/State", saveState());
    settings.setValue("MainWindow/Splitter",  QVariant(ui->splitter->saveState()));
    settings.sync();
}
