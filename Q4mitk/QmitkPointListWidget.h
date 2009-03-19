/*=========================================================================
 
Program:   Medical Imaging & Interaction Toolkit
Module:    $RCSfile: mitkPropertyManager.cpp,v $
Language:  C++
Date:      $Date$
Version:   $Revision: 1.12 $
 
Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/copyright.html for details.
 
This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.
 
=========================================================================*/

#ifndef QMITK_POINTLIST_WIDGET_H_INCLUDED
#define QMITK_POINTLIST_WIDGET_H_INCLUDED

#include <QListView>

#include "QmitkPointListModel.h"

class QmitkStdMultiWidget;

/*!
 * \brief GUI widget for handling mitk::PointSet
 *
 * Displays all the points in a mitk::PointSet graphically. 
 * Reacts automatically to changes in the PointSet's selection status.
 * Updates PointSet's selection status when this list's selection changes.
 *
 * If a QmitkStdMultiWidget is assigned via SetMultiWidget(), the
 * crosshair of the QmitkStdMultiWidget is moved to the currently selected
 * point.
 *
 */
class QmitkPointListWidget : public QListView
{
  Q_OBJECT

  public:

    QmitkPointListWidget( QWidget* parent = 0 );
    ~QmitkPointListWidget();

    /// assign a point set for observation
    void SetPointSet( mitk::PointSet* pointSet );
    
    /// assign a QmitkStdMultiWidget for updating render window crosshair
    void SetMultiWidget( QmitkStdMultiWidget* multiWidget );
  
  protected slots:

    /// called when the point set data structure changes
    void OnPointSetSelectionChanged();

    /// called when the selection of the view widget changes
    void OnListViewSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected);

  protected:

    QmitkPointListModel* m_PointListModel;
    bool m_SelfCall;

    /// used to position the planes on a selected point
    QmitkStdMultiWidget* m_MultiWidget;
};

#endif

