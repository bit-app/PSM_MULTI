//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include <System.IOUtils.hpp>
#include "Main.h"
#include "Sqlite_Class.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	DBPath = "C:\\MiraeData\\YK.DB";
	DBPath = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), "YK.DB");
	Class_Sqlite = new TClass_Sqlite(this);
	Class_Sqlite->Activate_SqliteDB(DBPath);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	Class_Sqlite->Create_SqliteDB();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
	Class_Sqlite->Add_MeneDB("YK", "15000", "10", "10000");
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button3Click(TObject *Sender)
{
	Class_Sqlite->Select_SqliteDB();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button4Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

