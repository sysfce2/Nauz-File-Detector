/* Copyright (c) 2018-2025 hors<horsicq@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "dialogabout.h"

#include "ui_dialogabout.h"

DialogAbout::DialogAbout(QWidget *pParent) : QDialog(pParent), ui(new Ui::DialogAbout)
{
    ui->setupUi(this);

    XAboutWidget::DATA _data = {};

    _data.sInfo += QString("<p align=\"center\"><span style=\" font-weight:600;\">%1</span></p>").arg(XOptions::getTitle(X_APPLICATIONDISPLAYNAME, X_APPLICATIONVERSION));
    _data.sInfo += QString("<p align=\"center\"><span style=\" font-weight:600;\">Copyright (C) 2017-%1 Hors</span></p>") .arg(QDate::currentDate().year());
    _data.sInfo += QString(
                       "<p align=\"center\"><span style=\" font-weight:600;\">%1: </span><a href=\"mailto:horsicq@gmail.com\"><span style=\" text-decoration: underline; "
                       "color:#ff0000;\">horsicq@gmail.com</span></a></p>")
                       .arg(tr("Bugreports"));
    _data.sInfo += QString(
                       "<p align=\"center\"><span style=\" font-weight:600;\">%1: </span><a href=\"http://ntinfo.biz\"><span style=\" text-decoration: underline; "
                       "color:#ff0000;\">http://ntinfo.biz</span></a></p>")
                       .arg(tr("Website"));
    _data.sInfo +=
        QString(
            "<p align=\"center\"><span style=\" font-weight:600;\">%1(Paypal): </span><a href=\"ntinfo.re@gmail.com\"><span style=\" text-decoration: underline; "
            "color:#ff0000;\">ntinfo.re@gmail.com</span></a></p>")
            .arg(tr("Donate"));
    _data.sInfo +=
        QString(
            "<p align=\"center\"><span style=\" font-weight:600;\">%1(BTC): </span><a href=\"3DqddVBX9PKqMvNPXZ3gPHBNNRtD9CnmJo\"><span style=\" text-decoration: "
            "underline; color:#ff0000;\">3DqddVBX9PKqMvNPXZ3gPHBNNRtD9CnmJo</span></a></p>")
            .arg(tr("Donate"));
    _data.sInfo +=
        QString(
            "<p align=\"center\"><span style=\" font-weight:600;\">%1: </span><a href=\"https://github.com/horsicq/Nauz-File-Detector\"><span style=\" text-decoration: "
            "underline; color:#ff0000;\">https://github.com/horsicq/Nauz-File-Detector</span></a></p>")
            .arg(tr("Source code"));

    _data.sLibraries +=
        QString(
            "<p align=\"center\"><span style=\" font-weight:600;\">QT Library %1 </span><a href=\"http://qt-project.org\"><span style=\" text-decoration: "
            "underline; color:#ff0000;\">http://qt-project.org</span></a></p>")
            .arg(QT_VERSION_STR);

    _data.sLogoPath = ":/images/main.png";
    _data.sUpdatesLink = "https://github.com/horsicq/Nauz-File-Detector/releases";
    _data.sThanksLink = "https://github.com/horsicq/Nauz-File-Detector/blob/master/doc/THANKS.md";

    ui->widgetAbout->setData(_data);
}

DialogAbout::~DialogAbout()
{
    delete ui;
}

void DialogAbout::on_pushButtonOK_clicked()
{
    this->close();
}
