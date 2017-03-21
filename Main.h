//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Layouts.hpp>
#include "Frame_Table.h"
#include <FMX.Forms.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TStyleBook *StyleBook1;
	TPanel *Panel1;
	TLabel *Label1;
	TGridPanelLayout *GridPanelLayout1;
	TfrmTable *frmTable1;
	TfrmTable *frmTable2;
	TfrmTable *frmTable3;
	TfrmTable *frmTable4;
	TfrmTable *frmTable5;
	TfrmTable *frmTable6;
	TfrmTable *frmTable7;
	TfrmTable *frmTable8;
	TfrmTable *frmTable9;
	TfrmTable *frmTable10;
	TfrmTable *frmTable11;
	TfrmTable *frmTable12;
	TfrmTable *frmTable13;
	TfrmTable *frmTable14;
	TfrmTable *frmTable15;
	TfrmTable *frmTable16;
	TfrmTable *frmTable17;
	TfrmTable *frmTable18;
	TfrmTable *frmTable19;
	TfrmTable *frmTable20;
	TPanel *Panel2;
private:	// User declarations
	String DBPath;
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
