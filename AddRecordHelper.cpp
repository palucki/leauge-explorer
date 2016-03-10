#include "AddRecordHelper.h"
#include "ui_addrecordhelper.h"

AddRecordHelper::AddRecordHelper(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRecordHelper)
{
    ui->setupUi(this);
    ui->newRecordTable->setRowCount(1);
}

AddRecordHelper::~AddRecordHelper()
{
    delete ui;
}

void AddRecordHelper::clearTable()
{
    ui->newRecordTable->clearContents();
}

void AddRecordHelper::updateTableHeaders(const int columns, const QStringList headersList)
{
    ui->newRecordTable->setColumnCount(columns);
    ui->newRecordTable->setHorizontalHeaderLabels(headersList);
    for(int i = 0; i < columns; i++)
        ui->newRecordTable->setItem(0, i,new QTableWidgetItem);

}

void AddRecordHelper::prepareIdColumn(QString tableName)
{
    //int nextId = databaseHandler->getNextId(tableName); QString::number(nextId)

    if(ui->newRecordTable->item(0,0) == NULL)
        ui->newRecordTable->setItem(0,0, new QTableWidgetItem);

    ui->newRecordTable->item(0,0)->setText("(automatic id)");
    ui->newRecordTable->item(0,0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
}

void AddRecordHelper::on_cancelAddingButton_clicked()
{
    this->hide();
    clearTable();
}

void AddRecordHelper::on_saveNewRecordButton_clicked()
{
    QStringList fields;
    for(int i = 1; i < ui->newRecordTable->columnCount(); i++)
        fields << ui->newRecordTable->item(0,i)->text();
    databaseHandler->insertNewRow(fields);

    this->hide();
    clearTable();

    databaseHandler->refreshTable();
}
