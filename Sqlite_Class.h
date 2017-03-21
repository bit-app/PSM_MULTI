//---------------------------------------------------------------------------

#ifndef Sqlite_ClassH
#define Sqlite_ClassH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
//---------------------------------------------------------------------------
class TClass_Sqlite : public TForm
{
__published:	// IDE-managed Components
	TFDConnection *FDConnection1;
	TFDQuery *FDQuery1;
private:	// User declarations
//---------------------------------------------------------------------------
//Functions
String __fastcall Create_MenuDB();
bool __fastcall Check_Table(String TableName);
void __fastcall CheckDBField(String TableName, String FieldName, int FieldType);
//---------------------------------------------------------------------------
public:		// User declarations
	__fastcall TClass_Sqlite(TComponent* Owner);
//---------------------------------------------------------------------------
//Functions
	void __fastcall Create_SqliteDB();
	void __fastcall Add_MeneDB(String MenuName, String MenuPrice, String MenuQty, String MenuInPrice);
	String __fastcall Select_SqliteDB();
	void __fastcall Activate_SqliteDB(String DBPath);
//---------------------------------------------------------------------------
};
//---------------------------------------------------------------------------
extern PACKAGE TClass_Sqlite *Class_Sqlite;
//---------------------------------------------------------------------------
#endif
