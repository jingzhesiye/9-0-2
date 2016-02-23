#include "stdafx.h"
#include "qword.h"
#include <QDateTime>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

QWord::QWord(QObject *parent)
{		
	m_word = new QAxObject(parent); 			
	m_documents = NULL;
	m_document = NULL;	
}

QWord::~QWord()
{
	close();
}

bool QWord::createNewWord()		//创建一个新的word
{
	QString defaultFileName = tr("日志记录%1").arg(QDateTime::currentDateTime().toString("yyyyMMddhhmmss"));
	m_saveName=QFileDialog::getSaveFileName(0,tr("日志信息"),defaultFileName,tr("*.doc"));
	QFile file(m_saveName);
	if(file.exists())
	{
		m_strError += "错误：目标文件已存在!";			
		return false;
	}
	if(!m_saveName.isEmpty())
	{		
		if(!m_word->setControl("Word.Application"))
		{
			m_strError += "错误：获取word组件失败，请确定是否安装了word!";	
			return false;
		}
		m_word->setProperty("Visible",false);
		m_word->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
		m_documents = m_word->querySubObject("Documents");
		m_documents->dynamicCall("Add (void)");
		m_document = m_word->querySubObject("ActiveDocument");//获取当前激活的文档 	
		return true;
	}else
	{
		m_strError += "错误：文件名为空";		
		return false;
	}
}
bool QWord::createNewWord(const QString& filePath )
{	
	m_saveName = filePath;
	QFile file(m_saveName);
	if(file.exists())
	{
		m_strError += "错误：目标文件已存在!";			
		return false;
	}
	if(!m_saveName.isEmpty())
	{		
		if(!m_word->setControl("Word.Application"))
		{
			m_strError += "错误：获取word组件失败，请确定是否安装了word!\n";
			return false;
		}
		m_word->setProperty("Visible",false);
		m_word->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
		m_documents = m_word->querySubObject("Documents");
		if(!m_documents)
		{
			m_strError += "获取文档失败！\n";
			return false;
		}
		m_documents->dynamicCall("Add (void)");
		m_document = m_word->querySubObject("ActiveDocument");//获取当前激活的文档 	
		return true;
	}else
	{
		m_strError += "错误：文件名为空";		
		return false;
	}
}
void QWord::save()	
{
	if(m_document)
		m_document->dynamicCall("Save()");
	else
		return;
}
void QWord::close()				//关闭 退出 析构时候也会自动调用一次
{
	if(!m_saveName.isEmpty())		//如果不为空  则为新建   
	{
		saveAs();
		m_saveName = "";
	}
	if(m_document)
		m_document->dynamicCall("Close (boolean)",false);
	if(m_word)	
		m_word->dynamicCall("Quit (void)");	
	if(m_documents)
		delete m_documents;	
	if(m_word)
		delete m_word;	
	m_document = NULL;
	m_documents = NULL;
	m_word = NULL;
}
void QWord::saveAs()				
{
	if(m_document)
		m_document->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(m_saveName));	
	else
		return;
}

void QWord::setPageOrientation(int flag)	//设置页面1 横向还是 0竖向
{	
	QAxObject* selection = m_word->querySubObject("Selection");	
	QString page;
	switch (flag)
	{
	case 0:
		page = "wdOrientPortrait";
		break;
	case 1:
		page = "wdOrientLandscape";
		break;
	}
	selection->querySubObject("PageSetUp")->setProperty("Orientation",page);
}
void QWord::setWordPageView(int flag)		
{
	QAxObject* viewPage = m_word->querySubObject("ActiveWindow");
	QString view;
	switch (flag)
	{
	case 1:
		view = "wdNormalView";
		break;
	case 2:
		view = "wdOutlineView";
		break;
	case 3:
		view = "wdPrintView";
		break;
	case 4:
		view = "wdPrintPreview";
		break;
	case 5:
		view = "wdMasterView";
		break;
	case 6:
		view = "wdWebView";
		break;
	case 7:
		view = "wdReadingView";
		break;
	case 8:
		view = "wdConflictView";
		break;
	}	
	viewPage->querySubObject("View")->setProperty("Type",view);
}
void QWord::insertMoveDown()				//插入回车
{
	QAxObject* selection  = m_word->querySubObject("Selection");	
	selection->dynamicCall("TypeParagraph(void)");	
}
void QWord::insertText(const QString& text)
{
	QAxObject* selection  = m_word->querySubObject("Selection");	
	selection->dynamicCall("TypeText(const QString&)",text);		
}

