#include "MainWindow.h"
#include "ui_mainwindow.h"

void MainWindow::connectAllSignals()
{
    connect(ui->connectButton, SIGNAL(clicked()),this, SLOT(connectToDatabase()));
    connect(ui->disconnectButton, SIGNAL(clicked()),this, SLOT(disconnectFromDatabase()));
    connect(ui->executeQueryButton, SIGNAL(clicked()),this, SLOT(executeQueryFromEditor()));
    connect(ui->showSelectedButton, SIGNAL(clicked()),this, SLOT(showSelectedFromButton()));
    connect(ui->editModeButton, SIGNAL(clicked()),this, SLOT(editSelectedTable()));
    connect(ui->saveButton, SIGNAL(clicked()),this, SLOT(savebuttonClicked()));
    connect(ui->deleteButton, SIGNAL(clicked()),this, SLOT(deletebuttonClicked()));
    connect(ui->addRecordButton, SIGNAL(clicked()),this, SLOT(addRecordButtonClicked()));
    connect(ui->resultTable, SIGNAL(cellDoubleClicked(int,int)),this, SLOT(onResultTableCellDoubleClicked(int,int)));
    connect(ui->exitButton, SIGNAL(clicked()),this, SLOT(close()));
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    newRecordWindow = new AddRecordHelper(this);

    connectAllSignals();
}

void MainWindow::setDatabaseHandler(DatabaseHandler* dbh)
{
    databaseHandler = dbh;
    newRecordWindow->setDatabaseHandler(databaseHandler);
}

MainWindow::~MainWindow()
{
    cleanupEnvironment();
    delete newRecordWindow;
    delete ui;
}

void MainWindow::setEditingButtonsState(bool state)
{
    ui->saveButton->setEnabled(state);
    ui->deleteButton->setEnabled(state);
    ui->addRecordButton->setEnabled(state);
}

void MainWindow::connectToDatabase()
{
    databaseHandler->connectToDatabase();
    updateConnectedIndicator(databaseHandler->getConnectionStatus());
    databaseHandler->setResultTable(ui->resultTable);
    databaseHandler->showAvailableTablesFromDatabaseIn(ui->allTables);

    setConnectionButtonsAfterConnectState();
    //setEditingButtonsState(false);
}

void MainWindow::disconnectFromDatabase()
{
    databaseHandler->disconnectFromDatabase();
    updateConnectedIndicator(databaseHandler->getConnectionStatus());

    setConnectionButtonsInitialState();
    setEditingButtonsState(false);

    ui->resultTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    cleanupEnvironment();
}

void MainWindow::setConnectionButtonsAfterConnectState()
{
    ui->connectButton->setEnabled(false);
    ui->disconnectButton->setEnabled(true);
    ui->showSelectedButton->setEnabled(true);
    ui->editModeButton->setEnabled(true);

    ui->addRecordButton->setEnabled(true);
}


void MainWindow::setConnectionButtonsInitialState()
{
    ui->connectButton->setEnabled(true);
    ui->disconnectButton->setEnabled(false);
    ui->showSelectedButton->setEnabled(false);
    ui->editModeButton->setEnabled(false);
}

void MainWindow::cleanupEnvironment()
{
    databaseHandler->clearAvailableTablesList(ui->allTables);
    for(int i = 0; i < ui->resultTable->columnCount(); i++)
        ui->resultTable->horizontalHeaderItem(i)->setText("");
    ui->resultTable->setColumnCount(0);
    ui->resultTable->setRowCount(0);
    ui->resultTable->clearContents();
}

void MainWindow::executeQueryFromEditor()
{
    databaseHandler->executeQuery(ui->queryEditor->toPlainText());
}

void MainWindow::showTableFrom(QListWidgetItem *item)
{
    if(!item) {
       item = ui->allTables->currentItem();
       qDebug() << "Allocated to item";
    }
    QString selectedTable = item->text();
    databaseHandler->showTableInResults(selectedTable);
    qDebug() << "selected table: " << selectedTable;

}

void MainWindow::updateConnectedIndicator(bool state)
{
    if(state)
    {
        ui->connectionIndicator->setStyleSheet("QCheckBox::indicator { background-color: green }");
    }
    else
    {
        ui->connectionIndicator->setStyleSheet("QCheckBox::indicator { background-color: red }");
    }
}

void MainWindow::on_allTables_itemDoubleClicked(QListWidgetItem *item)
{
    showTableFrom(item);
}

void MainWindow::showSelectedFromButton()
{
    showTableFrom(ui->allTables->currentItem());
}


void MainWindow::editSelectedTable()
{
    ui->resultTable->setEditTriggers(QAbstractItemView::DoubleClicked);

    ui->editModeButton->setEnabled(false);
    setEditingButtonsState(true);
}

void MainWindow::savebuttonClicked()
{
    ui->resultTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->editModeButton->setEnabled(true);
    setEditingButtonsState(false);

    databaseHandler->saveChangesToDatabase();
    showTableFrom(ui->allTables->currentItem()); //update table
}

void MainWindow::deletebuttonClicked()
{
        qDebug() << "Remove";
        ui->resultTable->removeRow(ui->resultTable->currentRow());
        ui->resultTable->setCurrentCell(ui->resultTable->currentRow(), ui->resultTable->currentColumn());
}

void MainWindow::addRecordButtonClicked()
{
    if(ui->allTables->currentRow() != -1)
    {
        //clear contents
        newRecordWindow->clearTable();

        //update table headers
        QStringList headersList;
        for(int i = 0; i < ui->resultTable->columnCount(); i++)
        {
            headersList << ui->resultTable->horizontalHeaderItem(i)->text();
        }
        newRecordWindow->updateTableHeaders(ui->resultTable->columnCount(), headersList);
        newRecordWindow->prepareIdColumn(ui->allTables->currentItem()->text());


        //add rows
        newRecordWindow->show();
    }
}

void MainWindow::onResultTableCellDoubleClicked(int row, int column)
{
    qDebug() << "We edit: " << row << " " << column;
}
