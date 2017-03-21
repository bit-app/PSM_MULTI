//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Frame_Table.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TfrmTable *frmTable;
//---------------------------------------------------------------------------
__fastcall TfrmTable::TfrmTable(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