QString QWord::GetText()
{
	QAxObject* selection = m_word->querySubObject("Selection");	
	QString str = selection->dynamicCall("GetText(void)").toString();	
	return str;
}
void QWord::setParagraphAlignment(int flag)
{
	QAxObject* selection = m_word->querySubObject("Selection");	
	if(flag == 0)
	{
		selection->querySubObject("ParagraphFormat")->setProperty("Alignment","wdAlignParagraphCenter");
	}else if(flag == 1)
	{
		selection->querySubObject("ParagraphFormat")->setProperty("Alignment","wdAlignParagraphJustify");
	}else if(flag == 2)
	{
		selection->querySubObject("ParagraphFormat")->setProperty("Alignment","wdAlignParagraphRight");
	}
}
void QWord::setFontSize(int fontsize)		//设置字体大小
{
	QAxObject* selection = m_word->querySubObject("Selection");	
	selection->querySubObject("Font")->setProperty("Size",fontsize);
}
void QWord::setFontBold(bool flag)
{
	QAxObject* selection = m_word->querySubObject("Selection");	
	selection->querySubObject("Font")->setProperty("Bold",flag);
}
void QWord::setFontName(QString& fontName)
{
	QAxObject* selection = m_word->querySubObject("Selection");	
	selection->querySubObject("Font")->setProperty("Name",fontName);
}
void QWord::setSelectionRange(int start,int end)
{
	QAxObject* selection = m_word->querySubObject("Selection");	
	selection->dynamicCall("SetRange(int, int)", start,end);	//第1个字符后开始，到第9个字符结束范围
}
void QWord::getUsedRange(int *topLeftRow, int *topLeftColumn, int *bottomRightRow, int *bottomRightColumn)
{
	QAxObject* range = m_document->querySubObject("Range");
	*topLeftRow = range->property("Row").toInt();
	*topLeftColumn = range->property("Column").toInt();

	QAxObject *rows = range->querySubObject("Rows");
	*bottomRightRow = *topLeftRow + rows->property("Count").toInt() - 1;

	QAxObject *columns = range->querySubObject("Columns");
	*bottomRightColumn = *topLeftColumn + columns->property("Count").toInt() - 1;
}
void QWord::intsertTable(int row,int column)
{	
	QAxObject* tables = m_document->querySubObject("Tables");	
	QAxObject* selection = m_word->querySubObject("Selection");	
	QAxObject* range = selection->querySubObject("Range");
	QVariantList params;
	params.append(range->asVariant());		
	params.append(row);
	params.append(column);	
	tables->querySubObject("Add(QAxObject*, int, int, QVariant&, QVariant&)", params);
	QAxObject* table = selection->querySubObject("Tables(1)");
	table->setProperty("Style","网格型");
}
void QWord::setColumnWidth(int column, int width)		//设置列宽
{
	QAxObject* selection = m_word->querySubObject("Selection");	
	QAxObject* table = selection->querySubObject("Tables(1)");
	table->querySubObject("Columns(int)",column)->setProperty("Width",width);
}
void QWord::setCellString(int row, int column, const QString& text)
{
	QAxObject* selection = m_word->querySubObject("Selection");	
	QAxObject* table = selection->querySubObject("Tables(1)");	
	table->querySubObject("Cell(int, int)",row,column)->querySubObject("Range")->dynamicCall("SetText(QString)", text);
}

