/*=========================================================================
                                                                                                                                    
Program:   VMTK
Module:    $RCSfile: vtkvmtkFluentWriter.h,v $
Language:  C++
Date:      $Date: 2006/04/06 16:47:47 $
Version:   $Revision: 1.2 $
                                                                                                                                    
  Copyright (c) Luca Antiga, David Steinman. All rights reserved.
  See LICENCE file for details.

  Portions of this code are covered under the VTK copyright.
  See VTKCopyright.txt or http://www.kitware.com/VTKCopyright.htm 
  for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.
                                                                                                                                    
=========================================================================*/

// .NAME vtkvmtkFluentWriter - 
// .SECTION Description
// vtkvmtkFluentWriter writes Fluent .msh files. Many thanks to M. Xenos, Y. Alemu and D. Bluestein, BioFluids Laboratory, Stony Brook University, Stony Brook, NY, for the inputs on the file format.

// .SECTION See Also

#ifndef __vtkvmtkFluentWriter_h
#define __vtkvmtkFluentWriter_h

#include "vtkvmtkWin32Header.h"
#include "vtkUnstructuredGridWriter.h"

class vtkCell;
class vtkIdList;

class VTK_VMTK_IO_EXPORT vtkvmtkFluentWriter : public vtkUnstructuredGridWriter
{
public:
  static vtkvmtkFluentWriter *New();
  vtkTypeRevisionMacro(vtkvmtkFluentWriter,vtkUnstructuredGridWriter);
  void PrintSelf(ostream& os, vtkIndent indent);

  vtkSetStringMacro(BoundaryDataArrayName);
  vtkGetStringMacro(BoundaryDataArrayName);

  vtkSetMacro(BoundaryDataIdOffset,int);
  vtkGetMacro(BoundaryDataIdOffset,int);

protected:
  vtkvmtkFluentWriter();
  ~vtkvmtkFluentWriter();

  void WriteData();

  char* BoundaryDataArrayName;
  int BoundaryDataIdOffset;

private:
  vtkvmtkFluentWriter(const vtkvmtkFluentWriter&);  // Not implemented.
  void operator=(const vtkvmtkFluentWriter&);  // Not implemented.
};

#endif
