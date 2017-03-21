//---------------------------------------------------------------------------

#ifndef Frame_TableH
#define Frame_TableH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TfrmTable : public TFrame
{
__published:	// IDE-managed Components
	TEdit *edtAmounts;
	TRectangle *Rectangle1;
	TLabel *lblTableNo;
private:	// User declarations
public:		// User declarations
	__fastcall TfrmTable(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTable *frmTable;
//---------------------------------------------------------------------------
#endif
