/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * Razor - a lightweight, Qt based, desktop toolset
 * http://razor-qt.org
 *
 * Copyright: 2012 Razor team
 * Authors:
 *   Christian Surlykke <christian@surlykke.dk>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */
#include "mainwindow.h"
#include "generalsettings.h"
#include "lidsettings.h"
#include "powerlowsettings.h"

MainWindow::MainWindow(QWidget *parent) :
    RazorConfigDialog(tr("Razor Autosuspend Configuration"), new RazorSettings("razor-autosuspend"), parent)
{

    GeneralSettings* generalSettings = new GeneralSettings(mSettings, this);
    addPage(generalSettings, tr("General"), "razor-autosuspend");
    connect(this, SIGNAL(reset()), generalSettings, SLOT(loadSettings()));

    LidSettings *lidSettings = new LidSettings(mSettings, this);
    addPage(lidSettings, tr("Lid closed"), "laptop-lid");
    connect(this, SIGNAL(reset()), lidSettings, SLOT(loadSettings()));

    PowerLowSettings* powerLowSettings = new PowerLowSettings(mSettings, this);
    addPage(powerLowSettings, tr("Power Low"), "battery-low");
    connect(this, SIGNAL(reset()), powerLowSettings, SLOT(loadSettings()));

    emit reset();
}
