//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Sqlite_Class.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TClass_Sqlite *Class_Sqlite;
//---------------------------------------------------------------------------
__fastcall TClass_Sqlite::TClass_Sqlite(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TClass_Sqlite::Activate_SqliteDB(String DBPath)
{
	FDConnection1->Params->Database = DBPath;
	FDConnection1->Connected = true;
}
//---------------------------------------------------------------------------
void __fastcall TClass_Sqlite::Create_SqliteDB()
{
	if(Check_Table("MenuTable") == false)
	{
		AnsiString sqlcreate = Create_MenuDB();
		FDConnection1->ExecSQL(sqlcreate);
	}
	else
	{
		//Field Check 필요시 수행
    }
}
//---------------------------------------------------------------------------
bool __fastcall TClass_Sqlite::Check_Table(String TableName)
{
	bool bExist = false;
	//FDConnection1->Connected = true;

	AnsiString sql = "SELECT * FROM sqlite_master WHERE type = 'table'";
	FDQuery1->SQL->Clear();
	FDQuery1->SQL->Add(sql);

	FDQuery1->Open();

	if(FDQuery1->RecordCount > 0)
	{
		for(int i = 1; i <= FDQuery1->RecordCount; i++)
		{
			FDQuery1->RecNo = i;
			if(FDQuery1->FieldByName("Name")->AsString == TableName)
			{
				bExist = true;
				break;
            }
        }

	}

	return bExist;
}
//---------------------------------------------------------------------------
void __fastcall TClass_Sqlite::CheckDBField(String TableName, String FieldName, int FieldType)
{
	//DB Field 존재 유무 체크 후 없으면 생성.
	String Result = "";
	String ColName = "";
	bool isExist = false;
	AnsiString sql = "PRAGMA table_info(" + TableName + ")";
	FDQuery1->SQL->Clear();
	FDQuery1->SQL->Add(sql);
	FDQuery1->Open();

	if(FDQuery1->RecordCount >= 2)
	{
		for(int i = 1; i <= FDQuery1->RecordCount; i++)
		{
			FDQuery1->RecNo = i;
			if(FDQuery1->FieldByName("Name")->AsString == FieldName)
			{
				isExist = true;
				break;
            }
		}

		if(isExist == false)
		{
			if(FieldType == 0) //INT
			{
				sql = "ALTER TABLE " + TableName + " ADD COLUMN " + FieldName + " Integer default 0";
			}
			else if(FieldType == 1) //FLOAT
			{
				sql = "ALTER TABLE " + TableName + " ADD COLUMN " + FieldName + " Float default 0.00";
			}
			//필요시 추후 추가.

			FDQuery1->SQL->Clear();
			FDQuery1->SQL->Add(sql);
			FDQuery1->ExecSQL();
		}
	}
}
//---------------------------------------------------------------------------
String __fastcall TClass_Sqlite::Create_MenuDB()
{
	AnsiString sql = "CREATE TABLE [MenuTable] ( \r\n"
					"[MenuName] 	VARCHAR(30), \r\n"
					"[MenuPrice] 	VARCHAR(30), \r\n"
					"[MenuQty] 		INTEGER, \r\n"
					"[MenuInPrice] 	VARCHAR(30) \r\n"
					");";
	return sql;
}
//---------------------------------------------------------------------------
void __fastcall TClass_Sqlite::Add_MeneDB(String MenuName, String MenuPrice, String MenuQty, String MenuInPrice)
{
	AnsiString sql = "INSERT INTO MenuTable VALUES ("
					"'" + MenuName + "',"
					"'" + MenuPrice + "',"
					"'" + MenuQty + "',"
					"'" + MenuInPrice + "'"
					");";

	//FDConnection1->Connected = true;
	FDConnection1->ExecSQL(sql);
}
//---------------------------------------------------------------------------
String __fastcall TClass_Sqlite::Select_SqliteDB()
{
	AnsiString sql = "SELECT COUNT(*) as YK FROM MenuTable";

	//FDConnection1->Connected = true;
	FDQuery1->SQL->Clear();
	FDQuery1->SQL->Add(sql);
	FDQuery1->Open();

	ShowMessage(FDQuery1->FieldByName("YK")->AsString);
}
//---------------------------------------------------------------------------