void QWord::setCellFontBold(int row, int column, bool isBold)	//设置内容粗体  isBold控制是否粗体
{
	QAxObject* selection = m_word->querySubObject("Selection");	
	QAxObject* table = selection->querySubObject("Tables(1)");
	table->querySubObject("Cell(int, int)",row,column)->querySubObject("Range")->dynamicCall("SetBold(int)", isBold);
}
void QWord::setCellFontSize(int row, int column, int size)		//设置文字大小
{
	QAxObject* selection = m_word->querySubObject("Selection");	
	QAxObject* table = selection->querySubObject("Tables(1)");
	table->querySubObject("Cell(int, int)",row,column)->querySubObject("Range")->querySubObject("Font")->setProperty("Size", size);	
}
QVariant QWord::getCellValue(int row, int column)					//获取单元格内容 此处对于Excel来说列和行从1开始最少
{
	QAxObject* selection = m_word->querySubObject("Selection");	
	QAxObject* table = selection->querySubObject("Tables(1)");
	return table->querySubObject("Cell(int, int)",row,column)->querySubObject("Range")->property("Text");	
}
int QWord::getTableCount()
{
	QAxObject* tables = m_document->querySubObject("Tables");	
	int val = tables->property("Count").toInt();
	return val;
}
void QWord::moveForEnd()
{
	QAxObject* selection = m_word->querySubObject("Selection");	
	QVariantList params;
	params.append(6);		
	params.append(0);		
	selection->dynamicCall("EndOf(QVariant&, QVariant&)", params).toInt();
}
void QWord::insertCellPic(int row,int column,const QString& picPath)
{
	QAxObject* selection = m_word->querySubObject("Selection");	
	QAxObject* table = selection->querySubObject("Tables(1)");
	QAxObject* range = table->querySubObject("Cell(int, int)",row,column)->querySubObject("Range");
	range->querySubObject("InlineShapes")->dynamicCall("AddPicture(const QString&)",picPath);
}
void QWord::setTableAutoFitBehavior(int flag)
{
	QAxObject* selection = m_word->querySubObject("Selection");	
	QAxObject* table = selection->querySubObject("Tables(1)");
	if(0 <= flag & flag <= 2 )
		table->dynamicCall("AutoFitBehavior(WdAutoFitBehavior)", flag);
}
void QWord::deleteSelectColumn(int column)
{
	QAxObject* selection = m_word->querySubObject("Selection");	
	QAxObject* table = selection->querySubObject("Tables(1)");
	QAxObject* columns = table->querySubObject("Columns(int)",column);	
	columns->dynamicCall("Delete()");
}
void QWord::insertTitle(const QString& str1,const QString& str2,const QString& str3,const QString& str4)
{
	setPageOrientation(1);			//页面横向
	setWordPageView(3);				//页面视图	
	setFontSize(25);				//字体大小	
	setParagraphAlignment(0);		//下面文字置中
	setFontBold(true);				//字体加粗
	insertText(QString("多维智能远程巡检系统"));//插入文字
	setFontBold(false);				//字体取消加粗
	insertMoveDown();				//回车换行
	setParagraphAlignment(1);		//下面文字置左
	setFontSize(14);
	insertText(QString("巡检单位：%1").arg(str1));//插入文字	
	insertMoveDown();	
	insertText(QString("巡检计划：%1").arg(str2));//插入文字	
	insertMoveDown();		
	insertText(QString("巡检时间：%1").arg(str3));//插入文字	
	insertMoveDown();	
	insertText(QString("巡 检 人：%1").arg(str4));//插入文字	
	insertMoveDown();	
	setFontSize(12);
	setParagraphAlignment(0);		//下面文字置中
	insertText(QString("巡检结果统计表"));
	insertMoveDown();	
}
void QWord::setOptionCheckSpell(bool flags)
{
	QAxObject* opetions = m_word->querySubObject("Options");	
	if(!opetions)
		return;
	opetions->setProperty("CheckGrammarAsYouType",flags);
	opetions->setProperty("CheckGrammarWithSpelling",flags);
	opetions->setProperty("ContextualSpeller",flags);
	opetions->setProperty("CheckSpellingAsYouType",flags);
}